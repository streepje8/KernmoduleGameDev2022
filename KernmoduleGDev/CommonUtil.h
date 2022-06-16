#pragma once
#include <string>
#include <sstream>
template<typename Base, typename T>
inline bool instanceof(const T* ptr) {
	return dynamic_cast<const Base*>(ptr) != nullptr;
}
inline std::string pointer_to_string(void* pointer) {
	std::stringstream ss;
	ss << pointer;
	return ss.str();
}

