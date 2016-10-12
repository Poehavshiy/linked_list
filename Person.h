//
// Created by normalteam on 12.10.16.
//

#ifndef TZTEST_PERSON_H
#define TZTEST_PERSON_H

#include "Date.h"

const int s_name_size = 20;

class Person {
private:
    char *sname;
    int grown;
    Date date;
public:
    Person();

    Person(const char *secondname, const int &grown = 0, const Date &date = 0);

    Person(const Person &right);

    void set_sname(const char *secondname);

    void set_grown(const int &grown);

    void set_date(const Date &date);

    void set_all(const char *secondname, const int &grown, const Date &date);


    const char *get_sname() const;

    int get_grown() const;

    const Date &get_date() const;


    bool operator==(const Person &right) const;

    bool operator<=(const Person &right) const;

    friend std::ostream &operator<<(std::ostream &stream, const Person &person);

    Person &operator=(const Person &person);

    ~Person();

};


#endif //TZTEST_PERSON_H
