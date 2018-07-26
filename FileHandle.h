/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FileHandle.h
 * Author: default
 *
 * Created on July 26, 2018, 2:19 PM
 */

#ifndef FILEHANDLE_H
#define FILEHANDLE_H

#include <fstream>


class FileHandle {
public:
    FileHandle(const std::string& readFrom);
    FileHandle(const FileHandle& orig);
    virtual ~FileHandle();
    
    void printFile();
private:
    std::ifstream file;
};

#endif /* FILEHANDLE_H */

