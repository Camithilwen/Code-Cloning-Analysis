    #include <bits/stdc++.h>
    using namespace std;
     
    int main() {
      int A;
      cin >> A;
      int B;
      cin >> B;
      int count=0;
      int a1,a2,a3,a4;
      // ここにプログラムを追記
      for(int i=0;i<B-A+1;i++){
        a1=(A+i)/10000;
        a2=((A+i)%10000)/1000;
        a3=(((A+i)%10000)%1000)%100/10;
        a4=(((A+i)%10000)%1000)%100%10;
        if(a1==a4 && a2==a3){
          count++;
        }
      }
      cout << count << endl;
      
    }