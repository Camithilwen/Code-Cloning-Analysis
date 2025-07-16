#include<iostream>
using namespace std;
int main(void){

    int n;
    cin >> n;
    int a,b,c,d;
    int score[1000]={0};
    int count=0;
    for(int i=0;i<n*(n-1)/2;i++){
        cin>>a>>b>>c>>d;
        if(c>d)score[a]+=3;
        else if(c<d)score[b]+=3;
        else if(c==d)score[a]++,score[b]++;

    }
    for(int i=1;i<=n;i++){
        count = 1;
        for(int j=1;j<=n;j++){
            if(score[i]<score[j])count++;
        }
        cout<<count<<endl;
    }


    return 0;
}