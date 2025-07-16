#include<iostream>
#include<cstring>

using namespace std;

char str[1010];

int main(){
    scanf("%s",str);
    int len=strlen(str);
    int res=0;
    for(int i=0;i<len;++i){
        int cnt=0;
        while(i<len&&str[i]=='R'){
            cnt++;
            i++;
        }
        res=max(cnt,res);
    }
    cout<<res<<endl;
    return 0;
}