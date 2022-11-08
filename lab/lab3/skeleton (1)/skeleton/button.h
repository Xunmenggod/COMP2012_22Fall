#ifndef BUTTON_H_
#define BUTTON_H_

#include "object.h"

const int MAX_BUTTON_LENGTH = 100;

class Button : public Object
{
private:
    char *_text;
    char *_trigger;

public:
    Button();
    ~Button();

    const char *getText() const;
    void setText(const char *text);
    void setTrigger(const char *trigger);

    void ButtonPressReleased();

    void display() const;
};

#endif