#include<bits/stdc++.h>

using namespace std;

// ����: ������ ���Ҹ� �� �� ������ ���ҵ��� �ִ��� (������ ���ҿ� ù��° ���Ҵ� �̾�������) 
vector<int> money={1,2,3,1};

int main(){
	
	int len=money.size();
    int dp[1000001]={0,};
    
    // ù��° ���� ���� ������ ���� ���� �ʴ� ��� 
    dp[0]=money[0];
    dp[1]=max(money[0],money[1]);
    int ans=INT_MIN;
    for(int i=2;i<len;i++){
        if(i==len-1) break;
        dp[i]=max(dp[i-1],dp[i-2]+money[i]);
        ans=max(ans,dp[i]);
    }
    
    // ù��° ���� ���� �ʰ� ������ ���� ���� ��� 
    memset(dp,0,sizeof(dp));
    dp[1]=money[1];
    for(int i=2;i<len;i++){
        dp[i]=max(dp[i-1],dp[i-2]+money[i]);
        ans=max(ans,dp[i]);
    }
    
    
    cout<<ans;
}
