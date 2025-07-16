#include <iostream>

using namespace std;

#define MIN(a,b) ((a)<(b)?(a):(b))

int main()
{
    int P;
    int minR=200,minS=200;
    int total=0;

    for(int i=0; i<4; ++i) {
        cin >> P;
        total+=P;
        minR=MIN(P,minR);
    }
    for(int i=0; i<2; ++i) {
        cin >> P;
        total+=P;
        minS=MIN(P,minS);
    }
    cout << total - minR - minS << endl;
    return 0;
}