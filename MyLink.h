/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MyLink.h
 * Author: default
 *
 * Created on June 29, 2018, 11:03 AM
 */

#ifndef MYLINK_H
#define MYLINK_H

#include <string>

namespace Containers {
    class MyLink {
    public:
        std::string value;
        MyLink(const std::string& val, MyLink* p = nullptr, MyLink* s = nullptr)
            : value{val},
              prev{p},
              succ{s}{
            
        }
     
        MyLink* insert(MyLink* n);
        MyLink* add(MyLink* n);
        MyLink* erase();
        MyLink* find(const std::string& s);
        const MyLink* find(const std::string& s ) const;
        MyLink* advance(int n) const;
        
        MyLink* next() const {
            return succ;
        }
        MyLink* previous() const {
            return prev;
        }
        
    private:
        MyLink* prev;
        MyLink* succ;
    };
}

#endif /* MYLINK_H */

