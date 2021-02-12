#include <iostream>
#include "Distance.h"
using namespace std;

Distance::Distance() {
    feet = 0;
    inches = 0;
}

Distance::Distance(unsigned ft, double in) {
    feet = ft;
    inches = in;
    init();
} 

Distance::Distance(double in) {
    feet = 0;
    inches = in;
    init();
}

unsigned Distance::getFeet() const{
    return feet;
}

double Distance::getInches() const{
    return inches;
}

double Distance::distanceInInches() const{
    return (feet * 12 + inches);
}

double Distance::distanceInFeet() const{
    return (feet + inches / 12.0);
}

double Distance::distanceInMeters() const{
    return distanceInInches() * 0.0254;
}

Distance Distance::operator+(const Distance &rhs) const{
    Distance temp((feet + rhs.feet),(inches + rhs.inches));
    return temp;
}

Distance Distance::operator-(const Distance &rhs) const{
    double tempInches = distanceInInches() - rhs.distanceInInches();
    Distance temp(tempInches);
    return temp;
}

ostream & operator<<(ostream &out, const Distance &rhs){
    out << rhs.getFeet()<< "' " << rhs.getInches() << "\"";
    return out;
}

void Distance::init() {
    if(inches < 0) {
        inches = -inches;
    }
    while(inches >= 12) {
        feet += 1;
        inches -= 12;
    }
} 