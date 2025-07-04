#include <iostream>
#include <list>
#include <string>
using namespace std;

// Define the hash table size
const int TABLE_SIZE = 10;

// Define the hash table class
class HashTable
{
private:
    // Array of linked lists to handle collisions
    list<string> table[TABLE_SIZE];

    // Hash function to map a word to an index
    int hashFunction(const string &word)
    {
        int hashValue = 0;
        for (char ch : word)
        {
            hashValue += ch; // Sum ASCII values of characters
        }
        return hashValue % TABLE_SIZE; // Use modulo to ensure the index is within table size
    }

public:
    // Function to insert a word into the hash table
    void insert(const string &word)
    {
        //Finding the index to whcih the word is to be inserted at the hash table
        int index = hashFunction(word);

        //Push the word at the specific index of the table found from the hash function
        table[index].push_back(word);
    }

    // Function to check if a word is in the hash table
    bool contains(const string &word)
    {
        int index = hashFunction(word);
        for (const string &entry : table[index])
        {
            if (entry == word)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    // Initialize the hash table
    HashTable hashTable;

    // Words to be inserted into the hash table
    string words[] = {"apple", "banana", "cherry", "dog", "elephant", "frog",
                      "grape", "hat", "ice cream", "jacket"};

    // Insert words into the hash table
    for (const string &word : words)
    {
        hashTable.insert(word);
    }

    // Check if the words "apple", "cat", and "frog" are in the dictionary
    string checkWords[] = {"apple", "cat", "frog"};

    for (const string &word : checkWords)
    {
        if (hashTable.contains(word))
        {
            cout << word << " is in the dictionary." << endl;
        }
        else
        {
            cout << word << " is not in the dictionary." << endl;
        }
    }

    return 0;
}
