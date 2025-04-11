#include "cacheserver.hxx"

CacheServer::CacheServer(
    const std::string & nodeName,
    const std::string vNodeName) :
_cacheSize(0),
_realNodeName(nodeName),
_vNodeName(vNodeName)
{

}
