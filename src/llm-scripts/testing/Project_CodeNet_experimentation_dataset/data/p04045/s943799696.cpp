        #include<bits/stdc++.h>
        using namespace std;
        int main(){
          int n;
          cin>>n;
          int k;
          cin>>k;
          bool arr[k];
         // memset(arr,false,sizeof(arr));
          int temp;
          for(int i=0;i<10;i++)
            arr[i] = false;
          for(int i=0;i<k;i++){
            cin>>temp;
            arr[temp] = true;
          }

          while(true){
            bool flag=true;
            int l = n;

            while(l!=0){
              int rem = l%10;
              if(arr[rem]==true){
                flag = false;
                break;
              }
              l = l/10;
            }
            if(flag == true){
              cout<<n;
              break;
            }
            n++;
          }
        }
