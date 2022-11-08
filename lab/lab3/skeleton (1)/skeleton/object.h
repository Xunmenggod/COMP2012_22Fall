#ifndef OBJECT_H_
#define OBJECT_H_

const int _Max_Name_Length = 100;

struct Pair
{
public:
    int x;
    int y;
};

class Object
{
private:
    Pair *_size;
    Pair *_position;
    char *_name;

public:
    Object();
    ~Object();

    const Pair &getSize() const;
    const Pair &getPosition() const;
    const char *getName() const;

    void setSize(int x, int y);
    void setPosition(int x, int y);
    void setName(const char *name);

    void displayBasic() const;
};

#endif