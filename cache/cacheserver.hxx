#ifndef CACHE_SERVER_HXX
#define CACHE_SERVER_HXX

#include <string>
#include <unordered_map>

class CacheServer
{
public:
    CacheServer(const std::string & nodeName, const std::string vNodeName);

    inline const std::string & nodeName() const
    {  return _realNodeName;  }

    inline const std::string & vNodeName() const
    {  return _vNodeName;  }

    inline void addCacheSize()
    {  ++_cacheSize;  }

    inline size_t getCacheSize() const
    {  return _cacheSize;  }

private:
    size_t _cacheSize;
    const std::string _realNodeName;
    const std::string _vNodeName;
};

#endif
