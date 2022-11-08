#include <iostream>

#include "kid.h"
#include "sorted_sequence.h"

int main() {
  int testcase;
  std::cin >> testcase;

  if (testcase < 1 || testcase > 2) {
    std::cout << "test case should be 1 or 2! " << testcase << " found\n";
    return 0;
  }

  std::cout << "LAB 5: Template and operator overloading\n";

  if (testcase == 1) {
    {
      std::cout << "Test 1:" << std::endl;
      Kid k1(120, Gender::Male, "Bob", 30);
      Kid k2(119, Gender::Female, "Alice", 31);
      std::cout << "Is " << k1 << " has a higher priority than " << k2 << "?"
                << std::endl;
      if (k1 < k2)
        std::cout << "Yes." << std::endl;
      else
        std::cout << "No." << std::endl;
      std::cout << std::endl;
    }

    {
      std::cout << "Test 2:" << std::endl;
      Kid k1(119, Gender::Female, "Alice", 31);
      Kid k2(119, Gender::Male, "Bob", 30);
      std::cout << "Is " << k1 << " has a higher priority than " << k2 << "?"
                << std::endl;
      if (k1 < k2)
        std::cout << "Yes." << std::endl;
      else
        std::cout << "No." << std::endl;
      std::cout << std::endl;
    }

    {
      std::cout << "Test 3:" << std::endl;
      Kid k1(119, Gender::Male, "Tom", 31);
      Kid k2(119, Gender::Male, "Tommy", 30);
      std::cout << "Is " << k1 << " has a higher priority than " << k2 << "?"
                << std::endl;
      if (k1 < k2)
        std::cout << "Yes." << std::endl;
      else
        std::cout << "No." << std::endl;
      std::cout << std::endl;
    }

    {
      std::cout << "Test 4:" << std::endl;
      Kid k1(119, Gender::Male, "Tommy", 30);
      Kid k2(119, Gender::Male, "Alex", 30);
      std::cout << "Is " << k1 << " has a higher priority than " << k2 << "?"
                << std::endl;
      if (k1 < k2)
        std::cout << "Yes." << std::endl;
      else
        std::cout << "No." << std::endl;
      std::cout << std::endl;
    }

    {
      std::cout << "Test 5:" << std::endl;
      Kid k1(119, Gender::Male, "Tommy", 31);
      Kid k2(119, Gender::Male, "Tommy", 30);
      std::cout << "Is " << k1 << " has a higher priority than " << k2 << "?"
                << std::endl;
      if (k1 < k2)
        std::cout << "Yes." << std::endl;
      else
        std::cout << "No." << std::endl;
      std::cout << std::endl;
    }

    {
      std::cout << "Test 6:" << std::endl;
      Kid k1(119, Gender::Male, "Tommy", 30);
      Kid k2(119, Gender::Male, "Tommy", 30);
      std::cout << "Is " << k1 << " has a higher priority than " << k2 << "?"
                << std::endl;
      if (k1 < k2)
        std::cout << "Yes." << std::endl;
      else
        std::cout << "No." << std::endl;
      std::cout << std::endl;
    }
  } else if (testcase == 2) {
    {
      std::cout << "Test 1:" << std::endl;
      SortedSequence<int> s1;
      const int num = 8;
      int a[num] = {2, 4, 6, 100, 2, 1, 6, 4};
      std::cout << "Input data:" << std::endl;
      for (int i = 0; i < num; i++) {
        std::cout << a[i] << " ";
      }
      std::cout << std::endl;
      std::cout << "Output data:" << std::endl;
      for (int i = 0; i < num; i++) {
        std::cout << "After adding " << a[i]
                  << " to the sequence:" << std::endl;
        s1.add(a[i]);
        std::cout << s1 << std::endl;
        std::cout << std::endl;
      }
      std::cout << std::endl;
      std::cout << std::endl;
    }

    {
      std::cout << "Test 2:" << std::endl;
      SortedSequence<char> s1;
      const int num = 5;
      char a[num] = {'a', 'p', 'p', 'l', 'e'};
      std::cout << "Input data:" << std::endl;
      for (int i = 0; i < num; i++) {
        std::cout << a[i] << " ";
      }
      std::cout << std::endl;
      std::cout << "Output data:" << std::endl;
      for (int i = 0; i < num; i++) {
        std::cout << "After adding " << a[i]
                  << " to the sequence:" << std::endl;
        s1.add(a[i]);
        std::cout << s1 << std::endl;
        std::cout << std::endl;
      }
      std::cout << std::endl;
      std::cout << std::endl;
    }

    {
      std::cout << "Test 3:" << std::endl;
      SortedSequence<Kid> s1;
      const int num = 5;
      Kid a[num] = {Kid(120, Gender::Male, "Bob", 30),
                    Kid(119, Gender::Female, "Alice", 31),
                    Kid(119, Gender::Male, "Tom", 31),
                    Kid(119, Gender::Female, "Alice", 31),
                    Kid(119, Gender::Male, "Alice", 30)};
      std::cout << "Input data:" << std::endl;
      for (int i = 0; i < num; i++) {
        std::cout << a[i] << " ";
      }
      std::cout << std::endl;
      std::cout << "Output data:" << std::endl;
      for (int i = 0; i < num; i++) {
        std::cout << "After adding " << a[i]
                  << " to the sequence:" << std::endl;
        s1.add(a[i]);
        std::cout << s1 << std::endl;
        std::cout << std::endl;
      }
      std::cout << std::endl;
      std::cout << std::endl;
    }
  }
  return 0;
}