/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Int.h
 * Author: default
 *
 * Created on July 25, 2018, 3:20 PM
 */

#ifndef INT_H
#define INT_H

#include <ostream>


class Int {
public:
    Int();
    Int(int n);
    Int(const Int& orig);
    virtual ~Int();
    
    int getNumber() const;
    
    Int& operator = (const Int& obj);
    Int& operator + (const Int& obj);
    Int& operator - (const Int& obj);
    Int& operator * (const Int& obj);
    Int& operator / (const Int& obj);
    
    friend std::ostream& operator << (std::ostream& os, const Int& obj) {
        return os << obj.getNumber(); 
    }
private:
    int number;
};

#endif /* INT_H */

