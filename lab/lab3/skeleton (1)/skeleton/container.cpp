#include "container.h"
#include <iostream>

Container::Container()
{
    for (int i = 0; i < MAX_CONTAINER_NUM; i++)
        _containers[i] = nullptr;
    for (int i = 0; i < MAX_TEXTBOX_NUM; i++)
        _textBoxes[i] = nullptr;
    for (int i = 0; i < MAX_BUTTON_NUM; i++)
        _buttons[i] = nullptr;

    _num_container = 0;
    _num_textBox = 0;
    _num_button = 0;
}

Container::~Container()
{
    std::cout<<"\nDestructing Container "<<this->getName();
    for (int i = 0; i < _num_container; i++)
        if ( _containers[i] != nullptr)
            delete _containers[i];
    for (int i = 0; i < _num_textBox; i++)
        if (_textBoxes[i] != nullptr)
            delete _textBoxes[i];
    for (int i = 0; i < _num_button; i++)
        if (_buttons[i] != nullptr)
            delete _buttons[i];
}

void Container::addContainer(Container *container)
{
    if (_num_container < MAX_CONTAINER_NUM)
        _containers[_num_container++] = container;
}

void Container::addTextBox(TextBox *textBox)
{
    if (_num_textBox < MAX_TEXTBOX_NUM)
        _textBoxes[_num_textBox++] = textBox;
}

void Container::addButton(Button *button)
{
    if (_num_button < MAX_BUTTON_NUM)
        _buttons[_num_button++] = button;
}

void Container::display() const // Task 2 - To Do
{
    std::cout << "\nContainer";
    this->displayBasic();
    std::cout <<"\n\t\t";
    if (_num_container>0)
        std::cout<<"#containers: "<<_num_container<<" | ";
    if (_num_textBox >0)
        std::cout<<"#textBoxes: "<<_num_textBox<<" | ";
    if (_num_button > 0)
        std::cout <<"#buttons: "<<_num_button<<" | ";
    std::cout << "\n";

    // Write your code here
    if (_num_container > 0) {
        for (int n = 0; n < _num_container; n++)
            _containers[n]->display();
    }
    
    for (int i = 0; i < _num_textBox; i++)
        _textBoxes[i]->display();
    for (int i = 0; i < _num_button; i++)
        _buttons[i]->display();
}