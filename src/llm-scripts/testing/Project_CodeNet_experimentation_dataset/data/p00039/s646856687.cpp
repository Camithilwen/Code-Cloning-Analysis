#include <iostream>
using namespace std;

int main(){
    string ss;
    int num[128];
    num['M'] = 1000;
    num['D'] = 500;
    num['C'] = 100;
    num['L'] = 50;
    num['X'] = 10;
    num['V'] = 5;
    num['I'] = 1;
    while( cin >> ss ){
        int answer = 0;
        string::iterator it = ss.begin();
        while( it != ss.end() ){
            if( it+1 == ss.end() || num[ *it ] >= num[ *(it+1) ] ){
                answer += num[ *it ];
            }else{
                answer += num[ *(it+1) ] - num[ *it ];
                it++;
            }
            it++;
        }
        cout << answer << endl;
    }
    return 0;
}