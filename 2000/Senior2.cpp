// This solution AC'd on DMOJ

// Strategy
// Simulation
// Get all streams and store them in a vector
// Procress each change by inserting and deleting elements
// Print out each stream rounded up

#include <iostream>
#include <vector>
using namespace std;

int startingStreams;
int main() {
    cin >> startingStreams;
    vector<double> streams(startingStreams+1);
    for (int i=1; i <= startingStreams; i++) {
        cin >> streams[i];
        cout << streams[i];
    }

    int nextChange;
    while (nextChange != 77) {
        cin >> nextChange;       
        int index, ratio;
        if (nextChange == 99) {
            cin >> index >> ratio;
            double current = streams[index];
            streams[index] = current * ratio/100;
            streams.insert(streams.begin()+index+1, current*(100-ratio)/100);
        }
        else if (nextChange == 88) {
            cin >> index;
            streams[index] = streams[index]+streams[index+1];
            streams.erase(streams.begin()+index+1);
        }
    }
    for (int i=1; i<streams.size(); i++){
        cout << (int)(streams[i]+0.5) << " ";
    }
    cout << endl;
    return 0;
}

/*
3
10
20
30
99
1
50
88
3
88
2
77
*/