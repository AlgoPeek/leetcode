#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

// 返回分界点p, 使得vec[lo, p-1] < vec[p] <= vec[p+1, hi]
int partition(std::vector<int>& vec, int lo, int hi) {
    int i = lo - 1;
    for (int j = lo; j < hi; j++) {
        if (vec[j] < vec[hi]) {
            i++;
            std::swap(vec[i], vec[j]);
        }
    }
    std::swap(vec[i + 1], vec[hi]);
    return i + 1;
}

// 快速排序，采用分治法(divide and conquer)
void quickSortHelp(std::vector<int>& vec, int lo, int hi) {
    if (lo >= hi) {
        return;
    }

    int p = partition(vec, lo, hi);
    quickSortHelp(vec, lo, p - 1);
    quickSortHelp(vec, p + 1, hi);
}

void quickSort(std::vector<int>& vec) {
    quickSortHelp(vec, 0, int(vec.size()) - 1);
}

void printVector(const std::vector<int>& vec) {
    for (auto v : vec) {
        std::cout << v  << " ";
    }
    std::cout << std::endl;
}

void testQuickSort() {
    std::vector<int> vec({3, 1, 4, 2, 5});
    std::vector<int> result({1, 2, 3, 4, 5});
    printVector(vec);
    quickSort(vec);
    printVector(vec);
    assert(vec == result);
    std::cout << "pass" << std::endl;

    printVector(vec);
    quickSort(vec);
    printVector(vec);
    assert(vec == result);
    std::cout << "pass" << std::endl;

    vec = std::vector<int>({5, 4, 3, 2, 1});
    printVector(vec);
    quickSort(vec);
    printVector(vec);
    assert(vec == result);
    std::cout << "pass" << std::endl;
}

int main() {
    testQuickSort();
    return 0;
}

