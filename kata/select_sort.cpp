// 选择排序
// 对于数组A，每一轮选择一个最大的元素将其和最右边的元素交换
// 直到所有元素都被选择出来

#include <iostream>
#include <vector>
#include <cassert>

void selectSort(std::vector<int>& vec) {
    for (int i = int(vec.size()) - 1; i > 0; i--) {
        int max = 0;
        for (int j = 1; j <= i; j++) {
            if (vec[j] > vec[max]) {
                max = j;
            }
        }
        std::swap(vec[max], vec[i]);
    }
}

void printVector(const std::vector<int>& vec) {
    for (auto v : vec) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}

void testSelectSort() {
    std::vector<int> vec({3, 1, 2, 4, 5});
    std::vector<int> result({1, 2, 3, 4, 5});
    printVector(vec);
    selectSort(vec);
    printVector(vec);
    assert(vec == result);
    std::cout << "pass" << std::endl;

    printVector(vec);
    selectSort(vec);
    printVector(vec);
    assert(vec == result);
    std::cout << "pass" << std::endl;

    vec = std::vector<int>({5, 4, 3, 2, 1});
    printVector(vec);
    selectSort(vec);
    printVector(vec);
    assert(vec == result);
    std::cout << "pass" << std::endl;
}

int main() {
    testSelectSort();
    return 0;
}
