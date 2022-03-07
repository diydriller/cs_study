#include<bits/stdc++.h>

using namespace std;

//vector<int> nums={3,5,4,1,2};
//vector<int> nums={1,2,3,4,5};
vector<int> nums={7,4,4,2,9,6};

int main(){
	
	stack<pair<int,int> > st;
	int len=nums.size();
	vector<int> ans(len,-1);
	
	for(int i=0;i<len;i++){
		int num=nums[i];
		
		if(st.empty()){
			st.push({i,num});
			continue;
		}
		
		while(!st.empty()){
			if(st.top().second>=num) break;
			ans[st.top().first]=i;
			st.pop();
		}
		
		st.push({i,num});
	}
	
	while(!st.empty()) st.pop();
	
	for(int i=len-1;i>=0;i--){
		int num=nums[i];
		
		if(st.empty()){
			st.push({i,num});
			continue;
		}
		
		while(!st.empty()){
			if(st.top().second>=num) break;
			if(ans[st.top().first]==-1){
				ans[st.top().first]=i;
			}
			else{
				int t1=ans[st.top().first];
				if(abs(t1-st.top().first)>=abs(i-st.top().first)){
					ans[st.top().first]=i;
				}
				st.pop();
			}
		}
		st.push({i,num});
	}
	
	
	for(int i=0;i<len;i++){
		cout<<ans[i]<<" ";
	}
	
	
	
	
	
}
