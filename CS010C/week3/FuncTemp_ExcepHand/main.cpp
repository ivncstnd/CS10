#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <ctime>

using namespace std;

template <typename T>
unsigned min_index(const vector<T> &vals, unsigned index);
template <typename T>
void selection_sort(vector<T> &vals);
template <typename T>
T getElement(vector<T> vals, int index);

vector<char> createVector();
vector<string> phraseVector();

int main () {
    //Part A
    
    srand(time(0));
    //Int Vector
    cout << endl << "Int Vector" << endl;
    vector<int> intVals;
    for (int i = 0; i < 10; ++i) {
        intVals.push_back(rand() % 20 + 1);
        cout << intVals.at(i) << " ";
    } 
    cout << endl;
    selection_sort(intVals);
    cout << "Sorted values" << endl;
    for (int i = 0; i < 10; ++i) {
        cout << intVals.at(i) << " ";
    }
    cout << endl;

    //String Vector
    cout << endl << "String Vector" << endl;
    vector<string> strVals = phraseVector();
    for (int i = 0; i < 10; ++i) {
        cout << strVals.at(i) << " ";
    }
    cout << endl;
    selection_sort(strVals);
    cout << "Sorted phrases" << endl;
    for (int i = 0; i < 10; ++i) {
        cout << strVals.at(i) << " ";
    }
    cout << endl;

    //Part B
    srand(time(0));
    vector<char> vals = createVector();
    char curChar;
    int index;
    int numOfRuns = 10;
    while(--numOfRuns >= 0){
        cout << endl << "Enter a number: " << endl;
        cin >> index;
        try {
            curChar = getElement(vals,index);
        } catch (out_of_range& err) {
            cerr << "out of range exception occured" << endl;
        }
        cout << "Element located at " << index << ": is " << curChar << endl;
    }
    return 0;
}

vector<char> createVector() {
    int vecSize = rand() % 26;
    char c = 'a';
    vector<char> vals;
    for(int i = 0; i < vecSize; i++)
    {
        vals.push_back(c);
        c++;
    }
    return vals;
}

vector<string> phraseVector() {
    int vecSize = 10;
    int code;
    string phrase;
    vector<string> vals;
    for (int i = 0; i < vecSize; i++) {
        for (int j = 0; j < 3; j++) {
            code = rand() % 25 + 65;
            phrase += (char)code;
        }
        vals.push_back(phrase);
        phrase = "";
    }
    return vals;
}

template<typename T>
unsigned min_index(const vector<T> &vals, unsigned index) {
    unsigned min = index;
    for (unsigned i = index; i < vals.size(); ++i) {
        if (vals.at(min) > vals.at(i))
            min = i;
    }
    return min;
}

template<typename T>
void selection_sort(vector<T> &vals) {
    for (unsigned int i = 0; i < vals.size(); i++) {
        unsigned min = min_index(vals, i);
        T temp = vals.at(i);
        vals.at(i) = vals.at(min);
        vals.at(min) = temp;
    }
}

template<typename T>
T getElement(vector<T> vals, int index) {
    return vals.at(index);
}