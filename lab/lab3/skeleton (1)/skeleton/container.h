#ifndef CONTAINER_H_
#define CONTAINER_H_

#include "object.h"
#include "textbox.h"
#include "button.h"

const int MAX_CONTAINER_NUM = 10;
const int MAX_TEXTBOX_NUM = 10;
const int MAX_BUTTON_NUM = 10;

class Container : public Object
{
private:
    Container *_containers[MAX_CONTAINER_NUM];
    TextBox *_textBoxes[MAX_TEXTBOX_NUM];
    Button *_buttons[MAX_BUTTON_NUM];
    int _num_container;
    int _num_textBox;
    int _num_button;

public:
    Container();
    ~Container();
    
    void addContainer(Container *container);
    void addTextBox(TextBox *textBox);
    void addButton(Button *button);

    void display() const;
};

#endif