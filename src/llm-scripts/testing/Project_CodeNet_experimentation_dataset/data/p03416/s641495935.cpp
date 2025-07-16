#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;
int kaibunnsuu (int n){
    vector<int> N;
    while(n > 0){
        int ind_digit = n % 10;
        N.push_back(ind_digit) ;
        n = n /10;
    }
    int size = N.size() ;
    vector<int> rev_N(size);
    for(int i=0;i<size;i++){
        rev_N.at(i) = N.at(i);
    }
    reverse(rev_N.begin(), rev_N.end());
    
    bool judge = false;
    for(int i=0;i<size;i++){
        if( rev_N.at(i)!=N.at(i) ){
            break;
        }
        else if((i==size -1)&&(rev_N.at(i)==N.at(i))){
            judge = true;
        }
    }
    if(judge){
        return 1;
    }
    else{
        return 0;
    }
}

int main() {
    int A,B;
    cin >> A >> B;
    int count =0;
    for(int i=A;i<=B;i++){
        count = count +kaibunnsuu(i);
    }
    cout << count << endl;
}