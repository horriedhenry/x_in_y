#include <iostream>

/*

   Enum, short for enumeration is a user defined data type that consists of set
   of named integral constants. Enum's help to define a set of related constants
   in a clear organised way.

   The problem with regular enum is that, it has a global scope i.e you can
   access enum constants in any scope, it be a function or a class. This might
   be problematic. To solve this c++11 introduced scoped enum, or also called
   as enum class.

   In the context of enumerators (enum) the individual constants are known as
   enumerators or enumerator constants.

   Enumerator constants can also be refered as enum members or enum variables.

   general enum's do not have type saftey, i.e if two different enum type's have
   same a similarly named member a name conflict occurs. On the other hand
   scoped enum's have type saftey. So you have to be careful when using global
   enums.

   For scoped enums you should use scope resolution operator '::' to access enum
   members.

*/

enum Color {
    Red,   // 0
    Green, // 1
    Yellow // 2
};

enum Other {
    Stuff = 2,  // start's from 2
    Stuff1,     // 3
    Stuff2,     // 4
    Stuff3 = 9, // the below integer values will start from 10
    Stuff4,     // 10
};

void change_color(Color& lightColor)
{
    lightColor = Green;
}

// even though Color has Red member this will not result in naming conflict
// becase it has a different scope and can only be accessed by using '::'
enum class SColor
{
    Red,
    Green,
    Yellow
};

// This will throw Redefinition of enumerator 'Red', as Color::Red has a global
// scope as does Color1, so this will result in a naming collision / conflict.
// enum Color1
// {
//     Red,
//     Green,
//     Yellow
// };

int main (int argc, char *argv[])
{
    Color signal { Red };

    change_color(signal);

    // if (signal == Green) {
    //     std::cout << "Go" << "\n";
    // } else if (signal == Red) {
    //     std::cout << "Stop" << "\n";
    // }

    // std::cout << signal << "\n"; // prints 1, Implicit conversion for Green

    // you can cast enum values explicitly
    int cast { static_cast<int>(signal) }; // 1

    // you can also use scope resolution operator to access enum members for
    // regular enums that are not scoped.

    Color signalYellow { Color::Yellow }; // other way to access enum member

    // you can also compare enum member with an integer

    if (signal == 0) {
        std::cout << "True" << "\n";
    }
    // or
    if (Color::Yellow == 2) {
        std::cout << "True" << "\n";
    }

    // scoped enum
    SColor Slight =  { SColor::Red };

    // This will not work, like it did above for 'signal'
    // signal is Implicitly converted to integer, but this is not the case for
    // scoped enums, becuase they are scoped, only user can access them

    // std::cout << Slight << "\n"; 

    // Instead, Convert it explicitly
    std::cout << static_cast<int>(Slight) << "\n"; // prints 0

    // if you want integer values of enum members you should Convert it
    // explicitly for every enum member..

    std::cout << static_cast<int>(SColor::Yellow) << "\n"; // prints 2

    // you cannot compare scoped enum member with integer directly for general
    // enums that aren't scoped.

    // This will not work.. 
    // if (SColor::Red == 0) {
    //     std::cout << "True" << "\n";
    // }

    // works - explicit cast

    if (static_cast<int>(SColor::Red) == 0) {
        std::cout << "True" << "\n";
    }


    // use cases for enum
    // for switch statements..

    switch (signal) {
        case Red:
            std::cout << "signal is Red" << "\n";
        break;

        case Green:
            std::cout << "signal is Green" << "\n";
        break;

        case Yellow:
            std::cout << "signal is Yellow" << "\n";
        break;
    }

    return 0;
}
