#include <bits/stdc++.h>
using namespace std;
#define rep( i, n, m ) for(int i = ( n ); i < ( m ); i++)
int main(void){
	int N;
  	cin >> N;
  	vector<pair<float, int>> vec(N);
  	float avg = 0.0f;
  	rep(i,0,N){
      	int input;
      	cin >> input;
      	vec[i] = make_pair(input, i);
      	avg+=(float)vec[i].first;
    }
  	avg/=N;
  	float minimum  = vec[0].first;
  	rep(i,0,N){
      	vec[i].first = abs(vec[i].first- avg);
      	if (minimum > vec[i].first)
          	minimum = vec[i].first;
    }
  	rep(i,0,N){
      	if ( minimum == vec[i].first){
    		cout << i << endl; 
          	return 0;
      	}
    }
}
        	