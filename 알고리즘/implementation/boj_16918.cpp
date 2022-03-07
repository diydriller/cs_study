#include<bits/stdc++.h>

using namespace std;
int r,c,n;
int board[201][201]={0,};
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};

void init(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>r>>c>>n;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			int ch=getchar();
			if(ch=='.') board[i][j]=0;
			else if(ch=='O') board[i][j]=4;
		}
		getchar();
	}	
}

void down(){
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(board[i][j]>0){
				board[i][j]--;
			}
		}
	}
	
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){		
			if(board[i][j]==1){
				for(int d=0;d<4;d++){
					int x=i+dx[d];
					int y=j+dy[d];
					if(x<0||y<0||x>=r||y>=c) continue;
					if(board[x][y]==1||board[x][y]==0) continue;
					board[x][y]=0;
				}
				board[i][j]=0;
			}
		
		}
	}
}

void put(){
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(board[i][j]==0){
				board[i][j]=4;
			}
		}
	}
}

void print(){
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cout<<board[i][j]<<" ";
		}
		cout<<'\n';
	}
	cout<<'\n'<<'\n';
}

void ex(){

	int t=0;
	down();
	t++;
	print();
	
	for(;t<n;){
		
		t++;
		
		down();
		put();
		if(t==n) break;
		print();
		
		t++;
		down();
		if(t==n) break;
		print();
	}
	
	print();
	

}

int main(){
	init();
	ex();
	
}
