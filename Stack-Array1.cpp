#include <iostream>
using namespace std;

#define MAX_SIZE 100

struct Stack {
    int arr[MAX_SIZE];
    int top;

    Stack() {
        top = -1; // Initialize top to -1
    }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == MAX_SIZE - 1);
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow: Cannot push " << value << ", the stack is full.\n";
            return;
        }
        arr[++top] = value;
        cout << "Pushed " << value << " into the stack.\n";
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow: Cannot pop, the stack is empty.\n";
            return;
        }
        cout << "Popped " << arr[top--] << " from the stack.\n";
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack stack;

    char choice;
    int value;

    do {
        cout << "\nChoose an operation:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Display Stack\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                cout << "Enter the value to push: ";
                cin >> value;
                stack.push(value);
                break;
            case '2':
                stack.pop();
                break;
            case '3':
                stack.display();
                break;
            case '4':
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != '4');

    return 0;
}

