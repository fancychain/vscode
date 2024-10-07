#pragma once

#include <string>

/* Returns string in upper case */
std::string upper(std::string str) {
    for (char& ch : str) {
        ch = toupper(ch);
    }
    return str;
}

/* Returns string in lower case */
std::string lower(std::string str) {
    for (char& ch : str) {
        ch = tolower(ch);
    }
    return str;
}

/* Returns repeated <how_many_times> times string */
std::string repeat(const std::string& str, const unsigned int how_many_times) {
    std::string repeated_str = "";

    for (int i = 0; i < how_many_times; i++) {
        repeated_str += str;
    }

    return repeated_str;
}

/* Returns repeated <how_many_times> times string */
std::string repeat(const char character, const unsigned int how_many_times) {
    std::string repeated_str = "";

    for (int i = 0; i < how_many_times; i++) {
        repeated_str += character;
    }

    return repeated_str;
}

/* Returns reversed string */
std::string reverse(const std::string& str) {
    std::string reversed_str = "";

    for (int i = str.size() - 1; i >= 0; i--) {
        reversed_str += str[i];
    }

    return reversed_str;
}
