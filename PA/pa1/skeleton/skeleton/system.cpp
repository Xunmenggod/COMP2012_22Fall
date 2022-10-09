#include <iostream>
#include <cstring>
#include "system.h"
#include "student.h"
#include "course.h"
#include "course_database.h"
#include "student_database.h"
#include "wait_list.h"
#include "swap_list.h"

using namespace std;

/*
The following 3 helper functions may be useful in add/swap/drop function. You may implement them if you find them useful.
If not, you can remove these 3 helper functions as we will NOT set any test case testing these helper functions.
*/

// Helper function: add the Student to the end of the waitlist of the Course.
void join_waitlist(const int student_id, Course* course) {
    // TODO
}

// Helper function: find the index of a course within the enrolled course list of a student.
int search_course_index(const Student* const student, const char* const course_name) {
    // TODO
}

// Helper function: find the index of the student_id in the enrolled student list
int search_student_id(const int student_id, const Course* const course) {
    // TODO
}


System::System(const int max_num_course, const int max_num_student) {
    course_database = new Course_Database(max_num_course);
    student_database = new Student_Database(max_num_student);
}

System::System(const System& system) {
    this->course_database = new Course_Database(*system.course_database);
    this->student_database = new Student_Database(*system.student_database);
}

System::~System() {
    delete course_database;
    delete student_database;
}

void System::admit(const char* const name, const int student_id, const double gpa) {
    this->student_database->create_entry(name, student_id, gpa);
}

bool System::apply_overload(const int student_id, const int request_credit) {
    // TODO
    if (request_credit > 30)
        return false;

    Student* applicant = student_database->get_student_by_id(student_id);
    if (request_credit > 18 && applicant->get_gpa() >= 3.3) {
        applicant->set_max_credit(request_credit);
        return true;
    }
    else if(request_credit > 24 && applicant->get_gpa() >= 3.7) {
        applicant->set_max_credit(request_credit);
        return true;
    }
    else
        return false;
}

bool System::add(const int student_id, const char* const course_name) {
    // TODO
    Student* requester = student_database->get_student_by_id(student_id);
    Course* reqeusted_course = course_database->get_course_by_name(course_name);
    if ((requester->get_curr_credit() + requester->get_pending_credit() + reqeusted_course->get_num_credit()) > requester->get_max_credit())
        return false;

    if (reqeusted_course->get_size() < reqeusted_course->get_capacity()) {
        char** enrolled_courses = requester->get_enrolled_courses();
        enrolled_courses[requester->get_num_enrolled_course()] = new char[strlen(course_name) + 1];
        strcpy(enrolled_courses[requester->get_num_enrolled_course()], course_name);
        requester->set_enrolled_courses(enrolled_courses);
        requester->set_curr_credit(requester->get_curr_credit() + reqeusted_course->get_num_credit());
        requester->set_num_enrolled_course(requester->get_num_enrolled_course() + 1);

        int* student_enrolled = reqeusted_course->get_students_enrolled();
        student_enrolled[reqeusted_course->get_size()] = student_id;
        reqeusted_course->set_students_enrolled(student_enrolled);
        reqeusted_course->set_size(reqeusted_course->get_size() + 1);
    }else
    {
        requester->set_pending_credit(requester->get_pending_credit() + reqeusted_course->get_num_credit());
        Wait_List* wait_list = reqeusted_course->get_wait_list();
        Student_ListNode* head = wait_list->get_head();
        Student_ListNode* end = wait_list->get_end();
        if(head == nullptr && end == nullptr) {
            head = new Student_ListNode(student_id, nullptr);
            end = head;
        }else{
            end->next = new Student_ListNode(student_id, nullptr);
            end = end->next;
        }
        wait_list->set_head(head);
        wait_list->set_end(end);
    }
    return true;
}

