#ifndef __KID_H__
#define __KID_H__

#include <iostream>
enum Gender {
  Female,
  Male
};

class Kid {
  public:
    Kid();
    Kid(int height, Gender gender, const char *name, int weight);
    Kid(const Kid &kid);
    ~Kid();

    // Operator functions
    bool operator<(const Kid& other) const;
    Kid& operator=(const Kid& other);

    int height() const;
    Gender gender() const;
    const char* name() const;
    int weight() const;

  private:
    int height_;
    Gender gender_;
    char* name_;
    int weight_;
};

std::ostream& operator<<(std::ostream& os, const Kid& t);

#endif
