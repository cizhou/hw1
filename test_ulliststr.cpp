#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite
void printList (ULListStr* test, int size, std::string info); 
void createUlList (ULListStr* test, std::string* array, int arraySize);
void deleteUlList (ULListStr* test, int size); 

std::string array1[15] ={"hello", "yellow", "mellow", "fellow", "nellow"
                         "tellow", "wellow", "gellow", "kellw", "lellow"
                         "sellow", "dellow", "sellow", "xellow", "jellow"};
std::string contents[3] ={"768", "1024", "1536"};

int main(int argc, char* argv[])
{
    ULListStr* test = new ULListStr();
    createUlList(test, array1, 15);
    printList(test, 15, "array1");
    deleteUlList(test, 15); 

    // createUlList(test, contents, 5); 
    // printList(test, 5, "content"); 
}

void printList (ULListStr* test, int size, std::string info)
{
    std::cout << info << ": "; 
    for (int i = 0; i < size; i++)
    {
        std::cout << test->get(i) << " ";
    }
    std::cout << std::endl; 
}

void createUlList (ULListStr* test, std::string* array, int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        test->push_back(array[i]); 
    }
}

void deleteUlList (ULListStr* test, int size)
{
    for (int i = 0; i < size; i++)
    {
        test->pop_back(); 
    }
}