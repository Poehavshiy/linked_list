#include "Person.h"

Person::Person() : date() {
    sname = new char[20];
    grown = 0;
}

Person::Person(const Person& right): grown(right.grown), date(right.date){
    sname = new char[20];
    for (int i = 0; i < s_name_size; ++i) {
        this->sname[i] = right.sname[i];
    }

}

Person::Person(const char *secondname, const int &grown, const Date &date) : date(date), grown(grown) {
    sname = new char[20];
    for (int i = 0; i < s_name_size; ++i) {
        this->sname[i] = secondname[i];
    }
}

void Person::set_sname(const char *secondname) {
    for (int i = 0; i < s_name_size; ++i) {
        this->sname[i] = secondname[i];
    }
}

void Person::set_grown(const int &grown) {
    this->grown = grown;
}

void Person::set_date(const Date &date) {
    this->date = date;

}

void Person::set_all(const char *secondname,  const int &grown, const Date &date){
    set_sname(secondname);
    set_grown(grown);
    set_date(date);
}

const char *Person::get_sname() const {
    return sname;
}

int Person::get_grown() const {
    return grown;
}

const Date &Person::get_date() const {
    return date;
}


bool Person::operator==(const Person &right) const {
    if (strcmp(this->get_sname(), right.get_sname()) == 0) return true;
    return false;

}

bool Person::operator<=(const Person &right) const {
    if (strcmp(this->get_sname(), right.get_sname()) <= 0) return true;
    return false;

}

std::ostream & operator<<(std::ostream &stream, const Person &person){
    stream<<"Person_begin"<<endl;
    for (int i = 0; person.sname[i] != '\0'; ++i) {
        stream << person.sname[i];
    }
    stream<<endl;
    stream<<person.grown<<endl;
    for (int i = 0; person.date.data[i] != '\0'; ++i) {
        stream<<person.date.data[i];
    }
    stream<<endl;
    stream<<"Person_end"<<endl;


}

Person &Person::operator=(const Person &right) {
    if (this == &right) {
        return *this;
    }
    this->set_date(right.date);
    this->set_sname(right.sname);
    this->set_grown(right.grown);
}


Person::~Person(){
    free(sname);
}







































