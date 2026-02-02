#include <iostream>

class myQueue {
private:
    int *arr;      // array to store elements
    int capacity;  // max size
    int size;      // current number of elements

    
public:
    // Constructor
    myQueue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        size = 0;
    }

    // Check empty
    bool isEmpty() {
        return size == 0;
    }

    // Check full
    bool isFull() {
        return size == capacity;
    }

    // Enqueue
    void enqueue(int x) {
        if (isFull()) {
            std::cout << "Queue is full!\n";
            return;
        }
        arr[size] = x;
        size++;
    }

    // Dequeue
    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty!\n";
            return;
        }
        for (int i = 1; i < size; i++) {
            arr[i - 1] = arr[i];
        }
        size--;
    }

    // Get front element
    int getFront() {
        if (isEmpty()) {
            std::cout << "Queue is empty!\n";
            return -1;
        }
        return arr[0];
    }

    // Get rear element
    int getRear() {
        if (isEmpty()) {
            std::cout << "Queue is empty!\n";
            return -1;
        }
        return arr[size - 1];
    }
};



// Driver code
int main() {
    myQueue q(3);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    std::cout << "Front: " << q.getFront() << "\n";
    


    q.dequeue();
    std::cout << "Front: " << q.getFront() << "\n";
    std::cout << "Rear: " << q.getRear() << "\n";

    q.enqueue(40);

    return 0;
}
