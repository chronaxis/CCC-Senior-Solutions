// This solution AC'd on DMOJ
// Simulation problem
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int clubsP = 0, diamondsP = 0, heartsP = 0, spadesP = 0;
    vector<char> clubs, diamonds, hearts, spades;
    string line, current;
    cin >> line;

    for (int i = 0; i<17; i++) {
        if (line[i] == 'C') current = "C";
        else if (line[i] == 'D') current = "D";
        else if (line[i] == 'H') current = "H";
        else if (line[i] == 'S') current = "S";

        else if (current == "C") {
            if (line[i] == 'A') clubsP += 4;
            if (line[i] == 'K') clubsP += 3;
            if (line[i] == 'Q') clubsP += 2;
            if (line[i] == 'J') clubsP += 1;
            clubs.push_back(line[i]);
        }
        
        else if (current == "D") {
            if (line[i] == 'A') diamondsP += 4;
            if (line[i] == 'K') diamondsP += 3;
            if (line[i] == 'Q') diamondsP += 2;
            if (line[i] == 'J') diamondsP += 1;
            diamonds.push_back(line[i]);
        }

        else if (current == "H") {
            if (line[i] == 'A') heartsP += 4;
            if (line[i] == 'K') heartsP += 3;
            if (line[i] == 'Q') heartsP += 2;
            if (line[i] == 'J') heartsP += 1;
            hearts.push_back(line[i]);
        }

        else {
            if (line[i] == 'A') spadesP += 4;
            if (line[i] == 'K') spadesP += 3;
            if (line[i] == 'Q') spadesP += 2;
            if (line[i] == 'J') spadesP += 1;
            spades.push_back(line[i]);            
        }
    }

    if (clubs.size() == 0) clubsP+=3;
    if (clubs.size() == 1) clubsP+=2;
    if (clubs.size() == 2) clubsP+=1;

    if (diamonds.size() == 0) diamondsP+=3;
    if (diamonds.size() == 1) diamondsP+=2;
    if (diamonds.size() == 2) diamondsP+=1;

    if (hearts.size() == 0) heartsP+=3;
    if (hearts.size() == 1) heartsP+=2;
    if (hearts.size() == 2) heartsP+=1;

    if (spades.size() == 0) spadesP+=3;
    if (spades.size() == 1) spadesP+=2;
    if (spades.size() == 2) spadesP+=1;

    cout << "Cards Dealt Points\n";

    cout << "Clubs ";
    for (int i = 0; i<clubs.size(); i++) {
         cout << clubs[i] << " ";
    }
    cout << clubsP << '\n';

    cout << "Diamonds ";
    for (int i = 0; i<diamonds.size(); i++) {
         cout << diamonds[i] << " ";
    }
    cout << diamondsP << '\n';

    cout << "Hearts ";
    for (int i = 0; i<hearts.size(); i++) {
         cout << hearts[i] << " ";
    }
    cout << heartsP << '\n';

    cout << "Spades ";
    for (int i = 0; i<spades.size(); i++) {
         cout << spades[i] << " ";
    }
    cout << spadesP << '\n';
    cout << " Total " << clubsP+diamondsP+heartsP+spadesP;
}
