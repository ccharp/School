#include <iostream>
#include <cstdlib>
using namespace std;

// Class Declaration
class DayOfYear
{
public:
    void input();
    void output();
    
    void set(int new_month, int new_day);
    // Precondition: new_month and new_day form a possible date.
    // Precondition: The date is reset according to the argument.

    int get_month();
    // Returns the month, 1 for January, 2 for February, etc.

    int get_day();
    // Returns the day of the month.

private:
    void check_date();
    int month;
    int day;
};

int main()
{
    DayOfYear today, birthday;
    int birth_month, birth_day;
    cout << "Enter today's date. ";
    today.input(); // call input function
    cout << "Today's date is: ";
    today.output(); // call output function
    
    cout << "Enter your birthday's month (1,2,...,12): ";
    cin >> birth_month;
    cout << "Enter your birthday's day (1,2,...,31): ";
    cin >> birth_day;
    birthday.set(birth_month, birth_day); // call set function to set the date of your birthday.
    cout << "Your birthday is: ";
    birthday.output(); // call output function
    
    if(today.get_month() == birthday.get_month() && today.get_day() == birthday.get_day()) // Check whether today is your birthday
       cout << "Happy Birthday!\n";
    else
       cout << "Happy Unbirthday!\n";
    return 0;
}

// Member Function Declaration: 
void DayOfYear::input()
{
    cout << "Enter the month as a number: ";
    cin >> month;
    cout << "Enter the day of the month: ";
    cin >> day;
    check_date(); // function call: check
}

void DayOfYear::output()
{
    cout << month << "/" << day << "(month/day).\n";
}
void DayOfYear::set(int new_month, int new_day)
{
    month = new_month; // private member "month" assignment: new_month
    day = new_day; // private member "day" assignment: new_day
    check_date(); // function call: check
}

int DayOfYear::get_month()
{
    return month; // Return the month
}

int DayOfYear::get_day()
{
    return day; // Returns the day
}

void DayOfYear::check_date()
{
    if (month<1 || month>12 || day<1 || day>31)
    {
        cout << "Illegal date. Aborting program.\n";
        exit(1);
    }
}

