#include <iostream>
#include "textbox.h"

TextBox::TextBox()
{
    _text = new char[MAX_TEXTBOX_LENGTH];
}

TextBox::~TextBox() 
{
    std::cout<<"\nDestructing TextBox "<<this->getName();
    delete[] _text;
}

const char* TextBox::getText() const
{
    return _text;
}

void TextBox::setText(const char* text)
{
    for(int i=0;i<MAX_TEXTBOX_LENGTH; i++)
    {
        _text[i] = text[i];
        if (text[i] == '\0') break;
    }
}

void TextBox::display() const  
{
    std::cout << "\nTextBox";
    this->displayBasic();
    std::cout <<"\n\t\t";
    std::cout <<"TextBoxText=["<<this->getText()<<"]\n";
}