#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
#include <iostream>

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

// INSTRUCTIONS
// You need to examine the code provided in ulliststr.h and ulliststr.cpp and add the implementations for 
// push_back, push_front 
// pop_back, pop_front, 
// back, front
// getValAtLoc

void ULListStr::push_back(const std::string& val) 
{
  //std::cout << "add back: " << val << std::endl;
	if(tail_ == nullptr) {                // empty list
		Item *newItem = new Item();
		newItem->val[0] = val;
		newItem->first = 0;
		newItem->last = 1;
    newItem->next = nullptr;
    newItem->prev = nullptr;

		head_ = newItem;
		tail_ = newItem;
		size_++;
	}
	else if (tail_->last != 10) {         // there is room 
		tail_->val[tail_->last] = val; 
		tail_->last++;
		size_++;
	}
	else {                                // there is no room, make a new item
		size_++;
		Item *newItem = new Item();
		newItem->val[0] = val;
		newItem->first = 0;
		newItem->last = 1;
    newItem->next = nullptr;
		newItem->prev = tail_;

		tail_->next = newItem;
		tail_ = newItem;
	}
}

void ULListStr::push_front(const std::string& val) 
{
  //std::cout << "add front: " << val << std::endl;
	if(head_ == nullptr) {                // empty list
		Item *newItem = new Item();
		newItem->val[9] = val;
		newItem->first = 9;
		newItem->last = 10;
    newItem->next = nullptr;
    newItem->prev = nullptr;

		head_ = newItem;
		tail_ = newItem;
		size_++;
	}
	else if (head_->first != 0) {         // there is room 
		head_->first --;
		head_->val[head_->first] = val;
		size_++;
	}
	else{                                 // there is no room, make a new item
		size_++;
		Item *newItem = new Item();
		newItem->val[9] = val;
		newItem->first = 9;
		newItem->last = 10;
    newItem->next = head_;
		newItem->prev = nullptr;

    head_->prev = newItem; 
		head_ = newItem;
	}
}


void ULListStr::pop_back()
{
  if (tail_ != nullptr)
  {
    if (size_ == 1)                   // one string turns into zero
    {
      delete head_;      
      head_ = nullptr; 
      tail_ = nullptr;
      size_--;
    } 
    else if (tail_->last != 0)        // no need to delete Item
    {
      tail_->last--;
      size_--;
    } 
    else if (tail_->last == 0)
    {
      Item* temp = tail_;
      tail_ = tail_->prev;
      tail_->next = nullptr; 
      delete temp;
      size_--;
    }
  }
}

void ULListStr::pop_front()
{
  if (tail_ != nullptr)
  {
    if (size_ == 1)                   // one string turns into zero
    {
      delete head_; 
      head_ = nullptr; 
      tail_ = nullptr;
      size_--;
    } 
    else if (head_->first != 9)      // no need to delete Item
    {
      //std::cout << head_->first << "simple remove" << head_->last << " " << head_->val[head_->first] << std::endl; 
      head_->first++;
      size_--;
    } 
    else if (head_->first == 9)
    {
      Item* temp = head_;
      head_ = head_->next;
      head_->prev = nullptr;
      delete temp;
      size_--;
    }
  }
}

std::string const & ULListStr::back() const
{ 
  return tail_->val[tail_->last - 1];   
}

std::string const & ULListStr::front() const
{ 
  return head_->val[head_->first]; 
}

std::string* ULListStr::getValAtLoc(size_t loc) const
{
  if (loc >= size_)
  {
    return nullptr;
  }

  Item* temp = head_;
  int tempFirst = head_->first;
  
  std::string* stringPointer = &temp->val[tempFirst]; 

  int i = 0;
  while (i < loc)
  {
    tempFirst++; 
    if (tempFirst == 10)
    {
      temp = temp->next;
      tempFirst = temp->first; 
    }
    i++; 
  }

  stringPointer = &temp->val[tempFirst]; 
  return stringPointer; 
}





// CODE ALREADY GIVEN

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
