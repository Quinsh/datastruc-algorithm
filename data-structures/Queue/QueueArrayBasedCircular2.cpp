
#include <iostream>
#include <vector>

using namespace std;

/**
 * Array Based Circular Queue. 
 * This implementation only uses `capacity` field.
 */
class QueueArrayBasedCircular2 {

private:
    vector<int> list;
    int frontIndex;
    int endIndex;
    int capacity;

public:
    QueueArrayBasedCircular2(int k) {
        list.resize(k);
        capacity = k;
        frontIndex = -1;
        endIndex = -1;
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        
        if (isEmpty()) {
            frontIndex = 0;
        }

        endIndex = (endIndex+1) % capacity;
        list[endIndex] = value;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        if (frontIndex == endIndex) {
            frontIndex = endIndex = -1;
            return true;
        }
        
        frontIndex = (frontIndex + 1) % capacity;
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
        return frontIndex == -1;
    }
    
    bool isFull() {
        return (endIndex+1) % capacity == frontIndex;
    }
};
