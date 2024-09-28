#include <iostream>
#include <vector>
#include <cmath>

// bool binary_search(const int number, const std::vector<int>& list) {
//     size_t size = list.size();

//     size_t log2_of_size = ceil(log2(size));

//     size_t left_boundary = 0;
//     size_t right_boundary = size;
//     size_t mid_index = floor(size / 2);

//     for (int i = 0; i < log2_of_size; i++) {
//         std::cout << "i is " << i << '\n';
//         if (list[mid_index] < number) {
//             std::cout << "Element is to the right of index " << mid_index << '\n';
//             left_boundary = mid_index;
//             mid_index = floor((left_boundary + right_boundary) / 2);
//         }
//         else if (list[mid_index] > number) {
//             std::cout << "Element is to the left of index " << mid_index << '\n';
//             right_boundary = mid_index;
//             mid_index = floor((left_boundary + right_boundary) / 2);
//         }
//         else {
//             std::cout << "Element is at the index " << mid_index << '\n';
//             return true;
//         }
//     }

//     std::cout << "Not found" << '\n';
//     return false;
// }

int binary_search(const std::vector<int>& list, const int number) {
    size_t size = list.size();

    if (size == 2) {
        if (list[0] == number)
            return 0;
        else if (list[1] == number)
            return 1;
        else
            return -1;
    }
    else if (size == 1) {
        if (list[0] == number)
            return 0;
        else
            return -1;
    }

    size_t log2_of_size = ceil(log2(size));

    size_t left_boundary = 0;
    size_t right_boundary = size;
    size_t mid_index = floor(size / 2);

    for (int i = 0; i < log2_of_size; i++) {
        if (list[mid_index] < number) {
            left_boundary = mid_index;
            mid_index = floor((left_boundary + right_boundary) / 2);
        }
        else if (list[mid_index] > number) {
            right_boundary = mid_index;
            mid_index = floor((left_boundary + right_boundary) / 2);
        }
        else {
            return mid_index;
        }
    }

    return -1;
}

int main(int argc, char const* argv[]) {

    // std::vector<int> list = {0, 1, 4, 5, 7, 10, 15, 29, 145, 1941, 12741, 13415, 15182, 103184};
    //                       0  1  2  3  4  5   6   7   8    9     10     11     12     13

    std::vector<int> list = {5};

    // binary_search(std::stoi(argv[1]), list);
    std::cout << binary_search(list, std::stoi(argv[1])) << '\n';

    return 0;
}
