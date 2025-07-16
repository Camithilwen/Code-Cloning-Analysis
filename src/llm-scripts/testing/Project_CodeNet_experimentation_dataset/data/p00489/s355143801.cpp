#include <iostream>
#include <vector>
using namespace std;

int main(){
  int N;
  int p[100], order[100];
  int a,b,c,d;
  vector<int> v;

  cin >> N;
  for( int i=0;i<N;i++ ) p[i]=0;
  for( int i=0,len=N*(N-1)/2;i<len;i++ ){
    cin >>a >> b >> c >> d;
    //    cout << a<<b<<c<<d<<endl;
    a--; b--;
    if( c==d ){ // テつ暗δクテつづつォテつ陛つェテつづつッ
      p[a]++; p[b]++;
    }else if( c>d )
      p[a]+=3;
    else 
      p[b]+=3;
  }
  /*
  for( int i=0;i<N;i++ )
    cout << "p "<<p[i] << endl;    
  */
  for( int i=1;i<=N; ){ // テつ湘つつ暗δ甘つεつ凝つーテつプ
    //    cout << "No."<<i<<endl;
    v.clear();
    int max = -1;
    for( int j=0;j<N;j++ ){
      if( p[j]>max ){
	max=p[j];
	//	cout << " max="<<j<<endl;
	v.clear();
	v.push_back( j );
      } else if( p[j]==max ){
	v.push_back( j );
      }
    }
    for( int j=0;j<v.size();j++ ){
      order[v[j]] = i; p[v[j]] = -10;
    }
    i+=v.size();
  }
  for( int i=0;i<N;i++ )
    cout << order[i] << endl;
  

  return 0;
}