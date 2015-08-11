#include<iostream>
#include<string>

using namespace std;

int main(){
	int flag = 0;
	string str;
	getline(cin,str);
	for(int i = 0; i < str.length();i++)
		str[i] = tolower(str[i]);
		
	cout << str << endl;
	int *alpha = new int[26];
	for(int i = 0; i < 26; i++)
		alpha[i] = 0;
		
	for(int i = 0; i < str.length(); i++){
		int temp = int(str[i]);
		if(temp != 32)
			alpha[temp-97] = 1;
	}
	
	for(int i = 0; i < 26; i++){
		if(alpha[i] != 1)
			flag = 1;
	}
	
	if(flag == 1)
		cout << "not panagram\n";
	else
		cout << "panagram\n";
	return 0;
}
