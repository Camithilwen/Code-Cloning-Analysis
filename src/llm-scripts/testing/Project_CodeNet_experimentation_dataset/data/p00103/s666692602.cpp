#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int score = 0, out = 0;
        int bases[3] = {};
        while (true) {
            char event[8];
            cin >> event;
            if (strcmp(event, "OUT") == 0) {
                out++;
                if (out == 3) {
                    break;
                }
            } else if (strcmp(event, "HIT") == 0) {
                score += bases[2];
                bases[2] = bases[1];
                bases[1] = bases[0];
                bases[0] = 1;
            } else if (strcmp(event, "HOMERUN") == 0) {
                score += bases[0] + bases[1] + bases[2] + 1;
                bases[0] = bases[1] = bases[2] = 0;
            }
        }
        cout << score << endl;
    }
}