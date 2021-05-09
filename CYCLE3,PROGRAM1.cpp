// CHRISTO REJI SAM
// CYCLE 3
// Program 1: Define a class Date. Overload the operator �+� such that it adds a given date with certain number of days.


// PROGRAM

#include <iostream>
using namespace std;
class Date
{
    int day, month, year;
public:
    void input()
    {
        cout << "\n Enter the first Date ";
        cout << "\n Enter the day: ";
        cin >> day;
        cout << "\n Enter the month: ";
        cin >> month;
        cout << "\n Enter the year: ";
        cin >> year;
    }
    bool validate()
    {
        if (day <= 0 || month <= 0 || year < 0 || day > 31 || month > 12)
            return false;
        return true;
    }
    bool checkLeap()
    {
        if (year % 4 == 0 && year % 100 != 0)
            return true;
        else if (year % 400 == 0)
            return true;
        else
            return false;
    }
    int returnElapsedDays()
    {
        int elapsed = day;
        switch (month - 1)
        {
        case 11:
            elapsed += 30;
        case 10:
            elapsed += 31;
        case 9:
            elapsed += 30;
        case 8:
            elapsed += 31;
        case 7:
            elapsed += 31;
        case 6:
            elapsed += 30;
        case 5:
            elapsed += 31;
        case 4:
            elapsed += 30;
        case 3:
            elapsed += 31;
        case 2:
            elapsed += 28;
        case 1:
            elapsed += 31;
        }
        if (checkLeap() && month > 2)
            elapsed++;
        return elapsed;
    }
    void setDate(Date &temp, int elapsedDate)
    {
        int i, months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (checkLeap())
            months[1]++;
        for (i = 0; i < 12; i++)
        {
            if (elapsedDate <= months[i])
                break;
            elapsedDate -= months[i];
        }
        temp.day = elapsedDate;
        temp.month = i + 1;
    }
    Date operator+(int daysAdded)
    {
        Date temp;
        cout << "\n Adding " << daysAdded << " to the date: " << day << " / " << month << " / " << year;
        int elapsedDays, initiallyElapsedDays = returnElapsedDays();
        int remainingDays = checkLeap() ? 366 - initiallyElapsedDays : 365 - initiallyElapsedDays;
        if (daysAdded <= remainingDays)
        {
            temp.day = day;
            temp.month = month;
            temp.year = year;
            elapsedDays = initiallyElapsedDays + daysAdded;
        }
        else
        {
            daysAdded -= remainingDays;
            temp.year = year + 1;
            int newYearDays = checkLeap() ? 366 : 365;
            while (daysAdded >= newYearDays)
            {
                daysAdded -= newYearDays;
                temp.year++;
                newYearDays = checkLeap() ? 366 : 365;
            }
            elapsedDays = daysAdded;
        }
        setDate(temp, elapsedDays);
        return temp;
    }
    void show()
    {
        cout << endl
             << " "
             << day << " / " << month << " / " << year;
    }
};

int main()
{
    Date d, newDate;
    d.input();
    if (d.validate())
    {
        int daysAdded;
        cout << "\n Input number of days to be added: ";
        cin >> daysAdded;
        newDate = d + daysAdded;
        newDate.show();
    }
    else
        cout << "\n Invalid Date!";
    return 0;
}
