#include<iostream>

using namespace std;

void LCS(string str1,string str2){
	int m = str1.length();
	int n = str2.length();
	int l[m+1][n+1];
	for(int i = 0; i <= m; i++){
		for(int j = 0; j <= n; j++){
			if(i == 0 || j == 0)
				l[i][j] = 0;
			else if(str1[i-1] == str2[j-1]){
				l[i][j] = l[i-1][j-1] + 1;
			}
			else{
				l[i][j] = max(l[i-1][j],l[i-1][j-2]);
			}
	
int main(){
	string str1,str2;
	cin >> str1 >> str2;
	LCS(str1,str2);
	return 0;
}
