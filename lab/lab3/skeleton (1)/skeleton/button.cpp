#include <iostream>

#include "button.h"

Button::Button()
{
    _text = new char[MAX_BUTTON_LENGTH];
    _text[0] = '\0';
    _trigger = new char[MAX_BUTTON_LENGTH];
    _trigger[0] = '\0';
}

Button::~Button()
{
    std::cout<<"\nDestructing Button "<<this->getName();
    delete[] _text;
    delete[] _trigger;
}

const char *Button::getText() const
{
    return _text;
}

void Button::setText(const char *text)
{
    for (int i = 0; i < MAX_BUTTON_LENGTH; i++)
    {
        _text[i] = text[i];
        if (text[i] == '\0')
            break;
    }
}

void Button::setTrigger(const char *trigger)
{
    for (int i = 0; i < MAX_BUTTON_LENGTH; i++)
    {
        _trigger[i] = trigger[i];
        if (trigger[i] == '\0')
            break;
    }
}

void Button::ButtonPressReleased()
{
    std::cout << "Button " << this->getName() << " Pressed! " << _trigger << std::endl;
}

void Button::display() const // Task 1 - To Do
{
    //
    std::cout << "\nButton";
    this->displayBasic();
    std::cout <<"\n\t\t";
    std::cout <<"ButtonText=["<<this->getText()<<"]\n";
}