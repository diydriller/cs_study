#include<bits/stdc++.h>

using namespace std;

int n;
vector<int> nums;

void init(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		nums.push_back(t);
	}
	
}

void ex(){
	
	sort(nums.begin(),nums.end());
	
	int ans1,ans2;
	int s=0,e=n-1;
	int dif=INT_MAX;
	while(s<e){
		int sum=nums[s]+nums[e];
		if(dif>abs(sum)){
			dif=abs(sum);
			ans1=nums[s];
			ans2=nums[e];
		}
		
		if(sum>=0){
			e--;
		}
		else{
			s++;
		}
	}
	
	cout<<ans1<<" "<<ans2;
}


int main(){
	init();
	ex();
}
