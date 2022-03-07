#include<bits/stdc++.h>

using namespace std;

int n;
vector<pair<int,int> > lines;

bool cmp(pair<int,int> f,pair<int,int> b){
	if(f.first==b.first){
		return f.second<b.second;
	}
	return f.first<b.first;
}

void init(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n;
	for(int i=0;i<n;i++){
		int t1,t2;
		cin>>t1>>t2;
		lines.push_back({t1,t2});
	}
	
	sort(lines.begin(),lines.end(),cmp);
}

void ex(){
	
	map<int,int> line_m;
	
	for(auto el:lines){
		auto it=line_m.lower_bound(el.first);
		if(it==line_m.end()){
			line_m[el.second]=el.first;
		}
		else{
			if(it->first<el.second){
				int s=it->second;
				line_m.erase(it);
				line_m[el.second]=s;
			}
		}
	}
	
	int ans=0;
	for(auto it=line_m.begin();it!=line_m.end();it++){
		ans+=(it->first)-(it->second);
	}
	
	cout<<ans;
}

int main(){
	init();
	ex();
	
}
