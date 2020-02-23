#include <iostream>
#include <vector>
#include <cassert>

// 插入排序
void insertSort(std::vector<int>& vec) {
    for (int i = 1; i < vec.size(); i++) {
        int j = i;
        int curr = vec[i];
        while (j > 0 && curr < vec[j - 1]) {
            vec[j] = vec[j-1];
            j--;
        }
        vec[j] = curr;
    }
}

void printVector(const std::vector<int>& vec) {
    for (auto v : vec) {
        std::cout << v << " ";
    }
    std::cout << std::endl; 
}

void testInsertSort() {
    std::vector<int> vec({3, 1, 2, 4, 5});
    std::vector<int> result({1, 2, 3, 4, 5});
    printVector(vec);
    insertSort(vec); 
    printVector(vec);
    assert(vec == result);
    std::cout << "pass" << std::endl;

    printVector(vec);
    insertSort(vec); 
    printVector(vec);
    assert(vec == result);
    std::cout << "pass" << std::endl;

    vec = std::vector<int>({5, 4, 3, 2, 1});
    printVector(vec);
    insertSort(vec); 
    printVector(vec);
    assert(vec == result);
    std::cout << "pass" << std::endl;
}

int main() {
    testInsertSort();
    return 0;
}
