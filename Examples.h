/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Examples.h
 * Author: default
 *
 * Created on June 29, 2018, 10:41 AM
 */

#ifndef EXAMPLES_H
#define EXAMPLES_H

#include "containers/Link.h"
#include "containers/MyLink.h"
#include "containers/MyVector.h"
#include "utils/FileHandle.h"
#include <iostream>
#include <vector>
#include <bits/c++config.h>
#include <cstring>
#include <iterator>

void printAll(Test::Link* p) {
    std::cout << "{";
    
    while(p) {
        std::cout << p->value;
        if(p = p->next) {
            std::cout << ", ";
        }
    }
    std::cout << "}";
}
void testLinks() {
    Test::Link* norseGods = new Test::Link("Thor");
    norseGods->insert(norseGods, new Test::Link{"Odin"});
    norseGods->insert(norseGods, new Test::Link{"Zeus"});
    norseGods->insert(norseGods, new Test::Link{"Freia"});
    
    Test::Link* greekGods = new Test::Link("Hera");
    greekGods->insert(greekGods, new Test::Link{"Athena"});
    greekGods->insert(greekGods, new Test::Link{"Mars"});
    greekGods->insert(greekGods, new Test::Link{"Poseidon"});
    
    Test::Link* p = greekGods->find(greekGods, "Mars");
    if(p) {
        p->value = "Ares";
    }
    
    Test::Link* pp = norseGods->find(norseGods, "Zeus");
    if(pp) {
        if(pp == norseGods) {
            norseGods = p->next;
        }
        norseGods->erase(pp);
        greekGods = greekGods->insert(greekGods, pp);
    }
    printAll(norseGods);
    std::cout << std::endl;
    printAll(greekGods);
}

void printMyLink(Containers::MyLink* p) {
    std::cout << "{";
    while(p) {
        std::cout << p->value;
        if(p = p->next()) {
            std::cout << ", ";
        }
    }
    std::cout << "}";
}

void testClassLink() {
    Containers::MyLink* norseGods = new Containers::MyLink("Thor");
    norseGods = norseGods->insert(new Containers::MyLink{"Odin"});
    norseGods = norseGods->insert(new Containers::MyLink{"Zeus"});
    norseGods = norseGods->insert(new Containers::MyLink{"Freia"});
    
    Containers::MyLink* greekGods = new Containers::MyLink("Hera");
    greekGods = greekGods->insert(new Containers::MyLink{"Athena"});
    greekGods = greekGods->insert(new Containers::MyLink{"Mars"});
    greekGods = greekGods->insert(new Containers::MyLink{"Poseidon"});
    
    Containers::MyLink* p = greekGods->find("Mars");
//    std::cout << "p: " << p->value << std::endl;
    if(p) {
        std::cout << "Found!\n";
        p->value = "Ares";
    }
    Containers::MyLink* p2 = norseGods->find("Zeus");
    if(p2) {
        if(p2 == norseGods) {
            norseGods = p2->next();
        }
        p2->erase();
        greekGods = greekGods->insert(p2);
    }
    
    printMyLink(norseGods);
    std::cout << std::endl;
    printMyLink(greekGods);
    std::cout << std::endl;
}


//Drill
void printArr10(std::ostream& os, int* arr) {
    for(int i = 0; i < 11; ++i) {
        os << arr[i] << " ";
    }
}
void printArrNSize(std::ostream& os, int* arr, int size) {
    for(int i = 0; i < size; ++i) {
        os << arr[i] << " ";
    }
}
void drill() {
    constexpr int size = 20;
    int* arr = new int[size];
    for(int i = 0; i < size; ++i) {
        arr[i] = i + 100;
    }
    printArrNSize(std::cout, arr, size);
    delete [] arr;
}
void printVector(std::ostream& os, std::vector<int>& v) {
    for(int i = 0; i < v.size(); ++i) {
        os << v.at(i) << " ";
    }
}
void drillVector() {
    constexpr int size = 11;
    std::vector<int> v;
    for(int i = 0; i < size; ++i) {
        v.push_back(i + 100);
    }
    printVector(std::cout, v);
    std::cout << std::endl;
    
    int myInt = 7;
    int* p1 = &myInt;
    std::cout << "address myPtrInt: " << p1 << ", myInt&: " << &myInt << ", value: " << *p1 << ", " << myInt << std::endl;
    
    int* arr2 = new int[7];
    for(int i = 0; i < 7; ++i) {
        int num = 1;
        for(int j = i; j > 0; j--) {
            num *= 2;
        }
        arr2[i] = num;
    }
    int* p2 = arr2;
    for(int i = 0; i < 7; ++i) {
        std::cout << p2[i] << " " << arr2[i] << std::endl;
    }
    int* p3 = p2;
    p1 = p2;
    p3 = p2;
    std::cout << "p1: " << p1 << ", p2: " << p2 << std::endl;
    delete[] arr2;
    
    
}

