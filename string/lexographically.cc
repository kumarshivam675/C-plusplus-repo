#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

void swap(char& a, char& b){
	char temp = a;
	a = b;
	b = temp;
}

int findFirst(string str, int size){
	int i=size-2;
	while(i >= 0){
		if(str[i] < str[i+1])
			break;
		i--;
	}
	return i;
}

int findCeil(string str, char first, int l, int r){
	int ceil = l;
	for(int i = l+1; i < r; i++){
		if(str[i] > first && str[i] < str[ceil])
			ceil = i;
	}
	return ceil;
}

void printLexographically(string str, int size){
	sort(str.begin(),str.end());
	cout << str << endl;
	bool isFinished = false;
	while(!isFinished){
		int first_index = findFirst(str,size);
		
		if(first_index == -1)
			break;
			
		int ceil_index = findCeil(str,str[first_index],first_index+1,size);
		swap(str[first_index],str[ceil_index]);
		sort(str.begin()+first_index+1,str.end());
		cout << str << endl;
	}
}

int main(){
	string str;
	cin >> str;
	int size = str.length();
	printLexographically(str, size);
	return 0;
}
