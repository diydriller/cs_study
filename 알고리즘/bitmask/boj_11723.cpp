#include<bits/stdc++.h>

using namespace std;

int n;
int set_num=0;


bool check(int x){
	if(set_num&(1<<x)) return true;
	else return false;
}

void add(int x){
	set_num=set_num|(1<<x);
} 

void remove(int x){
	set_num=set_num&(~(1<<x));
}

void toggle(int x){
    set_num=set_num^(1<<x);	
}

void all(){
	set_num=(1<<21)-1;
}

void empty(){
	set_num=0;
}


int main(){
	
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
	cin>>n;
	
	while(n--){
		string command;
		cin>>command;
		
		int num;
		if(command=="add"){
			cin>>num;
			add(num);
		}
		else if(command=="remove"){
			cin>>num;
			remove(num);
		}
		else if(command=="check"){
			cin>>num;
			cout<<(check(num)?"1":"0")<<"\n";
		}
		else if(command=="toggle"){
			cin>>num;
			toggle(num);
		}
		else if(command=="all"){
			all();
		}
		else if(command=="empty"){
			empty();
		}
	}	
}
