/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Int.cpp
 * Author: default
 * 
 * Created on July 25, 2018, 3:20 PM
 */

#include "Int.h"
#include <iostream>

Int::Int() : number{0} {
    std::cout << "Default Constructor: " << number << std::endl;
}
Int::Int(int n) 
    : number{n}{
    std::cout << "Constructor: " << number << std::endl;
}

Int::Int(const Int& orig) : number{orig.number} {
    std::cout << "Copy Constructor: " << number << std::endl;
}

Int::~Int() {
}

Int& Int::operator = (const Int& obj) {
    if(this == &obj) {
        return *this;
    }
    number = obj.number;
    std::cout << "Operator = " << number << " " << obj.number << std::endl;
    return *this;
}

Int& Int::operator + (const Int& obj) {
    if(this == &obj) {
        return *this;
    }
    number += obj.number;
    std::cout << "Operator + " << number << " " << obj.number << std::endl;
    return *this;
}

Int& Int::operator - (const Int& obj) {
    if(this == &obj) {
        return *this;
    }
    number -= obj.number;
    std::cout << "Operator - " << number << " " << obj.number << std::endl;
    return *this;
}

Int& Int::operator *(const Int& obj) {
    if(this == &obj) {
        return *this;
    }
    number *= obj.number;
    std::cout << "Operator * " << number << " " << obj.number << std::endl;
    return *this;
}

Int& Int::operator / (const Int& obj) {
    if(this == &obj) {
        return *this;
    }
    
    number /= obj.number;
    std::cout << "Operator / " << number << " " << obj.number << std::endl;
    return *this;
}

int Int::getNumber() const {
    return number;
}