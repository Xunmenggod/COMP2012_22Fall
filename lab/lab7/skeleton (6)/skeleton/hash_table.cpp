#include "hash_table.h"
#include <cmath>
#include <iostream>

int HashTable::hashFunction(const std::string &name, int base, int table_size) {
  int res = 0;
  for (unsigned int i = 0; i < name.size(); i++) {
    res = (base*res + name[i] - 'a') % table_size;
  }
  return res;
}

int HashTable::getNextHashTableSize(int now_hash_table_size) {
  int res = now_hash_table_size*2;
  bool is_prime = false;
  while (true) {
    is_prime = true;
    int sq = sqrt(res);
    for (int i = 2; i <= sq; i++) {
      if (res % i == 0) {
        is_prime = false;
        break;
      }
    }
    if (is_prime)
      break;
    res++;
  }
  return res;
}

HashTable::HashTable(int init_size, int maximum_probe_num,
                     ProbeMode probe_mode): hash_table_size_(init_size), maximum_probe_num_(maximum_probe_num), probe_mode_(probe_mode) 
{  // Task 1
  base_1_ = 37;
  base_2_ = 41;
  table_ = new HashCell[hash_table_size_];
  for (int i = 0; i < hash_table_size_; i++) {
    table_[i].state = HashCellState::Empty;
    table_[i].student = nullptr;
  }
  switch (probe_mode)
  {
    case ProbeMode::Linear:
      probe_func_ = [](int hash_value1, int hash_value2, int num_probe, int hash_table_size){
        int p = (hash_value1 + num_probe) % hash_table_size;
        std::cout << "Probing for the position: " << p << std::endl;
        return p;
      };
      break;
    case ProbeMode::Quadratic:
      probe_func_ = [](int hash_value1, int hash_value2, int num_probe, int hash_table_size){
        int p = hash_value1;
        p = (hash_value1 + num_probe * num_probe) % hash_table_size;
        std::cout << "Probing for the position: " << p << std::endl;
        return p;
      };
      break;
    case ProbeMode::DoubleHash:
      probe_func_ = [](int hash_value1, int hash_value2, int num_probe, int hash_table_size){
          int p = hash_value1;
          p = (hash_value1 + num_probe * hash_value2) % hash_table_size;
          std::cout << "Probing for the position: " << p << std::endl;
          return p;
      };
      break;
    default:
      break;
  }

}

HashTable::~HashTable() {  // Task 1
  // for (int i = 0; i < hash_table_size_; i++) {
  //   if (table_[i].state == HashCellState::Active)
  //     delete table_[i].student;
  // }
  delete[] table_;
}

bool HashTable::add(const std::string &name, int score) {  // Task 2 & 5
  int hash_value1 = hashFunction(name, base_1_, hash_table_size_);
  int hash_value2 = hashFunction(name, base_2_, hash_table_size_);
  if (probe_mode_ == ProbeMode::DoubleHash && hash_value2 == 0) 
    hash_value2 = 1; 

  for (int i = 0; i < maximum_probe_num_; i++) {
    // std::cout<<"probe print position: "<<1<<std::endl;
    int p = probe_func_(hash_value1, hash_value2, i, hash_table_size_);
    if (table_[p].state == HashCellState::Active) {
      if (name == table_[p].student->name())
        return false;
    }else{
      table_[p].state = HashCellState::Active;
      table_[p].student = new Student(name, score);
      return true;
    }
  }
  // return false; // will need to be further adjusted at task 5
  reHashUntilSuccess();
  return add(name, score);
}

