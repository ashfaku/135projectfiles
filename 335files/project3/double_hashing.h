#ifndef DOUBLE_PROBING_H
#define DOUBLE_PROBING_H

#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

namespace {

// Internal method to test if a positive number is prime.
bool IsPrimeDouble(size_t n) {
  if( n == 2 || n == 3 )
    return true;
  
  if( n == 1 || n % 2 == 0 )
    return false;
  
  for( int i = 3; i * i <= n; i += 2 )
    if( n % i == 0 )
      return false;
  
  return true;
}


// Internal method to return a prime number at least as large as n.
int NextPrimeDouble(size_t n) {
  if (n % 2 == 0)
    ++n;  
  while (!IsPrimeDouble(n)) n += 2;  
  return n;
}

}  // namespace


// DOUBLE probing implementation.
template <typename HashedObj>
class HashTableDouble {
 public:
  enum EntryType {ACTIVE, EMPTY, DELETED};
  // constructor 
  explicit HashTableDouble(size_t size = 101) : array_(NextPrimeDouble(size)) , collisions(0)
    { MakeEmpty(); }
// returns total probes checked to find/ not find element
  int Contains(const HashedObj & x) {
    int count = 0;
    IsActive(FindPos(x, count)); 
    return count;
  }
  // returns if element exists
  bool contains(const HashedObj & x) {
    bool result = IsActive(FindPos(x)); 
    return result;
  }
   // emptys the array
  void MakeEmpty() {
    current_size_ = 0;
    for (auto &entry : array_)
      entry.info_ = EMPTY;
  }
// finds the supposed position of the given element, checks if its empty (if it is, return false), and thene insert it
  // if the incremented size is greater than half of array.size, rehash and return true
  bool Insert(const HashedObj & x) {
    // Insert x as active
    size_t current_pos = FindPos(x);
    if (IsActive(current_pos))
      return false;  
    array_[current_pos].element_ = x;
    array_[current_pos].info_ = ACTIVE;
    
    // Rehash; see Section 5.5
    if (++current_size_ > array_.size() / 2)
      Rehash();    
    return true;
  }
    // same thing as above hash, just uses std::move instead
  bool Insert(HashedObj && x) {
    // Insert x as active
    size_t current_pos = FindPos(x);
    if (IsActive(current_pos))
      return false;
    
    array_[current_pos] = std::move(x);
    array_[current_pos].info_ = ACTIVE;

    // Rehash; see Section 5.5
    if (++current_size_ > array_.size() / 2)
      Rehash();

    return true;
  }
  // checks if element exists, if it doesnt reutrn false, else remove the item and return true
  bool Remove(const HashedObj & x) {
    size_t current_pos = FindPos(x);
    if (!IsActive(current_pos))
      return false;

    array_[current_pos].info_ = DELETED;
    return true;
  }
  // return current size of hash table
  int getSize()
  {
      return current_size_;
  } 
  // returns total size of array 

  int getTableSize()
  {
    return array_.size();
  }
  // returns global variable to count collisions
  int getCollisions()
  {
    return collisions;
  }
  // sets R value to double hash. If it's not prime, get nextPrime of r. 
  //If it's greater than the array.size(), abort the program
  void setRValue(int r)
  {
    int next = r;
    if (!IsPrimeDouble(r))
    {
      next = NextPrimeDouble(r);
      if (next >= getTableSize())
        abort();
      
    }
    R = next;
  }
 private:
 // R value to double hash
  int R;        
  int collisions;
  struct HashEntry {
    HashedObj element_;
    EntryType info_;
    
    HashEntry(const HashedObj& e = HashedObj{}, EntryType i = EMPTY)
    :element_{e}, info_{i} { }
    
    HashEntry(HashedObj && e, EntryType i = EMPTY)
    :element_{std::move(e)}, info_{ i } {}
  };
    

  std::vector<HashEntry> array_;
  size_t current_size_;
//checks if given position has an element or not
  bool IsActive(size_t current_pos) const
  { return array_[current_pos].info_ == ACTIVE; }
// finds position (or supposed position) of given element, regardless of if it exists or not with double
// probing, adding R - x mod R and then modding by array.size()
  
  size_t FindPos(const HashedObj & x) {
    size_t offset = DoubleHash(x);
    size_t current_pos = InternalHash(x);
      
    while (array_[current_pos].info_ != EMPTY &&
	   array_[current_pos].element_ != x) {
      current_pos = (current_pos + offset) % array_.size();
      collisions++;
      if (current_pos >= array_.size())
	current_pos -= array_.size();
    }
    return current_pos;
  }
 // same thing as above, just has an extra parameter to count collisions for the specific element
 
  size_t FindPos(const HashedObj & x, int& count) {
    size_t offset = DoubleHash(x);
    size_t current_pos = InternalHash(x);
    count++;
    while (array_[current_pos].info_ != EMPTY &&
	   array_[current_pos].element_ != x) {
      
      collisions++;  
      current_pos = (current_pos + offset) % array_.size();
    
      if (current_pos >= array_.size())
      {
        count++;
	      current_pos -= array_.size();
      }
      count++;
    }
    return current_pos;
  }
   // rehashes the array by doubling its size, and moving over the old elements
  
  void Rehash() {
    std::vector<HashEntry> old_array = array_;

    // Create new double-sized, empty table.
    array_.resize(NextPrimeDouble(2 * old_array.size()));
    for (auto & entry : array_)
      entry.info_ = EMPTY;
    
    // Copy table over.
    current_size_ = 0;
    for (auto & entry :old_array)
      if (entry.info_ == ACTIVE)
	      Insert(std::move(entry.element_));
  }
  // returns hash value of given HashedObj
  size_t InternalHash(const HashedObj & x) const {
    static std::hash<HashedObj> hf;
    return hf(x) % array_.size( );
  }
  // double hash function with R - x mod R
   size_t DoubleHash(const HashedObj & x) const {
    static std::hash<HashedObj> hf;
    return R -  (hf(x) % R);
  }
};

#endif  // DOUBLE_PROBING_H