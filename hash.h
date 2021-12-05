#pragma once
//-----------------------------------------------------------
//  Purpose:    Header file for the HashTable class.
//  Author:     John Gauch
//-----------------------------------------------------------

#include <iostream>
using namespace std;

//-----------------------------------------------------------
// Define the HashTable class interface 
//-----------------------------------------------------------
class HashTable
{
public:
    // Constructors
    HashTable(int size);
    HashTable(const HashTable& ht);
    ~HashTable();

    // Methods 
    bool Insert(string key, string value);
    bool Search(int key, int& value);
    bool Delete(int key);
    void Print();

private:
    // Private methods
    int Hash(int key);
    int Hash2(int index);

    // Private constants
    static const char AVAIL = 'A';
    static const char EMPTY = 'E';
    static const char FULL = 'F';

    // Private data
    int Size;
    int Count;
    char* Status;
    string* Value;
    string* Key;
};