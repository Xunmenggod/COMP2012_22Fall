#ifndef TEXTBOX_H_
#define TEXTBOX_H_

#include "object.h"

const int MAX_TEXTBOX_LENGTH = 1000;

class TextBox : public Object
{
private:
    char *_text;

public:
    TextBox();
    ~TextBox();

    const char *getText() const;
    void setText(const char *text);

    void display() const;
};

#endif