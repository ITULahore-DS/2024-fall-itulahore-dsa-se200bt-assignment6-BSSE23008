#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream> 
#include <string> 
#include <stdexcept> 
#include <limits> 

using std::cout; 
using std::endl; 
using std::cin; 


// Node class: represents a single node
class Node { 
public: 
    Node (); 
    Node (int = 0); 
    ~Node (); 
    void setData (int); 
    int getData () const; 
    void setNext (Node*); 
    Node* getNext () const; 
    void display () const; 

private: 
    int data; 
    Node* next; 
};



// List class : manages the list of nodes
class List { 
public: 
    List (); 
    ~List ();
    int getSize () const; 
    bool isEmpty () const; 
    Node* getHead () const; 
    Node* getTail () const;

    void clear();
    void append(int data); 
    void prepend(int data); 
    void insertAtIndex(int data, int index);
    void deleteFromEnd();
    void deleteFromStart();
    void deleteFromIndex(int index);
    void printList () const; 

private: 
    Node* head; 
    Node* tail; 
    int count; 
}; 



// Stack class: maintains the linked list of node objects
// LIFO
class Stack { 
public: 
   
   // Constructor & destructor is not needed.
   // The compiler will automatically call the constructor of List, when stack is constructed.

    int size () const;
    bool isEmpty () const; 
    void push (int data); 
    void pop (); 
    int peek () const; 
    void clear (); 
    void printStack () const;  

private: 
    List list;
}; 



// Queue class: maintains the linked list of node objects 
// FIFO
class Queue { 
public: 

    // Constructor & destructor is not needed.
    // The compiler will automatically call the constructor of List, when queue is constructed.

    bool isEmpty() const; 
    int size () const;
    void enqueue (int data); 
    void dequeue (); 
    void printQueue () const; 

private: 
    List list; 
}; 

#endif // FUNCTIONS_H
