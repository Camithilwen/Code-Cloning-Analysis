#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int N;
    cin>>N;
    int *vCount=new int[N],*b=new int[N],*c=new int[N+1];
    for(int i=0;i<N;++i){
        vCount[i]=0;
    }
    
    bool yesFlg=true;
    int oldA=-1,ci=0;
    for(int i=0;i<N;++i){
        int a1;
        cin>>a1;
        ++vCount[a1-1];
        if(vCount[a1-1]>N){
            yesFlg=false;
            break;
        }
        if(oldA!=a1){
            for(;ci<a1;++ci){
                c[ci]=i;
            }
            oldA=a1;
        }
    }
    for(;ci<=N;++ci){
        c[ci]=N;
    }
    
    int oldB=-1,di=0;
    
    int x=0;
    for(int i=0;i<N&&yesFlg;++i){
        int b1;
        cin>>b1;
        b[i]=b1;
        ++vCount[b1-1];
        if(vCount[b1-1]>N){
            yesFlg=false;
            break;
        }
        if(oldB!=b1){
            for(;di<b1;++di){
                int d=i;
                int x1=c[di+1]-d;
                if(x<x1){
                    x=x1;
                }
            }
            oldB=b1;
        }
    }
    for(;di<N;++di){
        int d=N;
        int x1=c[di+1]-d;
        if(x<x1){
            x=x1;
        }
    }
    
    if(yesFlg){
        cout<<"Yes"<<endl;
        for(int i=0;i<N;++i){
            int idx=(i-x)%N;
            if(idx<0){
                idx+=N;
            }
            int b1=b[idx];
            if(i==0){
                cout<<b1;
            }else{
                cout<<" "<<b1;
            }
        }
        cout<<endl;
    }else{
        cout<<"No"<<endl;
    }
    
    delete[] b;
    delete[] c;
    delete[] vCount;
    return 0;
}
