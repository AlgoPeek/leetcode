#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

// 父结点
inline int parent(int i) {
    return (i - 1) / 2;
}

// 左结点
inline int left(int i) {
    return 2 * i + 1;
}

// 右结点
inline int right(int i) {
    return 2 * i + 2;
}

// 下调：将结点i调整成最大堆O(lgn)
void heapDown(std::vector<int>& vec, int i, int n) {
    int p = i;
    int l = left(i);
    int r = right(i);
    if (l < n && vec[l] > vec[p]) {
        p = l;
    }
    if (r < n && vec[r] > vec[p]) {
        p = r;
    }
    if (p != i) {
        std::swap(vec[i], vec[p]);
        heapDown(vec, p, n);
    }
}

// 上调：建最大堆O(n)
void makeHeap(std::vector<int>& vec) {
    int n = int(vec.size());
    for (int i = (n / 2) - 1; i >= 0; i--) {
        heapDown(vec, i, n);
    }
}

// 最大堆排序
void heapSort(std::vector<int>& vec) {
    // 先对vec建堆
    makeHeap(vec);
    for (int i = int(vec.size()) - 1; i > 0; i--) {
        std::swap(vec[0], vec[i]);
        heapDown(vec, 0, i);
    }    
}

void printVector(const std::vector<int>& vec) {
    for (auto v : vec) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}

void testHeapSort() {
    std::vector<int> vec({3, 1, 4, 2, 5}); 
    std::vector<int> result({1, 2, 3, 4, 5}); 
    printVector(vec); 
    heapSort(vec);
    printVector(vec); 
    assert(vec == result);
    std::cout << "pass" << std::endl;

    printVector(vec); 
    heapSort(vec);
    printVector(vec);
    assert(vec == result);
    std::cout << "pass" << std::endl;

    vec = std::vector<int>({5, 4, 3, 2, 1});
    printVector(vec); 
    heapSort(vec);
    printVector(vec); 
    assert(vec == result);
    std::cout << "pass" << std::endl;
}

int main() {
    testHeapSort();
    return 0;
}
