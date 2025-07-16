#include <bits/stdc++.h>
using namespace std;
int fact(int n){
    if(n == 1) return 1;
    else return n * fact(n-1);
}

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> array(n);
    for(int i=0;i<n;i++) cin >> array.at(i).first >> array.at(i).second;
    sort(array.begin(),array.end());
    double sum = 0;
    do{
        for(int i=0;i<n-1;i++){
            int d2 = (array.at(i+1).first - array.at(i).first) * (array.at(i+1).first - array.at(i).first) +
                    (array.at(i+1).second - array.at(i).second) * (array.at(i+1).second - array.at(i).second);
            double d = sqrt((double)d2);
            sum += d;
        }
    } while(next_permutation(array.begin(),array.end()));

    int kaijou = fact(n);
    double ave = sum / (double)kaijou;
    printf("%.10lf \n",ave);
}
