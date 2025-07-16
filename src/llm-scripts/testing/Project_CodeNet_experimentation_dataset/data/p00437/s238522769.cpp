#include <iostream>
using namespace std;
struct results{
        int a;
        int b;
        int c;
        int result;
};
int main(){
        while(true){
        int parts[1000]={0};
        int aa,bb,cc,n;
        cin >> aa >> bb >> cc;
        if(aa+bb+cc==0)
                break;
        cin >> n;
        results data[1000];
        for( int i=0 ; i<n ; i++ )
                cin >> data[i].a >> data[i].b >> data[i].c >> data[i].result;
        for( int all_counter=0 ; all_counter<2 ; all_counter++)
        for( int i=0 ; i<n ; i++ ){
                if(data[i].result){
                        parts[data[i].a]=1;
                        parts[data[i].b]=1;
                        parts[data[i].c]=1;
                }
                else{
                        int level=parts[data[i].a]+parts[data[i].b]+parts[data[i].c];
                        if(level>1){
                                parts[data[i].a]==0?parts[data[i].a]=-1:0;
                                parts[data[i].b]==0?parts[data[i].b]=-1:0;
                                parts[data[i].c]==0?parts[data[i].c]=-1:0;
                        }
                }
        }
        for( int i=0+1 ; i<=aa+bb+cc ; i++ )
                if(parts[i]==-1)
                        cout << 0 << endl;
                else if(parts[i]==0)
                        cout << 2 << endl;
                else
                        cout << 1 << endl;
        }
        return 0;
}