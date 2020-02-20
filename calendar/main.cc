#include "calendar.h"
using namespace std;

int main() {
    string year;

    do {
        cout << "Enter a year -> ";
        getline(cin, year);

        if (!is_all_numbers(year))
            cout << endl << "Please enter a number for the year!" << endl << endl;
    }
    while (!is_all_numbers(year));

    print_calendar(stoi(year));
}
