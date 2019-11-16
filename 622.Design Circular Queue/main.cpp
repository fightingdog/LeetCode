//
//  main.cpp
//  Design Circular Queue
//
//  Created by 刘昭 on 2019/11/16.
//  Copyright © 2019 刘昭. All rights reserved.
//

#include <iostream>

using namespace std;

class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        a = new int [k + 1];
        size = k;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        a[back] = value;
        back = (back + 1) % (size + 1);
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        front = (front + 1) % (size + 1);
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return a[front];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        int index = (back - 1 + size + 1) % (size + 1);
        return a[index];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return front == back;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        if ((back + 1) % (size + 1) == front) {
            return true;
        }
        return false;
    }
private:
    int *a;
    int front = 0;
    int back = 0;
    int size = 0;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

int main(int argc, const char * argv[]) {
    MyCircularQueue circularQueue = MyCircularQueue(3); // set the size to be 3
    cout << circularQueue.enQueue(1) << endl;  // return true
    cout << circularQueue.enQueue(2) << endl;  // return true
    cout << circularQueue.enQueue(3) << endl;  // return true
    cout << circularQueue.enQueue(4) << endl;  // return false, the queue is full
    cout << circularQueue.Rear() << endl;  // return 3
    cout << circularQueue.isFull() << endl;  // return true
    cout << circularQueue.deQueue() << endl;  // return true
    cout << circularQueue.enQueue(4) << endl;  // return true
    cout << circularQueue.Rear() << endl;  // return 4

    return 0;
}
