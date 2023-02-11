#ifndef QUADRATIC_PROBING_H
#define QUADRATIC_PROBING_H

#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
using std::cout;
using std::endl;
namespace {

// Internal method to test if a positive number is prime.
bool IsPrime(size_t n) {
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
int NextPrime(size_t n) {
  if (n % 2 == 0)
    ++n;  
  while (!IsPrime(n)) n += 2;  
  return n;
}

}  // namespace


// Quadratic probing implementation.
template <typename HashedObj>
class HashTable {
 public:
  
  /*
    Wrapper function to just call the three cases
  */
  void printSuggestions(HashedObj& x)
  {
    std::string hold = x;
    caseA(x);
    x = hold;
    caseB(x);
    x = hold;
    caseC(x);
  }
  enum EntryType {ACTIVE, EMPTY, DELETED};
  // constructor 
  explicit HashTable(size_t size = 101) : array_(NextPrime(size)) , collisions(0)
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
 private:        
   // private variable to count total collisions
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

  // finds position (or supposed position) of given element, regardless of if it exists or not with quadratic probing,
  // adding 2n+1 each time, n starting at 0
  size_t FindPos(const HashedObj & x) {
    size_t offset = 1;
    size_t current_pos = InternalHash(x);
      
    while (array_[current_pos].info_ != EMPTY &&
	   array_[current_pos].element_ != x) {
      current_pos += offset;  // Compute ith probe.
      offset += 2;
      collisions++;
      if (current_pos >= array_.size())
	      current_pos -= array_.size();
    }
    return current_pos;
  }
  // same thing as above, just has an extra parameter to count collisions for the specific element
  size_t FindPos(const HashedObj & x, int& count) {
    size_t offset = 1;
    size_t current_pos = InternalHash(x);
    count++;
    while (array_[current_pos].info_ != EMPTY &&
	   array_[current_pos].element_ != x) {
      current_pos += offset;  // Compute ith probe.
      offset += 2;
      collisions++;
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
    array_.resize(NextPrime(2 * old_array.size()));
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
  /*
  `   * case A where I try inserting an alphabetical letter in each gap / at front and back to try 
        making counsl -> counsel, as an example
        et -> wet
        la -> law
        wih -> wish
  */
  void caseA(HashedObj& x)
  {

    std::string currString = "";
    std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVXYZ";
    for (size_t i = 0; i < x.size(); i++)
    {
      currString += x[i];
      std::string hold = currString;
      for (int j = 0; j < 52; j++)
      {
        currString += alphabet[j];
        currString += x.substr(i+1);
        if (contains(currString))
        {
          cout << "** " << x << " -> " << currString << " ** case A" << endl;
        }
        currString = hold;
      }

    }
  }
  /*
      * case B where I try removing each character and check if the new word exists
      laaw -> law exists
      wordd -> word (twice, because both d's can be removed)
      
  */
  void caseB(HashedObj& x)
  {
    for (size_t i = 0; i < x.size(); i++)
    {
      std::string currString = x.substr(0, i) + x.substr(i+1);
      if (contains(currString))
      {
          cout << "** " << x << " -> " << currString << " ** case B" << endl;
      }
    } 
  }
  /*
    * case C where I try swapping adjacent pairs of letters to form a correct word
    counsle -> counsel
    weildy -> wieldy

  */
  void caseC(HashedObj& x)
  {
    std::string hold = x;
    for (size_t i = 0; i < x.size() - 1; i++)
    {
      char c = x[i];
      x[i] = x[i+1];
      x[i+1] = c;
   //   cout << x << endl;
      if (contains(x))
      {
            cout << "** " << hold << " -> " << x << " ** case C" << endl;
      }
      c = x[i];
      x[i] = x[i+1];
      x[i+1] = c;
      
    }
  }
};

#endif  // QUADRATIC_PROBING_H
