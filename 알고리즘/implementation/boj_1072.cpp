#include<bits/stdc++.h>

using namespace std;

long long x,y;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>x>>y;
	
	int ratio=(int)(y*100/x);
	
	if(ratio>=99){
		cout<<"-1";
		return 0;
	}
	
	long long l=y,r=2000000000;
	int  ans=0;
	while(l<=r){
		long long m=(l+r)/2;
		int t_ratio=(int)((m*100)/(x+m-y));
		
		if(t_ratio!=ratio){
			ans=m;
			r=m-1;
		}	
		else{
			l=m+1;
		}
	}
	
	cout<<ans-y;
	
}
