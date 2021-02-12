#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;

void readData(const string &, vector<double> &, vector<double> &);
double interpolation(double, const vector<double> &, const vector<double> &);
bool isOrdered(const vector<double> &);
void reorder(vector<double> &, vector<double> &);

int main(int argc, char* argv[]) {
    
    string filename;
    string replay = " ";
    vector<double> angles;
    vector<double> coeffs;
    double inAngle;

    filename = argv[1];

    while(replay != "No") {
        cin >> inAngle;
        readData(filename, angles, coeffs);

        bool inOrder = isOrdered(angles);
        if(!inOrder){
            reorder(angles, coeffs);
        }

        double outCoeff = interpolation(inAngle, angles, coeffs);
        cout << outCoeff << endl;

        cin >> replay;
    }

    return 0;
}

void readData(const string &filename, vector<double> &angles, vector<double> &coeffs) {
   
    ifstream inFS;

    inFS.open(filename);

    if(!inFS.is_open()) {
        cout << "Error opening " << filename << endl;
        exit(1);
    }
    else {
        string line;

        while(!inFS.eof()) {
            while(getline(inFS, line)){
                istringstream inSS;
                double angleNum;  
                double coeffNum;

                inSS.str(line);
                inSS >> angleNum >> coeffNum;

                angles.push_back(angleNum);
                coeffs.push_back(coeffNum);
            }
        }
    }

    inFS.close();
}

double interpolation(double inAngle, const vector<double> &angles, const vector<double> &coeffs) {

    double angleUpperBound;
    double coeffUpperBound;
    double angleLowerBound;
    double coeffLowerBound;
    double outCoeff;

    for(unsigned int i = 0; i < angles.size(); i++) {
        if(inAngle == angles[i]) {
            return outCoeff = coeffs[i];
        }
        else if(inAngle > angles[i]) {
            angleLowerBound = angles[i];
            coeffLowerBound = coeffs[i];
        }
        else if(inAngle < angles[i]) {
            angleUpperBound = angles[i];
            coeffUpperBound = coeffs[i];
            break;
        }
    }

    outCoeff = (((inAngle - angleLowerBound) * (coeffUpperBound - coeffLowerBound)) / (angleUpperBound - angleLowerBound)) + coeffLowerBound;

    return outCoeff;
}

bool isOrdered(const vector<double> &angles) {
   
    bool inOrder = true;

    if(!angles.empty()) {
        for(unsigned int i = 0; i < angles.size()-1; i++) {
            if(angles[i] > angles[i+1]) {
                inOrder = false;
                break;
            }
        }
    }
    else {
        inOrder = true;
    }

    return inOrder;
}

void Swap(double &x, double &y) {
    double temp = x;
    x = y;
    y = temp;
}

void reorder(vector<double> &angles, vector<double> &coeffs) {
    if(!angles.empty()) {
        for(unsigned int i = 0; i < angles.size()-1; i++) {
            for(unsigned int j = 0; j < angles.size()-1; j++) {
                if(angles[j] > angles[j+1]) {
                    Swap(angles[j], angles[j+1]);
                    Swap(coeffs[j], coeffs[j+1]);
                }
            }
        }
    }
}