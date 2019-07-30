#ifndef TOSTR_H_INCLUDED
#define TOSTR_H_INCLUDED

#include <sstream>

namespace util {

template <typename t>
std::string toString ( const t number )
{
	std::stringstream ss;
	ss << number;
	return ss.str();
}

} //namespace util

#endif // TOSTR_H_INCLUDED
