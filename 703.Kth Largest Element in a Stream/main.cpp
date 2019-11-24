//
//  main.cpp
//  Kth Largest Element in a Stream
//
//  Created by 刘昭 on 2019/11/24.
//  Copyright © 2019 刘昭. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

#define LEFT(i) (((i) << 1) + 1)
#define RIGHT(i) (((i) << 1) + 2)
#define PARENT(i) (((i) - 1) >> 1)

// 构建大根堆
bool myLess(int lhs, int rhs) {
    return lhs < rhs;
}

// 构建小根堆
bool myGreater(int lhs, int rhs) {
    return lhs > rhs;
}

typedef bool (*Comp)(int, int);

static inline void swap(int& lhs, int& rhs) {
    int temp = lhs;
    lhs = rhs;
    rhs = temp;
}

void Heapify(int a[], int len, int index, Comp comp) {
    if (a == nullptr || index >= len || index < 0 || comp == nullptr) {
        return;
    }
    // 递归
//    int left = LEFT(index);
//    int right = RIGHT(index);
//    int maxIndex = index;
//    if (left < len && comp(a[maxIndex], a[left])) {
//        maxIndex = left;
//    }
//    if (right < len && comp(a[maxIndex], a[right])) {
//        maxIndex = right;
//    }
//    if (index == maxIndex) {
//        return;
//    }
//    swap(a[maxIndex], a[index]);
//    Heapify(a, len, maxIndex, comp);
    
    // 非递归
    int child = 2 * index + 1;
    int maxIndex = index;
    while (maxIndex < len / 2) {
        if (child + 1 < len && comp(a[child], a[child + 1])) {
            child += 1;
        }
        if (comp(a[maxIndex], a[child])) {
            swap(a[maxIndex], a[child]);
            maxIndex = child;
            child = 2 * child + 1;
        } else {
            break;
        }
    }
}

void BuildHeap(int a[], int len, Comp comp) {
    if (a == nullptr || len <= 1 || comp == nullptr) {
        return;
    }
    for (int i = len / 2; i >= 0; i--) {
        Heapify(a, len, i, comp);
    }
}

void HeapSort(int a[], int len, Comp comp) {
    if (a == nullptr || len <= 1 || comp == nullptr) {
        return;
    }
    BuildHeap(a, len, comp);
    for (int i = len-1; i > 0; i--) {
        swap(a[0], a[i]);
        Heapify(a, i-1, 0, comp);
    }
}

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        queSize = k;
        for (int i : nums) {
            que.push(i);
            if (que.size() > queSize) {
                que.pop();
            }
        }
    }
    
    int add(int val) {
        que.push(val);
        if (que.size() > queSize) {
            que.pop();
        }
        return que.top();
    }
    
private:
    priority_queue<int, vector<int>, greater<int>> que;
    int queSize;
};

// 打印数组函数
void PrintArray(int array[], int nLength_)
{
    if (nullptr == array || nLength_ <= 0)
        return;

    for (int i = 0; i < nLength_; ++i)
    {
        std::cout << array[i] << " ";
    }

    std::cout << std::endl;
}
    
int main(int argc, const char * argv[]) {
//    int k = 3;
//    vector<int> nums = {4, 5, 8, 2};
//    KthLargest* so = new KthLargest(k, nums);
//    cout << so->add(3) << endl;
//    cout << so->add(5) << endl;
//    cout << so->add(10) << endl;
//    cout << so->add(9) << endl;
//    cout << so->add(4) << endl;
    
    int array[10] = { 100, 1, 1, -1243, 0, 223, 443, 123, -12, -129};
    
    PrintArray(array, 10);
    HeapSort(array, 10, myLess);
    PrintArray(array, 10);
    
    return 0;
}
