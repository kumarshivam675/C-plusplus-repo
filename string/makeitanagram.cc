#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string str,str1;
    cin >> str;
    cin >> str1;
    int count = 0;
    for(int i = 0; i < str.length(); i++){
        for(int j = 0; j < str1.length(); j++){
            if(str[i] == str1[j]){
                str.erase(i,1);
                str1.erase(j,1);
                i--;
                j--;
                //break;
            }
            cout << i << "   " << j << endl;
            cout << "str    " << str << endl;
            cout << "str1   " << str1 << endl;
        }
    }
    //cout << "str    " << str << endl;
    //cout << "str1   " << str1 << endl;
    cout << str.length() << endl;
    cout << str1.length() << endl;
    return 0;
}

