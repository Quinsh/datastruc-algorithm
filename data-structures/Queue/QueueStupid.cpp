
#include <iostream>
#include <vector>

using namespace std;

// memory is wasted when we remove elements from the front of the queue
// lol
// credit: from LeetCode Queue-Implementation chapter
class QueueStupid {
    private:
        vector<int> data;
        int p_start;
    public:
        QueueStupid() {
            p_start = 0;
        }

        bool enQueue(int x) {
            data.push_back(x);
            return true;
        }

        int deQueue() {
            if (isEmpty()) return NULL;
            else {
                int ret = data[p_start++];
                return ret;
            }
        }
        
        bool isEmpty() {
            return p_start >= data.size();
        }
        
        int peek() {
            return data[p_start];
        }
};