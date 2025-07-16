#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, count;
    cin >> N;
    count = 0;
    vector<int> vec(N);
    for(int i = 0; i < N; i++){
        cin >> vec.at(i);
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < i; j++){
            for(int k = 0; k < j; k++){
                if((abs(vec.at(i) - vec.at(j)) < vec.at(k) && vec.at(k) < vec.at(i) + vec.at(j)) && vec.at(i) != vec.at(j) && vec.at(j) != vec.at(k)&& vec.at(k) != vec.at(i))
                count++;
        }
      
     }
       
	}
  cout << count << endl;
}