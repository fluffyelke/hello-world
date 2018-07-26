/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MyPair.h
 * Author: default
 *
 * Created on July 25, 2018, 3:01 PM
 */

#ifndef MYPAIR_H
#define MYPAIR_H

#include <vector>


namespace Containers {
    template<typename K, typename V>
    class Pair {
        public:
            K key;
            V value;
            
            Pair(K k, V v) 
            : key{k}, value{v} {
            }
    };  //end of class Pair.
}   //end of namespace Containers

std::vector<Containers::Pair<std::string, int>> varTable;

template<typename K, typename V>
V getValue(K k) {
    try {
        for(const Containers::Pair<K, V>& v : varTable) {
            if(v.key == k) {
                return v.value;
            }
        }
    }
    catch(...) {
        std::cout << "Cant find the element.\n";
    }
} 

void testMyPair() {
    Containers::Pair<std::string, int> p1{"First", 1};
    Containers::Pair<std::string, int> p2{"Second", 2};
    Containers::Pair<std::string, int> p3{"Third", 3};
    varTable.push_back(p1);
    varTable.push_back(p2);
    varTable.push_back(p3);
    
    
    std::cout << getValue<std::string, int>("Third") << std::endl;
}
#endif /* MYPAIR_H */

