#include<bits/stdc++.h>

using namespace std;

int n,m;


bool check;


void dfs(int l,int d,vector<int> &v,vector<bool> &visited,int sum,int x){
	if(d==l){
		if(sum==pow(2,n+1)-1){
			check=true;
		}
		return;
	}
	
	for(int i=x;i<m;i++){
		if(visited[i]) continue;
		visited[i]=true;
		dfs(l,d+1,v,visited,sum|v[i],i+1);
		visited[i]=false;
	}
}

int main(){
	
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
	cin>>n>>m;

    // 각 멤버마다 풀 수 있는 문제를 bitmask로 저장한다.
	vector<int> v;

	for(int i=0;i<m;i++){
		int cnt;
		cin>>cnt;
		
		int t=1;
		for(int j=0;j<cnt;j++){
			int num;
			cin>>num;
			
			t=t|(1<<num);
		}
		
		v.push_back(t);
	}

    // m명 중에서 1~m명을 고르면서 bitmask 합을 구한다.
    // 최대 10명이 입력되므로 2^10으로 시간초과되지않는다.
	for(int i=1;i<=m;i++){
		vector<bool> visited(m,false);
		check=false;
		dfs(i,0,v,visited,1,0);
		if(check){
			cout<<i;
			return 0; 
		}	
	}
	
	cout<<-1;
	
	
		
}
