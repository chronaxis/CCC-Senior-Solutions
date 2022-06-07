#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, p, highest = 0, highestN;
    string name, mostCalled;
    map<int, string> phone;
    map<int, int> called;
    cin >> n;

    for (int i = 0; i<n; i++) {
        cin >> name >> p;
        phone[p] = name;
    }

    cin >> n;
    for (int i = 0; i<n; i++) {
        cin >> p;
        called[p]++;

        if (called[p]>highest) {
            mostCalled = phone[p];
            highest = called[p];
            highestN = p;
        }

        if (called[p] == highest) {
            if (p < highestN) {
                mostCalled = phone[p];
                highest = called[p];
                highestN = p;
            }
        }
    }

    cout << mostCalled;
}

/*
5
Mary 26000404
Susan 92132122
May 21232132
Ann 62343244
Peter 21321322
8
92132122
62343244
62343244
26000404
21321322
21232132
62343244
92132122
*/