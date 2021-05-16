#pragma once

namespace example_clr
{

public ref class clr1
{
private:
    double m_d;
    clr2 m_clr2;

public:
    clr1( double d, int i );

    double get_d();
    int get_i();
};

}
