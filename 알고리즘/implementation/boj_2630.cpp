#include<bits/stdc++.h>

using namespace std;

int n;
int paper[129][129]={0,};
int ans1=0,ans2=0;

void init(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int t;
			cin>>t;
			
			paper[i][j]=t+1;
		}
	}
}

void recur(int x,int y,int num){
	int t=paper[x][y];
	bool check=true;
	for(int i=x;i<x+num;i++){
		for(int j=y;j<y+num;j++){
			if(t!=paper[i][j]){
				check=false;
			}
		}
	}
	if(check){
		if(t==1) ans1++;
		else if(t==2) ans2++;
		return;
	}
	else{
		recur(x,y,num/2);
		recur(x+num/2,y,num/2);
		recur(x,y+num/2,num/2);
		recur(x+num/2,y+num/2,num/2);
	}
}

void ex(){
	recur(0,0,n);
	
	cout<<ans1<<'\n'<<ans2;
}

int main(){
	init();
	ex();
}
