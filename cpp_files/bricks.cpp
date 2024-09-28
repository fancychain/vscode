#include <iostream>

void bricks(const int amount, const std::string character = "#") {
    for (size_t i = 1; i < amount * 2; i += 2) {
        for (size_t j = 1; j < amount - int(i / 2); j++)
            std::cout << ' ';

        for (size_t j = 0; j < i; j++)
            std::cout << character;

        std::cout << '\n';
    }
}

int main(int argc, char const* argv[]) {
    int amount_of_bricks;

    try {
        amount_of_bricks = std::stoi(argv[1]);
    }
    catch (const std::exception& e) {
        std::cerr << "Enter a whole positive number" << '\n';
        return 2;
    }

    if (amount_of_bricks > 1000) {
        std::cerr << "That's too many bricks! Try less than 1000" << '\n';
        return 4;
    }
    else if (argc == 1) {
        std::cerr << "You need to specify the amount of bricks you want to print using command line arguments" << '\n';
        return 1;
    }
    else if (argc == 2 and amount_of_bricks < 0) {
        std::cerr << "The amount of bricks can't be negative" << '\n';
        return 3;
    }

    bricks(amount_of_bricks);

    return 0;
}
