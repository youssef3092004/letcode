#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

template <class T>
class Stack {
    int top;
    T arr[MAX_SIZE];

public:
    Stack() {
        top = -1;
    }

    void push(T element) {
        if (top >= MAX_SIZE - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }
        top++;
        arr[top] = element;
    }

    bool isEmpty() {
        return top == -1;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return;
        }
        top--;
    }

    void pop(T &element) {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return;
        } else {
            element = arr[top];
            top--;
        }
    }

    void get_top(T &element) {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return;
        } else {
            element = arr[top];
        }
    }

    void print() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        } else {
            cout << "[";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << "]" << endl;
        }
    }
};

int main() {
    Stack<char> s;
    char element;

    s.push('A');
    s.push('B');
    s.push('C');
    s.pop(element);
    cout << "Popped element: " << element << endl;
    s.get_top(element);
    cout << "Top element: " << element << endl;
    s.print();
    return 0;
}
