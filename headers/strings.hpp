#pragma once

#include <string>

/*
   Returns string in upper case
 */
std::string upper(std::string str) {
    for (char& ch : str) {
        ch = toupper(ch);
    }
    return str;
}

/*
   Returns string in lower case
 */
std::string lower(std::string str) {
    for (char& ch : str) {
        ch = tolower(ch);
    }
    return str;
}