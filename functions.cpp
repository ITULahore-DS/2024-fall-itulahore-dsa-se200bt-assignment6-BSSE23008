#include "functions.h"

// Default Constructor
Node :: Node() : data(0), next {nullptr} { 

}


// Overloaded Constructor 
Node :: Node (int d) : data (d), next (nullptr) { 

} 


// Default Constructor
Node :: ~Node() { 

}


// Set the data
void Node :: setData(int data) {
    this->data = data; 
}


// Get the data
int Node :: getData() const { 
    return data; 
}


// Setting the next Node
void Node :: setNext(Node* val) { 
    this->next = val; 
}


// getting the next node 
Node* Node :: getNext() const { 
    return next;
}



void Node :: display () const { 

    std::cout << "\nData: " << this->data << ", Next: " << this->next << std::endl;

}



// List Class Implementation
// Default Constructor 
List :: List () : head (nullptr), tail (nullptr), count(0) { 
    std::cout << "\nList constructor called\n"; 
}


// Destructor 
List :: ~List () { 
    if (head) { 
        Node* temp = head; 
        while (temp) { 
            head = head->getNext();
            delete temp; 
            temp = head; 
        }
    }
    std::cout << "\nList destructor called\n"; 
}


// returns the size of the list
int List :: getSize () const { 
    return count; 
}



// Empty check
bool  List :: isEmpty () const { 
    if (!head) { 
        return true; 
    }
    return false; 
}


// Head node 
Node* List :: getHead () const { 
    return head; 
}



// Tail node
Node* List ::  getTail () const { 
    return tail; 
}


// Prints the whole list 
void List :: printList () const { 
    Node* temp = head; 
    // std::cout << "\nHead data: " << head->getData() << std::endl; 
    std::cout << "\n----------------------------------\n"; 
    while (temp) {
        temp->display (); 
        temp = temp->getNext();    
    std::cout << "\n----------------------------------\n"; 
    }
}


// Delete all the nodes (free memory)
void List :: clear () { 
    while (!isEmpty()) { 
        deleteFromStart(); 
    }
}


// Append a new element at the end of the list 
void List :: append(int data) {
    Node* newNode = new Node(data);
    
    if (isEmpty()) {
        // If the list is empty, the new node becomes both head and tail
        head = newNode;
        tail = newNode;
    } else {
        // Otherwise, add the new node after the current tail
        tail->setNext(newNode);
        tail = newNode;
    }
    
    // Increment the count of nodes in the list
    count++;
}



// Add a new element at the start of the List 
void List :: prepend(int data) {
    Node* newNode = new Node(data);
    
    if (!head) { 
        // If the list is empty
        head = newNode;
        tail = newNode;
    } else {
        // If the list is not empty
        newNode->setNext(head);
        head = newNode;
    }
    
    ++count;
}



void List :: insertAtIndex(int data, int index) {
    if (index < 0 || index > count) {
        // Invalid index
        return;
    }

    if (index == 0) {
        // Inserting at start
        prepend(data);
        return;
    }

    if (index == count) {
        // Inserting at end
        append(data);
        return;
    }

    // Inserting in middle
    Node* newNode = new Node(data);
    Node* current = head;
    for (int i = 0; i < index - 1; i++) {
        current = current->getNext();
    }

    newNode->setNext(current->getNext());
    current->setNext(newNode);

    count++;
}



void List :: deleteFromIndex(int index) {
    if (isEmpty() || index < 0 || index >= count) {
        // Invalid index or empty list
        return;
    }

    if (index == 0) {
        // Deleting from start
        deleteFromStart();
        return;
    }

    if (index == count - 1) {
        // Deleting from end
        deleteFromEnd();
        return;
    }

    // Deleting from middle
    Node* current = head;
    for (int i = 0; i < index - 1; i++) {
        current = current->getNext();
    }

    Node* toDelete = current->getNext();
    current->setNext(toDelete->getNext());
    delete toDelete;

    count--;
}




void List :: deleteFromStart() {

    if (isEmpty()) {
        throw std::underflow_error("Stack underflow: Cannot pop from an empty stack");
    }

    Node* temp = head;
    head = head->getNext();
    delete temp;

    count--;

    if (head == nullptr) {
        // If the list becomes empty after deletion, update tail
        tail = nullptr;
    }
}



void List :: deleteFromEnd() {
    if (isEmpty()) {
        // If the list is empty, there's nothing to delete
        return;
    }

    if (head == tail) {
        // If there's only one node in the list
        delete head;
        head = tail = nullptr;
    } else {
        // Find the second-to-last node
        Node* current = head;
        while (current->getNext() != tail) {
            current = current->getNext();
        }

        delete tail;
        tail = current;
        tail->setNext(nullptr);
    }
    count--;
} 



// Stack Implementation using linked list
// LIFO

// returns the current size of the stack 
int Stack :: size () const { 
    return list.getSize(); 
}


// Is the list empty?
bool Stack :: isEmpty () const { 
    return list.isEmpty(); 
} 


// Push at front of list
void Stack :: push (int data) { 
    this->list.prepend (data); 
}


// Pop from front
void Stack :: pop () { 
    try { 
        this->list.deleteFromStart(); 
    } catch (const std::underflow_error& ex) { 
        std::cerr << ex.what(); 
    }
}


// Returns the element at top
int Stack :: peek() const {
    if (isEmpty()) { 
        std::cout << "Stack is empty: "; 
        return -1; 
    }
    return list.getHead()->getData(); 
}


// Clear the stack completely
void Stack :: clear () {
    if (isEmpty()) { 
        // If already empty, then return
        return; 
    }    
    list.clear(); 
}


// Print the whole stack
void Stack :: printStack () const { 
    this->list.printList(); 
}




// Queue Implementation using linked list 
// FIFO 

bool Queue ::  isEmpty() const { 
    return list.isEmpty(); 
}


int  Queue :: size () const { 
    return list.getSize(); 
}


// Append data at the end
void Queue ::  enqueue (int data) {
    this->list.append(data); 
}


// Removes data from the front
void Queue ::  dequeue () { 
    if (isEmpty()) {
        std:: cerr << "\nCannot dequeue from an empty queue" << std::endl; 
        return; 
    }
    this->list.deleteFromStart(); 
}


// Print the entire queue
void Queue ::  printQueue () const { 
    this->list.printList(); 
}



