#ifndef MAKE_UNQIUE_H_INCLUDED
#define MAKE_UNQIUE_H_INCLUDED

#include <memory>

namespace std {

template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args)
{
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

}
#endif // MAKE_UNQIUE_H_INCLUDED
