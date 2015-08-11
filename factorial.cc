#include <iostream>
using namespace std;

long long int findTrailingZeros(long long int  n)
{
    // Initialize result
    int count = 0;
 
    // Keep dividing n by powers of 5 and update count
    for (int i=5; n/i>=1; i *= 5)
          count += n/i;
 
    return count;
}

int main() {
	
	// your code here
	int size;
	long long int input;
	cin>>size;
	while(size--){
		cin >> input;
		cout << findTrailingZeros(input) << endl;
	}

	return 0;
}