bool System::swap(const int student_id, const char* const original_course_name, const char* const target_course_name) {
    // TODO
    Course* original_course = course_database->get_course_by_name(original_course_name);
    Course* target_course = course_database->get_course_by_name(target_course_name);
    Student* requester = student_database->get_student_by_id(student_id);

    int potential_swap_pending_credit = 0;
    if ((target_course->get_num_credit() - original_course->get_num_credit()) > 0)
        potential_swap_pending_credit = target_course->get_num_credit() - original_course->get_num_credit();
    if ((requester->get_curr_credit() + requester->get_pending_credit() + potential_swap_pending_credit) > requester->get_max_credit())
        return false;

    if (target_course->get_size() < target_course->get_capacity()) {
        //enroll target course
        requester->set_curr_credit(requester->get_curr_credit() + target_course->get_num_credit());
        char** enrolled_courses = requester->get_enrolled_courses();
        enrolled_courses[requester->get_num_enrolled_course()] = new char[strlen(target_course_name) + 1];
        strcpy(enrolled_courses[requester->get_num_enrolled_course()], target_course_name);
        requester->set_enrolled_courses(enrolled_courses);
        requester->set_num_enrolled_course(requester->get_num_enrolled_course() + 1);
        int* student_enrolled = target_course->get_students_enrolled();
        student_enrolled[target_course->get_size()] = student_id;
        target_course->set_students_enrolled(student_enrolled);
        target_course->set_size(target_course->get_size() + 1);

        //drop original course
        drop(student_id, original_course_name);
    }else{ // no vacancy add the request to the swap list
        requester->set_pending_credit(requester->get_pending_credit() + potential_swap_pending_credit);
        // add the student to waitlist
        Wait_List* wait_list = target_course->get_wait_list();
        Student_ListNode* head = wait_list->get_head();
        Student_ListNode* end = wait_list->get_end();
        if(head == nullptr && end == nullptr) {
            head = new Student_ListNode(student_id, nullptr);
            end = head;
        }else{
            end->next = new Student_ListNode(student_id, nullptr);
            end = end->next;
        }
        wait_list->set_head(head);
        wait_list->set_end(end);

        // update the swap list of the student class
        Swap_List* swap_list = requester->get_swap_list();
        Swap* swap_head = swap_list->get_head();
        if (!swap_head) {
            swap_head = new Swap(original_course_name, target_course_name, nullptr);
        }else{
            swap_head = new Swap(original_course_name, target_course_name, swap_head);
        }
        swap_list->set_head(swap_head);
    }
    return true;
}

