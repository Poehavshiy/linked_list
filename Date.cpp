//
// Created by normalteam on 12.10.16.
//

#include "Date.h"

Date::Date() {
}

Date::Date(const Date &date) {
    for (int i = 0; i < date_size; ++i) {
        this->data[i] = date.data[i];
    }
}

Date::~Date() {

}

Date::Date(const char *data) {
    if (data == nullptr) return;
    for (int i = 0; i < date_size && data[i] != '\n'; ++i) {
        this->data[i] = data[i];
    }
}

void Date::set_date(const char *data) {
    for (int i = 0; i < date_size && data[i] != '\n'; ++i) {
        this->data[i] = data[i];
    }
}

Date &Date::operator=(const Date &date) {
    for (int i = 0; i < date_size; ++i) {
        this->data[i] = date.data[i];
    }
}















