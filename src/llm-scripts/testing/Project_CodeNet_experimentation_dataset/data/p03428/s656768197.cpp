#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool nul[200];
bool nul1[200];
int main() {
	ios_base::sync_with_stdio(false);
	cout.precision(15);
	double pog =1/10e10;
	int n;
	cin>>n;
	double x[200], y[200];
	for(int i=0;i<n;i++){
		cin>>x[i]>>y[i];
	}
	if(n==2){
		cout<<"0.5"<<endl<<"0.5";
		return 0;
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
            		int r=0;
            		bool h=1;
            		for(int k=0;k<n;k++){
            			if(k!=i&&k!=j){
            				double s=(x[i]-x[k])*(y[i]-y[j])-(y[i]-y[k])*(x[i]-x[j]);
            				if(s>pog){
                        				if(r==-1){
                        					h=0;
                        				}
                        				r=1;
            				}
            				if(s+pog<0){
                        				if(r==1){
                        					h=0;
                        				}
                        				r=-1;
            				}
            			}
            		}
			if(h==1){
            			nul[i]=1;
		        		nul[j]=1;
		        	//	cout<<i<<" "<<j<<endl;
            		}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				if(k!=i&&j!=i&&j!=k){
					double s=(x[i]-x[k])*(y[i]-y[j])-(y[i]-y[k])*(x[i]-x[j]);
					if(s<pog&&s+pog>0){
                        				double f=abs(x[i]-x[k])+abs(y[i]-y[k]);
                        				double g=abs(x[i]-x[j])+abs(y[i]-y[j]);
                        				double s=abs(x[j]-x[k])+abs(y[j]-y[k]);
                        			//	cout<<i<<" "<<j<<endl;
                        				if(g+f+pog>s&&g+f-pog<s){
                        					nul1[i]=1;
                        	//	cout<<"eys"<<endl;		
                        				}
            				}
				}
			}
		}
	}
	double ans[200];
 
	for(int i=0;i<n;i++){
		if(nul[i]==0||nul1[i]==1){
            		ans[i]=0;
		}
		else{
            		int j1;
            		int j2;
            		int j3;
            		int sled=0;
            		for(int j=0;j<n;j++){
            			int r=0;
            			bool h=1;
            			bool p=1;
            			for(int k=0;k<n;k++){
            				if(k!=i&&k!=j){
                        				double s=(x[i]-x[k])*(y[i]-y[j])-(y[i]-y[k])*(x[i]-x[j]);
                        				if(s>0){
                        					if(r==-1){
                        						h=0;
                        					}
                        					r=1;
                        				}
                        				if(s<0){
                        					if(r==1){
                        						h=0;
                        					}
                        					r=-1;
                        				}
                        				if(s==0&&sled>0){
                        					double f=abs(x[i]-x[j1])+abs(y[i]-y[j1]);
                        					double g=abs(x[i]-x[j])+abs(y[i]-y[j]);
                        					double s=abs(x[j]-x[j1])+abs(y[j]-y[j1]);
                        					if(s+f==g||s+g==f){
                        						p=0;
                        					}
                        				}
            				}
            			}
            			if(h==1&&j!=i&&p==0){
            				j3=j;	
            			}
            			if(h==1&&sled==1&&j!=i&&p==1){
            				j2=j;
            				sled++;
            			}
            			if(h==1&&sled==0&&j!=i&&p==1){
            				j1=j;
            				sled++;
            			}
            		}
            		if(sled<2){
            			ans[i]=0.5;
            		}
            		else{
            			double a=sqrt((x[j1]-x[j2])*(x[j1]-x[j2])+(y[j1]-y[j2])*(y[j1]-y[j2]));
            			double b=sqrt((x[j1]-x[i])*(x[j1]-x[i])+(y[j1]-y[i])*(y[j1]-y[i]));
            			double c=sqrt((x[j2]-x[i])*(x[j2]-x[i])+(y[j2]-y[i])*(y[j2]-y[i]));
            			double angle=acos((c*c+b*b-a*a)/(2*b*c));
            			double pi= acos(-1);
            			ans[i] = (pi-angle)/(2*pi);
            		}
		}
	}
	for(int i=0;i<n;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}