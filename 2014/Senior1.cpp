// This solution AC'd on DMOJ
#include <iostream>
#include <vector>
using namespace std;    

int n, rounds, m;
vector<int> friends;
int main() {
    cin >> n;
    for (int i = 0; i<n; i++) {
        friends.push_back(i+1);
    }

    cin >> rounds;
    for (int i = 0; i<rounds; i++) {
        vector<int> eraseList;
        cin >> m;
        for (int k = 0; k<friends.size(); k++) {
            if ((k+1)%m == 0) {
                eraseList.push_back(friends[k]);
            }
        }

        for (int k = 0; k<eraseList.size(); k++) {
            for (int j = 0; j<friends.size(); j++) {
                if (friends[j] == eraseList[k]) {
                    friends.erase(friends.begin() + j);
                    break;
                }
            }
        }
    }

    for (int i : friends) {
        cout << i << '\n';
    }
}