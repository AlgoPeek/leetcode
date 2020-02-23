#include <iostream>
#include <vector>
#include <cassert>

// 将两个已序数组排序[lo, mid], [mid+1, hi]合并
void merge(std::vector<int>& vec, int lo, int hi, int mid) {
    // 创建两个临时数据，分别存储[lo, mid]和[mid+1, hi]
    std::vector<int> lvec(vec.begin() + lo, vec.begin() + mid + 1);
    std::vector<int> rvec(vec.begin() + mid + 1, vec.begin() + hi + 1);

    // 为实现方便，设置了一个哨兵
    lvec.push_back(INT_MAX);
    rvec.push_back(INT_MAX);
    for (int i = 0, j = 0, k = lo; k <= hi; k++) {
        if (lvec[i] < rvec[j]) {
            vec[k] = lvec[i];
            i++;
        } else {
            vec[k] = rvec[j];
            j++;
        }
    }
}

// 归并排序，采用分治法(divide and conquer), 然后对结束进行合并
void mergeSortHelp(std::vector<int>& vec, int lo, int hi) {
    if (lo >= hi) {
        // conquer: 数组中只有一个, 显然已序
        return;
    }

    // divide: 数据中大于一个元素时，分成左右两部分
    int mid = (lo + hi) / 2;
    
    // 对左边部分进行归并排序
    mergeSortHelp(vec, lo, mid);
    // 对右边部分进行归并排序
    mergeSortHelp(vec, mid + 1, hi);
    // 将左右两个已序部分进行合并
    merge(vec, lo, hi, mid);
}

void mergeSort(std::vector<int>& vec) {
    mergeSortHelp(vec, 0, int(vec.size()) - 1);
}

void printVector(const std::vector<int>& vec) {
    for (auto v : vec) {
        std::cout << v  << " ";
    }
    std::cout << std::endl;
}

void testMergeSort() {
    std::vector<int> vec({3, 1, 2, 4, 5});
    std::vector<int> result({1, 2, 3, 4, 5});
    printVector(vec);
    mergeSort(vec);
    printVector(vec);
    assert(vec == result);
    std::cout << "pass" << std::endl;

    printVector(vec);
    mergeSort(vec);
    printVector(vec);
    assert(vec == result);
    std::cout << "pass" << std::endl;

    vec = std::vector<int>({5, 4, 3, 2, 1});
    printVector(vec);
    mergeSort(vec);
    printVector(vec);
    assert(vec == result);
    std::cout << "pass" << std::endl;
}

int main() {
    testMergeSort();
    return 0;
}
