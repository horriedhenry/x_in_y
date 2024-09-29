#include <iostream>
/*
 * Reference is like an alias to a varialbe or any object, this makes it easy to
 * acces the varialbe or object using it's reference rather than creating a new
 * variable. This is often used for function parameters to avoid copying.
 *
 * A reference pointes to the same memory address that it is referrying to.
 * Any changes made using the reference effects the original varialbe.
 */

std::string returnTempObj()
{
    return "tempObject";
}

void constReferenceTempObj()
{
    const std::string& constRef = returnTempObj();
    // The lifetime of temporary object returned by the function is extended and
    // it's lifetime is till the end of this scope / function.
}

void regularReference(std::string& ref)
{
    std::cout << ref << "\n";
    // the argument for this function should be defined in any scope, it will
    // not work if you pass a temporary object like this ..
    // regularReference("some value"), it should be defined atleast.

    // This will not accept a return value from a function as it's not defined
    // in any scope rather it's a temporary object that is returned and
    // destroyed.
}

void tempReference(std::string&& ref)
{
    std::cout << ref << "\n";
    // this function only accepts a temporary object as an argument i.e you can
    // only use this.. as so.. tempReference("some text") not like this
    // tempReference(someDefinedVariable)
    // or
    // this also accepts the return value of some function that returns a
    // string, as it's a temporary object.
}

int main (int argc, char *argv[])
{
    std::string foo("I am foo");
    std::string bar("I am bar");

    std::string& fooRef { foo }; // creates a reference to foo

    // you can access foo without using the dereferincing it using *, this is
    // not a pointer

    // both print "text"
    std::cout << fooRef << "\n";
    std::cout << foo << "\n";

    // use address of operator to print the address of fooRef
    // both will print same addressess
    std::cout << &fooRef << "\n";
    std::cout << &foo << "\n";

    fooRef = "other text";
    std::cout << foo << "\n"; // prints "other text"

    fooRef = bar; // now foo becomes "I am bar", fooRef still refers to foo

    std::cout << foo << "\n";

    // you can use barRef to acces but cannot modify it's contents.
    const std::string barRef { bar };

    tempReference("some text");

    return 0;
}
