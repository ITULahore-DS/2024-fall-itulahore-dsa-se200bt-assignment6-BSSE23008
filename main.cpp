#include "functions.h"


// Stack ADT
void stackMenu(Stack& stack) {
    int choice, value;
    do {
        cout << "\n\n\t******************* Stack Menu *******************" << endl;
        cout << "\t 1. Push" << endl;
        cout << "\t 2. Pop" << endl;
        cout << "\t 3. Peek" << endl;
        cout << "\t 4. Check if empty" << endl;
        cout << "\t 5. Get size" << endl;
        cout << "\t 6. Print stack" << endl;
        cout << "\t 7. Clear stack" << endl;
        cout << "\t 0. Back to main menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                stack.push(value);
                cout << "Pushed " << value << " to the stack." << endl;
                break;
            case 2:
                if (!stack.isEmpty()) {
                    stack.pop();
                    cout << "Popped top element from the stack." << endl;
                } else {
                    cout << "Stack is empty." << endl;
                }
                break;
            case 3:
                if (!stack.isEmpty()) {
                    cout << "Top element: " << stack.peek() << endl;
                } else {
                    cout << "Stack is empty." << endl;
                }
                break;
            case 4:
                cout << (stack.isEmpty() ? "Stack is empty." : "Stack is not empty.") << endl;
                break;
            case 5:
                cout << "Stack size: " << stack.size() << endl;
                break;
            case 6:
                cout << "Stack contents: ";
                stack.printStack();
                break;
            case 7:
                stack.clear();
                cout << "Stack cleared." << endl;
                break;
            case 0:
                cout << "Returning to main menu." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);
}


// Queue ADT 
void queueMenu(Queue& queue) {
    int choice, value;
    do {
        cout << "\n\n\t******************* Queue Menu *******************\n" << endl;
        cout << "\t 1. Enqueue" << endl;
        cout << "\t 2. Dequeue" << endl;
        cout << "\t 3. Check if empty" << endl;
        cout << "\t 4. Get size" << endl;
        cout << "\t 5. Print queue" << endl;
        cout << "\t 0. Back to main menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                queue.enqueue(value);
                cout << "Enqueued " << value << " to the queue." << endl;
                break;
            case 2:
                if (!queue.isEmpty()) {
                    queue.dequeue();
                    cout << "Dequeued front element from the queue." << endl;
                } else {
                    cout << "Queue is empty." << endl;
                }
                break;
            case 3:
                cout << (queue.isEmpty() ? "Queue is empty." : "Queue is not empty.") << endl;
                break;
            case 4:
                cout << "Queue size: " << queue.size() << endl;
                break;
            case 5:
                cout << "Queue contents: ";
                queue.printQueue();
                break;
            case 0:
                cout << "Returning to main menu." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);
}

// Main menu
int main() {
    Stack stack;
    Queue queue;
    int choice;

    do {
        cout << "\n\t\t============ << ASSIGNMENT 06 >> ============\n" << endl;
        cout << "\t 1. Stack Operations" << endl;
        cout << "\t 2. Queue Operations" << endl;
        cout << "\t 0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                stackMenu(stack);
                break;
            case 2:
                queueMenu(queue);
                break;
            case 0:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}