#include <iostream>
#include "system.h"
#include "wait_list.h"
#include "swap_list.h"

using namespace std;

int main() {
    int test_case = 1;
    cout << "Enter testcase number: " << endl;
    cin >> test_case;

    cout << "Test Case: " << test_case << endl;
    
    switch(test_case) {
        case 1: // Admit one student
        {
            System* system = new System(20, 50);

            system->admit("Adam", 1000, 3.0);

            system->print_info();
            delete system;
        }
        break;
        
        case 2: // Add one course
        {
            System* system = new System(20, 50);

            system->add_course("COMP1000", 3, 10);

            system->print_info();
            delete system;
        }
        break;

        case 3: // Add multiple students
        {
            System* system = new System(20, 50);

            system->admit("Adam", 1000, 3.8);
            system->admit("Brian", 1001, 4.3);
            system->admit("Cindy", 1002, 4.3);
            system->admit("Desmond", 1003, 4.3);

            system->print_info();
            delete system;
        }
        break;
        
        case 4: // Add multiple courses
        {
            System* system = new System(20, 50);

            system->add_course("COMP1000", 3, 10);
            system->add_course("COMP1022P", 3, 50);
            system->add_course("ECON1000", 4, 50);
            system->add_course("MATH1003", 2, 10);
            system->add_course("LANG1002A", 3, 20);

            system->print_info();
            delete system;
        }
        break;

        case 5: // Student overload: failure because of not enough gpa.
        {
            System* system = new System(20, 50);

            system->admit("Adam", 1000, 3.0);
            bool success = system->apply_overload(1000, 30);
            if(success) {
                cout << "Apply Overload Successfully." << endl;
            } 
            else{
                cout << "Fail to overload." << endl;
            }
            system->print_info();
            delete system;
        }
        break;

        case 6: // Student overload: success
        {
            System* system = new System(20, 50);

            system->admit("Adam", 1000, 3.4);
            bool success = system->apply_overload(1000, 21);
            if(success) {
                cout << "Apply Overload Successfully." << endl;
            } 
            else{
                cout << "Fail to overload." << endl;
            }

            system->print_info();
            delete system;
        }
        break;

        case 7: // Simple add function
        {
            System* system = new System(20, 50);

            system->admit("Adam", 1000, 3.0);
            system->add_course("COMP2012", 4, 10);
            system->add(1000, "COMP2012");
            system->print_info();
            delete system;
        }
        break;

        case 8: // Multiple add function calls, reaching credit limit (Array: Insertion)
        {
            System* system = new System(20, 50);

            system->admit("Adam", 1000, 3.0);

            system->add_course("COMP2012", 4, 10);
            system->add_course("COMP1000", 3, 10);
            system->add_course("COMP1022P", 3, 50);
            system->add_course("ECON1000", 3, 50);
            system->add_course("MATH1003", 2, 10);
            system->add_course("LANG1002A", 3, 20);

            system->add(1000, "COMP2012");
            system->add(1000, "COMP1000");
            system->add(1000, "COMP1022P");
            system->add(1000, "ECON1000");
            system->add(1000, "MATH1003");
            system->add(1000, "LANG1002A");
            system->print_info();
            delete system;
        }
        break;

        case 9: // Same as case 8 but with deep copy
        {
            System* system = new System(20, 50);

            system->admit("Adam", 1000, 3.0);

            system->add_course("COMP2012", 4, 10);
            system->add_course("COMP1000", 3, 10);
            system->add_course("COMP1022P", 3, 50);
            system->add_course("ECON1000", 3, 50);
            system->add_course("MATH1003", 2, 10);
            system->add_course("LANG1002A", 3, 20);

            system->add(1000, "COMP2012");
            system->add(1000, "COMP1000");
            system->add(1000, "COMP1022P");
            system->add(1000, "ECON1000");
            system->add(1000, "MATH1003");
            system->add(1000, "LANG1002A");

            System* system2 = new System(*system);
            system2->print_info();
            delete system2;
            delete system;
        }
        break;

        case 10: // Multiple adds (Array: Insertion)
        {
            System* system = new System(20, 50);

            system->admit("Adam", 1000, 3.8);
            system->admit("Brian", 1001, 4.3);
            system->admit("Cindy", 1002, 4.3);
            system->admit("Desmond", 1003, 4.3);

            system->add_course("COMP2012", 4, 10);

            system->add(1000, "COMP2012");
            system->add(1001, "COMP2012");
            system->add(1002, "COMP2012");
            system->add(1003, "COMP2012");

            system->print_info();
            delete system;
        }
        break;

        case 11: // Simple drop 
        {
            System* system = new System(20, 50);

            system->admit("Adam", 1000, 3.8);
            system->add_course("COMP2012", 4, 3);

            system->add(1000, "COMP2012");
            system->print_info();

            system->drop(1000, "COMP2012");
            system->print_info();
            delete system;
        }
        break;

        case 12: // Multiple students enrolled in a course and no one is waiting, a student drops (Array Deletion)
        {
            System* system = new System(20, 50);

            system->admit("Adam", 1000, 3.8);
            system->admit("Brian", 1001, 4.3);
            system->admit("Cindy", 1002, 4.3);
            system->admit("Desmond", 1003, 4.3);
            system->admit("Harry", 1004, 2.0);
            system->admit("Ron", 1005, 2.0);
            system->admit("Hermione", 1006, 4.3);

            system->add_course("COMP2012", 4, 10); // Quota: 10

            system->add(1000, "COMP2012");
            system->add(1001, "COMP2012");
            system->add(1002, "COMP2012");
            system->add(1003, "COMP2012");
            system->add(1004, "COMP2012");
            system->add(1005, "COMP2012");
            system->add(1006, "COMP2012");

            system->drop(1004, "COMP2012");

            system->print_info();
            delete system;
        }
        break;

        case 13: // Multiple students waiting in the waitlist, and someone in the course drops (Wait List: deletion)
        {
            System* system = new System(20, 50);

            system->admit("Adam", 1000, 3.8);
            system->admit("Brian", 1001, 4.3);
            system->admit("Cindy", 1002, 4.3);
            system->admit("Desmond", 1003, 4.3);
            system->admit("Harry", 1004, 2.0);
            system->admit("Ron", 1005, 2.0);
            system->admit("Hermione", 1006, 4.3);

            system->add_course("COMP2012", 4, 3); // Quota: 3

            system->add(1000, "COMP2012");
            system->add(1001, "COMP2012");
            system->add(1002, "COMP2012");
            system->add(1003, "COMP2012");  // Student 1003 gets into the wait list of COMP2012
            system->add(1004, "COMP2012");  // Student 1004 gets into the wait list of COMP2012
            system->add(1005, "COMP2012");  // Student 1005 gets into the wait list of COMP2012
            system->add(1006, "COMP2012");  // Student 1006 gets into the wait list of COMP2012

            system->drop(1001, "COMP2012"); // Student 1001 drops, student 1003 should get into COMP2012

            system->print_info();
            delete system;
        }
        break;

        case 14: // Same as case 13 but with deep copy
        {
            System* system = new System(2, 10);

            system->admit("Adam", 1000, 3.8);
            system->admit("Brian", 1001, 4.3);
            system->admit("Cindy", 1002, 4.3);
            system->admit("Desmond", 1003, 4.3);
            system->admit("Harry", 1004, 2.0);
            system->admit("Ron", 1005, 2.0);
            system->admit("Hermione", 1006, 4.3);

            system->add_course("COMP2012", 4, 3); // Quota: 3

            system->add(1000, "COMP2012");
            system->add(1001, "COMP2012");
            system->add(1002, "COMP2012");
            system->add(1003, "COMP2012");  // Student 1003 gets into the wait list of COMP2012
            system->add(1004, "COMP2012");  // Student 1004 gets into the wait list of COMP2012
            system->add(1005, "COMP2012");  // Student 1005 gets into the wait list of COMP2012
            system->add(1006, "COMP2012");  // Student 1006 gets into the wait list of COMP2012

            system->drop(1001, "COMP2012"); // Student 1001 drops, student 1003 should get into COMP2012

            System* system2 = new System(*system);
            system2->print_info();
            delete system2;
            delete system;
        }
        break;

        case 15: // Simple swap
        {
            System* system = new System(20, 50);

            system->admit("Adam", 1000, 3.8);

            system->add_course("COMP2012", 4, 3);
            system->add_course("ECON1000", 3, 3);

            system->add(1000, "COMP2012");
            system->swap(1000, "COMP2012", "ECON1000");
            
            system->print_info();
            delete system;
        }
        break;

        case 16: // Deadlock example
        {
            System* system = new System(20, 50);

            system->admit("Harry", 1000, 2.0);
            system->admit("Ron", 1001, 2.0);

            system->add_course("MAGIC1000", 1, 1);
            system->add_course("MAGIC1001", 1, 1);

            system->add(1000, "MAGIC1000");
            system->add(1001, "MAGIC1001");

            system->swap(1000, "MAGIC1000", "MAGIC1001");
            system->swap(1001, "MAGIC1001", "MAGIC1000");

            system->print_info();
            delete system;
        }
        break;

        case 17: // A drop trigger a swap (Swap List: Deletion)
        {
            System* system = new System(20, 50);

            system->admit("Ivan", 1000, 2.0);
            system->admit("Desmond", 1001, 4.3);
            system->admit("Cindy", 1002, 4.3);
            system->admit("Cecia", 1003, 4.3);
            system->admit("Brian", 1004, 4.3);

            system->add_course("COMP1022P", 3, 2);
            system->add_course("MATH1000", 1, 2);

            system->add(1000, "COMP1022P");
            system->add(1001, "COMP1022P");
            system->add(1002, "MATH1000");
            system->add(1004, "MATH1000");
            system->add(1003, "MATH1000");
            system->add(1000, "MATH1000");
            system->print_info();

            system->swap(1002, "MATH1000", "COMP1022P");
            system->drop(1000, "COMP1022P");

            system->print_info();
            delete system;
        }
        break;

        case 18: // Add operation rejected under pending add (Worst Case Credit Control)
        {
            System* system = new System(20, 50);

            system->admit("Adam", 1000, 2.0);
            system->admit("Brian", 1001, 4.3);
            system->admit("Cindy", 1002, 4.3);
            system->admit("Desmond", 1003, 4.3);

            system->add_course("COMP1022P", 4, 2);
            system->add_course("MATH1000", 3, 2);
            system->add_course("ECON1000", 3, 2);
            system->add_course("A_VERY_HARD_COURSE", 10, 2);

            system->add(1000, "COMP1022P");
            system->add(1000, "A_VERY_HARD_COURSE");

            system->add(1001, "MATH1000");
            system->add(1002, "MATH1000");
            system->add(1000, "MATH1000"); // Student 1000 get into the wait list of MATH1000

            system->add(1000, "ECON1000"); // Student 1000 is rejected by the system

            system->print_info();
            delete system;
        }
        break;

        case 19: // Swap operation rejected under pending swap (Worst Case Credit Control)
        {
            System* system = new System(20, 50);

            system->admit("Adam", 1000, 2.0);
            system->admit("Brian", 1001, 4.3);
            system->admit("Cindy", 1002, 4.3);

            system->add_course("COMP1022P", 3, 2);
            system->add_course("MATH1000", 2, 2);
            system->add_course("A_VERY_HARD_COURSE", 10, 2);
            system->add_course("SOSC1960", 4, 2);
            system->add_course("COMP2012H", 5, 2);

            system->add(1000, "COMP1022P");
            system->add(1000, "A_VERY_HARD_COURSE");
            system->add(1000, "MATH1000");

            system->add(1001, "SOSC1960");
            system->add(1002, "SOSC1960");
            system->swap(1000, "MATH1000", "SOSC1960");   // Student 1000 get into the wait list of SOSC1960

            system->swap(1000, "COMP1022P", "COMP2012H"); // Student 1000 is rejected by the system

            system->print_info();
            delete system;
        }
        break;

        case 20: // Same as case 19 but with deep copy
        {
            System* system = new System(20, 50);

            system->admit("Adam", 1000, 2.0);
            system->admit("Brian", 1001, 4.3);
            system->admit("Cindy", 1002, 4.3);

            system->add_course("COMP1022P", 3, 2);
            system->add_course("MATH1000", 2, 2);
            system->add_course("A_VERY_HARD_COURSE", 10, 2);
            system->add_course("SOSC1960", 4, 2);
            system->add_course("COMP2012H", 5, 2);

            system->add(1000, "COMP1022P");
            system->add(1000, "A_VERY_HARD_COURSE");
            system->add(1000, "MATH1000");

            system->add(1001, "SOSC1960");
            system->add(1002, "SOSC1960");
            system->swap(1000, "MATH1000", "SOSC1960");   // Student 1000 get into the wait list of SOSC1960

            system->swap(1000, "COMP1022P", "COMP2012H"); // Student 1000 is rejected by the system

            System* system2 = new System(*system);
            system2->print_info();

            delete system2;
            delete system;
        }
        break;

        case 21: // [hidden] student overload: fail
        {
            System* system = new System(20, 50);

            system->admit("Adam", 1000, 3.6);
            bool success = system->apply_overload(1000, 27);
            if(success){
                cout << "Apply Overload Successfully." << endl;
            } 
            else{
                cout << "Fail to overload." << endl;
            }

            system->print_info();
            delete system;
        }
        break;

        case 22: // [hidden] multiple add function call, rejected add due to reaching maximum number of credits. (Worst Case Credit Control)
        {
            System* system = new System(20, 50);

            system->admit("Adam", 1000, 3.5);

            system->add_course("COMP2012", 18, 10);
            system->add_course("LANG1002A", 3, 20);

            system->add(1000, "COMP2012");
            system->add(1000, "LANG1002A"); //the student should be rejected by the system for this add

            system->print_info();
            delete system;
        }
        break;

        case 23: // [hidden] continuation of case 22, apply for overload this time.
        {
            System* system = new System(20, 50);

            system->admit("Adam", 1000, 3.5);

            system->add_course("COMP2012", 18, 10);
            system->add_course("LANG1002A", 3, 20);

            system->add(1000, "COMP2012");
            system->add(1000, "LANG1002A"); // The student should be rejected by the system for this add
            system->print_info();

            system->apply_overload(1000, 21);
            system->add(1000, "LANG1002A"); // The student can now get into the course.
            system->print_info();
            delete system;
        }
        break;

        case 24: // [hidden] multiple adds, a student joins a course's wait list (Wait List: insertion) 
        {
            System* system = new System(20, 50);

            system->admit("Adam", 1000, 3.8);
            system->admit("Brian", 1001, 4.3);
            system->admit("Cindy", 1002, 4.3);
            system->admit("Desmond", 1003, 4.3);

            system->add_course("COMP2012", 4, 3);

            system->add(1000, "COMP2012");
            system->add(1001, "COMP2012");
            system->add(1002, "COMP2012");
            system->add(1003, "COMP2012"); // Student 1003 gets into the wait list of COMP2012

            system->print_info();
            delete system;
        }
        break;

        case 25: // [hidden] multiple adds, multiple students join a course's wait list (Wait List: insertion)
        {
            System* system = new System(20, 50);

            system->admit("Adam", 1000, 3.8);
            system->admit("Brian", 1001, 4.3);
            system->admit("Cindy", 1002, 4.3);
            system->admit("Desmond", 1003, 4.3);
            system->admit("Harry", 1004, 2.0);
            system->admit("Ron", 1005, 2.0);
            system->admit("Hermione", 1006, 4.3);

            system->add_course("COMP2012", 4, 3); // Quota: 3

            system->add(1000, "COMP2012");
            system->add(1001, "COMP2012");
            system->add(1002, "COMP2012");
            system->add(1003, "COMP2012"); // Student 1003 gets into the wait list of COMP2012
            system->add(1004, "COMP2012"); // Student 1004 gets into the wait list of COMP2012
            system->add(1005, "COMP2012"); // Student 1005 gets into the wait list of COMP2012
            system->add(1006, "COMP2012"); // Student 1006 gets into the wait list of COMP2012
            system->print_info();
            delete system;
        }
        break;

        case 26: // [hidden] one swap operation but get into wait list. (Swap List: Insertion)
        {
            System* system = new System(20, 50);

            system->admit("Adam", 1000, 3.8);
            system->admit("Brian", 1001, 4.3);
            system->admit("Cindy", 1002, 4.3);
            system->admit("Desmond", 1003, 4.3);
            system->admit("Harry", 1004, 2.0);

            system->add_course("COMP2012", 4, 3);
            system->add_course("ECON1000", 3, 3);

            system->add(1000, "COMP2012");
            system->add(1001, "ECON1000");
            system->add(1002, "ECON1000");
            system->add(1003, "ECON1000");
            system->add(1004, "ECON1000"); //student 1004 get into wait list

            system->swap(1000, "COMP2012", "ECON1000"); //student 1000 get into wait list of ECON1000
            
            system->print_info();
            delete system;
        }
        break;

        case 27: // [hidden] multiple swap operations but some get into wait list. (Swap List: Insertion)
        {
            System* system = new System(20, 50);

            system->admit("Adam", 1000, 3.8);
            system->admit("Brian", 1001, 4.3);
            system->admit("Cindy", 1002, 4.3);
            system->admit("Desmond", 1003, 4.3);
            system->admit("Harry", 1004, 2.0);

            system->add_course("COMP2012", 4, 3);
            system->add_course("MATH1014", 3, 3);
            system->add_course("MECH1906", 3, 3);
            system->add_course("SOSC1960", 3, 3);
            system->add_course("ECON1000", 3, 3);
            system->add_course("BIEN1010", 3, 3);

            system->add(1000, "COMP2012");
            system->add(1000, "MATH1014");
            system->add(1000, "MECH1906");

            system->add(1001, "ECON1000");
            system->add(1002, "ECON1000");
            system->add(1003, "ECON1000");
            system->add(1004, "ECON1000"); // Student 1004 get into wait list of ECON1000

            system->add(1001, "SOSC1960");
            system->add(1002, "SOSC1960");
            system->add(1003, "SOSC1960");
            system->add(1004, "SOSC1960"); // Student 1004 get into wait list of SOSC1960

            system->add(1001, "BIEN1010");
            system->add(1002, "BIEN1010");
            system->add(1003, "BIEN1010");
            system->add(1004, "BIEN1010"); // Student 1004 get into wait list of BIEN1010

            system->swap(1000, "MATH1014", "SOSC1960"); // Student 1000 get into wait list of SOSC1960
            system->swap(1000, "COMP2012", "ECON1000"); // Student 1000 get into wait list of ECON1000
            system->swap(1000, "MECH1906", "BIEN1010"); // Student 1000 get into wait list of BIEN1010
            
            system->print_info();
            delete system;
        }
        break;
        
        case 28: // [hidden] Deep Copy of above case
        {
            System* system = new System(20, 50);

            system->admit("Adam", 1000, 3.8);
            system->admit("Brian", 1001, 4.3);
            system->admit("Cindy", 1002, 4.3);
            system->admit("Desmond", 1003, 4.3);
            system->admit("Harry", 1004, 2.0);

            system->add_course("COMP2012", 4, 3);
            system->add_course("MATH1014", 3, 3);
            system->add_course("MECH1906", 3, 3);
            system->add_course("SOSC1960", 3, 3);
            system->add_course("ECON1000", 3, 3);
            system->add_course("BIEN1010", 3, 3);

            system->add(1000, "COMP2012");
            system->add(1000, "MATH1014");
            system->add(1000, "MECH1906");

            system->add(1001, "ECON1000");
            system->add(1002, "ECON1000");
            system->add(1003, "ECON1000");
            system->add(1004, "ECON1000"); // Student 1004 get into wait list of ECON1000

            system->add(1001, "SOSC1960");
            system->add(1002, "SOSC1960");
            system->add(1003, "SOSC1960");
            system->add(1004, "SOSC1960"); // Student 1004 get into wait list of SOSC1960

            system->add(1001, "BIEN1010");
            system->add(1002, "BIEN1010");
            system->add(1003, "BIEN1010");
            system->add(1004, "BIEN1010"); // Student 1004 get into wait list of BIEN1010

            system->swap(1000, "MATH1014", "SOSC1960"); // Student 1000 get into wait list of SOSC1960
            system->swap(1000, "COMP2012", "ECON1000"); // Student 1000 get into wait list of ECON1000
            system->swap(1000, "MECH1906", "BIEN1010"); // Student 1000 get into wait list of BIEN1010
            System* system2 = new System(*system);

            system->print_info();
            system2->print_info();
            delete system2;
            delete system;
        }
        break;

        case 29: // [hidden] multiple swap operations but some get into wait list, then some students drops. (Swap List: Deletion)
        {
            System* system = new System(20, 50);

            system->admit("Adam", 1000, 3.8);
            system->admit("Brian", 1001, 4.3);
            system->admit("Cindy", 1002, 4.3);
            system->admit("Desmond", 1003, 4.3);
            system->admit("Harry", 1004, 2.0);

            // All courses with capacity 3 except BIEN1010 has 4 seats
            system->add_course("COMP2012", 4, 3);
            system->add_course("MATH1014", 3, 3);
            system->add_course("COMP3021", 3, 3);
            system->add_course("MECH1906", 3, 3);
            system->add_course("SOSC1960", 3, 3);
            system->add_course("ECON1000", 3, 3);
            system->add_course("CIVL1100", 3, 3);
            system->add_course("BIEN1010", 3, 4);

            system->add(1000, "COMP2012");
            system->add(1000, "MATH1014");
            system->add(1000, "COMP3021");
            system->add(1000, "MECH1906");

            system->add(1001, "ECON1000");
            system->add(1002, "ECON1000");
            system->add(1003, "ECON1000");
            system->add(1004, "ECON1000"); // Student 1004 get into wait list of ECON1000

            system->add(1001, "SOSC1960");
            system->add(1002, "SOSC1960");
            system->add(1003, "SOSC1960");
            system->add(1004, "SOSC1960"); // Student 1004 get into wait list of SOSC1960

            system->add(1001, "BIEN1010");
            system->add(1002, "BIEN1010");
            system->add(1003, "BIEN1010");
            system->add(1004, "BIEN1010");

            system->swap(1000, "MATH1014", "SOSC1960"); // Student 1000 get into wait list of SOSC1960
            system->swap(1000, "COMP3021", "CIVL1100"); // Student 1000 get into CIVL1100
            system->print_info();
            system->swap(1000, "COMP2012", "ECON1000"); // Student 1000 get into wait list of ECON1000
            system->swap(1000, "MECH1906", "BIEN1010"); // Student 1000 get into wait list of BIEN1010

            system->drop(1001, "BIEN1010"); // Student 1000 in waitlist now get into BIEN1010

            system->print_info();
            delete system;
        }
        break;

        case 30: // [hidden] add operation rejected under pending swap (Worst Case Credit Control)
        {
            System* system = new System(20, 50);

            system->admit("Adam", 1000, 2.0);
            system->admit("Brian", 1001, 4.3);
            system->admit("Cindy", 1002, 4.3);

            system->add_course("COMP1022P", 4, 2);
            system->add_course("MATH1000", 3, 2);
            system->add_course("ECON1000", 3, 2);
            system->add_course("A_VERY_HARD_COURSE", 10, 2);
            system->add_course("SOSC1960", 1, 2);

            system->add(1000, "COMP1022P");
            system->add(1000, "A_VERY_HARD_COURSE");
            system->add(1000, "MATH1000");

            system->add(1001, "SOSC1960");
            system->add(1002, "SOSC1960");
            system->swap(1000, "MATH1000", "SOSC1960"); // Student 1000 get into the wait list of SOSC1960.

            system->add(1000, "ECON1000"); // Student 1000 is rejected by the system

            system->print_info();
            delete system;
        }
        break;

        case 31: // [hidden] Intially in a waitlist through swap operation, 
        //fail to add a course, someone drops and get into the course, able to add back that course (Worst Case Credit Control)
        {
            System* system = new System(20, 50);

            system->admit("Adam", 1000, 2.0);
            system->admit("Brian", 1001, 4.3);
            system->admit("Cindy", 1002, 4.3);

            system->add_course("COMP1022P", 3, 2);
            system->add_course("MATH1000", 3, 2);
            system->add_course("A_VERY_HARD_COURSE", 10, 2);
            system->add_course("COMP1029C", 1, 2);
            system->add_course("COMP2012", 4, 2);

            system->add(1000, "COMP1022P");
            system->add(1000, "A_VERY_HARD_COURSE");
            system->add(1000, "MATH1000");

            system->add(1001, "COMP1029C");
            system->add(1002, "COMP1029C");
            system->swap(1000, "MATH1000", "COMP1029C"); // Student 1000 get into the wait list of COMP1029C.

            system->add(1000, "COMP2012"); // System reject the student request
            system->drop(1001, "COMP1029C"); // Student 1000 get into COMP1029C and drop MATH1000.

            system->add(1000, "COMP2012"); // System now approve the student request

            system->print_info();
            delete system;
        }
        break;

        case 32: // [hidden] Initially in a waitlist through add operation, 
        //fail to add a course, someone drops and get into the course, able to add a course (Worst Case Credit Control)
        {
            System* system = new System(20, 50);

            system->admit("Adam", 1000, 2.0);
            system->admit("Brian", 1001, 4.3);
            system->admit("Cindy", 1002, 4.3);

            system->add_course("COMP1022P", 3, 2);
            system->add_course("MATH1000", 3, 2);
            system->add_course("A_VERY_HARD_COURSE", 10, 2);
            system->add_course("COMP1029C", 1, 2);
            system->add_course("COMP1029V", 1, 2);

            system->add(1000, "COMP1022P"); 
            system->add(1000, "A_VERY_HARD_COURSE");
            system->add(1000, "MATH1000"); //student credit: 16

            system->add(1001, "COMP1029C");
            system->add(1002, "COMP1029C");
            system->add(1000, "COMP1029C"); // student 1000 get into the wait list of COMP1029C. Worst case credit: 17

            system->drop(1001, "COMP1029C"); // student 1000 get into COMP1029C

            system->add(1000, "COMP1029V"); // system approve the student request

            system->print_info();
            delete system;
        }
        break;

        case 33: // [hidden] A single drop trigger a chain of drops
        {
            System* system = new System(20, 50);

            system->admit("Adam", 1000, 2.0);
            system->admit("Brian", 1001, 4.3);
            system->admit("Cindy", 1002, 4.3);
            system->admit("Desmond", 1003, 4.3);
            system->admit("Eddy", 1004, 4.3);

            system->add_course("COMP1022P", 3, 1);
            system->add_course("MATH1000", 3, 1);
            system->add_course("ECON1000", 3, 1);
            system->add_course("COMP1029C", 3, 1);
            system->add_course("COMP1029V", 3, 1);

            system->add(1000, "COMP1022P");
            system->add(1001, "MATH1000");
            system->add(1002, "ECON1000");
            system->add(1003, "COMP1029C");
            system->add(1004, "COMP1029V");

            // All swaps are getting into wait list
            system->swap(1001, "MATH1000", "COMP1022P");
            system->swap(1002, "ECON1000", "MATH1000");
            system->swap(1003, "COMP1029C", "ECON1000");
            system->swap(1004, "COMP1029V", "COMP1029C");

            system->print_info();
            
            system->drop(1000, "COMP1022P"); // A chain of drops is triggered

            system->print_info();
            delete system;
        }
        break;

        case 34: // [hidden] multiple swaps for multiple students
        {
            System* system = new System(20, 50);

            system->admit("Adam", 1000, 3.8);
            system->admit("Brian", 1001, 4.3);
            system->admit("Cindy", 1002, 4.3);
            system->admit("Desmond", 1003, 4.3);

            system->add_course("COMP1022P", 3, 4);
            system->add_course("LANG1002A", 3, 4);
            system->add_course("SOSC1960", 3, 4);
            system->add_course("MATH1013", 3, 4);

            system->add(1000, "COMP1022P");
            system->add(1000, "LANG1002A");
            system->add(1000, "SOSC1960");
            system->add(1000, "MATH1013");

            system->add(1001, "COMP1022P");
            system->add(1001, "LANG1002A");

            system->add(1002, "COMP1022P");
            system->add(1002, "LANG1002A");

            system->add(1003, "COMP1022P");
            system->add(1003, "LANG1002A");

            system->swap(1001, "COMP1022P", "SOSC1960");
            system->swap(1002, "COMP1022P", "SOSC1960");
            system->swap(1003, "COMP1022P", "SOSC1960");

            system->swap(1001, "LANG1002A", "MATH1013");
            system->swap(1002, "LANG1002A", "MATH1013");
            system->swap(1003, "LANG1002A", "MATH1013");
            
            system->print_info();
            delete system;
        }
        break;

        case 35: // [hidden] A series of apply overloads
        {
            System* system = new System(20, 50);

            system->admit("Adam", 1000, 3.35);
            for(int i = 19; i < 30; ++i){
                bool success = system->apply_overload(1000, i);
                if(success) {
                    cout << "Apply Overload Successfully." << endl;
                } 
                else{
                    cout << "Fail to overload." << endl;
                }
            }

            system->print_info();
            delete system;
        }
        break;
        
        case 36: // [hidden] Deep Copy of Student and Courses
        {
            System* system = new System(20, 50);

            system->admit("Adam", 1000, 3.8);
            system->admit("Brian", 1001, 4.3);
            system->admit("Cindy", 1002, 4.3);
            system->admit("Desmond", 1003, 4.3);

            system->add_course("COMP1022P", 3, 3);
            system->add_course("MATH1013", 3, 5);
            system->add_course("LANG1002A", 3, 4);
            system->add_course("SOSC1960", 3, 3);

            system->add(1000, "COMP1022P");
            system->add(1000, "MATH1013");
            system->add(1000, "LANG1002A");

            system->add(1001, "COMP1022P");
            system->add(1003, "COMP1022P");

            system->add(1002, "MATH1013");
            system->add(1003, "MATH1013");

            system->add(1003, "LANG1002A");
            system->add(1001, "LANG1002A");

            system->add(1001, "SOSC1960");
            system->add(1002, "SOSC1960");

            System* system2 = new System(*system);
            
            system->print_info();
            system2->print_info();
            delete system2;
            delete system;
        }
        break;

        case 37: // [hidden] Wait List insertion and deletion, deep copy
        {
            System* system = new System(20, 50);

            system->admit("Adam", 1000, 2.0);
            system->admit("Brian", 1001, 4.3);
            system->admit("Cindy", 1002, 4.3);
            system->admit("Desmond", 1003, 4.3);
            system->admit("Eddy", 1004, 4.3);
            system->admit("Fred", 1005, 2.0);

            system->add_course("COMP1022P", 3, 2);

            system->add(1000, "COMP1022P");
            system->add(1001, "COMP1022P");
            system->add(1002, "COMP1022P");
            system->add(1003, "COMP1022P");
            system->add(1004, "COMP1022P");
            system->add(1005, "COMP1022P");

            System* system2 = new System(*system);

            system->drop(1000, "COMP1022P");
            system->drop(1001, "COMP1022P");
            system->drop(1002, "COMP1022P");
            system->drop(1003, "COMP1022P");
            system->drop(1004, "COMP1022P");
            system->drop(1005, "COMP1022P");

            system->print_info();
            system2->print_info();
            delete system2;
            delete system;
        }
        break;

        case 38: // [hidden] A series of adds and drops
        {
            System* system = new System(20, 50);

            system->admit("Adam", 1000, 3.8);
            system->admit("Brian", 1001, 4.3);
            system->admit("Cindy", 1002, 4.3);
            system->admit("Desmond", 1003, 4.3);

            system->add_course("COMP1022P", 3, 4);
            system->add_course("LANG1002A", 3, 4);
            system->add_course("SOSC1960", 3, 3);

            system->add(1001, "COMP1022P");
            system->add(1002, "COMP1022P");
            system->add(1002, "SOSC1960");
            system->add(1003, "COMP1022P");
            system->add(1000, "COMP1022P");
            system->drop(1001, "COMP1022P");
            system->drop(1002, "COMP1022P");

            system->add(1003, "SOSC1960");
            system->drop(1003, "SOSC1960");
            system->add(1000, "SOSC1960");
            system->add(1002, "LANG1002A");

            system->print_info();
            delete system;
        }
        break;

        case 39: // [hidden] Iterations of Add and Drop
        {
            System* system = new System(20, 50);

            system->admit("Adam", 1000, 3.0);
            system->add_course("COMP2012", 4, 10);

            for(int i = 0; i < 20; ++i){
                system->add(1000, "COMP2012");
                system->drop(1000, "COMP2012");
            }
            
            system->print_info();
            delete system;
        }
        break;

        case 40: // [hidden] Iterations of Add and Drop and Swap
        {
            System* system = new System(20, 50);

            system->admit("Adam", 1000, 3.0);
            system->add_course("COMP2012", 4, 10);
            system->add_course("COMP2611", 4, 10);

            for(int i = 0; i < 30; ++i){
                system->add(1000, "COMP2012");
                system->swap(1000, "COMP2012", "COMP2611");
                system->drop(1000, "COMP2611");
            }
            
            system->print_info();
            delete system;
        }
        break;

        case 41: // [hidden] Destructor of Swap_List, Swap
        {
            const char* course_list[20] = {
                "COMP1022P", "MATH2033",
                "COMP1029C", "ECON1013",
                "COMP1029V", "PPOL2110",
                "COMP1029P", "ECON3113",
                "COMP1029A", "MATH3033",
                "COMP2011", "MATH2343",
                "COMP2012", "MATH4114",
                "COMP2611", "MATH3423",
                "COMP3511", "MATH3424",
                "COMP3711", "MATH3425"
            };
            Swap_List* list = new Swap_List();
            list->set_head(new Swap("EASY_COURSE", "DIFFICULT_COURSE", nullptr)); 
            Swap* temp = list->get_head();
            for(int i = 0; i < 10; ++i){
                temp->next = new Swap(course_list[2*i], course_list[2*i+1], nullptr);
                temp = temp->next;
            }
            list->print_list();
            delete list;
        }
        break;

        case 42: // [hidden] Copy Constructor of Swap_List
        {
            const char* course_list[20] = {
                "COMP1022P", "MATH2033",
                "COMP1029C", "ECON1013",
                "COMP1029V", "PPOL2110",
                "COMP1029P", "ECON3113",
                "COMP1029A", "MATH3033",
                "COMP2011", "MATH2343",
                "COMP2012", "MATH4114",
                "COMP2611", "MATH3423",
                "COMP3511", "MATH3424",
                "COMP3711", "MATH3425"
            };
            Swap_List* list = new Swap_List();
            list->set_head(new Swap("EASY_COURSE", "DIFFICULT_COURSE", nullptr)); 
            Swap* temp = list->get_head();
            for(int i = 0; i < 10; ++i){
                temp->next = new Swap(course_list[2*i], course_list[2*i+1], nullptr);
                temp = temp->next;
            }
            Swap_List* list2 = new Swap_List(*list);
            Swap* delete_head = list->get_head();

            if(delete_head){
                list->set_head(delete_head->next);
            }
            
            delete delete_head; // Deletion of the head of list should not affect list2
            
            cout << "\nPrint list: " << endl;
            list->print_list();

            cout << "\nPrint list2: " << endl;
            list2->print_list();

            delete list2;
            delete list;
        }
        break;

        case 43: // [hidden] Destructor of Wait_List, Student_ListNode
        {
            Wait_List* list = new Wait_List();
            list->set_head(new Student_ListNode(1000, nullptr)); 
            Student_ListNode* temp = list->get_head();
            for(int i = 1; i <= 10; ++i){
                temp->next = new Student_ListNode(1000+i, nullptr);
                temp = temp->next;
            }
            list->print_list();

            delete list;
        }
        break;

        case 44: // [hidden] Copy Constructor of Wait_List, Student_ListNode
        {
            Wait_List* list = new Wait_List();
            list->set_head(new Student_ListNode(1000, nullptr));
            Student_ListNode* temp = list->get_head();
            for(int i = 1; i <= 10; ++i){
                temp->next = new Student_ListNode(1000+i, nullptr);
                temp = temp->next;
            }
            Wait_List* list2 = new Wait_List(*list);
            Student_ListNode* delete_head = list->get_head();
            if(delete_head){
                list->set_head(delete_head->next);
            }
            delete delete_head; // Deletion of the head of list should not affect list2

            cout << "\nPrint list: " << endl;
            list->print_list();

            cout << "\nPrint list2: " << endl;
            list2->print_list();

            delete list2;
            delete list;
        }
        break;

        default:
            cout << "NO SUCH TESTCASE!!!" << endl;
        
    }
    return 0;
}