// This solution AC'd on DMOJ
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> dmoj;
vector<int> pegi;

int question, n, speed, total;
int main() {
    scanf("%d\n%d", &question, &n);
    
    for (int i = 0; i<n; i++) {
        scanf("%d", &speed);
        dmoj.push_back(speed);
    }

    for (int i = 0; i<n; i++) {
        scanf("%d", &speed);
        pegi.push_back(speed);
    }
    
    sort(dmoj.begin(), dmoj.end());
    sort(pegi.begin(), pegi.end());

    if (question == 2) {
        reverse(pegi.begin(), pegi.end());
    } 

    for (int i = 0; i<n; i++) {
        total+=max(dmoj[i], pegi[i]);
    }

    printf("%d", total);
    return 0;
}