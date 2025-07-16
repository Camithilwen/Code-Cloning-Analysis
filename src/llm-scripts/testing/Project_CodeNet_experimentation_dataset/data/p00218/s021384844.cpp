#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
    while(1){
        int n;
        cin >> n;
        if(n == 0) break;
        for(int i = 0; i < n; i++){
            int pm,pe,pj;
            int heikin = 0;
            cin >> pm >> pe >> pj;
            heikin = pm + pe + pj;
            heikin /= 3;
            if(pm == 100 || pe == 100 || pj == 100) cout << "A" << endl;
            else if((pm + pe) / 2 >= 90) cout << "A" << endl;
            else if(heikin >= 80) cout << "A" << endl;
            else if(heikin >= 70) cout << "B" << endl;
            else if(heikin >= 50 && pm >= 80 || pe >= 80) cout << "B" << endl;
            else cout << "C" << endl;
        }
    }
	return 0;
}