/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Drills.h
 * Author: default
 *
 * Created on July 25, 2018, 1:14 PM
 */

#ifndef DRILLS_H
#define DRILLS_H

#include <vector>
#include <string>

#include "utils/Number.h"

template<typename T>
struct S {
    private:
    T value;
    
    public:
    S(T val) 
        : value{val} {
    }
        
    T& getValue();
    const T& getValue() const;
    void setValue(T val);
    
    T& operator = (const T& obj);
};

template<typename T>
T& S<T>::getValue(){
    return value;
}
template<typename T>
const T& S<T>::getValue() const {
    return value;
}
template<typename T>
void S<T>::setValue(T val) {
    value = val;
}
template<typename T>
T& S<T>::operator =(const T& obj) {
    value = obj.value;
    return *this;
}

void testStructS() {
    S<int> intS(5);
//    intS = 25;
    S<int> intS2(19);
    intS = intS2;
    S<char> charS{'G'};
    S<double> doubleS{45.6};
    S<std::string> stringS{"This is S String"};
    
    std::vector<int> numbers = {5, 10, 15, 20, 25};
    S<std::vector<int>> vectorIntS{numbers};
    
    std::cout << intS.getValue() << std::endl;
    std::cout << charS.getValue() << std::endl;
    std::cout << doubleS.getValue() << std::endl;
    std::cout << stringS.getValue() << std::endl;
    
    for(int i = 0; i < 5; i++) {
        std::cout << vectorIntS.getValue()[i] << " ";
    }
    std::cout << std::endl;
}

struct ThrowError {
    ThrowError(const std::string errorMsg) {
        std::cout << errorMsg << std::endl;
    }
};

template<typename T>
void addVectorElements(std::vector<T>& v1, std::vector<T>& v2) {
    if(v1.size() != v2.size()) {
        throw ThrowError("Vectors are of different size");
    }
    for(int i = 0; i < v1.size(); i++) {
        v1[i] += v2[i]; 
    }
}

void testEx1() {
    std::vector<int> v1{10, 20, 30, 40, 50};
    std::vector<int> v2{1, 2, 3, 4, 5, 6};
    
    addVectorElements(v1, v2);
    for(int i = 0; i < 5; i++) {
        std::cout << v1.at(i) << std::endl;
    }
}

template<typename T, typename U, typename Sum>
Sum sumElements(std::vector<T>& vt, std::vector<U>& vu) {
    if(vt.size() != vu.size()) {
        throw ThrowError("Vector size is different!");
    }
    Sum sum = 0;
    try {
        for(int i = 0; i < vt.size(); i++) {
            sum += vt.at(i) * vu.at(i);
        }
    }
    catch(...) {
        std::cout << "Exception occured in summing elements" << std::endl;
        return -1;
    }
    return sum;
}
void testEx2() {
    std::vector<int> vt{5, 6, 7, 8, 9};
    std::vector<double> vd{1.15, 2.25, 3.35, 4.45, 5.55};
    
    int sum = sumElements<int, double, int>(vt, vd);
    std::cout << sum << std::endl;
}

void testNumberWithVector() {
    std::vector<Number<int>> v1;
    Number<int> n1{10};
    Number<int> n2{15};
    Number<int> n3{20};
    Number<int> n4{25};
    Number<int> n5{30};
    v1.push_back(n1);
    v1.push_back(n2);
    v1.push_back(n3);
    v1.push_back(n4);
    v1.push_back(n5);
    
    std::vector<Number<double>> v2;
    Number<double> nd1{1.5};
    Number<double> nd2{1.75};
    Number<double> nd3{2.15};
    Number<double> nd4{2.35};
    Number<double> nd5{2.5};
    v2.push_back(nd1);
    v2.push_back(nd2);
    v2.push_back(nd3);
    v2.push_back(nd4);
    v2.push_back(nd5);
    for(int i = 0; i < v2.size(); i++) {
        std::cout << v2.at(i) << " ";
    }
    std::cout << std::endl;
//    double sum = sumElements<Number<int>, Number<double>, double>(v1, v2);
//    std::cout << "Total sum: " << sum << std::endl;
}
#endif /* DRILLS_H */

