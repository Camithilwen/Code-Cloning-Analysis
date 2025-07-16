#include <bits/stdc++.h>
using namespace std;

int main(){
    string root;
    int sx, sy, tx, ty;
    int dx, dy;
    int i, j;

    cin >> sx >> sy >> tx >> ty;

    dx = tx - sx;
    dy = ty - sy;

    //root = NULL;
    //root = '\0';

    root = 'R';

    for (i=1; i<dx; i++){
        root = root + 'R';
    }
    for (i=0; i<dy; i++) {
        root = root + 'U';
    }
    for (i=0; i<dx; i++){
        root = root + 'L';
    }
    for (i=0; i<dy; i++) {
        root = root + 'D';
    }

    root = root +'L';
    for (i=0; i<dy+1; i++) {
        root = root + 'U';
    }
    for (i=0; i<dx+1; i++){
        root = root + 'R';
    }
    root = root +'D';

    root = root +'R';
    for (i=0; i<dy+1; i++) {
        root = root + 'D';
    }
    for (i=0; i<dx+1; i++){
        root = root + 'L';
    }
    root = root +'U';


    
    cout << root << endl;

}