#include<bits/stdc++.h>

using namespace std;

//vector<vector<int> > ads={{1,3},{5,4},{3,2}};
//vector<vector<int> > ads={{0,3},{5,4}};
vector<vector<int> > ads={{0,1},{0,2},{6,3},{8,4}};
//vector<vector<int> > ads={{5,2},{2,2},{6,3},{9,2}};


struct cmp{
	bool operator()(vector<int> a,vector<int> b){
		if(a[0]==b[0]){
			return a[1]<b[1];
		}
		return a[0]>b[0];
	}
};

int main(){
		
	sort(ads.begin(),ads.end());

	priority_queue<vector<int>,vector<vector<int> > ,cmp> pq;
	
	queue<vector<int> > q;
	for(auto el:ads){
		q.push(el);
	}
	
	int time=ads[0][0];
	int ans=0;

	while(!pq.empty()||!q.empty()){
	
		while(!q.empty()){
			auto f=q.front();
			if(f[0]>time&&pq.size()>0){
				break;
			}
			q.pop();
			pq.push({(time-f[0])*f[1],f[1],time});
			
		}
		
		vector<vector<int> > v;
		
		if(!pq.empty()){
			auto t=pq.top();
			pq.pop();
			ans+=t[0];
			time+=5;
			
			cout<<t[1]<<" "<<ans<<" "<<time<<endl;
			
			while(!pq.empty()){
				auto tt=pq.top();
				
				if(tt[2]<=time){
					tt[0]+=(time-tt[2])*tt[1];
					tt[2]=time;
				}
				v.push_back(tt);
				pq.pop();
			}
			
			for(auto el:v){
				pq.push(el);
			}
		}		
			
	}
	
	cout<<ans;
}
