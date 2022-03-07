#include<bits/stdc++.h>

using namespace std;

int n;
vector<int> g[17];
// ���� i ��° ���� & �湮���õ�(��Ʈ����ũ) �϶� �湮�������� ��� ��� 
int dp[17][1<<17];
const INF=987654321;

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
	
	// dp �ʱ�ȭ  
	for(int i=0;i<n;i++){
		for(int j=0;j<(1<<17);j++){
			dp[i][j]=-1;
		}
	}
}


int recur(int here,int visited){
	if(visited==(1<<n)-1){
		return g[here][0]?g[here][0]:INF;
	}
	int &ret=dp[here][visited];
	if(ret!=-1){
		return ret;
	}
	ret=INF;
	for(int i=0;i<n;i++){
		if(visited&(1<<i)) continue;
		if(g[here][i]==0) continue;
		ret=min(ret,recur(i,visited|(1<<i))+g[here][i]);
	}
	
	return ret;
}


void ex(){
	// �湮�������� ��� ��� 
	cout<<recur(0,1);
}


int main(){

	init();
	ex();
	
}
