#pragma once

#include <iostream>
#include <vector>
// #include <type_traits> // was supposed to be used for checking whether vector's elements are strings to print quotes

/*
   Prints a vector with strings
 */
void print(const std::vector<std::string>& list) {
    std::cout << '{';

    for (int i = 0; i < list.size() - 1; i++) {
        std::cout << '"' << list[i] << "\", ";
    }
    std::cout << '"' << list.back() << '"';

    std::cout << "}\n";
}

/*
   Prints a vector with strings with indentation
 */
void printi(const std::vector<std::string>& list) {
    std::cout << '{' << '\n';

    for (int i = 0; i < list.size() - 1; i++) {
        std::cout << "    \"" << list[i] << '"' << ',' << '\n';
    }
    std::cout << "    \"" << list.back() << '"' << '\n';

    std::cout << "}\n";
}

/*
   Prints a vector
 */
template <typename T>
void print(const std::vector<T>& list) {
    std::cout << '{';

    for (int i = 0; i < list.size() - 1; i++) {
        std::cout << list[i] << ", ";
    }
    std::cout << list.back();

    std::cout << "}\n";
}

/*
   Prints a vector with indentation
 */
template <typename T>
void printi(const std::vector<T>& list) {
    std::cout << '{' << '\n';

    for (int i = 0; i < list.size() - 1; i++) {
        std::cout << "    " << list[i] << ',' << '\n';
    }
    std::cout << "    " << list.back() << '\n';

    std::cout << "}\n";
}

void print(bool boolean) {
    std::cout << (boolean ? "true" : "false");
}

template <typename T>
void print(T t) {
    if (typeid(t) == typeid(bool)) {
        std::cout << (t ? "true" : "false") << " ";
        return;
    }
    else {
        std::cout << t << " ";
    }
}

template<typename T, typename ... Args>
void print(T t, Args... args) {
    if (typeid(t) == typeid(bool)) {
        std::cout << (t ? "true" : "false") << " ";
    }
    else {
        std::cout << t << " ";
    }

    print(args ...);
}
