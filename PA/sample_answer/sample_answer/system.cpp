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
    Student_ListNode* node = new Student_ListNode(student_id, nullptr);
    Wait_List* wait_list = course->get_wait_list();
    if(!wait_list->get_head()){
        wait_list->set_head(node);
        wait_list->set_end(node);
    }
    else{
        wait_list->get_end()->next = node;
        wait_list->set_end(node);
    }
}

// Helper function: find the index of a course within the enrolled course list of a student.
int search_course_index(const Student* const student, const char* const course_name) {
    char** enrolled_courses = student->get_enrolled_courses();
    for(int i = 0; i < student->get_num_enrolled_course(); ++i){
        if(strcmp(enrolled_courses[i], course_name) == 0){
            return i;
        }
    }
    return -1;
}

// Helper function: find the index of the student_id in the enrolled student list
int search_student_id(const int student_id, const Course* const course) {
    int* students_enrolled = course->get_students_enrolled();
    for(int i = 0; i < course->get_size(); ++i){
        if(students_enrolled[i] == student_id){
            return i;
        }
    }
    return -1;
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
    Student* student = this->student_database->get_student_by_id(student_id);
    
    if(request_credit > 30 || request_credit <= 18){
        return false;
    }

    if(request_credit >= 24 && student->get_gpa() < 3.7){
        return false;
    }

    if(student->get_gpa() < 3.3){
        return false;
    }
    
    student->set_max_credit(request_credit);
    return true;
}

bool System::add(const int student_id, const char* const course_name) {
    Student* student = this->student_database->get_student_by_id(student_id);
    Course* course = this->course_database->get_course_by_name(course_name);
    // Credit check
    if(student->get_curr_credit() + student->get_pending_credit() + course->get_num_credit() > student->get_max_credit()){
        return false;
    }
    // Course size check
    if(course->get_size() == course->get_capacity()){
        // Student gets into waitlist
        join_waitlist(student_id, course);
        student->set_pending_credit(student->get_pending_credit() + course->get_num_credit());
    }
    else{
        // Student gets enrolled into the target course.
        // Course related changes
        int* students_enrolled = course->get_students_enrolled();
        students_enrolled[course->get_size()] = student_id;
        course->set_size(course->get_size()+1);

        // Student related changes
        student->set_curr_credit(student->get_curr_credit() + course->get_num_credit());

        char** enrolled_courses = student->get_enrolled_courses();
        enrolled_courses[student->get_num_enrolled_course()] = new char[strlen(course_name)+1];
        strcpy(enrolled_courses[student->get_num_enrolled_course()], course_name);
        student->set_num_enrolled_course(student->get_num_enrolled_course() + 1);
    }
    return true;
}

bool System::swap(const int student_id, const char* const original_course_name, const char* const target_course_name) {
    Student* student = this->student_database->get_student_by_id(student_id);
    Course* original_course = this->course_database->get_course_by_name(original_course_name);
    Course* target_course = this->course_database->get_course_by_name(target_course_name);
    // Credit check
    if(student->get_curr_credit() + student->get_pending_credit() + target_course->get_num_credit() - original_course->get_num_credit() > student->get_max_credit()){
        return false;
    }
    // Course size check
    if(target_course->get_size() == target_course->get_capacity()){
        // Course changes: student gets into waitlist
        join_waitlist(student_id, target_course);

        // Student changes: record pending swap, attach to head
        Swap_List* swap_list = student->get_swap_list();
        Swap* next_swap = new Swap(original_course_name, target_course_name, swap_list->get_head());
        swap_list->set_head(next_swap);
        int net_swap_credit = target_course->get_num_credit() - original_course->get_num_credit();
        if(net_swap_credit > 0){
            student->set_pending_credit(student->get_pending_credit()+ net_swap_credit);
        }
    }
    else{
        // Student gets enrolled into the target course.
        // Course changes
        int* target_students_enrolled = target_course->get_students_enrolled();
        target_students_enrolled[target_course->get_size()] = student_id;
        target_course->set_size(target_course->get_size()+1);

        // Student changes
        student->set_curr_credit(student->get_curr_credit() + target_course->get_num_credit());

        // Update the enrolled course structure, replace the original course by target course.
        char** enrolled_courses = student->get_enrolled_courses();
        enrolled_courses[student->get_num_enrolled_course()] = new char[strlen(target_course_name)+1];
        strcpy(enrolled_courses[student->get_num_enrolled_course()], target_course_name);
        student->set_num_enrolled_course(student->get_num_enrolled_course() + 1);

        // Student drops the original course. Note that the dynamic memory of original course name will be dealt by drop function
        // Note: by drop function, it decrease the course count by 1, now since we are introducing new course, we need to add 1, see line 160
        this->drop(student_id, original_course_name);
    }
    return true;
}

