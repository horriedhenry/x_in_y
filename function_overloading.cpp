#include <iostream>

/*

   C++ supports function overloading, provided each function takes different
   arguments.

*/

void print()
{
    std::cout << "no parameters \n";
}

void print(int number)
{
    std::cout << "one parameter of type int i.e " << number << "\n";
}

void print(char ch)
{
    std::cout << "one parameter of type char i.e " << ch << "\n";
}


// Default function arguments

// you can provide Default arguments for a function, if they are not provided by
// the caller
void add(int a = 1, int b = 2)
{
    std::cout << a + b << "\n";
}

// Default arguments should be at the end of the arguments list
// void do_something(int a = 10, int b); // throws an error

int main (int argc, char *argv[])
{
    print();
    print(10);
    print('a');


    // Default arguments
    add(); // 3
    add(10); // 12 =: a = 10, b = 2
    add(10, 10); // 20 =: a = 10, b = 10
    add(); // 20 =: a = 10, b = 10
    return 0;
}
