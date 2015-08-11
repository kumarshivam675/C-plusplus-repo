#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void swap(char& a, char& b){
	char temp = a;
	a = b;
	b = temp;
}

int findFirst(string str, int size){
    int i = size-2;
    while(i >= 0){
        if(str[i] < str[i+1]){
            break;
        }
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

void lexographicallySmallestOne(string str, int size){
    int first_index = findFirst(str,size);
    if(first_index == -1){
        cout << "no answer\n";
        return ;
    }
    int ceil_index = findCeil(str,str[first_index], first_index+1,size);
    swap(str[first_index],str[ceil_index]);
    sort(str.begin()+first_index+1,str.end());
    cout << str << endl;
    
}

int main() {
    string str;
    int size;
    while(size--){
        cin >> str;
        lexographicallySmallestOne(str, str.length());
    }
    return 0;
}

