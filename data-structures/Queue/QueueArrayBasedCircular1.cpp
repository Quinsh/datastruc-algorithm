
#include <iostream>
#include <vector>

using namespace std;

/**
 * Array Based Circular Queue. 
 * This implementation uses `size` and `capacity` fields, which facilitate the logic.
 */
class QueueArrayBasedCircular1 {

private:
    vector<int> list;
    int frontIndex;
    int endIndex;
    int capacity;
    int size;

public:
    QueueArrayBasedCircular1(int k) {
        list.resize(k);
        capacity = k;
        size = 0;
        frontIndex = -1;
        endIndex = -1;
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        
        endIndex = (endIndex+1) % capacity;
        list[endIndex] = value;
        size++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        
        frontIndex = (frontIndex + 1) % capacity;
        size--;
        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        
        return list[frontIndex];
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        
        return list[endIndex];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size==capacity;
    }
};
