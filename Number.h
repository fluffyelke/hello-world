/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Number.h
 * Author: default
 *
 * Created on July 25, 2018, 3:44 PM
 */

#ifndef NUMBER_H
#define NUMBER_H

#include <ostream>


template<typename T>
class Number {
public:
    Number<T>(): value{} {
    }
    Number<T>(T val) : value{val} {}
    Number<T>(const Number& orig) : value{orig.value} {
    }
    virtual ~Number() {
    }
    
    T getValue() const {
        return value;
    }

    Number<T>& operator=(const Number<T>& obj) {
        value = obj.value;
        return *this;
    }
    
    Number<T>& operator + (const Number<T>& obj) {
        if(this == &obj) {
            return *this;
        }
        value += obj.value;
        return *this;
    }

    Number<T>& operator - (const Number<T>& obj) {
        if(this == &obj) {
            return *this;
        }
        value -= obj.value;
        return *this;
    }
    
    Number<T>& operator * (const Number<T>& obj) {
        if(this == &obj) {
            return *this;
        }
        value *= obj.value;
        return *this;
    }
    
    Number<T>& operator / (const Number<T>& obj) {
        if(this == &obj) {
            return *this;
        }
        value /= obj.value;
        return *this;
    }
    
    friend std::ostream& operator << (std::ostream& os, const Number<T>& obj) {
        return os << obj.getValue();
    }
private:
    T value;
};

#endif /* NUMBER_H */

