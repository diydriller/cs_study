#include<bits/stdc++.h>

using namespace std;

// 문제: 인접한 원소를 고를 수 없을때 원소들의 최대합 (마지막 원소와 첫번째 원소는 이어져있음) 
vector<int> money={1,2,3,1};

int main(){
	
	int len=money.size();
    int dp[1000001]={0,};
    
    // 첫번째 원소 고르고 마지막 원소 고르지 않는 경우 
    dp[0]=money[0];
    dp[1]=max(money[0],money[1]);
    int ans=INT_MIN;
    for(int i=2;i<len;i++){
        if(i==len-1) break;
        dp[i]=max(dp[i-1],dp[i-2]+money[i]);
        ans=max(ans,dp[i]);
    }
    
    // 첫번째 원소 고르지 않고 마지막 원소 고르는 경우 
    memset(dp,0,sizeof(dp));
    dp[1]=money[1];
    for(int i=2;i<len;i++){
        dp[i]=max(dp[i-1],dp[i-2]+money[i]);
        ans=max(ans,dp[i]);
    }
    
    
    cout<<ans;
}
