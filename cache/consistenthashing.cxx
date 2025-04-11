#include "consistenthashing.hxx"

void ConsistentHashing::cacheDistribution() const
{
    std::unordered_map<std::string, size_t> cacheDistribute;
    for (auto pair : hashRing) {
        if (cacheDistribute.find(pair.second->nodeName()) == std::end(cacheDistribute))
        {
            cacheDistribute[pair.second->nodeName()] = pair.second->getCacheSize();
        }
        else
        {
            cacheDistribute[pair.second->nodeName()] += pair.second->getCacheSize();
        }
    }

    for (auto entry : cacheDistribute)
    {
        std::cout << "cache node: " << entry.first << " has " << entry.second << " caches;" << std::endl;
    }
}