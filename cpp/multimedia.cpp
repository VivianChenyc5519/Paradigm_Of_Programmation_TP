#include "multimedia.h"
#include <string>
#include <iostream>

Multimedia::Multimedia(std::string name, std::string filepath)
{
    this->name = name;
    this->filepath = filepath;
}

Multimedia::~Multimedia(){}
    
std::string Multimedia::getName() const
{
    return name;
}

void Multimedia::setName(std::string name)
{
    this->name = name;
}

std::string Multimedia::getFilepath() const
{
    return filepath;
}

void Multimedia::setFilepath(std::string filepath)
{
    this->filepath = filepath;
}


