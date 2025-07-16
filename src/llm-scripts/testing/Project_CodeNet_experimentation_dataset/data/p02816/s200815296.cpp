#include<bits/stdc++.h>
using namespace std;

class MP
{
public:
    vector<long long> pattern;
    long long plen;
    vector<long long> table;
    MP(const vector<long long>& s) : pattern(s), plen((long long)pattern.size()), table(plen + 1){
        table[0] = -1;
        long long j = -1;
        for(long long i = 0; i < plen; ++i){
            while(j >= 0 && pattern[i] != pattern[j]){
                j = table[j];
            }
            table[i+1] = ++j;
        }
    }
    void search(const vector<long long>& text, vector<long long>& res){
        long long head = 0, j = 0, tlen = (long long)text.size();
        while(head + j < tlen){
            if(pattern[j] == text[head + j]) {
                if(++j == plen){
                    res.push_back(head);
                    head = head + j - table[j];
                    j = table[j];
                }
            }else{
                head = head + j - table[j];
                if(j) j = table[j];
            }
        }
    }
    void minimum_cycle(vector<long long>& res){
	    res.resize((long long)pattern.size());
	    for(long long i = 0; i < (long long)pattern.size(); ++i){
	    	res[i] = i + 1 - table[i+1];
	    }
    }
};

int main(){
    //input
    long long N;
    cin >> N;
    long long a[N], b[N];
    long long i;
    for(i=0; i<N; i++){
        cin >> a[i];
    }
    for(i=0; i<N; i++){
        cin >> b[i];
    }

    //exceptional
    if(N==1){
        cout << 0 << " " << (a[0]^b[0]) << endl;
        system("pause");
        return 0;
    }

    //calc
    vector<long long> AA,BB;
    for(i=0; i<N-1; i++){
        AA.push_back(a[i]^a[i+1]);
    }
    AA.push_back(a[N-1]^a[0]);
    for(i=0; i<N-1; i++){
        AA.push_back(a[i]^a[i+1]);
    }
    AA.push_back(a[N-1]^a[0]);
    for(i=0; i<N-1; i++){
        BB.push_back(b[i]^b[i+1]);
    }
    MP BBBB(BB);
    vector<long long> adj;
    BBBB.search(AA,adj);
    for(i=0; i<adj.size(); i++){
        if(adj[i]>=N) break;
        cout << adj[i] << " " << (a[adj[i]]^b[0]) << endl;
    }
    system("pause");
    return 0;
}