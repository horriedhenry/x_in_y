#include <iostream>
#include <string>

int main (int argc, char *argv[])
{
    // different ways to initialize a string
    // default initialization

    std::string str; // empty string

    // initialization using a c-style string using null terminator operator
    std::string c_str = "text"; // or
    std::string c_str2("text");

    // copy initialization
    std::string cp_str = "text";
    str = cp_str; // var str now has text

    // initialization with a character
    // multiple repetitions of a single character

    std::string rp_str(5, 'a'); // rp_str = aaaaa

    // range initialization
    // you can initialize a string with part of another string
    std::string str1("Hello, World");
    std::string str2(str1, 5, 8); // copy from str1 , start at index 5 with length 8
    // std::cout << str2 << "\n"; // str2 = ", World"


    // range initialization using iterators
    std::string itr_str1("Hello, World");
    std::string itr_str2(itr_str1.rbegin(), itr_str1.rend()); // reverse of itr_str1

    // std::cout << itr_str1.capacity() << "\n";
    // std::cout << itr_str1.size() << "\n";
    // std::cout << itr_str1.max_size() << "\n";

    // std::string::reserver

    std::string res_str("Hello, World"); // size is 12

    // before reserve, size, capacity

    std::cout << "before reserve" << "\n";
    std::cout << res_str.size() << "\n";
    std::cout << res_str.capacity() << "\n";

    res_str.reserve(20); // reserver 20 spots, maintain 20 as the length of string

    std::cout << "after reserve" << "\n";
    std::cout << res_str.size() << "\n";
    std::cout << res_str.capacity() << "\n";

    return 0;
}
