#include<iostream>
#include<list>
#include<queue>

using namespace std;

class Graph{
	int v;
	list<int> *adj;
public:
	Graph(int v);
	void addEdge(int v, int w);
	void BFS(int s);
	void DFSUtil(int v, bool visited[]);
	void DFS(int s);
};

Graph::Graph(int val){
	v = val;
	adj = new list<int>[v];
}

void Graph::addEdge(int v, int w){
	adj[v].push_back(w);
}

void Graph::BFS(int s){
	bool *visited = new bool[v];
	for(int i = 0; i < v; i++)
		visited[i] = false;
		
	queue<int> q;
		
	visited[s] = true;
	q.push(s);
	
	list<int>::iterator it;
	
	while(!q.empty()){
		s = q.front();
		cout << s << " ";
		q.pop();
		
		for(it = adj[s].begin(); it != adj[s].end(); it++){
			if(visited[*it] == false){
				visited[*it] = true;
				q.push(*it);
			}
		}
	}
	cout << endl;
}

void Graph::DFSUtil(int v, bool visited[]){
	visited[v] = true;
	cout << v << "  ";
	list<int>::iterator it;
	
	for(it = adj[v].begin(); it != adj[v].end(); it++){
		if(visited[*it] == false)
			DFSUtil(*it,visited);
	}
}

void Graph::DFS(int s){
	bool *visited = new bool[v];
	for(int i = 0; i < v; i++)
		visited[i] = false;
	DFSUtil(s,visited);
}

int main(){
	Graph g(4);
	g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.BFS(2);
    g.DFS(2);
 	return 0;
}
		
		
		
		
