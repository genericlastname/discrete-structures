#include "calendar.h"
using namespace std;

#define MAX_LINE_LENGTH 21

// ===================================================================
// Return true if year is a leap year.
// ===================================================================
bool is_leap_year(int year) {
    if ((year % 4 == 0 && year % 100 != 0) ||
        (year % 400 == 0))
        return true;

    return false;
}

// ===================================================================
// Return a number (where Su=0), representing the day of the week a
// particular day falls on. month passed in should be 0-11, not 1-12.
// ===================================================================
int get_weekday(int day, int month, int year) {
    string year_str = to_string(year);
    int year_short = stoi(year_str.substr(year_str.length() - 2));
    int month_code_table[] = { 0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5 };

    int year_code = ((year_short / 4) + year_short) % 7;
    int month_code = month_code_table[month];
    int century_code = 0;

    while (year >= 2100) {
        year -= 400;
    }

    while (year < 1700) {
        year += 400;
    }

    if (year >= 2000)
        century_code = 6;
    else if (year >= 1900)
        century_code = 0;
    else if (year >= 1800)
        century_code = 2;
    else if (year >= 1700)
        century_code = 4;

    int weekday = year_code + month_code + century_code + day;
    
    if (is_leap_year(year))
        weekday--;

    return weekday % 7;
}

// ===================================================================
// Print a line of dashes of n length.
// ===================================================================
void print_line(int n) {
    for (int i = 0; i < n; i++)
        cout << "-";
    cout << endl;
}

// ===================================================================
// Print the header with the month, year, and days of the week.
// ===================================================================
void print_header(int month, int year) {
    string weekdays[] = { "Su", "Mo", "Tu", "We", "Th", "Fr", "Sa" };
    string months[] = {
        "JANUARY",
        "FEBRUARY",
        "MARCH",
        "APRIL",
        "MAY",
        "JUNE",
        "JULY",
        "AUGUST",
        "SEPTEMBER",
        "OCTOBER",
        "NOVEMBER",
        "DECEMBER"
    };
    int offset = (MAX_LINE_LENGTH - months[month].length() - to_string(year).length() - 1) / 2;

    for (int h = 0; h < offset; h++)
        cout << " ";

    cout << months[month] << " " << year << endl;


    for (int i = 0; i < 7; i++)
        cout << " " << weekdays[i];

    cout << endl;
    print_line(MAX_LINE_LENGTH);
}
