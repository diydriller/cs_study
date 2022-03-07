#include<bits/stdc++.h>

using namespace std;

int m,n;
vector<int> nums;
map<int,int> num_m;
int num[10]={0,};

void init(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n>>m;
	
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		num_m[t]++;
	}
	for(auto it=num_m.begin();it!=num_m.end();it++){
		nums.push_back(it->first);
	}
}

void dfs(int d,int x){
	if(d==m){
		for(int i=0;i<m;i++){
			cout<<num[i]<<" ";
		}
		cout<<'\n';
		return;
	}
	for(int i=x;i<nums.size();i++){
		num[d]=nums[i];
		dfs(d+1,i);
	}
	
}

void ex(){
	
	dfs(0,0);
}

int main(){
	init();
	ex();
}
