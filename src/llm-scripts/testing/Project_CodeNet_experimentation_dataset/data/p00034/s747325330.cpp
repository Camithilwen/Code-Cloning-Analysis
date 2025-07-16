#include<iostream>
#include<map>
using namespace std;

int main(void){

    int l[10];
    int v1,v2;
    char c;


    while(cin >> l[0]){
        int sum = 0;
        int ans=0;
        sum= l[0];

        for(int i = 1;i < 10;i++){
            cin >> c >> l[i];
            sum+=l[i];
        }
        cin >> c >> v1 >> c >> v2;
        //cout << v1 << " " << v2 << endl;

        double ti = sum/double(v1+v2);
        double tmp = ti*double(v1);
        //cout << ti << " " << tmp << endl;

        for(int i = 0;i < 10;i++){
            tmp-=l[i];
            if(tmp<=0){
                ans=i+1;
                break;
            }

        }
        cout << ans << endl;

    }

   
    
    return 0;
}

