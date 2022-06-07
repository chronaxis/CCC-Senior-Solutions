// works and passes CCC test cases, but DMOJ test cases TLE it :(
// most switches and if statments ever lol
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

char changeDir(char dir, char change) {
    if (change == 'R') {
        switch(dir) {
            case 'N':
                return 'E';
            case 'E':
                return 'S';
            case 'S':
                return 'W';
            case 'W':
                return 'N';
        }
    } else {
        switch(dir) {
            case 'N':
                return 'W';
            case 'W':
                return 'S';
            case 'S':
                return 'E';
            case 'E':
                return 'N';
        }
    }

    return 'l';
}

int main() {
    int r, c, m;
    char square, prev;
    vector<char> grid, directions;

    scanf("%d\n%d", &r, &c);
    for (int i = 0; i<r*c; i++) {
        cin >> square;
        grid.push_back(square);
    }

    scanf("%d", &m);
    for (int i = 0; i<m; i++) {
        cin >> square;

        if (i>0) {
            prev = directions.back();
            if ((square == 'R' && prev == 'L') || (square == 'L' && prev == 'R')) {
                directions.pop_back();
                continue;
            }
        }
        
        directions.push_back(square);
    }   

    for (int j = 0; j<4; j++) {
        for (int i = 0; i<r*c; i++) {
            if (grid[i] == 'X') {
                continue;
            }

            char dir = 'N';
            switch (j) {
                case 1:
                    dir = 'E';
                    break;
                case 2:
                    dir = 'S';
                    break;
                case 3:
                    dir = 'W';
                    break;
            }

            int pos = i;
            bool isPos = true;
            for (int k = 0; k<m; k++) {
                if (directions[k] == 'F') {
                    switch (dir) {
                        case 'N': 
                            pos -= c;
                            if (pos<0 || grid[pos] == 'X') {
                                isPos = false;
                                goto breaked;
                            }
                            break;
                        case 'E':
                            pos++;
                            if (pos%c<1 || grid[pos] == 'X') {
                                isPos = false;
                                goto breaked;
                            }
                            break;
                        case 'S':
                            pos += c;
                            if (pos>r*c-1 || grid[pos] == 'X') {
                                isPos = false;
                                goto breaked;
                            }
                            break;
                        case 'W': 
                            pos--;
                            if ((pos+1)%c<1 || grid[pos] == 'X') {
                                isPos = false;
                                goto breaked;
                            }
                            break;
                    }
                } else {
                    dir = changeDir(dir, directions[k]);
                }
            }
            
            breaked:
            if (isPos) {
                grid[pos] = '*';
            }
        }
    }

    for (int i = 0; i<r*c; i++) {
        cout << grid[i];
        if ((i+1)%c==0) {
            cout << "\n";
        }
    }
}

/*
2
4
....
.XX.
3
F
R
F
*/