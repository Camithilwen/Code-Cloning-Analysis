#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <climits>
#include <cfloat>
using namespace std;

int main()
{
    for(;;){
        vector<int> card(5);
        if(!(cin >> card[0]))
            return 0;

        for(int i=1; i<5; ++i){
            char c;
            cin >> c >> card[i];
        }
        sort(card.begin(), card.end());

        vector<int> num(5, 0);
        for(int i=0; i<5; ++i){
            int j = i+1;
            while(j < 5 && card[j] == card[i])
                ++ j;
            ++ num[j-i];
            i = j-1;
        }

        if(num[4] == 1)
            cout << "four card" << endl;
        else if(num[3] == 1 && num[2] == 1)
            cout << "full house" << endl;
        else if(num[3] == 1)
            cout << "three card" << endl;
        else if(num[2] == 2)
            cout << "two pair" << endl;
        else if(num[2] == 1)
            cout << "one pair" << endl;
        else if(card[0] == 1 && card[1] + 3 == card[4])
            cout << "straight" << endl;
        else if(card[0] + 4 == card[4])
            cout << "straight" << endl;
        else
            cout << "null" << endl;
    }
}