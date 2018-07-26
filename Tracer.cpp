/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tracer.cpp
 * Author: default
 * 
 * Created on July 26, 2018, 2:46 PM
 */

#include "Tracer.h"

Tracer::Tracer(const std::string& arg) 
    : str{arg} {
    std::cout << "Object: " << arg << " CREATED." << std::endl;
}

Tracer::Tracer(const Tracer& orig) 
    : str{orig.str} {
    std::cout << "Object: " << str << " COPIED." << std::endl; 
}

Tracer& Tracer::operator=(const Tracer& obj) {
    if(this == &obj) {
        std::cout << "Self Assignment operator." << std::endl;
        return *this;
    }
    str = obj.str;
    std::cout << "Operator = " << str << " Used." << std::endl;
    return *this;
}
    
    
Tracer::~Tracer() {
    std::cout << "Object " << str << ", DESTROYED." << std::endl;
}

