#include<bits/stdc++.h>

using namespace std;

int n,k,ans=INT_MAX;
vector<int> v;

void init(){
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	cin>>n>>k;	
	
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		v.push_back(t);
	}	
}

void ex(){
	int ans=0;
	for(int i=0;i<=n-k;i++){
		if(v[i]==1){
			for(int j=i;j<i+k;j++){
				v[j]=v[j]^1;
			}
			ans++;
		}
	}
	
	
	
	for(int i=0;i<n;i++){
		if(v[i]==1){
			cout<<"Insomnia";
			return;
		}
	}
	
	cout<<ans;
	
}


int main(){
	init();
	ex();
	
	
}
