#include<iostream>
#include<string.h>
#include<vector>
#include<list>
#include<stdio.h>
#include<math.h>
#include<iomanip>
#include<map>
#include<stack>
#include<queue>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) range(i,0,b)
#define debug(x) cout << "debug " << x << endl;
using namespace std;

int main(){
    int distance[10], v1, v2;
    char garbage;
    while(cin >> distance[0]){
        cin >> garbage;
        double lineLength = distance[0];
        range(i,1,10){
            cin >> distance[i] >> garbage;
            lineLength+= distance[i];
        }
        cin >> v1 >> garbage >> v2;
        double sum_v = v1 + v2;
        double time = lineLength / sum_v;
        double pass_location = v1 * time;
        rep(i,10){
            pass_location-= static_cast<double>(distance[i]);
            if(pass_location <= 0){
                cout << i + 1 << endl;
                break;
            }
        }
    }
}