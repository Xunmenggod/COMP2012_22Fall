#include <iostream>
#include <cstring>
#include "swap_list.h"

using namespace std;

Swap::Swap(const char* const original_course_name, const char* const target_course_name, Swap* const next) 
:next(next) {
    // TODO
    this->original_course_name = new char[strlen(original_course_name) + 1];
    strcpy(this->original_course_name, original_course_name);
    this->target_course_name = new char[strlen(target_course_name) + 1];
    strcpy(this->target_course_name, target_course_name);
}

Swap::~Swap() {
    // TODO
    delete[] original_course_name;
    delete[] target_course_name;
    //delete next; perform this operation in Swap_List destructor
}

Swap_List::Swap_List():head(nullptr) {
    // TODO
}

Swap_List::Swap_List(const Swap_List& swap_list) {
    // TODO
    if (!swap_list.head){
        head = nullptr;
        return ;
    }
    
    Swap* this_list = nullptr;
    Swap* node = swap_list.head;
    while(node) {
        this_list = new Swap(node->original_course_name, node->target_course_name, node->next);
        if (node == swap_list.head)
            head = this_list;
        this_list = this_list->next;
        node = node->next;
    }
}

Swap_List::~Swap_List() {
    // TODO
    while(head) {
        Swap* temp = head;
        head = head->next;
        delete temp;
    }
}

void Swap_List::print_list() const {
    Swap* temp = this->head;
    int index = 0;
    while(temp) {
        cout << "Swap: " << index++ << endl;
        cout << "Original Course: " << temp->original_course_name << endl;
        cout << "Target Course: " << temp->target_course_name << endl;
        temp = temp->next;
    }
}

Swap* Swap_List::get_head() const {
    return head;
}

void Swap_List::set_head(Swap* const head) {
    this->head = head;
}