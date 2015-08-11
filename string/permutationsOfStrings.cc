#include<iostream>
#include<string>

using namespace std;

void swap(char& a, char& b){
	char temp = a;
	a = b;
	b = temp;
}

void stringPerm(string s, int i){
	int len = s.size();
	if(i == s.size())
		cout << s << endl;
	else{
		for(int j = i; j < len;j++){
			swap(s[i],s[j]);
			stringPerm(s,i+1);
			swap(s[i],s[j]);
		}
	}
}

int main(){
	string s = "ABC";
	stringPerm(s,0);
	return 0;
}
