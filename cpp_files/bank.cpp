#include <iostream>
#include <fstream>
#include <cstring>
#include <regex>

int main(int argc, char const* argv[]) {
    const char* deposit = "deposit";
    const char* withdraw = "withdraw";
    const char* balance = "balance";

    std::string filename = "bank.txt";

    if (argc >= 3 and std::regex_search(argv[2], std::regex ("\\D"))) {
        std::cout << "Incorrect arguments" << '\n';
        return 1;
    }

    std::fstream file_read;
    std::fstream file_write;
    std::string line;
    file_read.open(filename, std::ios::in);


    std::getline(file_read, line);

    if (argc == 1 or argc == 2) {
        if (argc == 2 and std::strcmp(argv[1], balance) == 0) {
            std::cout << "Your balance:\t$" << line << '\n';
            return 0;
        }

        std::cout << "Arguments:\n"
                     "1. deposit / withdraw / balance\n"
                     "2. amount of money\n";
    }
    else if (argc == 3) {

        if (std::strcmp(argv[1], deposit) == 0) {
            file_write.open(filename, std::ios::out);
            file_write << std::stoi(line) + std::stoi(argv[2]);
            std::cout << "Your balance before:\t$" << line << '\n';
            std::cout << "Your balace now:\t$" << std::stoi(line) + std::stoi(argv[2]) << '\n';
        }
        else if (std::strcmp(argv[1], withdraw) == 0) {
            file_write.open(filename, std::ios::out);
            file_write << std::stoi(line) - std::stoi(argv[2]);
            std::cout << "Your balance before:\t$" << line << '\n';
            std::cout << "Your balace now:\t$" << std::stoi(line) - std::stoi(argv[2]) << '\n';
        }
        else {
            std::cout << "Incorrect arguments" << '\n';
        }
    }
    else {
        std::cout << "Too many arguments" << '\n';
    }


















    file_read.close();
    file_write.close();

    return 0;
}
