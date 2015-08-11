#include<iostream>
#include<map>

using namespace std;

void anagrams(string str){
	string s1 = "",s2 = "";
	int count = 0;
	int length = str.length();
	map<char,int> s1Map,s2Map;
	map<char,int>::iterator it;
	for(int i = 0; i < length/2; i++){
		s1 = s1 + str[i];
	}
	for(int i = length/2; i < length; i++){
		s2 = s2 + str[i];
	}
	//cout << s1 << endl;
	//cout << s2 << endl;
	if(s1.length() != s2.length()){
		cout << "-1\n";
		return ;
	}
	for(int i = 0; i < s1.length(); i++){
		s1Map[s1[i]] += 1;
	}
	for(int i = 0; i < s2.length(); i++){
		s2Map[s2[i]] += 1;
	}
	/*for(it = s1Map.begin(); it != s1Map.end(); it++){
		cout << it->first << "  " << it->second << endl;
	}
	for(it = s2Map.begin(); it != s2Map.end(); it++){
		cout << it->first << "  " << it->second << endl;
	}*/
	for(it = s1Map.begin(); it != s1Map.end(); it++){
		if(s2Map[it->first])
			s2Map[it->first] -= it->second;
	}
	for(it = s2Map.begin(); it != s2Map.end(); it++){
		if(it->second > 0)
			count += it->second;
	}
	cout << count << endl;
}

int main(){
	int size;
	string str;
	cin >> size;
	while(size--){
		cin >> str;
		anagrams(str);
	}
	return 0;
}
