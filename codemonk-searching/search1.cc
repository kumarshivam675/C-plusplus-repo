#include <iostream>
#include<climits>
#include<algorithm>
using namespace std;

long long int binarySearch(long long int a[], long long int size, long long int key){
	long long int start = 0;
	long long int end = size - 1;
	while(start <= end){
		long long int mid = (start + end)/2;
		if(a[mid] == key){		
			return mid;
		}
		if(a[mid] > key)
			end = mid - 1;
		else if(a[mid] < key)
			start = mid + 1;
	}
	return INT_MAX;
}

int main()
{
    long long int n,q, *value,num;
    cin >> n >> q;
    value = new long long int[n];
    for(long long int i = 0; i < n; i++){
    	cin >> value[i];
    }
    sort(value,value+n);
    /*for(long long int i = 0; i < n; i++){
    	cout <<	 value[i] << " ";
    }*/
    //cout << "\n";
    for(long long int i = 0; i < q; i++){
    	cin >> num;
    	long long int ans = binarySearch(value,n,num);
    	//cout << num << "  " << ans << endl;
    	if(ans != INT_MAX)
    		cout << "YES\n";
    	else 
    		cout << "NO\n";
    }
    return 0;
}

