#ifndef OBJECT_H_
#define OBJECT_H_

using namespace std;

const int MAX_NAME_LENGTH = 100;

struct Pair
{
public:
    int x;
    int y;
};

const Pair SCREEN_RESOLUTION = {1920, 1080};

class Object
{
private:
    Pair _size;
    Pair _position;
    char *_name;
    Object *_parent;

public:
    Object();
    virtual ~Object();

    const Pair getSize() const;
    const Pair getPosition() const;
    const char *getName() const;

    void setSize(int x, int y);
    void setPosition(int x, int y);
    void setName(const char *name);
    void setParent(Object *parent); 
    void displayBasic() const;

    virtual void display() const = 0;   
};


#endif