//
// Created by nikita on 12.10.16.
//

#include "Linked_list.h"
Linked_list::Linked_list() {
    head = nullptr;
}

Linked_list::Linked_list(const Person &person) {
    head->person = new Person(person);
}

Linked_list::~Linked_list() {
    if (head == nullptr) {
        cout << " from ~Linked_list() list is empty " << endl;
        return;
    }
    Node *iterator = head;
    Node *priv = nullptr;
    while (iterator != nullptr) {
        priv = iterator;
        iterator = iterator->next;
        delete priv;
    }
}

void Linked_list::write_xml( const char* path ) const{

}

void Linked_list::write_txt( const char* path ) const{

}

void Linked_list::delete_node(Node *fordel) {
    Node *del_next = fordel->next;
    Node *del_prev = fordel->prev;
    if (del_prev != nullptr) {
        del_prev->next = del_next;
    }

    if (del_next != nullptr) {
        del_next->prev = del_prev;
        if (fordel == head) head = del_next;
    }

    delete fordel;

}

void Linked_list::insert_node(Node *new_node, Node *prev, Node *next) {
    new_node->next = next;
    new_node->prev = prev;
    if(prev != nullptr){
        prev -> next = new_node;
    }
    if(next != nullptr){
        next -> prev = new_node;
        if(next == head){
            head = new_node;
        }
    }
}

Node *Linked_list::get_last() const {
    Node *iterator = head;
    while (iterator->next != nullptr) {
        iterator = iterator->next;
    }
    return iterator;
}

void Linked_list::show() const {
    if (head == nullptr) {
        cout << " from show() list is empty " << endl;
        return;
    }
    Node *iterator = head;
    Node *prev = nullptr;
    int debug_counter = 0;
    while (iterator != nullptr) {
        cout<<"debug_counter = "<<debug_counter<<endl;
        prev = iterator;
        iterator = iterator->next;
        cout << *(prev->person);
        ++debug_counter;
    }
}

void Linked_list::show_reverse() const {
    if (head == nullptr) {
        cout << " from show_reverse() list is empty " << endl;
        return;
    }
    Node *iterator = get_last();
    Node *prev = nullptr;
    while (iterator != nullptr) {
        prev = iterator;
        iterator = iterator->prev;
        cout << *(prev->person);
    }
}

void Linked_list::delete_by_id(const int &index) {
    if (head == nullptr) {
        cout << " from delete_by_id() list is empty " << endl;
        return;
    }
    int counter = 0;
    Node *iterator = head;
    while (counter != index && iterator->next != nullptr) {
        iterator = iterator->next;
        ++counter;
    }
    if (counter != index && iterator->next == nullptr) {
        cout << " from delete_by_id() index is out of bound " << endl;
        return;
    }
    delete_node(iterator);
}

void Linked_list::delete_by_sname(const char *sname) {
    if (head == nullptr) {
        cout << " from delete_by_sname() list is empty " << endl;
        return;
    }
    Person target(sname);
    Node *iterator = head;
    Node *prev = nullptr;
    while (iterator != nullptr) {
        prev = iterator;
        iterator = iterator->next;
        if (*(prev->person) == target) {
            delete_node(prev);
        }
    }

}

void Linked_list::insert(const Person &person) {
    Node *new_node = new Node(person);
    if (head == nullptr) {
        head = new_node;
        return;
    }
    Node *iterator = head;
    Node *prev = nullptr;
    while (iterator != nullptr && *(iterator->person) <= person) {
        prev = iterator;
        iterator = iterator->next;
    }
    insert_node(new_node, prev, iterator);
}

void Linked_list::insert_by_id(const Person &person, const int &index){
    if (head == nullptr && index != 0) {
        cout << " from insert_by_id() list is empty and index != NULL" << endl;
        return;
    }
    if(head == nullptr && index == 0){
        Node *new_node = new Node(person);
        head = new_node;
        return;
    }
    if(head != nullptr && index == 0 ) {
        Node *new_node = new Node(person);
        insert_node(new_node, nullptr, head);
        return;
    }
    int counter = 0;
    Node *iterator = head;
    while (counter != index -1 && iterator->next != nullptr) {
        iterator = iterator->next;
        ++counter;
    }
    if (counter != index -1 && iterator->next == nullptr) {
        cout << " from delete_by_id() index is out of bound " << endl;
        return;
    }
    Node *new_node = new Node(person);
    insert_node(new_node, iterator->prev, iterator);
}

void Linked_list::sort(){
    head = mergeSort(head);
}

Node* Linked_list::split(Node* _head) {
    Node* fast = _head;
    Node* slow = _head;
    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    Node *temp = slow->next;
    slow->next = nullptr;
    return temp;
}

Node* Linked_list::merge(Node *first, Node *second) {
    if (!first)
        return second;

    if (!second)
        return first;

    if (*(first->person) <= *(second->person))
    {
        first->next = merge(first->next,second);
        first->next->prev = first;
        first->prev = NULL;
        return first;
    }
    else
    {
        second->next = merge(first,second->next);
        second->next->prev = second;
        second->prev = NULL;
        return second;
    }
}

Node* Linked_list:: mergeSort(Node* _head) {
    if (!_head || !_head->next)
        return _head;
    Node* second = split(_head);

    _head = mergeSort(_head);
    second = mergeSort(second);

    return merge(_head,second);
}


void Linked_list::write(const char *path, FTYPE type) const{
    if(type == TXT) write_txt(path);
    else write_xml(path);
}