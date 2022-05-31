// This solution AC'd on DMOJ

// Strategy
// Simulation
// everytime you play, minus a quarter, increase the machine tracker and play count
// loop back the machine tracker when you play the last machine
// each machine has an individual count that keeps track of the amount of plays it has
// when the times it has been played % its number is 0, give quarters
// print out number of plays

#include <iostream>
using namespace std;

int quarters, m1, m2, m3, plays = 0, current = 0;
int main() {
    cin >> quarters;
    cin >> m1;
    cin >> m2;
    cin >> m3;

    while (quarters > 0) {
        quarters--;
        plays++;
        current++;
        if (current == 1) {
            m1++;
            if (m1%35 == 0){
                quarters += 30;
            }
        } else if (current == 2) {
            m2++;
            if (m2%100 == 0) {
                quarters += 100;
            }
        } else {
            current = 0;
            m3++;
            if (m3%10 == 0){
                quarters += 9;
            }
        }
    }

    cout << "Martha plays " << plays << " times before going broke.";
    return 0;
}

/*
48
3
10
4
*/