#include<iostream>
#include<algorithm>

using namespace std;

void findUnion(int a[], int b[],int size1,int size2){
	sort(a,a+size1);
	sort(b,b+size2);
	int l = 0; 
	int r = 0;
	/*for(int i = 0; i < size1; i++)
		cout << a[i] << "  ";
	cout << endl;
	for(int i = 0; i < size2;i++)
		cout << b[i] << "  ";
	cout << "\n";*/
	while(l < size1 && r < size2){
		if(a[l] < b[r]){
			cout << a[l] << " ";
			l++;
		}
		else if(b[r] < a[l]){
			cout << b[r] << " ";
			r++;
		}
		else{
			cout << a[l] << " ";
			l++;
			r++;
		}
	}
	//cout << endl << l << "  " << r << endl;
	while(l < size1){
		cout << a[l] << " ";
		l++;
	}
	while(r < size2){
		cout << b[r] << " ";
		r++;
	}
	cout << endl;
}

int main(){
	int a[] = {7,1,5,2,3,6};
	int b[] = {3,8,6,20,7};
	int size1 = sizeof(a)/sizeof(a[0]);
	int size2 = sizeof(b)/sizeof(b[0]);
	findUnion(a,b,size1,size2);
	return 0;
}
