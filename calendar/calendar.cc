#include "calendar.h"
using namespace std;

#define MAX_LINE_LENGTH 28

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
        cout << "  " << weekdays[i];

    cout << endl;
    print_line(MAX_LINE_LENGTH);
}

// ===================================================================
// Print the actual days for each month on the proper day of the week.
// ===================================================================
// void print_days(int month, int year) {
//     int month_lengths[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//     int current_length = month_lengths[month];
//     int start_weekday = get_weekday(1, month, year);
    
//     if (is_leap_year(year) && month == 1) {
//         current_length += 1;
//     }

//     int current_weekday = 0;
//     for (int days_printed = 1; days_printed <= current_length; days_printed++) {
//         for (int col = 0; col < MAX_LINE_LENGTH; col++) {
//             cout << "  ";

//             // if month hasn't started yet print blank space.
//             if (current_weekday < start_weekday && days_printed == 1) {
//                 cout << "  ";
//             }
//             else {
//                 if (to_string(days_printed).length() < 2)
//                     cout << " " << days_printed;
//                 else
//                     cout << days_printed;

//                 current_weekday++;
//                 if (current_weekday > 6)
//                     current_weekday = 0;
//             }
//         }
//     }
// }

void print_days(int month, int year) {
    int month_lengths[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    int day = 1;
    int current_weekday = 0;
    int start_weekday = get_weekday(day, month, year);
    int line = 0;

    int leap = 0;
    if (is_leap_year(year))
        leap = 1;

    while (day <= month_lengths[month] + leap) {
        if (line + 4 > MAX_LINE_LENGTH)
        {
            cout << endl;
            line = 0;
        }

        cout << "  ";

        if (current_weekday < start_weekday) {
            cout << "  ";
            current_weekday++;
        }
        else {
            if (to_string(day).length() < 2)
                cout << " ";

            cout << day;

            day++;
        }

        line += 4;
    }

    cout << endl << endl;
}
