/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: default
 *
 * Created on June 27, 2018, 12:08 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <memory>
#include "utils/Stuff.h"
#include "containers/MyVector.h"
#include "Examples.h"
#include "Drills.h"
#include "containers/MyPair.h"
#include "utils/Int.h"
#include "utils/Number.h"
#include "utils/SmartPointers.h"
#include "utils/Tracer.h"
using namespace std;

int *getP(int a) {
    int* p = &a;
    return p;
}

void test() {
    int a = *getP(10);
    std::cout << a << std::endl;
    
    int b;
    b;
}
void test2() {
    int b = 10;
    sizes(5, 'a', &b, 25.5, false);
    
    std::vector<int> v(1000);
    std::cout << "sizeof vector: " << sizeof(v) << std::endl;
}
/*
 * 
 */

void myVectorTest1() {
//    Containers::MyVector v(5);
//    for(int i = 0; i < v.getSize(); ++i) {
//        v.setElement(i, 1.1 * i);
//        std::cout << "v[" << i << "] = " << v.getElement(i) << std::endl;
//    }
}


//Containers::MyVector* loadVector(int n) {
//    Containers::MyVector* p = new Containers::MyVector(n);
//    
//    for(int i = 0; i < p->getSize(); ++i) {
//        p->setElement(i, 1.1 * i);
//    }
//    
//    return p;
//}
//void testLoadVector() {
//    Containers::MyVector* p = loadVector(15);
//    for(int i = 0; i < p->getSize(); ++i) {
//        std::cout << p->getElement(i) << std::endl;
//    }
//    delete p;
//}

void testVoidPtr(void* p) { 
    void* ptrVoid = p;      //Copying is ok
//    double* ptrD = p;   //error cannot convert void* to double;
//    *p = 7; //error cannot dereference void*
    int* ptr2 = static_cast<int*>(p);
    *ptr2 = 50;
}


void printSomeVectorStuff(Containers::MyVector<int>& v) {
    int i = -1;
    while(std::cin >> i && i != -1) {
        try {
            std::cout << "v[" << i << "] = " << v.at(i) << std::endl;
        }
        catch(Containers::OutOfRange) {
            std::cerr << "Bad Index: " << i << std::endl;
        }
    }
}

std::unique_ptr<std::vector<int>> makeVector() {
    std::unique_ptr<std::vector<int>> unqPtrVec {new std::vector<int>}; //allocate new vector on the free store.
    // we can now fill vector with that that can throw exception.
    // if throw std::unique_ptr will automaticaly clean the allocated memory.
    return unqPtrVec;
//    return unqPtrVec.release(); // if we use standard pointer we must return .release() function std::vector<int>* makeVector() {}
}

void testInt() {
    Int n1;
    Int n2{5};
    Int n3{14};
    
    std::cout << n1 << " " << n2 << " " << n3 << std::endl;
    
    n1 = n2;
    std::cout << n1 << " " << n2 << " " << n3 << std::endl;
    n1 = 20;
    std::cout << n1 << " " << n2 << " " << n3 << std::endl;
    n1 = n2 * n3;
    std::cout << n1 << " " << n2 << " " << n3 << std::endl;
    n1 = 5;
    n2 = 10;
    n3 = 15;
    std::cout << n1 << " " << n2 << " " << n3 << std::endl;
    n1 = n1 + n2;
    std::cout << n1 << " " << n2 << " " << n3 << std::endl;
    n1 = n1 + n2 + n3;
    std::cout << n1 << " " << n2 << " " << n3 << std::endl;
    n3 = n1 / n2;
    std::cout << n1 << " " << n2 << " " << n3 << std::endl;
}

void testTemplateNumber() {
    Number<int> n1;
    Number<int> n2{5};
    Number<int> n3{14};
    
    std::cout << n1 << " " << n2 << " " << n3 << std::endl;
//    
    n1 = n2;
    std::cout << n1 << " " << n2 << " " << n3 << std::endl;
    n1 = 20;
    std::cout << n1 << " " << n2 << " " << n3 << std::endl;
    Number<int> n4;
    n4 = n1 + n2;
////    n1 * n2;
    std::cout << n4 << std::endl;
    n1 = 5;
    n2 = 10;
    n3 = 15;
    std::cout << n1 << " " << n2 << " " << n3 << std::endl;
    n1 = n1 + n2;
    std::cout << n1 << " " << n2 << " " << n3 << std::endl;
    n1 = n1 + n2 + n3;
    std::cout << n1 << " " << n2 << " " << n3 << std::endl;
    n3 = n1 / n2;
    std::cout << n1 << " " << n2 << " " << n3 << std::endl;
}

Tracer globalTracer("GLOBAL");
struct TestStruct {
    TestStruct() : tracerInTestStruct{"TEST_STRUCT"} {
        
    }
    Tracer tracerInTestStruct;
};
void testTracer() {
    Tracer* heapTracer = new Tracer("HEAP_NEW");
    Tracer localTracer{"LOCAL"};
    TestStruct ts;
    
    Tracer copyTracer{localTracer};
    Tracer* ptrAssgnment = heapTracer;
    
    Tracer asgnmentPtr = globalTracer;
    globalTracer = localTracer;
//    delete heapTracer;
    delete ptrAssgnment;
//    delete heapTracer;    //cant delete deleted pointer. Segmentation fault
}
int main(int argc, char** argv) {
    
    testFileHandle();
    
    return 0;
}