void toLower(char* s) {
    std::size_t size = strlen(s);
    std::cout << "size: " << size << std::endl;
    for(int i = 0; i < size; ++i) {
        if(s[i] == '\0') {
            return;
        }
        switch(s[i]) {
//            std::cout << s[i] << " ";

            case 'A': s[i] = 'a'; break;
            case 'B': s[i] = 'b'; break;
            case 'C': s[i] = 'c'; break;
            case 'D': s[i] = 'D'; break;
            case 'E': s[i] = 'e'; break;
            case 'F': s[i] = 'f'; break;
            case 'G': s[i] = 'g'; break;
            case 'H': s[i] = 'h'; break;
            case 'I': s[i] = 'i'; break;
            case 'Q': s[i] = 'q'; break;
            case 'W': s[i] = 'w'; break;
            case 'R': s[i] = 'r'; break;
            case 'T': s[i] = 't'; break;
            case 'Y': s[i] = 'y'; break;
            case 'U': s[i] = 'u'; break;
            case 'O': s[i] = 'o'; break;
            case 'P': s[i] = 'p'; break;
            case 'S': s[i] = 's'; break;
            case 'J': s[i] = 'j'; break;
            case 'K': s[i] = 'k'; break;
            case 'L': s[i] = 'l'; break;
            case 'Z': s[i] = 'z'; break;
            case 'X': s[i] = 'x'; break;
            case 'V': s[i] = 'v'; break;
            case 'N': s[i] = 'n'; break;
            case 'M': s[i] = 'm'; break;
        }
    }
}
void testToLower() {
    char cstr[] = "THisIs MathA Fuckin StRinG"; //c-style string
    std::cout << cstr << std::endl;
    toLower(cstr);
    std::cout << cstr << std::endl;
}

char* strdup(const char* str) {
    std::size_t length = strlen(str);
    if(length <= 0) {
        return nullptr;
    }
    char* myStr = new char[length];
    for(int i = 0; i < length; ++i) {
        myStr[i] = str[i];
    }
    return myStr;
}
void testThat() {
    char* sentence = strdup("What the fuck");
    std::cout << sentence << std::endl;
    delete sentence;
}

char* findx(const char* s, const char* x) {
    
    
//    char* found = new char[length];
}

void readChars() {
    constexpr int size = 10;
    char* buffer = new char[size];
    int count = 0;
    char c = ' ';
    while(c != '!') {
        std::cin >> c;
        if(c == ' ') {
            buffer[count++] = ' '; 
        }
        else {
            buffer[count++] = c;
        }
    }
    std::cout << buffer << std::endl;
    delete[] buffer;
}
void readCharsString() {
    std::string s = "";
    
    char c = ' ';
    while(c != '!') {
        std::cin >> c;
        s += c;
    }
    std::cout << s << std::endl;
}

struct SimpleStruct {
    int a;
    ~SimpleStruct() {
        std::cout << this << std::endl;
    }
};
void testSimpleStruct() {
    SimpleStruct* arr = new SimpleStruct[10];
    for(int i = 0; i < 10; ++i) {
        std::cout << &arr[i] << std::endl;
    }
    std::cout << std::endl;
    delete [] arr;
}

//void testMyVectorCopyMove() {
//    Containers::MyVector v1 = 10;
//    
//    for(int i = 0; i < v1.getSize(); ++i) {
//        std::cout << v1.getElement(i) << std::endl;
//    }
//}

//Simple Test class about constructors and destructors 
struct MyTestClass {
    int value;
    
    void output(const std::string& s, int val) {
        std::cerr << this << " -> " << s << ": " << value << " (" << val << ").\n";
    }
    
    //Default Constructor.
    MyTestClass() {
        output("MyTestClass() Constructor", 0);
        value = 0;
    }
    //Constructor
    MyTestClass(int v) {
        value = v;
        output("MyTestClass(int)", v);
    }
    MyTestClass(const MyTestClass& obj) {
        value = obj.value;
        output("MyTestClass(copy)", obj.value);
    }
    MyTestClass& operator = (const MyTestClass& obj) {
        output("MyTestClass::operator = ()", obj.value);
        value = obj.value;
        return *this;
    }
    ~MyTestClass() {
        output("~MyTestClass() Destructor", 0);
    }
};


