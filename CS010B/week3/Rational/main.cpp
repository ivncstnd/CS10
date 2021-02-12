#include <iostream>

using namespace std;

// Rational Class declaration
class Rational {
   private:
      int numerator;
      int denominator; 
   public:
      Rational();
      Rational(int); 
      Rational(int, int); 
      Rational add(const Rational &) const; 
      Rational subtract(const Rational &) const; 
      Rational multiply(const Rational &) const; 
      Rational divide(const Rational &) const;
      void simplify();
      void display() const;
   private:
      int gcd(int, int) const;
};

Rational::Rational() {
   numerator = 0;
   denominator = 1;
}

Rational::Rational(int numerator) {
   this->numerator = numerator;
   denominator = 1;
}

Rational::Rational(int numerator, int denominator) {
   this->numerator = numerator;
   this->denominator = denominator;
}

Rational Rational::add(const Rational &f) const {
   Rational temp;
   temp.numerator = ((f.numerator * denominator) + (f.denominator * numerator));
   temp.denominator = (f.denominator * denominator);
   return temp;
}

Rational Rational::subtract(const Rational &f) const {
   Rational temp;
   temp.numerator = ((f.denominator * numerator) - (f.numerator * denominator));
   temp.denominator = (f.denominator * denominator);
   return temp;
}

Rational Rational::multiply(const Rational &f) const {
   Rational temp;
   temp.numerator = (f.numerator * numerator);
   temp.denominator = (f.denominator * denominator);
   return temp;
}

Rational Rational::divide(const Rational &f) const {
   Rational temp;
   temp.numerator = (numerator * f.denominator);
   temp.denominator = (denominator * f.numerator);
   return temp;
}

void Rational::simplify() {
   int cd = gcd(numerator, denominator);
   numerator /= cd;
   denominator /= cd;
}

void Rational::display() const {
   cout << numerator << " / " << denominator;
}

int Rational::gcd(int numerator, int denominator) const{
   while(numerator != denominator) {
      if(numerator > denominator) {
         numerator -= denominator;
      }
      else {
         denominator -= numerator;
      }
   }
   return numerator;
}

Rational getRational();
void displayResult(const string &, const Rational &, const Rational&, const Rational&);

int main() {
   Rational A, B, result;
   char choice;
   
   cout << "Enter Rational A:" << endl;
   A = getRational();
   cout << endl;
   
   cout << "Enter Rational B:" << endl;
   B = getRational();
   cout << endl;
   
   cout << "Enter Operation:" << endl
      << "a - Addition (A + B)" << endl
      << "s - Subtraction (A - B)" << endl
      << "m - Multiplication (A * B)" << endl
      << "d - Division (A / B)" << endl
      << "y - Simplify A" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 'a') {
      result = A.add(B);
      displayResult("+", A, B, result);
   } else if (choice == 's') {
      result = A.subtract(B);
      displayResult("-", A, B, result);
   } else if (choice == 'm') {
      result = A.multiply(B);
      displayResult("*", A, B, result);
   } else if (choice == 'd') {
      result = A.divide(B);
      displayResult("/", A, B, result);
   } else if (choice == 'y') {
      A.simplify();
      A.display();
   } else {
      cout << "Unknown Operation";
   }
   cout << endl;
   
   return 0;
}


Rational getRational() {
   int choice;
   int numer, denom;
   
   cout << "Which Rational constructor? (Enter 2, 1, or 0)" << endl
      << "2 - 2 parameters (numerator & denominator)" << endl
      << "1 - 1 parameter (numerator)" << endl
      << "0 - 0 parameters (default)" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 2) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      cout << "denominator? ";
      cin >> denom;
      cout << endl;
      return Rational(numer, denom);
   } else if (choice == 1) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      return Rational(numer);
   } else {
      return Rational();
   }
}

void displayResult(const string &op, const Rational &lhs, const Rational&rhs, const Rational &result) {
   cout << "(";
   lhs.display();
   cout << ") " << op << " (";
   rhs.display();
   cout << ") = (";
   result.display();
   cout << ")";
}

