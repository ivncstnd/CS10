#include <iostream>
#include "Student.h"

using namespace std;

int main() {
  Student s1;
  Student s2 = Student("Jane Doe", "jdoe002", "Computer Science");
  Student s3 = Student("Jim Jenson", "jjenson");

  cout << endl << "Default Student: " << endl;
  cout << s1;
  cout << endl << "Student 4 params: " << endl;
  cout << s2;
  cout << endl << "Student 3 params: " << endl;
  cout << s3;
  cout << endl;

  cout << "Student s1 name: " << s1.name() << endl;
  cout << "Student s2 username: " << s2.username() << endl;
  cout << "Student s3 major: " << s3.major() << endl;
  cout << "Student s2 num courses: " << s2.numCourses() << endl;
  
  s3.changeMajor("English");
  cout << "Student s3 major (English): " << s3.major() << endl;

  s2.addCourse("CS012: Intro to CS");
  cout << endl << "Add CS012: " << endl;
  cout << s2;
  cout << endl;

  s2.addCourse("MATH 111");
  cout << endl << "Add MATH 111: " << endl;
  cout << s2;
  cout << endl;

  cout << "s2 num courses (2): " << s2.numCourses() << endl;

  s2.addCourse("PHYSICS 40A");
  cout << endl << "Add PHYSICS 40A: " << endl;
  cout << s2;
  cout << endl;

  s2.deleteCourse("MATH 111");
  cout << endl << "Delete MATH 111: " << endl;
  cout << s2;
  cout << endl;

  s2.deleteCourse("PHYSICS 40A");
  s2.deleteCourse("CS012: Intro to CS");
  cout << endl << "Delete all: " << endl;
  cout << s2;
  cout << endl << "Num Courses: " << s2.numCourses() << endl;
}