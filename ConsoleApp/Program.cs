using System;

namespace ConsoleApp
{
    class Program
    {
        static void Main()
        {
            var clr_class = new example_clr.clr1( 1.23, 99 );
            Console.WriteLine( "{0} {1}", clr_class.get_d(), clr_class.get_i() );
        }
    }
}
