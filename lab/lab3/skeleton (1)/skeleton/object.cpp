#include <iostream>
#include "object.h"

Object::Object()
{
    _size = new Pair;
    _position = new Pair;
    _name = new char[_Max_Name_Length];
    _name[0]='\0';
}

Object::~Object() // Task 3 - To Do
{
    delete _size;
    delete _position;
    delete[] _name;
}

const Pair& Object::getSize() const
{
    return *this->_size;
}

const Pair& Object::getPosition() const
{
    return *this->_position;
}

const char* Object::getName() const
{
    return this->_name;
}

void Object::setSize(int x, int y)
{
    _size->x = x;
    _size->y = y;
}

void Object::setPosition(int x, int y)
{
    _position->x = x;
    _position->y = y;
}

void Object::setName(const char*name)
{
    for(int i = 0;i<_Max_Name_Length; i++)
    {
        _name[i] = name[i];
        if(name[i]=='\0') break;
    }
}

void Object::displayBasic() const
{
    std::cout << "\n\tName: ["<<this->getName()<<"]"; 
    std::cout <<"\n\tPosition: ("<<this->getPosition().x << ", "<<this->getPosition().y<<")";
    std::cout <<"\n\tSize: (" << this->getSize().x << ", "<<this->getSize().y<<"). ";
}