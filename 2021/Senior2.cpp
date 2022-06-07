// This solution AC'd on DMOJ
#include <iostream>
using namespace std;

int row, col, inputs, ind, gold = 0, oddrows = 0, oddcols;
char r_or_c, rows[5000000], columns[5000000];
int main() {
    cin >> col;
    cin >> row;
    cin >> inputs;

    for (int i = 0; i < inputs; i++) {
        cin >> r_or_c >> ind;
        ind--;
        if (r_or_c == 'R') {
            if (rows[ind] == 'G') {
                rows[ind] = 'B';
                oddrows--;
            } else {
                rows[ind] = 'G';
                oddrows++;
            }
        } else {
            if (columns[ind] == 'G') {
                columns[ind] = 'B';
                oddcols--;
            } else {
                columns[ind] = 'G';
                oddcols++;
            }
        }
    }

    gold = (oddrows * row) + (oddcols * col);
    gold -= oddcols * oddrows * 2;

    cout << gold;
    return 0;    
}
