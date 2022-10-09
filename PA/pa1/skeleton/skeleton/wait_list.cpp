#include <iostream>
#include "wait_list.h"

using namespace std;

Student_ListNode::Student_ListNode(const int student_id, Student_ListNode* const next) 
:student_id(student_id), next(next)
{
    // TODO
}

Wait_List::Wait_List()
:head(nullptr), end(nullptr)
{
    // TODO
}

Wait_List::Wait_List(const Wait_List& wait_list) {
    // TODO
    if (!wait_list.head) {
        head = nullptr;
        end = nullptr;
        return ;
    }

    Student_ListNode* this_list = nullptr;
    Student_ListNode* node = wait_list.head;

    while(node) {
        this_list = new Student_ListNode(node->student_id, node->next);
        if (node == wait_list.head)
            head = this_list;
        else if(node == wait_list.end) {
            end = this_list;
            break; 
        }
        this_list = this_list->next;
        node = node->next;
    }
}

Wait_List::~Wait_List() {
    // TODO
    if (!head)
        return ;
        
    while(head != end) {
        Student_ListNode* temp = head;
        head = head->next;
        delete temp;
    }
    delete end;
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