//
// Created by nikita on 12.10.16.
//

#ifndef TZTEST_LINKED_LIST_H
#define TZTEST_LINKED_LIST_H
#include "Node.h"


enum FTYPE {XML, TXT};

class Linked_list {
    Node *head;

    void write_xml( const char* path ) const;

    void write_txt( const char* path ) const;

    void delete_node(Node* fordel);

    void insert_node(Node* new_node,Node* prev,Node* next);

    Node* get_last() const;
public:
    Linked_list();

    Linked_list(const Person& person);

    ~Linked_list();

    void show() const;

    void show_reverse() const;

    void delete_by_id(const int& index);

    void delete_by_sname( const char* sname);

    void insert ( const Person& person);

    void insert_by_id(const Person &person, const int& index);

    void sort();

    void write(const char* path, FTYPE type) const;
};


#endif //TZTEST_LINKED_LIST_H
