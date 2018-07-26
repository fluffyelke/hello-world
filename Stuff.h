/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Stuff.h
 * Author: default
 *
 * Created on June 28, 2018, 2:16 PM
 */

#ifndef STUFF_H
#define STUFF_H

void sizes(int i, char c, int* p, double d, bool b) {
    std::cout << "int size: " << sizeof(int) << " , i size: " << sizeof(i) << std::endl;
    std::cout << "char size: " << sizeof(char) << " , c size: " << sizeof(c) << std::endl;
    std::cout << "int* size: " << sizeof(int*) << " , p* size: " << sizeof(p) << std::endl;
    std::cout << "double size: " << sizeof(double) << " , c size: " << sizeof(d) << std::endl;
    std::cout << "bool size: " << sizeof(bool) << " , b size: " << sizeof(b) << std::endl;
}

#endif /* STUFF_H */