int HashTable::search(const std::string &name) const {  // Task 3
  int hash_value1 = hashFunction(name, base_1_, hash_table_size_);
  int hash_value2 = hashFunction(name, base_2_, hash_table_size_);
  if (probe_mode_ == ProbeMode::DoubleHash)
    if (hash_value2 == 0)
      hash_value2 = 1;
  for (int i = 0; i < hash_table_size_; i++) {
    int p = probe_func_(hash_value1, hash_value2, i, hash_table_size_);
    if (table_[p].state == HashCellState::Deleted) 
      continue;
    else if (table_[p].state == HashCellState::Active) {
      // std::cout<<"whether two names are equal: "<<(name == table_[p].student->name())<<std::endl;
      if (name == table_[p].student->name()) 
        return table_[p].student->score();
      else
        continue;
    }else
      return -1;
  }
  return -1; // no cell store the student with the same name -> no this student
}

bool HashTable::remove(const std::string &name) {  // Task 4
    int hash_value1 = hashFunction(name, base_1_, hash_table_size_);
    int hash_value2 = hashFunction(name, base_2_, hash_table_size_);
    if (probe_mode_ == ProbeMode::DoubleHash && hash_value2 == 0)
      hash_value2 = 1;
    for (int i = 0; i < hash_table_size_; i++) {
      int p = probe_func_(hash_value1, hash_value2, i, hash_table_size_);
      if (table_[p].state == HashCellState::Active) {
        if (table_[p].student->name() == name) {
          delete table_[p].student;
          table_[p].student = nullptr;
          table_[p].state = HashCellState::Deleted;
          return true;
        }
      }else if (table_[p].state == HashCellState::Empty)
        return false;
      else
        continue;
    }
    return false;
}

void HashTable::reHashUntilSuccess() {
  int next_hash_table_size = getNextHashTableSize(hash_table_size_);
  while (true) {
    if (reHash(next_hash_table_size)) {
      return;
    }
    next_hash_table_size = getNextHashTableSize(next_hash_table_size);
  }
}

bool HashTable::reHash(int rehash_table_size) {  // Task 5
  // create new hash table
  HashCell* newTable = new HashCell[rehash_table_size];
  for (int i = 0; i < rehash_table_size; i++) {
    newTable[i].state = HashCellState::Empty;
    newTable[i].student = nullptr;
  }

  for (int i = 0; i < hash_table_size_; i++) {
    if (table_[i].state == HashCellState::Active) {
      int hash_value1 = hashFunction(table_[i].student->name(), base_1_, rehash_table_size);
      int hash_value2 = hashFunction(table_[i].student->name(), base_2_, rehash_table_size);
      if (probe_mode_ == ProbeMode::DoubleHash && hash_value2 == 0)
        hash_value2 = 1;
      int newIndex = 0;
      bool insertSuccess = 0;
      for (int j = 0; j < maximum_probe_num_; j++) {
        // std::cout<<"probe print position: "<<2<<std::endl;
        // std::cout<<"hash_value2: "<<hash_value2<<std::endl;
        newIndex = probe_func_(hash_value1, hash_value2, j, rehash_table_size);
        if (newTable[newIndex].state == HashCellState::Empty) {
          newTable[newIndex].state = HashCellState::Active;
          newTable[newIndex].student = new Student(*table_[i].student);
          insertSuccess = 1;
          break;
        }else
          continue;
      }
      if (!insertSuccess){
        delete[] newTable;
        return false;
      }
    }else if (table_[i].state == HashCellState::Deleted)
      continue;
  }
  delete[] table_;
  table_ = newTable; 
  hash_table_size_ = rehash_table_size;
  // std::cout<<"current size: "<<hash_table_size_<<std::endl;
  return true;
}

void HashTable::print() const {
  std::cout << "hash_table_size:" << hash_table_size_ << std::endl;
  for (int i = 0; i < hash_table_size_; i++) {
    std::cout << i << ": state = ";
    if (table_[i].state == HashCellState::Empty) {
      std::cout << "Empty" << std::endl;
    } 
    else if (table_[i].state == HashCellState::Deleted) {
      std::cout << "Deleted" << std::endl;
    } 
    else if (table_[i].state == HashCellState::Active) {
      std::cout << "Active ";
      std::cout << "Student = (" << table_[i].student->name() << ", "
                << table_[i].student->score() << ")" << std::endl;
    }
  }
}

