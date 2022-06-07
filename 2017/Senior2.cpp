// This code has AC'd on DMOJ
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int measurements;
    cin >> measurements;
    vector<int> tides(measurements);
    for (int i = 0; i < measurements; i++) {
        cin >> tides[i];
    }

    sort(tides.begin(), tides.end());

    int half = measurements/2;
    if (measurements%2!=0) {
        half++;
        for (int i = 0; i < half; i++) {
            if (i+1 == half) {
                cout << tides[half-(i+1)];
            } else {
                cout << tides[half-(i+1)] << " " << tides[half+i] << " ";
            }
        }   
    } else {
        for (int i = 0; i < half; i++) {
            if (i+1 == half) {
                cout << tides[half-(i+1)] << " " << tides[half+i];
            } else {
                cout << tides[half-(i+1)] << " " << tides[half+i] << " ";
            }
        }    
    }
}