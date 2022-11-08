#include "kid.h"

#include <cstring>

Kid::Kid() : height_(0), gender_(Gender::Female), name_(nullptr), weight_(0) {}

Kid::Kid(int height, Gender gender, const char* name, int weight)
    : height_(height), gender_(gender), name_(nullptr), weight_(weight) {
  name_ = new char[strlen(name) + 1];
  strcpy(name_, name);
}

Kid::Kid(const Kid& other)
    : Kid(other.height(), other.gender(), other.name(), other.weight()) {}

Kid::~Kid() { delete[] name_; }

int Kid::height() const { return height_; }
Gender Kid::gender() const { return gender_; }
const char* Kid::name() const { return name_; }
int Kid::weight() const {return weight_;}

//self helper function to check name, if name1 < name2 return true else false
bool nameChekcing(const char* name1, const char* name2) {
  int n = strlen(name1), m = strlen(name2);
  
  if (n < m) { //condition 2
    for (int i = 0; i < n; i++) {
      if (name1[i] > name2[i])
        return false;
    }
    return true;
  }else{ // condition 1
    for (int i = 0; i < m; i++) {
      if (name1[i] >= name2[i])
        return false;
    }
    return true;
  }

}

bool Kid::operator<(const Kid& other) const {  // Task 1 - To Do
  // checking conditions
  if (height_ < other.height_)
    return true;
  else if(height_ > other.height_)
    return false;
  
  if (gender_ < other.gender_) // the enum deifinition shows female has lower number
    return true;
  else if(gender_ > other.gender_)
    return false;
  
  if (nameChekcing(name_, other.name_))
    return true;
  else{
    //std::cout<< "namechecking return false"<<std::endl;
    if ((strcmp(name_, other.name_) == 0) && (weight_ > other.weight_))
      return true;
    else
      return false;
  }

}

Kid& Kid::operator=(const Kid& other) {
  height_ = other.height();
  gender_ = other.gender();
  delete[] name_;
  name_ = new char[strlen(other.name()) + 1];
  strcpy(name_, other.name());
  weight_ = other.weight();
  return *this;
}

std::ostream& operator<<(std::ostream& os, const Kid& k) {
  os << "(Height:" << k.height();
  os << ", Gender:" << (k.gender() == Female ? "Female" : "Male");
  os << ", Name:" << k.name();
  os << ", weight:" << k.weight() << ")";
  return os;
}
