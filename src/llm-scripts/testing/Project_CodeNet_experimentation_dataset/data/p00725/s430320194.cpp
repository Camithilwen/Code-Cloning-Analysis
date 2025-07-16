#include <iostream>
#include <queue>
#define H 20+1
#define W 20+1
using namespace std;

signed char di[4] = { 1,0,-1,0 }; // i+, j+, i-, j-
signed char dj[4] = { 0,1, 0,-1};

typedef struct {
  char s[H][W]; // ÕÊÌóÔ
  char n;         // Ú®ñ
  char d;         // ±ê©çÚ®·éûü
  char i,j;       // »Ýn
} P;

int main(){
  short h,w, b;
  P p, p2;
  queue<P> q;
  short gi,gj;

  while( cin>>w>>h && (w||h) ){
    while( q.size()>0 ) q.pop();

    for( int i=1;i<=h;i++ )
      for( int j=1;j<=w;j++ ){
	cin >> b;
	p.s[i][j] = b;
	if( b==2 ){ p.i = i; p.j=j; p.s[i][j]=0; }
	else if( b==3 ){ gi=i; gj=j; }
      }
    p.n=1;
    for( int i=0;i<4;i++ ){
      p.d = i;
      q.push( p );
    }

    signed char ans = -1;
    while( q.size()>0 ){
      p = q.front(); q.pop();

      int i=p.i, j=p.j;
      bool f=true;
      while( f ){
	int in=i+di[p.d], jn=j+dj[p.d];

	if( in<1 || in>h || jn<1 || jn>w )
	  break;

	switch( p.s[ in ][ jn ] ){
	case 0: // ½àÈ¢
	  i=in; j=jn;
	  break;
	case 1: // áQ¨
	  if( p.i==i && p.j==j ){
	    f=false; break;
	  }
	  if( p.n==10 ){
	    f=false; break;
	  }else if( p.n==9 ){
	    if( i-gi!=0 && j-gj!=0 ){
	      f=false; break;
	    }
	  }
	  p2 = p;
	  p2.i=i; p2.j=j; p2.n++;
	  p2.s[ in ][ jn ] = 0; 
	  for( int k=0;k<4;k++ ){
	    p2.d = k; q.push( p2 );
	  }
	  f=false;
	  break;
	case 3: // S[
	  ans = p.n; f=false;
	  break;
	}
      }
      if( ans>0 ) break;
    }
    cout << (int)ans << endl;
  }

  return 0;
}