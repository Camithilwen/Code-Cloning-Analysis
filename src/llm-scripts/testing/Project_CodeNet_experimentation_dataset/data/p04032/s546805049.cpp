#include <bits/stdc++.h>
using namespace std;

int main(){
	string s; cin >> s;
  	map<char,vector<int>> dist;
  	for(int i=0; i< s.size(); i++){
    	dist[s.at(i)].push_back(i);
      	
    }
  	/*ここからアンバランス探しmapにはアルファベットと出現箇所が紐づけ
    各アルファベットについて、隣り合ってたらok
  	*/
  	bool seikai = false;
  	for(auto& a: dist ){
    	if(a.second.size()>1){
        	for(int i=0; i< a.second.size() - 1; i++ ){
            	if((a.second[i+1] - a.second[i] ==1) ||
                   (a.second[i+1] - a.second[i]==2)){
                	cout << a.second[i] +1<< " " << a.second[i+1] +1;
                  	seikai = true;
                  	goto Finish;
                	
                }
            }
        }
    }
  	Finish:
  	if(!seikai){cout << -1 << " " << -1;}
  	cout << endl;
  	
}
