#ifndef CONTAINER_H_
#define CONTAINER_H_

#include "object.h"
#include "textbox.h"
#include "button.h"

const int MAX_OBJECT_NUM = 10;

class Container : public Object
{
private:
    int _num_object;
    Object *_objects[MAX_OBJECT_NUM];

public:
    Container();
    ~Container();

    void addObject(Object *object);

    void display() const;
};

#endif