#include<bits/stdc++.h>

using namespace std;

vector<int> v={90,10,0,-10,20,30,-100,60};

// O(n^3) 
int getMaxRangeSumByBruteForce(){
	int len=v.size();
	int max_value=INT_MIN;
	
	for(int i=0;i<len;i++){
		for(int j=i;j<len;j++){
			
			int sum=0;
			for(int k=i;k<=j;k++){
				sum+=v[k];
			}
			max_value=max(max_value,sum);		
		}
	}
	
	return max_value;
}


// O(n^2)
int getMaxRangeSumByPrefixSum(){
	int len=v.size();
	vector<int> prefixSum(len+1,0);
	
	int sum=0;
	for(int i=0;i<len;i++){
		sum+=v[i];
		prefixSum[i+1]=sum;
	}
	
	int max_value=INT_MIN;
	for(int i=1;i<=len;i++){
		for(int j=i;j<=len;j++){
			max_value=max(max_value,prefixSum[j]-prefixSum[i-1]);
		}
	}
	return max_value;
	
}

// O(n)
int getMaxRangeSumByDp(){
	int len=v.size();
	vector<int> dp(len,0);
	
	dp[0]=v[0];
	for(int i=1;i<len;i++){
		dp[i]=max(dp[i],dp[i-1]+v[i]);
	}
	
	int max_value=INT_MIN;
	for(int i=0;i<len;i++){
		max_value=max(max_value,dp[i]);
	}
	
	return max_value;
}


int main(){
	
	cout<<getMaxRangeSumByBruteForce()<<endl;	
	cout<<getMaxRangeSumByPrefixSum()<<endl;
	cout<<getMaxRangeSumByDp()<<endl;	
}
