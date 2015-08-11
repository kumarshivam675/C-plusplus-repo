#include<iostream>

const int row = 8;
const int column = 5;

using namespace std;

void print(int a[row][column]){
	for(int i = 0; i < row; i++){
		for(int j = 0; j < column; j++){
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
}

void search(int a[row][column],int key){
	int i = 0;
	while(i < row){
		if(a[i][0] > key)
			break;
		i++;
	}
	row_index = i-1;
	if(row_index == -1){
		cout << "Not found\n";
		return ;
	}
	j = 0;
	while(j < column){
		if(a[row_index][j] == key){
			cout << row_index << "  " << j << endl;
			return ;
		}
	}
	cout << "Not found\n";
	return ;
}

int main(){
	int array[row][column], key = 1;
	for(int i = 0; i < row; i++){
		for(int j = 0; j < column; j++){
			array[i][j] = key;
			key++;
		}
	}
	search(array,34);
	return 0;
}
