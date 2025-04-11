#include <sstream>

#include "consistenthashing.hxx"


int main(int argc, char ** argv)
{
    ConsistentHashing ch(3); // 使用 3 个虚拟节点

    ch.addNode("127.0.0.1:6379", 5);
    ch.addNode("127.0.0.1:16379", 5);

    for (int i = 0; i < 2000; ++i)
    {
        std::stringstream ss;
        ss << "cache-key-" << i;
        std::string vnode = ch.getNode(ss.str());
        std::cout << "Key '" << ss.str() << "' is on node: " << vnode << std::endl;
    }

    ch.cacheDistribution();
    // for (const auto& entry : ch.cache) {
    //     std::cout << "Key '" << entry.first << "' is on node: " << ch.getNode(entry.first) << std::endl;
    // }

    return 0;
}
