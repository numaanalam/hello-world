#include<bits/stdc++.h>
using namespace std;

float allexponent(int b,int ex){
	float res=1;
	if(ex>=0){
		res=(float)positiveExponent(b,ex);
	
	}
	else
	{
		return 1;

	}
	return res;
}
int main(){
	int a,b;
	cin>>a>>b;
cout<<allexponent(a,b);

	return 0;
}
