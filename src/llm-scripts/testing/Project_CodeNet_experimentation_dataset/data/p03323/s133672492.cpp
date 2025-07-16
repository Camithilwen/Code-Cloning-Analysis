//#include "stdafx.h"
#include<bits/stdc++.h> 
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int a,b,ans,q;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	cin>>a>>b;
	q=abs(a-b);
	ans=16-(a+b);
	if(q>ans/2)
		cout<<":(\n";
	else
		cout<<"Yay!\n";
	
	
	return 0;
}

