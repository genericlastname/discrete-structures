#ifndef __CALENDAR_H__
#define __CALENDAR_H__

#include <iostream>
#include <string>

bool is_leap_year(int year);

int get_weekday(int day, int month, int year);

void print_line(int n);

void print_header(int month, int year);

void print_days(int month, int year);

#endif
