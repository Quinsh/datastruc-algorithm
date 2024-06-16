#include <vector>

using namespace std;

/**
 * simple implementation just using cpp vector (a dynamic array)
 */
class StackDynamicArrayBased {
private:
    vector<int> data;
public:
    void push(int element) {
        data.push_back(element);
    }
    bool isEmpty() {
        return data.empty();
    }
    int top() {
        return data.back();
    }
    bool pop() {
        if (isEmpty()) return false;
        data.pop_back();
        return true;
    }
};