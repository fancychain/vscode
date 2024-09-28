#include <iostream>
#include <regex>
#include <vector>

#include "headers/strings.hpp"
#include "headers/printing.hpp"

int main(int argc, const char* argv[]) {
    std::vector<std::string> words;

    // std::regex pattern ("(?:((?:[\\w']|[\\w'-]{3,})+)|([\\w']+)(?=[^\\w]+)|([\\w'])(?=[^\\w]))");
    std::regex pattern ("\\b([a-zA-Z'\\-]+)\\b");
    std::smatch groups;

    std::string str = "";
    if (argc == 1) {
        str = "This is a sentence, it's pretty cool";
    }
    else {
        for (int i = 1; i < argc; i++) {
            str += argv[i] + std::string(" ");
        }
    }

    auto str_begin = std::sregex_iterator(str.begin(), str.end(), pattern);
    auto str_end = std::sregex_iterator();

    for (std::sregex_iterator i = str_begin; i != str_end; i++) {
        std::smatch groups = *i;
        words.push_back(lower(groups.str(1)));
    }

    printi(words);

    return 0;
}
