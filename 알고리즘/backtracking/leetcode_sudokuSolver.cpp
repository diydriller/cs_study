#include<bits/stdc++.h>

using namespace std;

// 1. backtracking 중간에 멈추는 방법 

bool flag=false;

vector<vector<char>> board={
	{'5','3','.','.','7','.','.','.','.'},
	{'6','.','.','1','9','5','.','.','.'},
	{'.','9','8','.','.','.','.','6','.'},
	{'8','.','.','.','6','.','.','.','3'},
	{'4','.','.','8','.','3','.','.','1'},
	{'7','.','.','.','2','.','.','.','6'},
	{'.','6','.','.','.','.','2','8','.'},
	{'.','.','.','4','1','9','.','.','5'},
	{'.','.','.','.','8','.','.','7','9'}
};

bool check_board(vector<vector<char>>& board,pair<int,int> pos,char num){

    
    for(int i=0;i<9;i++){
        if(board[i][pos.second]==num){
            return false;
        }    
    }


    for(int i=0;i<9;i++){
        if(board[pos.first][i]==num){
            return false;
        }    
    }
 
    int xx=(pos.first/3)*3;
    int yy=(pos.second/3)*3;
    
    for(int x=0;x<3;x++){
        for(int y=0;y<3;y++){
            if(board[xx+x][yy+y]==num){
                return false;
            }
        }
    }
    return true;
}



void dfs(vector<vector<char>>& board,vector<pair<int,int>> &blank,int d){

    if(d==blank.size()){
        flag=true;
        return;
    }
    
    int x=blank[d].first;
    int y=blank[d].second;
    
    for(char num='1';num<='9';num++){
        if(!check_board(board,blank[d],num)){
            continue;
        }
        board[x][y]=num;
        dfs(board,blank,d+1);
        if(flag) return;
        board[x][y]='.';
    }       
}

void solveSudoku(vector<vector<char>>& board) {
    vector<pair<int,int>> blank;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]=='.'){
                blank.push_back({i,j});
            }
        }
    }
    dfs(board,blank,0);
    
}

int main(){
	solveSudoku(board);
}
