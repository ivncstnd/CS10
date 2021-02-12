#include <iostream>
#include <string>

using namespace std;

class Date {
    private:
        unsigned day;
        unsigned month;
        string monthName;
        unsigned year;
    public:
        Date();
        Date(unsigned m, unsigned d, unsigned y);
        Date(const string &mn, unsigned d, unsigned y);
        void printNumeric() const;
        void printAlpha() const;
    private:
        bool isLeap(unsigned y) const;
        unsigned daysPerMonth(unsigned m, unsigned y) const;
        string name(unsigned m) const;
        unsigned number(const string &mn) const;
};

Date::Date() {
    day = 1;
    month = 1;
    year = 2000;
}

Date::Date(unsigned m, unsigned d, unsigned y) {
    if((m > 0 && m <= 12) && (d <= daysPerMonth(m, y) && d > 0)) {
        month = m;
        day = d; 
        year = y;
    }
    else {
        if(m > 12 && d > daysPerMonth(m,y)) {
            month = 12;
            day = daysPerMonth(12, y);
            year = y;
            cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << year << "." << endl;
        }
        else if(1 > m && 1 > d) {
            month = 1;
            day = 1;
            year = y;
            cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << year << "." << endl;
        }
        else if(1 > m && d > daysPerMonth(m,y)) {
            month = 1;
            day = daysPerMonth(1,y);
            year = y;
            cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << year << "." << endl;
        }
        else if(m > 12 && 1 > d) {
            month = 12;
            day = 1;
            year = y;
            cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << year << "." << endl;
        }
        else if(m > 12) {
            month = 12;
            day = d;
            year = y;
            cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << year << "." << endl;
        }
        else if(1 > d) {
            month = m;
            day = 1;
            year = y;
            cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << year << "." << endl;
        }
        else if(d > daysPerMonth(m,y)) {
            month = m;
            day = daysPerMonth(m, y);
            year = y;
            cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << year << "." << endl;
        } 
    }
}

Date::Date(const string &mn, unsigned d, unsigned y) {
    string months[12] = {"January", "February", "March", "April", "May", "June",
                        "July", "August", "September", "October", "November", "December"};
    string monthUpper = mn;
    monthUpper[0] = toupper(monthUpper[0]);
    unsigned monthNumber;

    for(int i = 0; i < 12; ++i) {
        monthNumber = number(monthUpper);
    }
    
    if(monthNumber < 1 || monthNumber > 12) {
        monthName = months[0];
        month = 1;
        day = 1;
        year = 2000;
        cout << "Invalid month name: the Date was set to " << month << "/" << day << "/" << year << "." << endl;
    }
    else {
        if(1 > d) {
            monthName = monthUpper;
            month = monthNumber;
            day = 1;
            year = y;
            cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << year << "." << endl;
        }
        else if(d > daysPerMonth(monthNumber, y)) {
            monthName = monthUpper;
            month = monthNumber;
            day = daysPerMonth(monthNumber, y);
            year = y;
            cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << year << "." << endl;
        }
        else if(d <= daysPerMonth(monthNumber, y)) {
            monthName = monthUpper;
            month = monthNumber;
            day = d;
            year = y;
        }
    }
}

    
void Date::printNumeric() const {
    if(!monthName.empty()) {
        unsigned m = number(monthName);
        cout << m << "/" << day << "/" << year;
    }
    else {
        cout << month << "/" << day << "/" << year;
    }
}

void Date::printAlpha() const {
    if(monthName.empty()) {
        string mn = name(month);
        cout << mn << " " << day << ", " << year;
    }
    else {
        cout << monthName << " " << day << ", " << year;
    }
}

bool Date::isLeap(unsigned y) const {
    bool isLeapYear = false;

    if(y%4==0) {
        if(y%100==0) {
            if(y%400 == 0){
                isLeapYear = true;
            }
        }
        else {
            isLeapYear = true;
        }
    }
    
    return isLeapYear;
}

unsigned Date::daysPerMonth(unsigned m, unsigned y) const {
    unsigned isLeapYear = 0;
    unsigned daysInMonth;

    if(isLeap(y)){
        isLeapYear = 1;
    }

    if(m == 2) {
        daysInMonth = 28 + isLeapYear;
    }
    else {
        daysInMonth = 31 - (((m - 1) % 7)% 2);
    }

    return daysInMonth;
}

string Date::name(unsigned m) const {
    string months[12] = {"January", "February", "March", "April", "May", "June",
                        "July", "August", "September", "October", "November", "December"};
    string monthName = months[m-1];

    return monthName;
}

unsigned Date::number(const string &mn) const {
    unsigned monthNumber;
    string months[12] = {"January", "February", "March", "April", "May", "June",
                        "July", "August", "September", "October", "November", "December"};
    for(int i = 0; i < 12; ++i) {
        if(months[i] == mn) {
            monthNumber = i+1;
        }
    }
    return monthNumber;
}


// Don't change the code below this line.
// You may comment them out if you want to build your own test harness
// while in develope mode, but you will need these to pass tets in submit mode.

Date getDate();

int main() {
   
   Date testDate;
   testDate = getDate();
   cout << endl;
   cout << "Numeric: ";
   testDate.printNumeric();
   cout << endl;
   cout << "Alpha:   ";
   testDate.printAlpha();
   cout << endl;
   
   return 0;
}

Date getDate() {
   int choice;
   unsigned monthNumber, day, year;
   string monthName;

   cout << "Which Date constructor? (Enter 1, 2, or 3)" << endl
      << "1 - Month Number" << endl
      << "2 - Month Name" << endl
      << "3 - default" << endl;
   cin >> choice;
   cout << endl;

   if (choice == 1) {
      cout << "month number? ";
      cin >> monthNumber;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthNumber, day, year);
   } else if (choice == 2) {
      cout << "month name? ";
      cin >> monthName;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthName, day, year);
   } else {
      return Date();
   }
}
