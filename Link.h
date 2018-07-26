/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Link.h
 * Author: default
 *
 * Created on June 29, 2018, 10:24 AM
 */

#ifndef LINK_H
#define LINK_H

#include <string>

namespace Test {
    struct Link {
        std::string value;

        Link* previous;
        Link* next;

        Link(const std::string& val, Link* p = nullptr, Link* n = nullptr)
            : value{val},
              previous{p},
              next{n}{

        }

        Link* insert(Link* p, Link* n) {

            if(p == nullptr) {
                return n;
            }
            if(n == nullptr) {
                return p;
            }

            n->next = p;    //Next Link become p(p comes after n)
            if(p->previous) {
                p->previous->next = n;
            }
            n->previous = p->previous;
            p->previous = n;
            return n;
        }

        Link* add(Link* p, Link* n) {

        }

        Link* erase(Link* p) {
            if(p == nullptr) {
                return nullptr;
            }
            if(p->next) {
                p->next->previous = p->previous;
            }
            if(p->previous) {
                p->previous->next = p->next;
            }
            return p->next;
        }

        Link* find(Link* p, const std::string& s) {
            while(p) {
                if(p->value == s) {
                    return p;
                }
                p = p->next;
            }
            return nullptr;
        }

        Link* advance(Link* p, int n) {
            if(p == nullptr) {
                return nullptr;
            }
            if(0 < n) {
                while(n--) {
                    if(p->next == nullptr) {
                        return nullptr;
                    }
                    p = p->next;
                }
            }
            else if(n < 0) {
                while(n++) {
                    if(p->previous == nullptr) {
                        return nullptr;
                    }
                    p = p->previous;
                }
            }
            return p;
        }
    };
}

#endif /* LINK_H */

