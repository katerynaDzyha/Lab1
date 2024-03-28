#include <iostream>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    // Додавання одного дня до дати
    void addOneDay() {
        day++;
        if (day > daysInMonth(month, year)) {
            day = 1;
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        }
    }

    // Порівняння двох дат
    int compareDates(const Date& day2) const {
        if (year != day2.year)
            return year - day2.year;
        if (month != day2.month)
            return month - day2.month;
        return day - day2.day;
    }

    // Перевірка, чи рік високосний
    bool isLeapYear() const {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    // Виведення дати на екран
    void printDate() const {
        cout << day << "." << month << "." << year <<endl;
    }

private:
    // Допоміжна функція для визначення числа днів у місяці
    int daysInMonth(int m, int y) const {
        switch (m) {
            case 2:
                return isLeapYear() ? 29 : 28;
            case 4:
            case 6:
            case 9:
            case 11:
                return 30;
            default:
                return 31;
        }
    }
};

int main() {
    int day1, month1, year1;
    int day2, month2, year2;

    cout << "Enter first date:" <<endl;
    cout << "Enter day: ";
    cin >> day1;
    cout << "Enter month: ";
    cin >> month1;
    cout << "Enter year: ";
    cin >> year1;
    cout << endl;

    cout << "Enter second date:"<<endl;
    cout << "Enter day: ";
    cin >> day2;
    cout << "Enter month: ";
    cin >> month2;
    cout << "Enter year: ";
    cin >> year2;
    cout << endl;


    Date currentDate(day1, month1, year1);
    Date secondDate(day2, month2, year2);
   
    Date tomorrowDate = currentDate;
    tomorrowDate.addOneDay();

    cout << "Current date: ";
    currentDate.printDate();
    cout << "Another date: ";
    secondDate.printDate();
    cout << "Tomorrow's date: ";
    tomorrowDate.printDate();
    cout << endl;

    int comparison = currentDate.compareDates(secondDate);
    if (comparison < 0)
        cout << "First date is earlier than second date." <<endl;
    else if (comparison > 0)
        cout << "First date is later than second date." <<endl;
    else
        cout << "Both dates are the same." <<endl;


    if (currentDate.isLeapYear())
        cout << "Current year is a leap year." <<endl;
    else
        cout << "Current year is not a leap year." <<endl;

    return 0;
}

