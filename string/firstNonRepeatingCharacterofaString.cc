#include<iostream>

using namespace std;

void firstNonRepeatingString(string str){
	int hash[26];
	for(int i = 0; i < 26; i++)
		hash[i] = 0;
	int length = str.length();
	for(int i = 0; i < length; i++)
		hash[str[i]-'a'] += 1;
	
	for(int i = 0; i < length; i++){
		if(hash[str[i] - 'a'] == 1){
			cout << str[i] << endl;
			break;
		}
	}
}

int main(){
	string str;
	cin >> str;
	firstNonRepeatingString(str);
	return 0;
}
