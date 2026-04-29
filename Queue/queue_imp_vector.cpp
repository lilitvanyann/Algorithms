#include <vector>

class Queue {
private:
    std::vector<int> arr;
    int frontIndex = 0;

public:
    void enqueue(int value) {
        arr.push_back(value);
    }

    void dequeue() {
        if (isEmpty()) return;
        frontIndex++;
    }

    int front() {
        return arr[frontIndex];
    }

    int back() {
        return arr[arr.size() - 1];
    }

    bool isEmpty() {
        return frontIndex >= arr.size();
    }

    int size() {
        return arr.size() - frontIndex;
    }
};
