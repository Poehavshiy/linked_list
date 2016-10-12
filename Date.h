//
// Created by normalteam on 12.10.16.
//

#ifndef TZTEST_DATE_H
#define TZTEST_DATE_H

#include "string.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

const int date_size = 10;

struct Date {
    char data[date_size];

    Date();

    Date(const Date& date);

    ~Date();

    Date(const char *data);

    void set_date(const char *data);

    Date &operator=(const Date &date);
};


#endif //TZTEST_DATE_H
