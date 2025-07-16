#include<iostream>
#include<vector>

using namespace std;
long long cnt=0;
void insertionSort(int numbers[],int n,int g)
{
    for(int i=g;i<n;i++)
    {
        int v=numbers[i];
        int j=i-g;
        while(j>=0&&numbers[j]>v)
        {
            numbers[j+g]=numbers[j];
            j=j-g;
            cnt++;
        }
        numbers[j+g]=v;
    }
}
void shellSort(int numbers[],int n)
{
   // int m=2;
   //生成数列G int G[2]={4,1}
   vector<int> G;
   for(int i=1;i<=n;)
   {
       G.push_back(i);
       i=i*3+1;
   }
    for(int i=G.size()-1;i>=0;i--)
    {

        insertionSort(numbers,n,G[i]);
    }
    cout<<G.size()<<endl;
   for(int i=G.size()-1;i>0;i--)
   {
       cout<<G[i]<<" ";
   }
   cout<<G[0];
   cout<<endl;
}
int main()
{
    int n;
    cin>>n;
    int numbers[1000000];

    for(int i=0;i<n;i++)
    {
        cin>>numbers[i];
    }

    shellSort(numbers,n);
    cout<<cnt<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<numbers[i]<<endl;
    }
}



