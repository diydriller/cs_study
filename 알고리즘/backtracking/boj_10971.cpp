#include<bits/stdc++.h>

using namespace std;

int n;
vector<int> g[11];
bool check[11]={0,};
int ans=INT_MAX;

void init(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int t;
			cin>>t;
			g[i].push_back(t);
		}
	}
}

 
void dfs(int start,int from,int sum,int cnt){
	if(from==start&&cnt==n){
		ans=min(ans,sum);
		return;
	}
	
	for(int i=0;i<n;i++){
		if(check[i]||g[from][i]==0) continue;
		if(sum+g[from][i]>ans) continue;
		
		check[i]=true;
		dfs(start,i,sum+g[from][i],cnt+1);
		check[i]=false;
	}
	
}

void ex(){
	for(int i=0;i<n;i++){
		dfs(i,i,0,0);
	}
	cout<<ans;
}


int main(){
	
	init();
	ex();
	
}
