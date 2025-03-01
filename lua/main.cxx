#include <lua5.3/lua.hpp>

#include <iostream>

int main() {
    // 创建Lua状态
    lua_State* L = luaL_newstate();
    if (!L) {
        std::cerr << "Failed to create Lua state" << std::endl;
        return 1;
    }

    // 打开Lua标准库
    luaL_openlibs(L);

    // 加载并运行Lua脚本
    if (luaL_dofile(L, "example.lua") != 0) {
        std::cerr << "Error loading Lua script: " << lua_tostring(L, -1) << std::endl;
        lua_close(L);
        return 1;
    }

    // 调用Lua函数
    lua_getglobal(L, "add");  // 获取全局函数add
    if (!lua_isfunction(L, -1)) {
        std::cerr << "Function 'add' not found in Lua script" << std::endl;
        lua_close(L);
        return 1;
    }

    // 推送参数
    lua_pushnumber(L, 5);  // 第一个参数
    lua_pushnumber(L, 3);  // 第二个参数

    // 调用函数
    if (lua_pcall(L, 2, 1, 0) != 0) {
        std::cerr << "Error calling Lua function: " << lua_tostring(L, -1) << std::endl;
        lua_close(L);
        return 1;
    }

    // 获取返回值
    if (!lua_isnumber(L, -1)) {
        std::cerr << "Lua function did not return a number" << std::endl;
        lua_close(L);
        return 1;
    }

    double result = lua_tonumber(L, -1);
    std::cout << "Result of add(5, 3): " << result << std::endl;

    // 访问全局变量
    lua_getglobal(L, "my_global");
    if (!lua_isstring(L, -1)) {
        std::cerr << "Global variable 'my_global' not found in Lua script" << std::endl;
        lua_close(L);
        return 1;
    }

    std::string globalValue = lua_tostring(L, -1);
    std::cout << "Global variable 'my_global': " << globalValue << std::endl;

    // 关闭Lua状态
    lua_close(L);

    return 0;
}
