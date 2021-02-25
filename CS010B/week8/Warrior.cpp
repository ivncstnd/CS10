#include <iostream>
#include <string>
#include "Warrior.h"

using namespace std;

Warrior::Warrior(const string &name, double health, double attackStrength, const string &allegiance) 
    : Character(WARRIOR, name, health, attackStrength), allegiance(allegiance)
{}

void Warrior::attack(Character &opp) {
    // Check if Warrior and same allegiance
    if(opp.getType() == WARRIOR) {
        Warrior &warOpp = dynamic_cast<Warrior &>(opp);
        if(warOpp.allegiance == allegiance) {
            cout << "Warrior " << name << " does not attack Warrior " << warOpp.getName() << "." << endl;
            cout << "They share an allegiance with " << allegiance << endl;
            return;
        }
    }
    // Else attack based on remaining health
    double damage = (health / MAX_HEALTH) * attackStrength;
    opp.damage(damage);
    cout << "Warrior " << name << " attacks " << opp.getName() << " --- SLASH!!" << endl;
    cout << opp.getName() << " takes " << damage << " damage." << endl;
}