#include <iostream>
#include <string>
#include "Elf.h"

using namespace std;

Elf::Elf(const string &name, double health, double attackStrength, const string &familyName) 
    : Character(ELF, name, health, attackStrength), familyName(familyName)
{}

void Elf::attack(Character &opp) {
    // Check if Elf and same allegiance
    if(opp.getType() == ELF) {
        Elf &elfOpp = dynamic_cast<Elf &>(opp);
        if(elfOpp.familyName == familyName) {
            cout << "Elf " << name << " does not attack Elf " << elfOpp.getName() << "." << endl;
            cout << "They are both members of the " << familyName << " family." << endl;
            return;
        }
    }
    // Else attack based on remaining health
    double damage = (health / MAX_HEALTH) * attackStrength;
    opp.damage(damage);
    cout << "Elf " << name << " shoots an arrow at " << opp.getName() << " --- TWANG!!" << endl;
    cout << opp.getName() << " takes " << damage << " damage." << endl;
}