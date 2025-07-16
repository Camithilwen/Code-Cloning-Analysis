#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000

template <typename T,typename U>
struct compressor{
	vector<pair<T,U>> v;
	void add(T x,U y){
		v.emplace_back(x,y);
	}
	
	void compress(bool stable = false){
		
		if(stable){
			stable_sort(v.begin(),v.end(),[&] (pair<T,U> a,pair<T,U> b){
				return a.first < b.first;
			}
			);
		}
		else sort(v.begin(),v.end());
		
		vector<pair<T,U>> t;
		rep(i,v.size()){
			if(t.size()!=0 && t.back().first == v[i].first){
				t.back().second = func(t.back().second,v[i].second);
			}
			else{
				t.push_back(v[i]);
			}
		}
		swap(v,t);
		
	}

	U func(U a,U b){
		return a+b;
	}

	U e(){
		return 0;
	}

	int size(){
		return v.size();
	}
	
	pair<T,U> get(int p){
		return v[p];
	}
	
	U operator[] (T &x){
		auto it = lower_bound(v.begin(),v.end(),make_pair(x,e()));
		if(it==v.end() || it->first!=x){
			if(it!=v.begin()){
				it--;
			}
		}
		if(it==v.end() || it->first!=x){
			return e();
		}
		else return it->second;
	}
	
	U operator[] (T x){
		auto it = lower_bound(v.begin(),v.end(),make_pair(x,e()));
		if(it==v.end() || it->first!=x){
			if(it!=v.begin()){
				it--;
			}
		}
		if(it==v.end() || it->first!=x){
			return e();
		}
		else return it->second;
	}
};

bool f = false;
compressor<pair<string,string>,int> get(string S){
	int N = S.size();
	compressor<pair<string,string>,int> C;
	for(int i=0;i<(1<<N);i++){
		string s="",t="";
		for(int j=0;j<N;j++){
			if((i>>j)&1)s+=S[j];
			else t+=S[j];
		}
		reverse(t.begin(),t.end());
		if(f)swap(s,t);
		C.add(make_pair(s,t),1);
	}
	f=true;
	C.compress();
	return C;
}
 
int main(){
	
	int N;
	cin>>N;
	
	string S;
	cin>>S;
	
	compressor<pair<string,string>,int> C0 = get(S.substr(0,N)),C1 = get(S.substr(N));
	
	long long ans = 0;
 
	rep(i,C0.size()){
		ans += (long long)C0.get(i).second * C1[C0.get(i).first];
	}
	
	cout<<ans<<endl;
	
	return 0;
}
