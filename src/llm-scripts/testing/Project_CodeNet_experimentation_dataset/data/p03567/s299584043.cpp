#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void computeLPSArray(string pattern, int m, int lps[]){
    int len=0;
    lps[0]=0;   //lps[0] is always 0
    int i=1;
    while(i<m){
        if(pattern[i]==pattern[len]){
            len++;
            lps[i]=len;
            i++;
        }else{
            if(len!=0)
                len=lps[len-1];
            else{
                lps[i]=0;
                i++;
            }
        }
    }
}
void kmpSearch(string str,string pattern){
    int m=pattern.length();
    int n=str.length();
    int lps[m];  //longest prefix suffix array
    computeLPSArray(pattern,m,lps);
    int i=0; //text
    int j=0; //pattern
    bool found=0;
    while(i<n){
        if(pattern[j]==str[i]){
            i++;
            j++;
        }
        if(j==m){
            j=lps[j-1];
            found=1;
            break;
        }else if(i<n && pattern[j]!=str[i]){
            if(j!=0) j=lps[j-1];
            else i=i+1;
        }
    }
    if(!found)cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    string str,pattern;
    while(cin>>str){
        pattern="AC";
        kmpSearch(str,pattern);
    }
    return 0;
}

