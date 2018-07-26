/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MyVector.h
 * Author: default
 *
 * Created on June 28, 2018, 1:00 PM
 */

#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>
#include <algorithm>

namespace Containers {
    
    struct OutOfRange {

    };
    
    template<typename T, typename A = std::allocator<T>>
    class MyVector {
    private:
        A alloc;
        int size;
        T* data;
        int space;
    public:
        MyVector() 
            : size{0},
              data{nullptr},
              space{0} {
            
        }

        explicit MyVector(int sz) 
            : size{sz},
              data{new T[sz]},
              space{sz} {

                for(int i = 0; i < sz; ++i) {
                    data[i] = 0.0;
                } 
                std::cout << "MyVector CREATED with size: " << size << std::endl;
        }
              
        /**
         * Constructor which can use initializer list like MyVector v{1, 2, 3, 4, 5}; or MyVector v = {1, 2, 3, 4, 5};
         * @param lst
         */
        MyVector(std::initializer_list<T> lst) 
            : size{lst.size()},
              data{new T[size]},
              space{lst.size()}{

                std::copy(lst.begin(), lst.end(), data);

        }
        
        //Copy Operations      
        /**
         * Copy Constructor
         * @param orig
         */      
        MyVector(const MyVector& orig) 
            : size{orig.size},
              data{new T{orig.size}},
              space{orig.space}{
                std::copy(orig.data, orig.data + orig.size, data);
        }
        
        /**
         * Copy Operator = 
         * @param orig
         * @return 
         */
        MyVector& operator = (const MyVector& orig) {
            if(this == &orig) {
                return *this; //no Self assignment
            }
            
            //If the destination vector has enough space no need to allocate new memory, just copy the elements.
            if(orig.size <= space) {
                for(int i = 0; i < orig.size; ++i) {
                    data[i] = orig.data[i];
                }
                size = orig.size;
                return *this;
            }
            
            T* p = new T[orig.size];
//            std::copy(orig.data, orig.data + orig.size, data);
            for(int i = 0; i < orig.size; ++i) {
                p[i] = orig.data[i];
            }
            delete [] data; //delete old data
            space = size = orig.size;
            data = p;
            return *this;
        }
        //////////////////////// End Copy Operations
        
        //Move Operations
        /**
         * Move Constructor
         * Copy Elements from orig to this MyVector
         * Than make orig an empty Vector
         * @param orig
         */
        MyVector(MyVector&& orig) 
            : size{orig.size},
              data{orig.data},
              space{orig.space}{
                
                orig.size = 0;
                orig.data = nullptr;
                orig.space = 0;
                
        }
        /**
         * Move Operator = 
         * Move orig to this MyVector
         * @param orig
         * @return 
         */
        MyVector& operator = (MyVector&& orig) {
            delete [] data; //Deallocate old space
            //copy size and data
            data = orig.data;
            size = orig.size;
            space = orig.space;
            //make orig a empty MyVector
            orig.size = 0;
            orig.data = nullptr;
            orig.space = 0;
            
            return *this;   //return self reference
        }
        //////////////////////// End Move Operations
        
        /**
         * Destructor
         */
        virtual ~MyVector() {
            std::cout << "MyVector DESTROYED: " << std::endl;
            delete[] data;  //free allocated resources.
        }

        
        
        /**
         * Return MyVector size.
         * @return 
         */
        int getSize() const {
            return size;
        };

        /**
         * Get Element from the vector
         * @param n
         * @return 
         */
        T getElement(int n) const {
            return data[n];
        }

        /**
         * Set Element in the vector.
         * @param n
         * @param elem
         */
        void setElement(int n, T elem) {
            data[n] = elem;
        }
        
        
        //operators
        //Unchecked access
        /**
         * Can use notation like v[i] = num;
         * but we cant use const MyVector& v, and to set T d = v[i];
         * we should create T operator[](int i) const;
         * @param n
         * @return 
         */
        T& operator [] (int n) {
            return data[n];
        }
        
        /**
         * Now we can use notation line T d = v[i]; rvalue for vector element
         * @param n
         * @return 
         */
        const T& operator [] (int n) const {
            return data[n];
        }
        
        
        //operations
        void reserve(int newAlloc) {
            
            if(newAlloc <= space) {
                return;
            }
            T* p = alloc.allocate(newAlloc);
            
            for(int i = 0; i < size; ++i) {
                alloc.construct(&p[i], data[i]);
            }
            for(int i = 0; i < size; ++i) {
                alloc.destroy(&data[i]);
            }
            alloc.deallocate(data, space);
            data = p;
            space = newAlloc;
        }
        
        int capacity() const {
            return space;
        }
        
        void resize(int newSize, T value = T()) {
            reserve(newSize);
            for(int i = 0; i < newSize; ++i) {
                alloc.construct(&data[i], value);
            }
            for (int i = 0; i < size; i++) {
                alloc.destroy(&data[i]);
            }
            
            size = newSize;
        }
        
        void pushBack(const T& value) {
            if(space == 0) {
                reserve(8);
            }
            else if(size == space ) {
                reserve(2 * space);
            }
            alloc.construct(&data[size], value);
            ++size;
        }
        
        //Checked access
        T& at(int n) {
            if(n < 0 || size <= n) {
                throw OutOfRange();
            }
            return data[n];
        }
        const T& at(int n) const {
            if(n < 0 || size <= n) {
                throw OutOfRange();
            }
            return data[n];
        }
    };
}

#endif /* MYVECTOR_H */

