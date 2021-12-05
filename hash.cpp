//-----------------------------------------------------------
//  Purpose:    Implementation of HashTable class.
//  Author:     John Gauch
//-----------------------------------------------------------
#include "hash.h"
#include <stdlib.h>

//-----------------------------------------------------------
// Constructor
//-----------------------------------------------------------
HashTable::HashTable(int size)
{
    Size = size;
    Count = 0;
    Status = new char[Size];
    Value = new string[Size];
    Key = new int[Size];

    for (int index = 0; index < Size; index++)
    {
        Status[index] = EMPTY;
        Value[index] = "";
        Key[index] = 0;
    }
}

//-----------------------------------------------------------
// Copy constructor
//-----------------------------------------------------------
HashTable::HashTable(const HashTable& ht)
{
    Size = ht.Size;
    Count = ht.Count;
    Status = new char[Size];
    Value = new string[Size];
    Key = new int[Size];

    for (int index = 0; index < Size; index++)
    {
        Status[index] = ht.Status[index];
        Value[index] = ht.Value[index];
        Key[index] = ht.Key[index];
    }
}

//-----------------------------------------------------------
// Destructor
//-----------------------------------------------------------
HashTable::~HashTable()
{
    if (Status != NULL)
        delete[]Status;
    if (Value != NULL)
        delete[]Value;
    if (Key != NULL)
        delete[]Key;
    Status = NULL;
    Value = NULL;
    Key = NULL;
    Size = 0;
}

//-----------------------------------------------------------
// Insert method
//-----------------------------------------------------------
bool HashTable::Insert(string key, string value)
{
    // Check hash table overflow
    if (Count + 1 >= Size)
        return false;

    // Find desired key
    int index = Hash(key);
    while ((Key[index] != key) && (Status[index] != EMPTY))
        index = Hash2(index);

    // Insert value into hash table
    if (Key[index] == key)
    {
        Value[index] = value;
        return true;
    }

    // Find unoccupied location
    index = Hash(key);
    while (Status[index] == FULL)
        index = Hash2(index);

    // Insert value into hash table
    Status[index] = FULL;
    Value[index] = value;
    Key[index] = key;
    Count++;
    return true;
}

//-----------------------------------------------------------
// Search method
//-----------------------------------------------------------
bool HashTable::Search(int key, int& value)
{
    // Find desired key
    int index = Hash(key);
    while ((Key[index] != key) && (Status[index] != EMPTY))
        index = Hash2(index);

    // Return value from hash table
    if (Key[index] == key)
        value = Value[index];
    return (Key[index] == key);
}

//-----------------------------------------------------------
// Delete method
//-----------------------------------------------------------
bool HashTable::Delete(int key)
{
    // Find desired key
    int index = Hash(key);
    while ((Key[index] != key) && (Status[index] != EMPTY))
        index = Hash2(index);

    // Delete value from hash table
    if ((Key[index] == key) && (Status[index] == FULL))
    {
        Status[index] = AVAIL;
        Value[index] = 0;
        Key[index] = 0;
        Count--;
        return true;
    }
    return false;
}

//-----------------------------------------------------------
// Primary hash function
//-----------------------------------------------------------
int HashTable::Hash(int key)
{
    return key % Size;
}

//-----------------------------------------------------------
// Secondary hash function
//-----------------------------------------------------------
int HashTable::Hash2(int index)
{
    return (index + 1) % Size;
}

//-----------------------------------------------------------
// Print function for debugging
//-----------------------------------------------------------
void HashTable::Print()
{
    cout << "Index\t" << "Status\t" << "Value\t" << "Key\n";
    for (int index = 0; index < Size; index++)
        cout << index << "\t"
        << Status[index] << "\t"
        << Value[index] << "\t" << Key[index] << "\n";
    cout << "Count = " << Count << endl;
}