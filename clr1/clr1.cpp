#include "clr1.hpp"

namespace example_clr
{

clr1::clr1( double d, int i )
    : m_d( d )
    , m_clr2( i )
{
}

double clr1::get_d()
{
    return m_d;
}

int clr1::get_i()
{
    return m_clr2.get_i();
}

}