MyTestClass global(2);

MyTestClass copy1(MyTestClass a) {
    return a;
}

MyTestClass copy2(MyTestClass a) {
    MyTestClass aa = a;
    return aa;
}

MyTestClass& refTo(MyTestClass& a) {
    return a;
}
MyTestClass* make(int i) {
    MyTestClass a{i};
    return new MyTestClass(a);
}

struct MyTT {
    MyTestClass a;
    MyTestClass b;
};

void testMyTestClass() {
    MyTestClass loc{4}; //local variable
    MyTestClass loc2{loc};  //copy constructor
    loc = MyTestClass{5};   //copy assignment
    loc2 = copy1(loc);      //call by value and return
    loc2 = copy2(loc);      
    
    MyTestClass loc3{6};
    MyTestClass& ref = refTo(loc);  //call by reference and return;
    
    delete make(7);
    delete make(8);
    
    std::vector<MyTestClass> v(4);
    MyTT loc4;
    MyTestClass* p = new MyTestClass(9);    //an MyTestClass on the free store
    delete p;
    
    MyTestClass* pp = new MyTestClass[5];       //An array of MyTestClass on the free store
    delete [] pp;
}
//void testOperators(const Containers::MyVector& v1, Containers::MyVector& v2) {
//    double d = v1[2];   //fine uses const operator[]
//    //v1[3] = 2.0;   //error const MyVector&
//    double d1 = v2[1];  //fine uses non const operator[]
//    v2[3] = 15.0;   //fine uses non const operator[] 
//    
//}

//void testOperatorForVector() {
//    Containers::MyVector v(5);
//    v[3] = 5;
//    for(int i = 0; i < v.getSize(); ++i) {
//        std::cout << v[i] << std::endl;
//    }
//    
//    Containers::MyVector v2(5);
//    for(int i = 0; i < v2.getSize(); ++i) {
//        v2[i] = i;
//    }
//    testOperators(v2, v);
//    
//    std::cout << "v--------\n";
//    for(int i = 0; i < v.getSize(); ++i) {
//        std::cout << v[i] << std::endl;
//    }
//    std::cout << "v2--------\n";
//    for(int i = 0; i < v2.getSize(); ++i) {
//        std::cout << v2[i] << std::endl;
//    }
//}

//Drill
int globalArr[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
void fGlobalArr(int arr[], int size) {
    int localArr[10];
    memcpy(localArr, arr, 10 * sizeof(int));
    
    for(int i = 0; i < 10; i++) {
        std::cout << localArr[i] << std::endl;
    }
    
    std::cout << "---------- *p\n";
    int* p = new int[size];
    std::copy(arr, arr + size, p);
    for(int i = 0; i < 10; i++) {
        std::cout << p[i] << std::endl;
    }
//    while(p) {
//        std::cout << *p << std::endl;
//        p++;
//    }
    delete [] p;
}
void testDrill23() {
    fGlobalArr(globalArr, 10);
}


std::vector<int> globalVector = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
void fGlobalVector(std::vector<int> v) {
    std::vector<int> localVector(globalVector.size());
    std::copy(v.begin(), v.end(), localVector.begin());
    
    for(std::vector<int>::iterator it = localVector.begin(); it != localVector.end(); ++it) {
        std::cout << *it << std::endl;
    }
    
    std::vector<int> v2 = globalVector;
    std::copy(v2.begin(), v2.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}
void testDrillVector() {
    fGlobalVector(globalVector);
}

char* strdup2(const char* str) {
    int count = 0;
    const char* begin = str;
    while(*str != '\0') {
        str++;
        count++;
    }
    str = begin;
    char* result = new char[count];
    std::cout << std::endl;
    while(*str != '\0') {
        *result = *str;
        std::cout << *result << " ";
//        result++;

        str++;
    }
//    std::cout << result << std::endl;
    return result;
}
void testStrDup2() {
    char arr[] = "This is the new shit!";

    char* res = strdup2(arr);
    std::cout << std::endl;
    std::cout << "1: " << res << std::endl;
    delete res;
}

std::string catDot(const std::string& s1, const std::string& s2, const std::string& separator) {
    std::string result = s1 + separator + s2;
    return result;
}
void testThat2() {
    std::cout << catDot("Vanya", "Dimitrova", "#") << std::endl;
}

void testFileHandle() {
    try {
        FileHandle f("ReelsArea.h");
        f.printFile();
    }
    catch(...) {
        std::cerr << "Exception Thrown\n";
    }
}
#endif /* EXAMPLES_H */

