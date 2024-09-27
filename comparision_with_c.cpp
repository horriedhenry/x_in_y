#include <iostream>

int main (int argc, char *argv[])
{
    // command line arguments are passed in the same way as c
    // argc indicates number of arguments
    // argv is an array of c-style strings (char*)

    // in C++ char literals are character, therefore the size is 1
    // the statement below evaluates to True in c++, but not in c
    // sizeof('c') == sizeof(char) 

    // in C character literals are integers, therefore the size is 4
    // the statement below evaluates to True in c, but not in c++
    //  sizeof('c') == sizeof(int) 


    if (sizeof('c') == sizeof(char)) {
        std::cout << "True" << std::endl;
    } else {
        std::cout << "False" << std::endl;
    }

    // the above statement prints false

    std::cout << "sizeof char 'c' : " << sizeof('c') << std::endl;  // prints 1
    std::cout << "sizeof char     : " << sizeof(char) << std::endl; // prints 1

    if ('c' == 99) {
        std::cout << "Equal" << std::endl;
    }

    // implicit type conversion by the compiler either converts integer value 9
    // to it's associated ascii value or converts int to it's associated ascii
    // character

    // ---

    // C++ has strict prototyping
    // void func(); // function which accepts no arguments
    // void func(void); // same as above

    // in C
    // void func(); // function which may accept any number of arguments with
    // unknown type
    // void func(void); // function that does no accept any arguments


    // use nullptr instead of NULL in C++
    int *ptr = nullptr;

    // in C++, standard c headers are available and are prefixed with c
    // #include <cstdio> and we don't need to use .h at the end

    return 0;
}
