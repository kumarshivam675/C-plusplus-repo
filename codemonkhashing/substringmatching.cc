#include<iostream>
#include<string>

using namespace std;

void check(string str){
	int input;
	cin >> input;
	int flag,l,r,m,n;
	for(int i = 0; i < input; i++){
		string s1,s2;
		flag = 1;
		cin >> l >> r >> m >> n;
		if(l-r != m-n){
			cout << "No\n";
			continue;
		}
		s1 = str.substr(l-1,l-r+1);
		s2 = str.substr(m-1,m-n+1);
		cout << s1 << endl;
		cout << s2 << endl;
		if(s1 == s2){
			flag = 0;
		}
		
		if(flag == 0)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}

int main(){
	string str;
	cin >> str;
	check(str);
	return 0;
}
