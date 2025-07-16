#include <bits/stdc++.h>
using namespace std;
using P=pair<int,int>;
int main(){
    int N;
    cin>>N;
    vector<P> Bracketfirst(0);
    vector<P> Bracketsecond(0);
    //A (
    //B )
    for(int i=0;i<N;i++){
        int A=0,B=0;
        string S;
        cin>>S;
        for(int j=0;j<(int)S.size();j++){
            if(S.at(j)=='('){
                A++;
            }
            else{
                if(A>0){
                    A--;
                }
                else{
                    B++;
                }
            }
        }
        if(A>=B){
            Bracketfirst.push_back(make_pair(B,A));
        }
        else{
            Bracketsecond.push_back(make_pair(A,B));
        }
    }
    sort(Bracketfirst.begin(),Bracketfirst.end());
    sort(Bracketsecond.begin(),Bracketsecond.end());
    reverse(Bracketsecond.begin(),Bracketsecond.end());
    string answer="";
    for(int i=0;i<(int)Bracketfirst.size();i++){
        //cout<<Bracket.at(i).first<<" "<<Bracket.at(i).second<<endl;
        for(int j=0;j<Bracketfirst.at(i).first;j++){
            answer+=")";
        }
        for(int j=0;j<Bracketfirst.at(i).second;j++){
            answer+="(";
        }
    }
    for(int i=0;i<(int)Bracketsecond.size();i++){
        //cout<<Bracket.at(i).first<<" "<<Bracket.at(i).second<<endl;
        for(int j=0;j<Bracketsecond.at(i).second;j++){
            answer+=")";
        }
        for(int j=0;j<Bracketsecond.at(i).first;j++){
            answer+="(";
        }
    }
    //cout<<answer<<endl;
    int a=0,b=0;
    for(int i=0;i<(int)answer.size();i++){
        if(answer.at(i)=='('){
            a++;
        }
        if(answer.at(i)==')'){
            b++;
        }
        if(a<b){
            cout<<"No"<<endl;
            return 0;
        }
    }
    if(a==b){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}