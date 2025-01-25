#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

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
void ULListStr::push_back(const std::string& str)
{
 //ULList is empty
 if (head_ == NULL){
  Item *new_node = new Item;
  head_ = new_node;
  tail_ = new_node;
  new_node->val[0] = str;
  new_node->first = 0;
  new_node->last = 1;
  size_++;
 }  
 //adding another node if tail item uses last index
 else if (tail_->last == ARRSIZE){
  Item* new_node = new Item;
  new_node->prev = tail_;
  tail_->next = new_node;
  tail_ = new_node;
  new_node->val[0] = str;
  new_node->first = 0;
  new_node->last = 1;
  size_++;
}
//adding another node if tail item has space
else {
  tail_->val[tail_->last] = str;
  (tail_->last)++;
  size_++;

}
}
void ULListStr::push_front(const std::string& str)
{
  //ULList is empty
  if (head_ == NULL) {
    Item *new_node = new Item;
    head_ = new_node;
    tail_ = new_node;
    new_node->val[ARRSIZE - 1] = str;
    new_node->first = ARRSIZE - 1;
    new_node->last = ARRSIZE;
    size_++;

  }
  //adding another node if head item uses index 0
  else if (head_->first == 0){
    Item *new_node = new Item;
    new_node->next = head_;
    head_->prev = new_node;
    head_ = new_node;
    new_node->val[ARRSIZE - 1] = str;
    new_node->first = ARRSIZE - 1;
    new_node->last = ARRSIZE;
    size_++;

  }
  //adding string to middle of node
  else {
    head_->val[head_->first - 1] = str;
    (head_->first)--;
    size_++;
  }

}
void ULListStr::pop_back()
{
  //deallocating item if only one node present
if ((tail_->last - tail_->first) == 1) {
  Item* temp = tail_;
  tail_ = tail_->prev; 
  if (tail_ != NULL) {
      tail_->next = NULL; 
  } 
  else {
      head_ = NULL; // If the list becomes empty, update head_
  }
  delete temp;
  size_--;
} 
else {
  //clearing string and updating item's data members accordingly
  (tail_->val[(tail_->last) - 1]).clear();
  tail_->last--;
  size_--;
}
}

void ULListStr::pop_front(){
  //deallocating item if only one node present
  if ((head_->last - head_->first) == 1){
    Item* temp = head_;
    head_ = head_->next;
    if (head_ != NULL){
      head_->prev = NULL;
    }
    else {
      tail_ = NULL;// If the list becomes empty, update tail_
    }
    delete temp;
    size_--;
  }
  else {
    (head_->val[(head_->first)]).clear();
    head_->first++;
    size_--;
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
  if (loc > size_){
    return NULL;
  }
  Item* node = head_;//intialize a node to traverse thru list
  if (loc == 0){
    return &node->val[node->first];
  }
  //decrement loc as each string is read
  while (loc != 0){
    size_t diff = node->last - node->first;
    if (loc < diff){
      return &node->val[node->first + loc];
    }
    loc -= diff;
    node = node->next;
  }
  return &node->val[node->first];




}

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
