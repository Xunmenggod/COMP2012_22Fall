#include <iostream>
#include "wait_list.h"

using namespace std;

Student_ListNode::Student_ListNode(const int student_id, Student_ListNode* const next) {
    this->student_id = student_id;
    this->next = next;
}

Wait_List::Wait_List() {
    this->end = nullptr;
    this->head = nullptr;
}

Wait_List::Wait_List(const Wait_List& wait_list) {
    if(wait_list.head){
        this->head = new Student_ListNode(wait_list.head->student_id, nullptr);
        Student_ListNode* this_temp = this->head;
        Student_ListNode* another_next = wait_list.head->next;
        while(another_next){
            Student_ListNode* next_copy = new Student_ListNode(another_next->student_id, nullptr);
            this_temp->next = next_copy;
            this_temp = this_temp->next;
            another_next = another_next->next;
        }
        this->end = this_temp;
    }
    else{
        this->end = nullptr;
        this->head = nullptr;
    }
}

Wait_List::~Wait_List() {
    Student_ListNode* curr_node = this->head;
    Student_ListNode* next_node = this->head? this->head->next: nullptr;
    while(curr_node){
        delete curr_node;
        curr_node = next_node;
        next_node = next_node? next_node->next: nullptr;
    }
}

void Wait_List::print_list() const {
    Student_ListNode* temp = this->head;
    int index = 0;
    while(temp) {
        cout << "Waitlist Number: " << index++ << endl;
        cout << temp->student_id << endl;
        temp = temp->next;
    }
}

Student_ListNode* Wait_List::get_head() const {
    return head;
}

Student_ListNode* Wait_List::get_end() const {
    return end;
}

void Wait_List::set_head(Student_ListNode* const head) {
    this->head = head;
}

void Wait_List::set_end(Student_ListNode* const end) {
    this->end = end;
}