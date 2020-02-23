#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

void bubbleSort(std::vector<int>& vec) {
    for (int i = int(vec.size() - 1); i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (vec[j] > vec[j+1]) {
                std::swap(vec[j], vec[j+1]);
            }
        }
    }
}

void printVector(const std::vector<int>& vec) {
    for (auto v : vec) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}

void testBubbleSort() {
    std::vector<int> vec({3, 1, 2, 4, 5});
    std::vector<int> result({1, 2, 3, 4, 5});
    printVector(vec);
    bubbleSort(vec);
    printVector(vec);
    assert(vec == result);
    std::cout << "pass" << std::endl;

    printVector(vec);
    bubbleSort(vec);
    printVector(vec);
    assert(vec == result);
    std::cout << "pass" << std::endl;

    vec = std::vector<int>({5, 4, 3, 2, 1});
    printVector(vec);
    bubbleSort(vec);
    printVector(vec);
    assert(vec == result);
    std::cout << "pass" << std::endl;
}

int main() {
    testBubbleSort();
    return 0;
}
