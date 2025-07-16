#include<stdio.h>
#include<stdio.h>
#include<bits/stdc++.h>
#include<vector>
#define int long long int
#define rep(a,b,c) for(int a=b;a<c;a++)
using namespace std;
void a1(){
    int i, len = 3;
    char str[] = "abc";
    for(i=0;i<len;i++){
        printf("%c\n",str[2-i]);
    }
    return;
}

int length(char str[5]){
    int cut=0;
    while(*(str+cut)!='\0'){
        cut++;
    }
    return cut;
}

void a2(){
    char a[4][5]={"ab","cdef","g","hij"};
    int i;
    for(i=0; i<4; i++){
        printf("%d\n",length(a[i]));
    }
    return;
}

void a3(){
    char str[4];
    strcpy(str,"abc");
    printf("%s\n",str);
    return;
}

void a4(){
    char a[7]="saitou",b[7] = "suzuki";
    int i;

    for(i=0;i<7;i++){
        int k = a[i]-b[i];
        if(k > 0){
            printf("%c",a[i]);
        }else if(k < 0){
            printf("%c",b[i]);
        }else{
            printf("0");
        }
    }
    printf("\n");
    return;
}

void a5(){
    char *a[3];
    int n,i,j,cut = 0;
    for(i=0;i<3;i++){
        scanf("%d",&n);
        a[i]=(char *)malloc((n+1)*sizeof(char));
        scanf("%s",a[i]);
    }
    for(i=0;i<3;i++){
        for(j=0;j<strlen(a[i]);j++){
            if(a[i][j]=='P'||a[i][j]=='p'){
                cut++;
            }
        }
    }
    printf(">> %d\n",cut);
    for(i=0;i<3;i++){
        free(a[i]);
    }
}

void y(){
    int n,m;
    vector<int> v,v2;
    while(1){
    cin >> n >> m;
    v.clear();v2.clear();
    if(n==0&&m==0)break;
    v.push_back(0);
    rep(i,0,n){
        int x;cin >> x;
        v.push_back(x);
    }
    rep(i,0,v.size()){
        rep(j,0,v.size()){
            v2.push_back(v[i]+v[j]);
        }
    }
    v2.erase(unique(v2.begin(),v2.end()),v2.end());
    sort(v2.begin(),v2.end());
    int ans=0,k=0;
    //cout << v2.size() << " a " <<  endl;
    bool a=false;
    for(int j=v2.size()-1;j>=0;j--){
        rep(i,k,v2.size()){
            k=i;
            if(v2[i]+v2[j]>m){
                //if(i==(j-1))a=true;
                break;
            }
        ans=max(ans,v2[i]+v2[j]);
        //    cout << an << " a " << endl;
        }
        if(k>j)break;
    }
    cout << ans << endl;
    }
    return;
}

signed main(){
    y();
    return 0;
}