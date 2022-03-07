#include<bits/stdc++.h>

using namespace std;

int n=18;
vector<int> ans;


int getPrimeFactor(int m){
	
	map<int,int> prime_m;
	
	while(m%2==0){
		prime_m[2]++;
		m/=2;
	}
	
	for(int i=3;i<=sqrt(m);i+=2){
		while(m%i==0){
			prime_m[i]++;
			m/=i;
		}
	}

	if(m>2){
		prime_m[m]++;
	}	
	
	return prime_m.begin()->first;
}


void recur(int len,int dif,int s){
	int prime=getPrimeFactor(len);
	if(len==1){
		ans.push_back(s);
		return;
	}
	
	for(int i=0;i<prime;i++){
		recur(len/prime,dif*prime,s+dif*i);
	}
	
}

int main(){

	recur(n,1,1);
	
	cout<<endl<<endl;
	for(auto el:ans){
		cout<<el<<" ";
	}
	
	
}