void System::drop(const int student_id, const char* const course_name) {
    // TODO
    Student* requester = student_database->get_student_by_id(student_id);
    Course* dropped_course = course_database->get_course_by_name(course_name);

    // drop course for the student
    char** enrolled_courses = requester->get_enrolled_courses();
    int course_index = 0;
    for (int i = 0; i < requester->get_num_enrolled_course(); i++) {
        if (strcmp(enrolled_courses[i], course_name) == 0)
            course_index = i;
    }
    delete[] enrolled_courses[course_index];
    enrolled_courses[course_index] = enrolled_courses[requester->get_num_enrolled_course()];
    enrolled_courses[requester->get_num_enrolled_course()] = nullptr;
    requester->set_num_enrolled_course(requester->get_num_enrolled_course() - 1);
    requester->set_curr_credit(requester->get_curr_credit() - dropped_course->get_num_credit());
    // update the course class data member
    int* enrolled_students = dropped_course->get_students_enrolled();
    int student_index = 0;
    for (int i = 0; i < dropped_course->get_size(); i++) {
        if (enrolled_students[i] == student_id)
            student_index = i;
    }

    // if wait list is not empty
    Wait_List* wait_list = dropped_course->get_wait_list();
    Student_ListNode* wait_head = wait_list->get_head();
    Student_ListNode* wait_end = wait_list->get_end();
    if (wait_head) {
        // update class member for nwely enrolled student
        Student* new_enrolled_student = student_database->get_student_by_id(wait_head->student_id);
        new_enrolled_student->set_curr_credit(new_enrolled_student->get_curr_credit() + dropped_course->get_num_credit());
        char** new_enrolled_courses = new_enrolled_student->get_enrolled_courses();
        new_enrolled_courses[new_enrolled_student->get_num_enrolled_course()] = new char[strlen(course_name) + 1];
        strcpy(new_enrolled_courses[new_enrolled_student->get_num_enrolled_course()], course_name);
        new_enrolled_student->set_enrolled_courses(new_enrolled_courses);
        new_enrolled_student->set_num_enrolled_course(new_enrolled_student->get_num_enrolled_course() + 1);

        // update class member for dropped course
        enrolled_students[student_index] = new_enrolled_student->get_student_id();
        dropped_course->set_students_enrolled(enrolled_students);
        // dropped_course->set_size(dropped_course->get_size() + 1);
        if (wait_head == wait_end) {
            delete wait_head;
            wait_list->set_head(nullptr);
            wait_list->set_end(nullptr);
            dropped_course->set_wait_list(wait_list);
        }else{
            Student_ListNode* temp = wait_head;
            wait_head = wait_head->next;
            delete temp;
            wait_list->set_head(wait_head);
            dropped_course->set_wait_list(wait_list);
        }

        // check whether the newly enrolled student is through add/swap opeartion
        bool add_or_swap = 0; // add->0; swap->1
        Swap_List* swap_list = new_enrolled_student->get_swap_list();
        Swap* swap_head = swap_list->get_head();
        Swap* curr_swap_node = swap_head;
        while(curr_swap_node) {
            if (strcmp(course_name, curr_swap_node->target_course_name) == 0) {
                add_or_swap = 1;
                break;
            }
            curr_swap_node = curr_swap_node->next;
        }
        if (add_or_swap) {
            //check whether the swap will change the pending credit
            int credit_difference = 0;
            Course* original_course = course_database->get_course_by_name(curr_swap_node->original_course_name);
            if (original_course->get_num_credit() < dropped_course->get_num_credit())
                credit_difference = dropped_course->get_num_credit() - original_course->get_num_credit();
            new_enrolled_student->set_pending_credit(new_enrolled_student->get_pending_credit() - credit_difference);

            // recursive call to get the chain reaction of drop operation
            drop(new_enrolled_student->get_student_id(), curr_swap_node->original_course_name);
            //delete the swap
            if (curr_swap_node == swap_head) {
                if (swap_head->next == nullptr) {
                    delete swap_head;
                    swap_head = nullptr;
                }else{
                    Swap* temp = swap_head;
                    swap_head = swap_head->next;
                    delete temp;
                }
            }else{
                Swap* temp = curr_swap_node;
                curr_swap_node = swap_head;
                while(curr_swap_node) {
                    if (curr_swap_node->next == temp) 
                        break;
                }
                curr_swap_node->next = temp->next;
                delete temp;
            }
            // update
            swap_list->set_head(swap_head);
        }else
            new_enrolled_student->set_pending_credit(new_enrolled_student->get_pending_credit() - dropped_course->get_num_credit());
    }else{
        enrolled_students[student_index] = enrolled_students[dropped_course->get_size() - 1];
        enrolled_students[dropped_course->get_size()] = 0;
        dropped_course->set_students_enrolled(enrolled_students);
        dropped_course->set_size(dropped_course->get_size() - 1);
    }
}

void System::add_course(const char* const name, const int num_credit, const int course_capacity) {
    this->course_database->create_entry(name, num_credit, course_capacity);
}

void System::print_info() const {
    this->course_database->print_all_course();
    this->student_database->print_all_students();
}

Course_Database* System::get_course_database() const {
    return course_database;
}

Student_Database* System::get_student_database() const {
    return student_database;
}

void System::set_course_database(Course_Database* const course_database) {
    this->course_database = course_database;
}

void System::set_student_database(Student_Database* const student_database) {
    this->student_database = student_database;
}
