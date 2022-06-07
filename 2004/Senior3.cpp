// This solution AC'd on DMOJ
// THIS QUESTION WAS SO HARD
#include <bits/stdc++.h>
using namespace std;

string sheet[11][10];
int ans[11][10];
int vis[11][10];

int dfs(int r, int c) {
    if (ans[r][c] != -1) return ans[r][c];
    if (vis[r][c]) return -1;
    vis[r][c] = 1;

    string instruct = sheet[r][c];
    int n = 0;
    for (int i = 0; i<=instruct.size()-2; i+=2) {
        string sub = instruct.substr(i, i+2);

        int a = dfs(sub[0]-'A'+1, sub[1]-'0');
        if (a == -1) {
            ans[r][c] = -1;
            return -1;
        }
        n+=a;
    }

    ans[r][c] = n;
    return n;
}

int main() {
    string str;

    for (int i = 1; i<=10; i++) {
        for (int j = 1; j<=9; j++) {
            cin >> str;
            str.erase(remove(str.begin(), str.end(), '+'), str.end());
            sheet[i][j] = str;
            if (isdigit(str[0])) ans[i][j] = stoi(str);
            else ans[i][j] = -1;
        }
    }

    for (int i = 1; i<=10; i++) {
        for (int j = 1; j<=9; j++) {
            if (ans[i][j] == -1) {
                memset(vis, 0, sizeof(vis));
                dfs(i, j);
            }
        }
    }

    for (int i = 1; i<=10; i++) {
        for (int j = 1; j<=9; j++) {
            if (ans[i][j] == -1) {
                cout << "*" << " ";
            } else {
                cout << ans[i][j] << " ";
            }
        }
        cout << "\n";
    }
}

/*
A2+A3+A4+A5+A6+A7+A8+A9+B1+B2 A3+A4+A5+A6+A7+A8+A9+B1+B2+B3 A4+A5+A6+A7+A8+A9+B1+B2+B3+B4 A5+A6+A7+A8+A9+B1+B2+B3+B4+B5 A6+A7+A8+A9+B1+B2+B3+B4+B5+B6 A7+A8+A9+B1+B2+B3+B4+B5+B6+B7 A8+A9+B1+B2+B3+B4+B5+B6+B7+B8 A9+B1+B2+B3+B4+B5+B6+B7+B8+B9 B1+B2+B3+B4+B5+B6+B7+B8+B9+C1
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
*/