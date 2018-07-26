/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SmartPointers.h
 * Author: default
 *
 * Created on July 26, 2018, 11:58 AM
 */

#ifndef SMARTPOINTERS_H
#define SMARTPOINTERS_H

#include <iostream>


namespace MySmartPointers {
    
    template<typename T>
    class UniquePtr {
        private:
            T* ptr;
            
        public:
            UniquePtr(T* arg) 
                : ptr{arg} {
                    std::cout << "UniquePtr created\n";
            }
            
            ~UniquePtr() {
                delete ptr;
                ptr = nullptr;
                std::cout << "UniquePtr Destroyed\n";
            }
            
            T operator * () const {
                return *ptr;
            }
            T* operator -> () const {
                return ptr;
            }
            
            T* release() {
                T* temp = ptr;
                ptr = nullptr;
                return temp;
            }
    };  //end of UniquePtr
    
    
    template<typename T>
    class CountedPtr {
        private:
            T* ptr;
            int* count;
            
        public:
            //Constructor
            CountedPtr(const T& obj) {
                ptr = new T(obj);
                count = new int(1);
            }
            //Copy Constructor
            CountedPtr(const CountedPtr& obj) {
                ptr = obj.ptr;
                count = obj.count;
                ++(*count);
            }
            ~CountedPtr() {
                --(*count);
                if(*count == 0) {
                    std::cout << "Destruct CountedPtr\n";
                    delete ptr;
                    ptr = nullptr;
                    delete count;
                    count = nullptr;
                }
            }
            //Operator =
            CountedPtr& operator = (const CountedPtr& obj) {
                if(this == &obj) {
                    return *this;
                }
                --(*count);
                if(*count == 0) {
                    delete ptr;
                    ptr = nullptr;
                    delete count;
                    count = nullptr;
                }
                ptr = obj.ptr;
                count = obj.count;
                return *this;
            }
            
            T operator * () const {
                return *ptr;
            }
            T* operator -> () const {
                return ptr;
            }
            int getCount() const {
                return *count;
            }
    };  //end of CountedPtr class
}   //end of namespace MySmartPointers

struct TestSmartPtr {
    TestSmartPtr() {
        std::cout << "Constructor TestSmartPtr()" << std::endl;
    }
    TestSmartPtr(int n) {
        std::cout << "Constructor TestSmartPtr(int n)" << std::endl;
        val = n;
    }
    ~TestSmartPtr() {
        std::cout << "Destructor ~TestSmartPtr()" << std::endl;
    }
    
    int val;
};

TestSmartPtr* f() {
    TestSmartPtr* p = new TestSmartPtr;
    MySmartPointers::UniquePtr<TestSmartPtr> p1{new TestSmartPtr()};
    MySmartPointers::UniquePtr<TestSmartPtr> p2{new TestSmartPtr(5)};
    return p2.release();
}
void f2() {
    TestSmartPtr* p = new TestSmartPtr();
    MySmartPointers::UniquePtr<TestSmartPtr> p2{new TestSmartPtr()};
    if(false){
        return;
    }
    delete p;   //never reach this point
}
void testSmartPointers() {
    try {
        TestSmartPtr* p = f();
        std::cout << "Dereference operator: " << (*p).val << std::endl;
        std::cout << "Pointer access operator: " << p->val << std::endl;
        
        delete p;
        f2();
    }
    catch(...) {
        std::cerr << "Exception caught\n";
    }
}

#endif /* SMARTPOINTERS_H */

