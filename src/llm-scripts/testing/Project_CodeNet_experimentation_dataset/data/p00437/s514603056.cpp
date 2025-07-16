#include<iostream>
#include<vector>
using namespace std;

struct data{
    int a, b, c;
    data(int _a, int _b, int _c) : a(_a), b(_b), c(_c) {}
};

int main(){
    int a, b, c;
    while(cin >> a >> b >> c){
        if(a + b + c == 0)  break;

        int da[a], db[b], dc[c];
        for(int i = 0; i < a; i++) da[i] = 0;
        for(int i = 0; i < b; i++) db[i] = 0;
        for(int i = 0; i < c; i++) dc[i] = 0;

        vector<data> fault;
        
        int n;
        cin >> n;

        while(n-- > 0){
            int i, j, k, r;
            cin >> i >> j >> k >> r;
            if(r == 0)  fault.push_back(data(i,j,k));
            else        da[i-1] = db[j-a-1] = dc[k-a-b-1] = 1;
        }

        bool update = true;
        while(update){
            update = false;
            for(data d : fault){
                if(da[d.a-1] > 1 || db[d.b-a-1] > 1 || dc[d.c-a-b-1] > 1)
                   continue;
                if(da[d.a-1] + db[d.b-a-1] + dc[d.c-a-b-1] == 2){
                    update = true;
                    if(da[d.a-1] == 1 && db[d.b-a-1] == 1)         dc[d.c-a-b-1] = 2;
                    else if(db[d.b-a-1] == 1 && dc[d.c-a-b-1] == 1)    da[d.a-1] = 2;
                    else if(dc[d.c-a-b-1] == 1 && da[d.a-1] == 1)    db[d.b-a-1] = 2;
                }
            }
        }

        for(int i = 0; i < a; i++)  cout << 2-da[i] << endl;
        for(int i = 0; i < b; i++)  cout << 2-db[i] << endl;
        for(int i = 0; i < c; i++)  cout << 2-dc[i] << endl;
    }
    
    return 0;
}
