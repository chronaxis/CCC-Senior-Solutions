// This solution AC'd on DMOJ

// Strategy
// Graph Theory
// Get all avaiable URLs by search for "HREF=", as that signals a url
// Substring from that to ">" to get the url
// Store list of urls in a map with the page as the key
// DFS to see if the surf is possible
// Store results in a vector with different configurations depending on the result
// print them all out when done

#include <bits/stdc++.h>
using namespace std;

int pages;
string input, hold, currentPage;

map<string, vector<string>> webPages;
map<string, bool> visited;
vector<vector<string>> surfTracker;
vector<string> pageOrder;

bool canSurf = false;
void DFS(string page, string target) {
    visited[page] = true;

    for (auto i : webPages[page]) {
        if (i == target) {
            canSurf = true;
            return; 
        }

        if (!visited[i]) {
            DFS(i, target);
        }
    }

}

void addPage(string page, string page2) {
    webPages[page].push_back(page2);
};

int main() {
    cin >> pages;
    for (int i = 1; i <= pages; i++) {
        input = "";
        cin >> currentPage;
        pageOrder.push_back(currentPage);
        while (input != "</HTML>") {
            cin >> input;
            if (input.find("HREF=") != string::npos) {
                int end = input.find(">");
                addPage(currentPage, input.substr(6, end-7));
            }
        }
    }

    while (true) {
        visited.clear();
        canSurf = false;

        cin >> input >> hold;
        if (input == "The" && hold == "End") {
            break;
        }

        DFS(input, hold);
        if (canSurf) {
            surfTracker.push_back({"Can", input, hold});
        } else {
            surfTracker.push_back({"Can't", input, hold});
        }

    }

    for (int i = 0; i<pageOrder.size(); i++) {
        for (int k = 0; k<webPages[pageOrder[i]].size(); k++) {
            cout << "Link from " << pageOrder[i] << " to " << webPages[pageOrder[i]][k] << '\n';
        }
    }

    for (int i = 0; i<surfTracker.size(); i++) {
        cout << surfTracker[i][0] << " surf from " << surfTracker[i][1] << " to " << surfTracker[i][2] << ".\n";
    }
}

/*
3
http://ccc.uwaterloo.ca
<HTML> <TITLE>This is the CCC page</TITLE>
Hello there boys
and girls.  <B>Let's</B> try <A HREF="http://abc.def/ghi"> a
little
problem </A>
</HTML>
http://abc.def/ghi
<HTML> Now is the <TITLE>time</TITLE> for all good people to program.
<A HREF="http://www.www.www.com">hello</A><A HREF="http://xxx">bye</A>
</HTML>
http://www.www.www.com
<HTML>
<TITLE>Weird and Wonderful World</TITLE>
</HTML>
http://ccc.uwaterloo.ca
http://www.www.www.com
http://www.www.www.com 
http://ccc.uwaterloo.ca
The End
*/