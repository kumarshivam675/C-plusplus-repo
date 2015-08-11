#include<iostream>
#include<vector>
using namespace std; int main() { int t,n,count; long long int inp,tmp; cin >> t; for (int i=0; i<t; i++) { vector <long long int> setbits[61]; cin >> n; for (int j=0; j<n; j++) { count = 0; cin >> inp; tmp = inp; while (inp) { if (inp&1) count++; inp = inp >> 1; } setbits[count-1].push_back(tmp); } for (int j=0; j<61; j++) { for (int k=0; k<setbits[j].size(); k++) { cout << setbits[j][k] << " "; } } cout << endl; } }
