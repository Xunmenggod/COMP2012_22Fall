#include <iostream>
#include <cstring>
#include "swap_list.h"

using namespace std;

Swap::Swap(const char* const original_course_name, const char* const target_course_name, Swap* const next) {
    this->original_course_name = new char[strlen(original_course_name)+1];
    strcpy(this->original_course_name, original_course_name);
    this->target_course_name = new char[strlen(target_course_name)+1];
    strcpy(this->target_course_name, target_course_name);
    this->next = next;
}

Swap::~Swap() {
    delete [] this->original_course_name;
    delete [] this->target_course_name;
}

Swap_List::Swap_List() {
    head = nullptr;
}

Swap_List::Swap_List(const Swap_List& swap_list) {
    if(swap_list.head){
        this->head = new Swap(swap_list.head->original_course_name, swap_list.head->target_course_name, nullptr);
        Swap* this_list_temp = this->head;
        Swap* other_list_temp = swap_list.head->next;
        while(other_list_temp){
            Swap* this_next = new Swap(other_list_temp->original_course_name, other_list_temp->target_course_name, nullptr);
            this_list_temp->next = this_next;
            this_list_temp = this_list_temp->next;
            other_list_temp = other_list_temp->next;
        }
    }
    else{
        this->head = nullptr;
    }
}

Swap_List::~Swap_List() {
    Swap* curr_node = this->head;
    Swap* next_node = this->head? this->head->next: nullptr;
    while(curr_node){
        delete curr_node;
        curr_node = next_node;
        next_node = next_node? next_node->next: nullptr;
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