void System::drop(const int student_id, const char* const course_name) {
    Student* student = this->student_database->get_student_by_id(student_id);
    Course* course = this->course_database->get_course_by_name(course_name);
    // Student changes:
    // Search the position of the course, replace the dropped course by the last enrolled course
    char** enrolled_courses = student->get_enrolled_courses();
    int index = search_course_index(student, course_name);
    delete [] enrolled_courses[index];

    // Array Deletion
    if(index != student->get_num_enrolled_course() - 1){
        enrolled_courses[index] = enrolled_courses[student->get_num_enrolled_course() - 1];
    }
    student->set_num_enrolled_course(student->get_num_enrolled_course() - 1);
    enrolled_courses[student->get_num_enrolled_course()] = nullptr; //not necessary but for better debugging

    student->set_curr_credit(student->get_curr_credit() - course->get_num_credit());

    // Course changes
    Wait_List* wait_list = course->get_wait_list();
    if(wait_list->get_head()){
        // If there exists student in waitlist
        Student_ListNode* head = wait_list->get_head();

        // The first student gets enrolled into the course
        int next_student_id = head->student_id;
        Student* next_student = this->student_database->get_student_by_id(next_student_id);

        // Course changes:
        int* students_enrolled = course->get_students_enrolled();
        int index = search_student_id(student_id, course);
        students_enrolled[index] = next_student_id;
        wait_list->set_head(head->next);
        delete head;

        // Student changes:
        char** next_enrolled_courses = next_student->get_enrolled_courses();
        next_enrolled_courses[next_student->get_num_enrolled_course()] = new char[strlen(course_name)+1];
        strcpy(next_enrolled_courses[next_student->get_num_enrolled_course()], course_name);
        next_student->set_num_enrolled_course(next_student->get_num_enrolled_course() + 1);

        // Determine whether a student get in through Swap operation
        Swap_List* swap_list = next_student->get_swap_list();
        Swap* prev = nullptr;
        Swap* curr = swap_list->get_head();

        while(curr){
            if(strcmp(curr->target_course_name, course_name) == 0){
                break;
            }
            prev = curr;
            curr = curr->next;
        }

        if(curr){
            // Student get in through Swap operation

            // SwapList delete a node
            if(prev){
                prev->next = curr->next;
            }
            else{
                swap_list->set_head(curr->next);
            }

            // Deal with the worst case credit
            Course* original_course = this->course_database->get_course_by_name(curr->original_course_name);
            int net_swap_credit = course->get_num_credit() - original_course->get_num_credit();
            if(net_swap_credit > 0){
                next_student->set_pending_credit(next_student->get_pending_credit() - net_swap_credit);
            }
            next_student->set_curr_credit(next_student->get_curr_credit() + course->get_num_credit());
            
            //Note: Drop will delete the memory for us
            drop(next_student_id, curr->original_course_name); 
            
            delete curr;
        }
        else{
            // Student get in through Add Operation
            next_student->set_pending_credit(next_student->get_pending_credit() - course->get_num_credit());
            next_student->set_curr_credit(next_student->get_curr_credit() + course->get_num_credit());
        }
    }
    else{
        // No students in waitlist
        int index = search_student_id(student_id, course);
        int* students_enrolled = course->get_students_enrolled();
        students_enrolled[index] = 0;
        course->set_size(course->get_size() - 1);
        students_enrolled[index] = students_enrolled[course->get_size()]; 
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
