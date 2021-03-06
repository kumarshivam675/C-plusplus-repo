#include<iostream>

using namespace std;

int parent(int i){
	return (i-1)/2;
}
	
int left(int index){
	return 2*index + 1;
}
	
int right(int index){
	return 2*index + 2;
}
	
int getMin(int arr[]){
	return arr[0];
}
	
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void minHeapify(int arr[],int size,int i){
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if(l < size && arr[l] < arr[i])
		smallest = l;
	if(r < size && arr[r] < arr[l])
		smallest = r;
	if(smallest != i){
		swap(arr[i],arr[smallest]);
		minHeapify(arr,size,smallest);
	}
}

void heapify(int a[], int a_size){
	int j;
	for(int i = a_size - 1; i >=0; i--){
		j = i;
		//cout << "value of j is " << j << endl;
		while(j > 0){
			if(a[j] < a[parent(j)]){
				swap(a[j],a[parent(j)]);
				j = parent(j);
			}
			else{
				minHeapify(a,a_size,j);
				break;
			}
		}
	}
}

void heapifyOrderN(int a[],int size){
	for(int i = parent(size - 1); i >= 0; i--){
		minHeapify(a,size,i);
	}
}		

void heapSort(int a[], int size){
	heapifyOrderN(a,size);
	while(size > 1){
		//cout << a[0] << endl;
		swap(a[0],a[size-1]);
		size--;
		minHeapify(a,size,0);
	}
}

int main(){
	int input[] = {5,7,2,4,3};
	//heapifyOrderN(input,5);
	heapSort(input,5);
	for(int i = 0; i < 5;i++){
		cout << input[i] << endl;
	}
	return 0;
}












