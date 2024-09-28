#include <iostream>
#include <vector>

template <typename T1, typename T2, typename T3>
bool is_triangle_possible(const T1 a, const T2 b, const T3 c) {
    if (a + b > c) {
        if (a + c > b) {
            if (b + c > a) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}

template <typename T1, typename T2, typename T3>
bool is_triangle_possible2(const T1 a, const T2 b, const T3 c) {
    if ((a + b > c) and (a + c > b) and (b + c > a)) {
        return true;
    }
    else {
        return false;
    }

}

int main(int argc, char const* argv[]) {
    std::vector<int> sides = {1, 6, 5};

    if (argc == 4) {
        std::cout << is_triangle_possible(std::stod(argv[1]), std::stod(argv[2]), std::stod(argv[3])) << '\n';
    }
    else {
        std::cout << is_triangle_possible(sides[0], sides[1], sides[2]) << '\n';
    }

    return 0;
}
