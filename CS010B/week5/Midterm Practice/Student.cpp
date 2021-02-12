#include "Student.h"
#include <iostream>
using namespace std;

Student::Student() {
    _name = "John Doe";
    _username = "john001";
    _major = "Undecided";
}

Student::Student(const string & name, const string & username, const string & major) {
    _name = name;
    _username = username;
    _major = major;
}

Student::Student(const string & name, const string & username) {
    _name = name;
    _username = username;
    _major = "Undecided";
}

const string & Student::name() const {
    return _name;
}

const string & Student::username() const {
    return _username;
}

const string & Student::major() const {
    return _major;
}

int Student::numCourses() const {
    return _courses.size();
}

ostream &operator<<(ostream &out, const Student &s) {
    out << "Name: " << s._name << endl
    << "Username: " << s._username << endl
    << "Major: " << s._major << endl
    << "Courses: " << endl;
    for (unsigned int i = 0; i < s._courses.size(); ++i) {
        out << "\t" << s._courses[i] << endl;
    }
    return out;
}

void Student::changeMajor(const string &major) {
    _major = major;
}

void Student::addCourse(const string &course) {
  _courses.push_back(course);
}

void Student::deleteCourse(const string &course) {
  for (unsigned int i = 0; i < _courses.size(); ++i) {
      if (_courses.at(i) == course) {
          _courses.at(i) = _courses.back();
          _courses.pop_back();
          return;
      }
  }
}


