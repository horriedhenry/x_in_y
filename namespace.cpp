#include <iostream>

/*
 Namespeces are used to declare a seperate scope for functions, variable,
 classess.

 avoid the using derivative for Namespeces, because they violate the reason why
 they are introduced in the first place

 :: - is the scope resolution operator
 */

void foo()
{
    std::cout << "global foo" << "\n";
}

void bar()
{
    std::cout << "global bar" << "\n";
}

namespace FooBar
{
    int number {100};
    void foo()
    {
        std::cout << "FooBar::foo" << "\n";
    }

    void bar()
    {
        std::cout << "barBar::bar" << "\n";
    }
}

// Namespeces can be nested
namespace FooBarBaz
{
    namespace Foo
    {
        void foo()
        {
            std::cout << "FooBarBaz::Foo::foo" << "\n";
        }

        void bar()
        {
            std::cout << "FooBarBaz::Foo::bar" << "\n";
        }
    }

    namespace Bar
    {
        void foo()
        {
            std::cout << "FooBarBaz::Bar::foo" << "\n";
        }

        void bar()
        {
            std::cout << "FooBarBaz::Bar::bar" << "\n";
        }
    }
}

int main (int argc, char *argv[])
{
    ::foo(); // refers to global foo
    ::bar(); // refers to global bar
    FooBar::number = 200; // modify the default value 100
    std::cout << FooBar::number << "\n";
    FooBar::foo();
    FooBar::bar();
    FooBarBaz::Foo::foo();
    FooBarBaz::Foo::bar();
    FooBarBaz::Bar::foo();
    FooBarBaz::Bar::bar();
    return 0;
}
