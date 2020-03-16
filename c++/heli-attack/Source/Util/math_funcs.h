#ifndef MATH_FUNCS_H_INCLUDED
#define MATH_FUNCS_H_INCLUDED

#include <cmath>

namespace Math
{

    constexpr static double PI = 3.14159265359;

    template < typename T >
    const T
    toRads ( const T degrees )
    {
        return degrees * ( PI / 180 );
    }

    template < typename T >
    const T
    toDeg ( const T degrees )
    {
        return degrees * ( 180 / PI );
    }

    template <typename T>
    const float
    getRotInDeg ( T dx, T dy )
    {
        return toDeg ( atan2 ( dy,dx ) ) + 180;
    }

    template <typename T>
    const float
    getRotInRad ( T dx, T dy )
    {
        return  atan2 ( dy,dx ) + 180;
    }

    template <typename T, typename V>
    const T
    getDistance   ( const sf::Vector2<V>& vect1, const sf::Vector2<V>& vect2)
    {
        int dy = abs ( vect1.y - vect2.y );
        int dx = abs ( vect1.x - vect2.x );

        return  (T)sqrt( pow ( dx, 2 ) + pow ( dy, 2 ) );
    }

    template<typename T, typename R>
    void
    getDyDx ( sf::Vector2<T> v1, sf::Vector2<R> v2, float& dx, float &dy )
    {
        dx = v1.x - v2.x;
        dy = v1.y - v2.y;
    }

} //Namespace Math

#endif // MATH_FUNCS_H_INCLUDED
