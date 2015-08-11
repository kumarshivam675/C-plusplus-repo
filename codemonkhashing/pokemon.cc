#include<iostream>
#include<unordered_map>

using namespace std;

void countFood(){
    int size,food,pokemon,count = 0;
    unordered_map<int,int> myMap;
    unordered_map<int,int>::iterator it;
    cin >> size;
    for(int i = 0; i < size; i++){
        cin >> food >> pokemon;
        myMap[food] += 1;
        if(myMap.find(pokemon) != myMap.end()){
           myMap[pokemon] -= 1;
           if(myMap[pokemon] == 0)
                myMap.erase(pokemon);
        }
        else{
            count++;
        }
    }
    cout << count << endl;
}
            

int main(){
	int input;
	cin >> input;
	for(int i = 0; i < input; i++)
	    countFood();
	return 0;
}
