// YOUR NAME.
// spell_check.cc: A simple spell checker.

#include <fstream>
#include <iostream>
#include <string>

// You can change to quadratic probing if you
// haven't implemented double hashing.
#include "quadratic_probing.h"
using namespace std;

// You can add more functions here.

// Creates and fills double hashing hash table with all words from
// dictionary_file
HashTable<string> MakeDictionary(const string &dictionary_file) {
  HashTable<string> dictionary_hash;
  ifstream dictionary(dictionary_file);
  string word;
  while (dictionary >> word)
    dictionary_hash.Insert(word);
  return dictionary_hash;
}

//fixes a word by making it lowercase and removing all trailing/ leading non letter/number characters
string fixWord(string str){
  size_t length = str.length();
  for (size_t i = 0; i < length; i++) 
    str[i] = tolower(str[i]); // Convert word to lowercase
  while (!isalnum(str[0]))
  {
    length--;
    str = str.substr(1);
  }
  while (!isalnum(str[length-1]))
  {
    length--;
    str.pop_back();
  }
  return str;
}
// For each word in the document_file, it checks the 3 cases for a word being
// misspelled and prints out possible corrections
void SpellChecker(HashTable<string>& dictionary,
		  const string &document_file) {
    ifstream words(document_file);
    string word;
    while (words >> word)
    {
        string hold = word;
        word = fixWord(word);
        bool res = dictionary.contains(word);
        if (res)
        {
          cout << word << " IS CORRECT" << endl;
        }
        else
        {
            cout << word << " IS INCORRECT" << endl;
            dictionary.printSuggestions(word);
        }
      
    }
}

// @argument_count: same as argc in main
// @argument_list: save as argv in main.
// Implements
int testSpellingWrapper(int argument_count, char** argument_list) {
    const string document_filename(argument_list[1]);
    const string dictionary_filename(argument_list[2]);
    // Call functions implementing the assignment requirements.
    HashTable<string> dictionary = MakeDictionary(dictionary_filename);
    SpellChecker(dictionary, document_filename);

    return 0;
}

// Sample main for program spell_check.
// WE WILL NOT USE YOUR MAIN IN TESTING. DO NOT CODE FUNCTIONALITY INTO THE
// MAIN. WE WILL DIRECTLY CALL testSpellingWrapper. ALL FUNCTIONALITY SHOULD BE
// THERE. This main is only here for your own testing purposes.
int main(int argc, char** argv) {
  if (argc != 3) {
    cout << "Usage: " << argv[0] << " <document-file> <dictionary-file>"
         << endl;
    return 0;
  }
  
  testSpellingWrapper(argc, argv);
  
  return 0;
}
