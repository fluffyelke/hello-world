/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tracer.h
 * Author: default
 *
 * Created on July 26, 2018, 2:46 PM
 */

#ifndef TRACER_H
#define TRACER_H

#include <string>
#include <iostream>

class Tracer {
public:
    Tracer(const std::string& arg);
    Tracer(const Tracer& orig);
    Tracer& operator = (const Tracer& obj);
    virtual ~Tracer();
private:
    std::string str;
};

#endif /* TRACER_H */

