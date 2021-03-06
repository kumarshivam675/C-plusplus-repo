#include<iostream>

using namespace std;

void binarySearch(int a[],int start, int end, int key){
	while(start <= end){
		int mid = (start + end)/2;
		if(a[mid] == key){
			cout << "found at " << mid << endl;
			break;
		}
		else if(a[mid] > key)
			end = end - 1;
		else
			start = mid + 1;
	}
}

void searchPivoted(int a[],int start,int end,int key){
	int pivot = -1;
	while(start < end){
		int mid = (start + end)/2;
		if(mid < end && a[mid] > a[mid+1]){
			pivot = mid;
			break;
		}
		else if(mid > start && a[mid] < a[mid-1]){
			pivot = mid - 1;
			break;
		}
		else if(a[start] >= a[mid]){
			end = mid - 1;
		}
		else
			start = mid + 1;
	}
	if(start == end){
		pivot = start;
	}
	cout << "pivot is " << pivot << endl;
	if(key >= a[0])
		binarySearch(a,0,pivot,key);
	else
		binarySearch(a,pivot+1,end,key);
}

int main(){
	int input[] = {3,4,5,1,2};
	int size = sizeof(input)/sizeof(input[0]);
	//binarySearch(input,0,size-1,3);
	searchPivoted(input,0,size-1,3);
	return 0;
}
	
