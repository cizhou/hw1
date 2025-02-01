/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>
#include <string>


// Prints out the list for debugging
void printLinkedList(const std::string& listName, Node*& head);

// Making the linked lists for testing
Node* allocateLinkedList(int* intArray, int arraySize);
void deallocateLinkedList(Node*& head);



// Arrays for testing, these will be turned into a linkedList using allocatedLinkedList
// This is just for me to debug, looking at a list when it is in an array is far easier than having to manually create a linked list
// int array1[5] = {1, 2, 3, 4, 5};    // normal sorted array
// int array2[5] = {0, 2, 4, 6, 8};    // even sorted array 
// int array3[5] = {1, 3, 5, 7, 9};    // odd sorted array
// int array4[5] = {8, 6, 4, 2, 0};    // even unsorted array 
// int array5[5] = {9, 7, 5, 3, 1};    // odd unsorted array
// int array6[5] = {5, 1, 3, 0, -1};  // normal unsorted array
// int array7[5] = {5, 4, 3, 2, 1};    // backwards array
// int array8[5] = {1230, 1, 60, 49, -1}; 

void runtest(int* intArray, int arraySize, std::string message)
{
    Node* unsorted = allocateLinkedList(intArray, arraySize); 
    printLinkedList(message, unsorted); 
    Node* odds = nullptr; 
    Node* evens = nullptr; 
    
    split(unsorted, odds, evens); 
    printLinkedList("odds", odds); 
    printLinkedList("evens", evens); 

    deallocateLinkedList(odds);
    deallocateLinkedList(evens); 

    std::cout << std::endl; 
}

int main(int argc, char* argv[])
{
    // running my own tests
    // runtest(array1, 5, "sorted 1-5");
    // runtest(array2, 5, "sorted even");
    // runtest(array3, 5, "sorted odd");
    // runtest(array6, 5, "random 5 numbers");
    
    return 0;
}



// Helper functions for debugging


void printLinkedList(const std::string& listName, Node*& head)
{
    std::cout << listName << ": ";

    if (head == nullptr)
    {
        return; 
    }

    Node* current = head; 

    while (current != nullptr)
    {
        std::cout << current->value << " "; 
        current = current->next; 
    }
    std::cout << std::endl; 
}

Node* allocateLinkedList(int* intArray, int arraySize)
{
    if (arraySize == 0)
        return NULL; 

    Node* head = new Node(intArray[0], nullptr);
    Node* current = head;

    for (int i = 1; i < arraySize; ++i) {
        current->next = new Node(intArray[i], nullptr);
        current = current->next;
    }

    return head;
}

void deallocateLinkedList(Node*& head)
{
    while (head != nullptr)   
    {
        Node* temp = head; 
        head = head->next; 
        delete temp;
    } 
    head = nullptr;
}