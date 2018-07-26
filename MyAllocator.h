/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MyAllocator.h
 * Author: default
 *
 * Created on July 25, 2018, 4:38 PM
 */

#ifndef MYALLOCATOR_H
#define MYALLOCATOR_H

#include <stdlib.h>
#include <exception>
#include <initializer_list>
#include <algorithm>
#include <string>
#include <iostream>

namespace Excercises {
    
    struct ThrowError {
        ThrowError(const std::string& msg) {
            std::cerr << msg << std::endl;
        }
    };
    
    template<typename T>
    class MyAllocator {

        public:
            //allocate space for n objects of type T
            T* allocate(int n) {
                T* p = nullptr;
                try {
                    p = static_cast<T*>(malloc(n * sizeof(T)));
                }
                catch(std::exception& e) {
                    std::cout << "Exception Thrown at function MyAllocator::allocate() Cant allocate memory: " << e.what() << std::endl;
                }
                return p;
            }
            //deallocate n objects of type T starting at p
            void deallocate(T* p) {
                free(p);
            }       

            //construct a T with the value v in p
            void construct(T* p, const T& v) {
                new(p);
                T(v);
            }   

            //destroy T in p;
            void destroy(T* p) {
                p->~T();
            }                 

    };
    
    //My Vector Class
    template<typename T, typename A = MyAllocator<Type>>
    class MyNewVector {
        A alloc;        //used to handle memory for elements
        int size;       //current size of the vector
        T* data;     //a pointer to the elements;
        int space;      //size + free space
        
        public:
            /**
             * Default constructor
             */
            MyNewVector() 
                : size{0}, data{nullptr}, space{0} {
            } 
            
            /**
             * Explicit constructor create Vector with size n
             * @param n - initial size of the vector
             */    
            explicit MyNewVector(int n) 
                : size{n},
                  data{alloc.allocate(s)},
                  space{s} {
                      for(int i = 0; i < size; i++) {
                          alloc.construct(&data[i], T());
                      }
            }
            
            /**
             * Constructor which can use initializer_list<T> from c++11
             * @param lst
             */      
            MyNewVector(std::initializer_list<T> lst) 
                : size{lst.size()},
                  data{alloc.allocate(lst.size())},
                  space{lst.size()} {
                      std::copy(lst.begin(), lst.end(), data);
            }
                  
            //Copy Operations
            /**
             * Copy constructor
             * @param obj
             */      
            MyNewVector(const MyNewVector& obj) 
                : size{obj.size},
                  data{alloc.allocate(obj.size)},
                  space{obj.space}{
                      std::copy(obj.data, obj.data + obj.size, data);
            }
            
            MyNewVector& operator = (const MyNewVector& obj) {
                //No self assignment
                if(this == &obj) {
                    return *this;
                }
                
                //No need to allocate new size if the size is enough
                if(obj.size <= size) {
                    for(int i = 0; i < size; i++) {
                        alloc.construct(&data[i], obj.data[i]);
                    }
                    size = obj.size;
                    return *this;
                }
                
                //Size is not enough allocate new space
                T* p = alloc.allocate(obj.size);
                //copy elements
                for(int i = 0; i < obj.size; i++) {
                    alloc.construct(&p[i], obj.data[i]);
                }
                //destroy old objects
                for(int i = 0; i < size; i++ ){
                    alloc.destroy(&data[i]);
                }
                //deallocate old space
                alloc.deallocate(data);
                //set new size
                space = size = obj.size;
                //set new elements
                data = p;
                return *this;
            }
            
            ~MyNewVector() {
                for(int i = 0; i < size; i++) {
                    alloc.destroy(&data[i]);
                }
                alloc.deallocate(data);
            }
            
            //operations
            /**
             * Get vector current size
             * @return size
             */
            int getSize() const {
                return size;
            }
            
            int capacity() const {
                return space;
            }
            
            T& at(int n) {
                if(n < 0 || n >= size) {
                    throw ThrowError("Index " + n + " out of range");
                }
                return data[n];
            }
            const T& at(int n) const {
                if(n < 0 || n >= size) {
                    throw ThrowError("Index " + n + " out of range");
                }
                return data[n];
            }
            
            void reserve(int newAlloc){
                
                if(newAlloc <= space) {
                    return;
                }
                
                T* p = alloc.allocate(newAlloc);
                for(int i = 0; i < size; i++) {
                    alloc.construct(&p[i], data[i]);
                }
                for(int i = 0; i < size; i++) {
                    alloc.destroy(&data[i]);
                }
                data = p;
                space = newAlloc;
            }
            
            void resize(int newSize, T value = T()) {
                reserve(newSize);
                for(int i = 0; i < newSize; i++) {
                    alloc.construct(&data[i], value);
                }
                for(int i = 0; i < size; i++) {
                    alloc.destroy(&data[i]);
                }
                size = newSize;
            }
            
            void pushBack(const T& obj) {
                if(space == 0) {
                    reserve(8);
                }
                else if(size == space) {
                    reserve(2 * space);
                }
                alloc.construct(&data[size], obj);
                size++;
            }
    };
}
#endif /* MYALLOCATOR_H */

