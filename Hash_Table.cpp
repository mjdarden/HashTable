#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <ctype.h>
#include "hash.h"

using namespace std;


int main()
{
    string names[100];
    string num1[100];
    string num2[100];
    string num3[100];
    string name = "";
    string phoneNumber = "";

    ifstream din1;
    din1.open("people.txt");
    for (int i = 0; i < 100; i++) {
        getline(din1, names[i]);
    }

    ifstream din2;
    din2.open("num1.txt");
    for (int i = 0; i < 100; i++) {
        getline(din2, num1[i]);
    }

    ifstream din3;
    din3.open("num2.txt");
    for (int i = 0; i < 100; i++) {
        getline(din3, num2[i]);
    }

    ifstream din4;
    din4.open("num3.txt");
    for (int i = 0; i < 100; i++) {
        getline(din4, num3[i]);
    }

    HashTable ht(10);
    for (int i = 0; i < 10; i++) {
        name = names[i % 100];
        phoneNumber = num1[i % 100] + "-" + num2[i % 100] + "-" + num3[i % 100];
        ht.Insert(name, phoneNumber);
        cout << " " << name << " " << phoneNumber << endl;
    }
    ht.Print();
}

