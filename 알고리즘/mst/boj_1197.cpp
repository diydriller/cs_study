#include<bits/stdc++.h>

using namespace std;

int v,e;

struct info{
	int w;
	int v1;
	int v2;
};

// 최소 힙을 사용해서 비용이 작은 간선부터 탐색한다. 
struct cmp{
	bool operator()(info a,info b){
		return a.w>b.w;
	}
};

priority_queue<info,vector<info>,cmp> pq;

// union-find 
// 사이클 유무 파악하기 위해 사용한다. 
int parent[10001]={0,};

int find_parent(int x){
	if(parent[x]==x) return x;
	else return parent[x]=find_parent(parent[x]);
}

bool union_parent(int x,int y){
	int xx=find_parent(x);
	int yy=find_parent(y);
	
	if(xx==yy) return false;
	
	parent[xx]=yy;
	return true;
}

// 입력과 초기화  
void init(){
	cin>>v>>e;
	
	for(int i=0;i<e;i++){
		int p,q,r;
		cin>>p>>q>>r;
		pq.push({r,p,q});
	}
	
	for(int i=1;i<=v;i++){
		parent[i]=i;
	}	
}


void ex(){
	int ans=0;
	
	while(!pq.empty()){
		auto t=pq.top();
		pq.pop();
		
		// 사이클 이루면 제외한다. 
		if(!union_parent(t.v1,t.v2)){
			continue;
		}
		ans+=t.w;
	}
	cout<<ans;
}


int main(){
	init();
	ex();
}
