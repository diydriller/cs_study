#include<bits/stdc++.h>

using namespace std;

// 문제:  1~n번이 적혀 있는 전구를 모두 켜야하는데 구간으로 켜는 작업과 단일로 켜는 작업이 있을때 최소 작업횟수 

int n=10;
vector<vector<int>> groups={{1,5},{2,7},{4,8},{3,6}};
//int n=7;
//vector<vector<int>> groups={{6,7},{1,4},{2,4}};
//int n=100;
//vector<vector<int>> groups={{1,50},{1,100},{51,100}};


bool cmp(vector<int> v1,vector<int> v2){
	if(v1[0]==v2[0]){
		return v1[1]>v2[1];
	}
	return v1[0]<v2[0];
}

int main(){
	sort(groups.begin(),groups.end(),cmp);	
	
	int s=1,e=1;
	int ans=0;
	int len=groups.size();
	
	for(int i=0;i<len;i++){
		vector<int> group=groups[i];
		int t_s=group[0],t_e=group[1];
		
		if(e==t_s){
			ans++;
			e=t_e;
		}
		else if(e<t_s){
			ans+=(t_s-e);
			e=t_e;
		}
		else{
			if(e>=t_e){
				continue;
			}
			ans++;
			int new_e=max(e,t_e);
			while(1){
				if(i+1>=len) break;
				vector<int> next_group=groups[i+1];
				int next_s=next_group[0],next_e=next_group[1];
				if(e<next_s) break;
				
				new_e=max(new_e,next_e);
				i++;
			}
			e=new_e;
		}
	}
	ans+=(n-e);
	cout<<ans;
}
