#ifndef RANGEDNUM_H
#define RANGEDNUM_H

#include <iostream>
#include <numeric>

namespace util {

template<typename t>
class RangedNum
{
    public:

        RangedNum(t minimum, t maximum, t initialValue)
        :   minimumNumber ( std::numeric_limits<t>::min() )
        ,   maximumNumber ( std::numeric_limits<t>::max()  )
        ,   value         ( 0 )
        {
            setMin   (  minimum      );
            setMax   (  maximum      );
            setValue (  initialValue );
        }

        void setValue(const t newVal)
        {
            if (newVal == value) {
               return;
            }

            if (newVal <= maximumNumber
                &&
                newVal >= minimumNumber) {
                value = newVal;
            }
            else {
                std::cout << "Number out of of range! (" << minimumNumber << " <= n <= " << maximumNumber << ")! \n";
                if ( newVal > maximumNumber ) {
                   value = maximumNumber;
                }
                else if ( newVal < minimumNumber) {
                    value = minimumNumber;
                }
            }
        }


        t getValue()
        {
            return value;
        }

        void setMin( const int x )
        {
            if( x > maximumNumber) {
                minimumNumber = maximumNumber;
                std::cout << "Min number set too large! \n";
                return;
            }
            minimumNumber = x;
        }

        void setMax( const int x )
        {
            if( x < minimumNumber) {
                minimumNumber = maximumNumber;
                std::cout << "max number set too large! \n";
                return;
            }
            maximumNumber = x;
        }

        const t getMin() const
        {
            return minimumNumber;
        }

        const t getMax() const
        {
            return maximumNumber;
        }

    private:
        t minimumNumber;
        t maximumNumber;

        t value;
};
}//namespace util
#endif // RANGEDNUM_H
