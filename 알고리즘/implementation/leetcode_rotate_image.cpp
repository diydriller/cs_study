#include<bits/stdc++.h>

using namespace std;

// ���� : �迭�� 90�� ȸ���ϱ� 
vector<vector<int> > matrix={{1,2,3},{4,5,6},{7,8,9}};

int main(){
	
	int n=matrix.size();
	
	// transpose
	for(int i=0;i<n;i++){
	    for(int j=i+1;j<n;j++){
	        int temp=matrix[i][j];
	        matrix[i][j]=matrix[j][i];
	        matrix[j][i]=temp;
	    }
	}
	
	// horizontal reverse
	for(int i=0;i<n;i++){
	    for(int j=0;j<n/2;j++){
	        int temp=matrix[i][j];
	        matrix[i][j]=matrix[i][n-1-j];
	        matrix[i][n-1-j]=temp;
	    }
	}    
}
