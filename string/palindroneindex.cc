#include<iostream>
#include<string>

using namespace std;

bool checkPalindrome(string str){
	int l = 0;
	int r = str.length()-1;
	while(l < r){
		if(str[l] != str[r])
			return false;
		l++;
		r--;
	}
	return true;
}

int main(){
	string str,str1;
	int size;
	cin >> size;
	for(int i = 0; i < size; i++){
		cin >> str;
		int size = str.length();
		int j = 0;
		if(checkPalindrome(str)){
			cout << "-1\n";
			continue;
		}
		while(j < size){
			str1 = str;
			str1.erase(j,1);
			bool ans = checkPalindrome(str1);
			if(ans == true){
				cout << j << endl;
				break;
			}
			str1.clear();
			j++;
		}
	}
	return 0;
}
