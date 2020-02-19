#include "calendar.h"
using namespace std;

int main() {
    print_header(4, 2020);
    print_header(7, 1905);

    if (is_leap_year(2000))
        cout << "2000 is a leap year" << endl;

    if (is_leap_year(2100))
        cout << "2100 is a leap year" << endl;
    else
        cout << "2100 not a leap year" << endl;
}
