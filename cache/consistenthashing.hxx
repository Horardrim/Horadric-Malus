#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>
#include <algorithm>

#include "cacheserver.hxx"

class ConsistentHashing {
public:
    ConsistentHashing(size_t replicas) : replicas(replicas) {}

    void addNode(const std::string& node, const size_t & v_node_size) {
        for (size_t i = 0; i < v_node_size; ++i) {
            std::string vnode = node + "#" + std::to_string(i);
            size_t hash = hashFunction(vnode);
            CacheServer * cacheServer = new CacheServer(node, vnode);
            hashRing[hash] = cacheServer;
        }
        updateSortedHashes();
    }

    void removeNode(const std::string& node) {
        for (size_t i = 0; i < replicas; ++i) {
            std::string vnode = node + "#" + std::to_string(i);
            size_t hash = hashFunction(vnode);
            hashRing.erase(hash);
        }
        updateSortedHashes();
    }

    std::string getNode(const std::string& key) {
        size_t hash = hashFunction(key);
        auto it = std::lower_bound(sortedHashes.begin(), sortedHashes.end(), hash);
        if (it == sortedHashes.end()) {
            it = sortedHashes.begin();
        }

        hashRing[*it]->addCacheSize();
        return hashRing[*it]->vNodeName();
    }

    void redistributeCache(const std::string& node) {
        // std::unordered_map<std::string, std::string> cacheCopy = cache;
        // for (auto& entry : cacheCopy) {
        //     if (getNode(entry.first) == node) {
        //         // Remove the entry from the cache
        //         cache.erase(entry.first);
        //         // Find the next node and reassign the entry
        //         std::string nextNode = getNode(entry.first);
        //         cache[entry.first] = entry.second;
        //         std::cout << "Reassigned key '" << entry.first << "' to node " << nextNode << std::endl;
        //     }
        // }
    }
    // std::unordered_map<std::string, std::string> cache;
    void cacheDistribution() const;

private:
    size_t hashFunction(const std::string& key) {
        std::hash<std::string> hasher;
        return hasher(key);
    }

    void updateSortedHashes() {
        sortedHashes.clear();
        for (const auto& pair : hashRing) {
            sortedHashes.push_back(pair.first);
        }
        std::sort(sortedHashes.begin(), sortedHashes.end());
    }

    std::unordered_map<size_t, CacheServer *> hashRing;
    std::vector<size_t> sortedHashes;
    size_t replicas;
};
