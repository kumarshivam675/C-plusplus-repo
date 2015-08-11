#include<iostream>
#include<cmath>

using namespace std;

void LCS(string x, string y){
	int m = x.length();
	int n = y.length();
	int l[m+1][n+1];
	
	for(int i = 0; i <= m; i++){
		for(int j = 0; j <= n; j++){
			if(i == 0 || j == 0)
				l[i][j] = 0;
			else if(x[i-1] == y[j-1])
				l[i][j] = 1 + l[i-1][j-1];
			else
				l[i][j] = max(l[i-1][j],l[i][j-1]);
		}
	}
	cout << l[m][n] << endl;
}

int main(){
	string str1, str2;
	cin >> str1 >> str2;
	LCS(str1,str2);
	return 0;
}
