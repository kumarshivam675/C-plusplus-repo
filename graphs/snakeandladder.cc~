#include<iostream>
#include<list>
#include<queue>

using namespace std;

struct vertexdistance{
	int v;
	int dist;
};

class Graph{
	int v;
	list<int> *adj;
public:
	Graph(int v);
	void addEdge();
	void BFS(int s);
	void addSnakeLadder(int src, int dest);
	void addSnake(int src, int dest);
	int minDiceThrow();
};

Graph::Graph(int val){
	v = val;
	adj = new list<int>[v];
}

void Graph::addEdge(){
	for(int i = 0; i < v; i++)
		adj[i].clear();
	for(int i = 1; i < v; i++){
		for(int j = i+1; j <=(i+6) && j<v;j++){
			adj[i].push_back(j);
		}
	}
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

void Graph::addSnakeLadder(int src, int dest){
	list<int>::iterator it;
	for(int i = src-6; i < src; i++){
		if(i < 1)
			i = 1;
		for(it = adj[i].begin(); it != adj[i].end(); it++){
			if(*it == src){
				*it = dest;
				break;
			}
		}
	}
	//adj[src].push_back(dest);
}

void Graph::addSnake(int src,int dest){
	adj[src].clear();
	adj[src].push_back(dest);
}

int Graph::minDiceThrow(){
	bool *visited = new bool[v];
	for(int i = 0; i < v; i++)
		visited[i] = false;
		
	list<int>::iterator it;
	queue<vertexdistance> q;
		
	vertexdistance start = {1,0};
	visited[1] = true;
	q.push(start);
	
	vertexdistance qe;
	while(!q.empty()){
		qe = q.front();
		//cout << qe.v << "  " << qe.dist << endl;
		int v = qe.v;
		if(v == 100)
			break;
		q.pop();
		for(it = adj[v].begin(); it != adj[v].end(); it++){
			if(visited[*it] == false){
				vertexdistance temp;
				temp.v = *it;
				temp.dist = qe.dist + 1;
				visited[*it] = true;
				q.push(temp);
			}
		}
	}
	return qe.dist;
}
	
	

int main(){
	Graph g(101);
	int input,src,dest,n;
	cin >> input;
	for(int i = 0; i < input; i++){
		g.addEdge();
		cin >> n;
		for(int j = 0; j < n; j++){
			cin >> src >> dest;
			g.addSnakeLadder(src,dest);
		}
		cin >> n;
		for(int j = 0; j < n; j++){
			cin >> src >> dest;
			g.addSnake(src,dest);
		}
		cout << g.minDiceThrow() << endl;
	}
	return 0;
}
