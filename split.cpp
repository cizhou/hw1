/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
  // WRITE YOUR CODE HERE
  // main function goes through the linked list

  if (in != nullptr)
  {
    Node* temp = nullptr; 
    Node* next = in->next; 
    if (in->value % 2 == 0)           // is even
    {
      splitHelper(in, evens, temp); 
    } else if (in->value % 2 == 1 || in->value % 2 == -1)    // is odd
    {
      splitHelper(in, odds, temp); 
    }
    split(next, odds, evens);
  }
  in = nullptr;

}

void splitHelper(Node*& newNode, Node*& head, Node*& prev)
{
  if (head == nullptr && prev == nullptr)               // head is currently empty
  {
    head = newNode;
    head->next = nullptr;
  } else if (head == nullptr && prev != nullptr)        // newNode goes to the end
  {
    prev->next = newNode; 
    newNode->next = nullptr;
  } 
  else if (newNode->value <= head->value)
  {
    if(prev == nullptr)                                // add to front 
    {
      Node* temp = head; 
      newNode->next = temp;
      head = newNode; 
    } else                                             // add to middle
    {
      newNode->next = head; 
      prev->next = newNode; 
    }
  } else
  {
    splitHelper(newNode, head->next, head); 
  }
}