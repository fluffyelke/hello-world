/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MyLink.cpp
 * Author: default
 * 
 * Created on June 29, 2018, 11:03 AM
 */

#include "MyLink.h"
#include <iostream>

namespace Containers {

    MyLink* MyLink::insert(MyLink* n) {

        if(n == nullptr) {
            return this;
        }
        if(this == nullptr) {
            return n;
        }
        

        n->succ = this;    //Next Link become p(p comes after n)
        if(prev) {
            prev->succ = n;
        }
        n->prev = prev;
        prev = n;
        return n;
    }
    MyLink* MyLink::add(MyLink* n) {
        
    }

    MyLink* MyLink::erase() {
        if(this == nullptr) {
            return nullptr;
        }
        if(succ) {
            succ->prev = prev;
        }
        if(prev) {
            prev->succ = succ;
        }
        return succ;
    }

//    MyLink* MyLink::advance(int n) const {
//        if(this == nullptr) {
//            return nullptr;
//        }
//        if(0 < n) {
//            while(n--) {
//                if(next == nullptr) {
//                    return nullptr;
//                }
//                previous = next;
//            }
//        }
//        else if(n < 0) {
//            while(n++) {
//                if(previous == nullptr) {
//                    return nullptr;
//                }
//                p = p->previous;
//            }
//        }
//        return p;
//    }

    MyLink* MyLink::advance(int n) const {

    }

    MyLink* MyLink::find(const std::string& s) {
        while(prev) {
            if(value == s) {
                return prev;
            }
            prev = succ;
        }
        return nullptr;
    }
    
}   

