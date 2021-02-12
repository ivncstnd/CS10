#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <vector>

using namespace std;

class Student {
    private:
        string _name;
        string _username;
        string _major;
        vector<string> _courses;
    public:
        Student();
        Student(const string &name, const string &username, const string &major);
        Student(const string &name, const string &username);
        const string & name() const;
        const string & username() const;
        const string & major() const;
        int numCourses() const;
        void changeMajor(const string &);
        void addCourse(const string &);
        void deleteCourse(const string &);
        friend ostream &operator<<(ostream &, const Student &);
};


#endif