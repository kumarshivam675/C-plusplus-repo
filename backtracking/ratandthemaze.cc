/*A Maze is given as N*N binary matrix of blocks where source block is the upper left most block i.e., maze[0][0] and destination block is lower rightmost block i.e., maze[N-1][N-1]. A rat starts from source and has to reach destination. The rat can move only in two directions: forward and down.
In the maze matrix, 0 means the block is dead end and 1 means the block can be used in the path from source to destination. Note that this is a simple version of the typical Maze problem. For example, a more complex version can be that the rat can move in 4 directions and a more complex version can be with limited number of moves.

i/p =   {1, 0, 0, 0}
		{1, 1, 0, 1}
		{0, 1, 0, 0}
		{1, 1, 1, 1}
		
o/p =   {1, 0, 0, 0}
        {1, 1, 0, 0}
        {0, 1, 0, 0}
        {0, 1, 1, 1}
*/


#include<iostream>

using namespace std;

const int N = 4;

bool isSafe(int x, int y, int maze[N][N]){
	if(x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1)
		return true;
	else
		return false;
}

bool solveMazeUtil(int x, int y, int maze[N][N], int ans[N][N], int moveX[], int moveY[]){
	if(x == N-1 && y == N-1){
		ans[x][y] = 1;
		return true;
	}
	
	int next_x, next_y;
	for(int k = 0; k < 2; k++){
		next_x = x + moveX[k];
		next_y = y + moveY[k];
		if(isSafe(next_x,next_y,maze)){
			ans[next_x][next_y] = 1;
			if(solveMazeUtil(next_x,next_y,maze,ans,moveX,moveY) == true)
				return true;
			ans[next_x][next_y] = 0;
			
		}
	}
	return false;
}

void printAnswer(int ans[N][N]){
	for(int i = 0; i < N;i++){
		for(int j = 0; j < N; j++){
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
}
			

void solveMaze(int maze[N][N]){
	int ans[N][N];
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			ans[i][j] = 0;
		}
	}
	
	int moveX[] = {1,0};
	int moveY[] = {0,1};
	
	ans[0][0] = 1;
	
	if(solveMazeUtil(0,0,maze,ans,moveX,moveY) == true)
		//cout << "Yes\n";
		printAnswer(ans);
	else
		cout << "Not Possible to reach the Destination\n";
}

int main(){
	int maze[N][N] = {{1,0,0,0},
				   {1,1,0,1},
				   {0,1,0,0},
				   {1,1,1,1}};
	solveMaze(maze);
	return 0;
}
	
