#include<iostream>

using namespace std;

const int N = 8;

bool isSafe(int x, int y, int ans[N][N]){
	if(x >= 0 && x < N && y >= 0 && y < N && ans[x][y] == -1)
		return true;
	return false;
}

bool solveUtil(int x, int y, int move, int ans[N][N], int moveX[], int moveY[]){
	if(move == N*N)
		return true;
		
	//cout << move << endl;
		
	int next_x,next_y;
	for(int k = 0; k < 8; k++){
		next_x = x + moveX[k];
		next_y = y + moveY[k];
		if(isSafe(next_x,next_y,ans) == true){
			ans[next_x][next_y] = move;
			if(solveUtil(next_x,next_y,move+1,ans,moveX,moveY))
				return true;
			else
				ans[next_x][next_y] = -1;
		}
	}
	return false;
}

void printAnswer(int ans[N][N]){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
}

void solve(){
	int ans[N][N];
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			ans[i][j] = -1;
		}
	}
	
	int moveX [] = {2, 1, -1, -2, -2, -1,  1,  2};
	int moveY [] = {1, 2,  2,  1, -1, -2, -2, -1};
	
	ans[0][0] = 0;
	
	if(solveUtil(0,0,1,ans,moveX,moveY) == true)
		printAnswer(ans);
	else
		cout << "Solution not possible\n";
}

int main(){
	solve();
	return 0;
}
	
	
	
