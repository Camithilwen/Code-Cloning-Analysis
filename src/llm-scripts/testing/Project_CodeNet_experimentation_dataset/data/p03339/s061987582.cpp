// C Attention
#include <bits/stdc++.h>
using namespace std;

vector<int> input(int N){
    vector<int> vec;    
    int temp = 0;
    for (int i = 0; i < N; i++ )    {
        cin >> temp;
        vec.push_back(temp);
    }
    return vec;
}


int main(){
    int N; // 100
    cin >> N;
    string str;
    cin >> str;
    vector<int> east_num(N);
    vector<int> west_num(N);

    if (str.at(0)=='E'){
        east_num.at(0) = 1;
        west_num.at(0) = 0;
    }else{
        east_num.at(0) = 0;
        west_num.at(0) = 1;
    }
    for (int i =0; i <N-1; i++)    {
        if(str.at(i+1) == 'E'){
            east_num.at(i+1) = east_num.at(i)+1;
            west_num.at(i+1) = west_num.at(i);            
        }
        else{
            east_num.at(i+1) = east_num.at(i);
            west_num.at(i+1) = west_num.at(i)+1;            
        }
    }
    int min_val = east_num.at(N-1) - east_num.at(0);
    for (int i =0; i <N-1; i++)    {
        int value = east_num.at(N-1) - east_num.at(i+1) + west_num.at(i);
        if (value < min_val) min_val = value;
    }    
  /*
   for (int i =0; i <N; i++)    {
      cout << east_num.at(i) << " ";
    }
      cout << endl;
  for (int i =0; i <N; i++)    {
      cout << west_num.at(i) << " ";
    }
      cout << endl;
   */  
    cout << min_val << endl;
}