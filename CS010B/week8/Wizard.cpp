#include <iostream>
#include <string>
#include "Wizard.h"

using namespace std;

Wizard::Wizard(const string &name, double health, double attackStrength, int rank) 
: Character(WIZARD, name, health, attackStrength), rank(rank)
{}

void Wizard::attack(Character &opp) {
    double damage = attackStrength;
    if(opp.getType() == WIZARD) {
        Wizard &wizOpp = dynamic_cast<Wizard &>(opp);
        damage = attackStrength * (static_cast<double>(rank) / wizOpp.rank);
    }
    opp.damage(damage);
    cout << "Wizard " << name << " attacks " << opp.getName() << " --- POOF!!" << endl;
    cout << opp.getName() << " takes " << damage << " damage." << endl;
}