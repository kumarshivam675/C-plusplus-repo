#include<iostream>

using namespace std;

struct PetrolPump{
	int petrol;
	int distance;
};

void startIndex(struct PetrolPump a[], int size){
	int curr_petrol;
	int start = 0;
	int end = 1;
	curr_petrol = a[start].petrol - a[start].distance;
	while(start != end){
		while(curr_petrol < 0){
			curr_petrol -= a[start].petrol - a[start].distance;
			start = (start + 1)%size;
			
			if(start == 0)
				return ;
		}
		curr_petrol += a[end].petrol - a[end].distance;
		end = (end+1)%size;
	}
	cout << start << endl;
}


int main(){
	//struct PetrolPump input[] = {{4,6},{6,5},{7,3},{4,5}};
	struct PetrolPump input[] = {{6, 4}, {3, 6}, {7, 3}};
	int size = sizeof(input)/sizeof(input[0]);
	startIndex(input,size);
	return 0;
}
