#include<iostream>
#include<list>
#include<queue>

using namespace std;
class Graph{
	list<int> *adj;
public:
	Graph();
	void addEdge(int v, int w);
	int countCities();
};

Graph::Graph(){
	adj = new list<int>[10001];
}

void Graph::addEdge(int v, int w){
	adj[v].push_back(w);
	adj[w].push_back(v);
}

int Graph::countCities(){
	int count = 0;
	for(int i = 0; i < 10001; i++){
		if(adj[i].size() >0)
			count++;
			//cout << adj[i].size() << endl;
	}
	return count;
}

int main(){
	int size,no_roads,x,y;
	cin >> size;
	int i = 0;
	while(i < size){
		Graph g;
		cin >> no_roads;
		for(int j = 0; j < no_roads; j++){
			cin >> x >> y;
			g.addEdge(x,y);
		}
		cout << g.countCities() << endl;
		i++;
	}
	return 0;
}
	
