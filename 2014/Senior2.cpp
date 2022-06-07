// This solution has AC'd on DMOJ
#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

map<string, string> partners;
vector<string> namesList;
int input;
string name;

int main() {
    cin >> input;
    for (int i = 0; i<input; i++){
        cin >> name;
        namesList.push_back(name);
    }

    for (int i = 0; i<input; i++) {
        cin >> name;

        if (namesList[i] == name) {
            cout << "bad";
            return 0;
        }

        partners[namesList[i]] = name;
    }

    for (auto i : partners) {
        if (i.first != partners[i.second]) {
            cout << "bad";
            return 0;
        }
    }

    cout << "good";
}