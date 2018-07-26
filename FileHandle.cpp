/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FileHandle.cpp
 * Author: default
 * 
 * Created on July 26, 2018, 2:19 PM
 */

#include <iostream>

#include "FileHandle.h"

FileHandle::FileHandle(const std::string& readFrom) {
    try {
        file.open(readFrom);
        if(!file.is_open()) {
            throw;
        }
        std::cout << "File " << readFrom << " is open.\n";
    }
    catch(std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    catch(...) {
        std::cerr << "File: " << readFrom << " cannot be opened." << std::endl;
    }
}

FileHandle::FileHandle(const FileHandle& orig) {
}

FileHandle::~FileHandle() {
    std::cout << "File Closed" << std::endl;
    file.close(); 
}

void FileHandle::printFile() {
    std::cout << file.rdbuf();
}