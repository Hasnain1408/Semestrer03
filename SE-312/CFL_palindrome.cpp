#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> str = {"e", "0", "1", "0P0", "1P1"};

bool doesexist(string temp) {
    return (find(str.begin(), str.end(), temp) != str.end());
}

int findpositionp(string way) {
    int pos = -1;
    for(int i = 0; i < way.size(); i++) {
        if(way[i] == 'P') {
            pos = i;
            break;
        }
    }
    return pos;
}

void generate_cfg(string s) {
    string temp, way = "P";
    cout << "P -> ";

    for(int i = 0, j = s.size() - 1; i < j; i++, j--) {
        if(s[i] != s[j]) {
            cout << "NOT IN THIS LANGUAGE";
            return;
        }

        temp = "";
        temp = temp + s[i] + "P" + s[j];

        if(doesexist(temp)) {
            int pos = findpositionp(way);
            if (pos != -1) {
                way = way.replace(pos,1, temp);
            }
        }

        cout << way << " -> ";
    }

    cout << s << endl;
}

int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;
    generate_cfg(s);
    return 0;
}
