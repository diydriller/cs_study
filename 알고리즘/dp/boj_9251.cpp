#include<bits/stdc++.h>

using namespace std;


string a,b;
int dp[1001][1001];

int lcs_bottom_up(){
	
	for(int i=1;i<=a.size();i++){
		for(int j=1;j<=b.size();j++){
			if(a[i-1]==b[j-1]){
				dp[i][j]=dp[i-1][j-1]+1;
			}
			else{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	return dp[a.size()][b.size()];	
}

int lcs_top_down(int x,int y){
	if(x<0||y<0) return 0;
	if(dp[x][y]!=-1) return dp[x][y];
	
	if(a[x]==b[y]){
		return dp[x][y]=lcs_top_down(x-1,y-1)+1;
	}
	else{
		return dp[x][y]=max(lcs_top_down(x-1,y),lcs_top_down(x,y-1));
	}
	
}



int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	getline(cin,a);
	getline(cin,b);
	memset(dp,-1,sizeof dp);	
	cout<<lcs_top_down(a.size()-1,b.size()-1);
}
