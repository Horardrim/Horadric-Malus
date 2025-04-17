#include <iostream>
#include <unordered_map>
#include <list>
#include <utility>

class LFUCache {
public:
    LFUCache(size_t capacity) : capacity(capacity) {}

    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) {
            return -1; // 缓存中没有该键
        }

        // 更新频率
        Node* node = it->second;
        freqList[node->freq].erase(node->iter);
        node->freq++;
        freqList[node->freq].push_back(node);
        node->iter = --freqList[node->freq].end();

        return node->value;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        auto it = cache.find(key);
        if (it != cache.end()) {
            // 更新值
            Node* node = it->second;
            node->value = value;

            // 更新频率
            freqList[node->freq].erase(node->iter);
            node->freq++;
            freqList[node->freq].push_back(node);
            node->iter = --freqList[node->freq].end();
        } else {
            if (cache.size() == capacity) {
                // 淘汰频率最低且最久未使用的项
                auto& minFreqList = freqList[minFreq];
                Node* node = minFreqList.front();
                minFreqList.pop_front();
                cache.erase(node->key);
                delete node;
            }

            // 插入新项
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            freqList[1].push_back(newNode);
            newNode->iter = --freqList[1].end();
            minFreq = 1;
        }
    }

private:
    struct Node {
        int key;
        int value;
        int freq;
        std::list<Node*>::iterator iter;

        Node(int k, int v) : key(k), value(v), freq(1) {}
    };

    std::unordered_map<int, Node*> cache; // 键到节点的映射
    std::unordered_map<int, std::list<Node*>> freqList; // 频率到节点列表的映射
    size_t capacity; // 缓存容量
    int minFreq; // 当前最小频率
};
