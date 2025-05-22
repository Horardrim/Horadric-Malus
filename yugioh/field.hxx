#ifndef FIELD_HXX
#define FIELD_HXX

#include <type_traits>
#include "cardtag.hxx"

template<typename T>
typename std::enable_if<std::is_same<T, monster_card>::value, int>::type
summon(const T & mc) { return 0; }

template<typename T>
typename std::enable_if<std::is_same<T, magic_card>::value, int>::type
activate_magic(const T & mg) { return 0; }

template<typename T>
typename std::enable_if<std::is_same<T, trap_card>::value, int>::type
activate_trap(const T & tp) { return 0; }


#endif
