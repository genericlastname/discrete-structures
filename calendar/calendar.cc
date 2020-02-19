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
