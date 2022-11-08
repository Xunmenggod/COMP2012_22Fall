#ifndef __SORTED_SEQUENCE__
#define __SORTED_SEQUENCE__

#include <iostream>
#include <sstream>
#include <string>

template <typename T>
class SortedSequence{
  public:
    SortedSequence() : capacity_(0), size_(0), data_(nullptr) {}
    ~SortedSequence() { delete[] data_; }

    void add(const T &a) {  // Task 2 - To Do
      
      if ((size_ + 1) > capacity_){ // memory allocation
        if (data_ == nullptr) {
          data_ = new T(a);
          capacity_ = 1;
          size_ = 1;
          return ;
        }else{
          T* oldData = data_;
          data_ = new T[2 * capacity_];
          for (int i = 0; i < size_; i++)
            data_[i] = oldData[i];
          if (size_ == 1)
            delete oldData;
          else
            delete[] oldData;
          capacity_ *= 2;
        }
      }

      // memory inserrion
      if (!(a < data_[size_ - 1]))
        data_[size_] = a;
      else{
        int index = 0;
        for (int i = 0; i < size_; i++){
          if (!(data_[i] < a)) {
            index = i;
            break;
          }
        }
        for (int i = size_ - 1; i >= index; i--)
          data_[i + 1] = data_[i];
        data_[index] = a;
      }
      size_++;

    }

    std::string toString() const {
      std::stringstream ss;
      ss << "capacity: " << capacity_ << ", size: " << size_
        << ", data: " << std::endl;
      if (data_ == nullptr) {
        ss << "None";
      } else {
        for (int i = 0; i < size_; i++) {
          ss << data_[i] << " ";
        }
      }
      return ss.str();
    }

  private:
    int capacity_;
    int size_;
    T *data_;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const SortedSequence<T>& t) {
  os << t.toString();
  return os;
}

#endif 