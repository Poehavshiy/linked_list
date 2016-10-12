//
// Created by normalteam on 12.10.16.
//

#ifndef TZTEST_NODE_H
#define TZTEST_NODE_H


#include "Person.h"

struct Node {
    Node *next;
    Node *prev;
    Person* person;

    Node(): person(){
        next= nullptr;
        prev = nullptr;
    }

    Node(const Person& person){
        next= nullptr;
        prev = nullptr;
        this->person = new Person(person);
    }

    ~Node(){
        delete person;
        next = nullptr;
        prev = nullptr;
    }
};


#endif //TZTEST_NODE_H
