#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	double n,m,l;
  cin>>n>>m>>l;
  
 	if(l==0){
    	cout << std::setprecision(20) <<(m-1)/n<<endl;
    }else{
    	cout << std::setprecision(20) <<(m-1)*(2*(n-l))/(n*n)<<endl;
    }

}
