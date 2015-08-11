#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int a,b,m,temp,prev;
    cin >> a >> b >> m;
    int ans = b*b + a;
    prev = b;
    for(int i = 3; i < m; i++){
        temp = ans;
        ans = (ans*ans) + prev;
        prev = temp;
    }
    cout << ans << endl;
    return 0;
}

