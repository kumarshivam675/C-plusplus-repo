#include<iostream>
#include<list>
#include<queue>
#include<climits>

using namespace std;
class Graph{
	list<int> *adj;
public:
	Graph();
	void addEdge(int v, int w);
	//int countBanana(long long int a[],int size);
	void DFSUtil(int v,long long int a[], bool visited[], int& count);
	int DFS(long long int a[],int size);
};

Graph::Graph(){
	adj = new list<int>[100000];
}

void Graph::addEdge(int v, int w){
	adj[v].push_back(w);
	//adj[w].push_back(v);
}

/*int Graph::countBanana(long long int a[],int size){
	int count,i;
	int max = 0;
	bool *visited = new bool[100000];
	queue<int> q;
	list<int>::iterator it;
	for(int i = 0; i < 100000; i++)
			visited[i] = false;
	for(int k = 1; k <= size; k++){	
		if(visited[k] == true)
			continue;	
		visited[k] = true;
		count = 0;
		q.push(k);
		while(!q.empty()){
			int s = q.front();
			count += a[s-1];
			//cout << "count is " << count << endl;
			q.pop();
		
			for(it = adj[s].begin(); it != adj[s].end(); it++){
				if(visited[*it] == false){
					visited[*it] = true;
					q.push(*it);
				}
			}
		}
		if(count > max)
			max = count;
	}
	return max;
}*/

void Graph::DFSUtil(int v,long long int a[], bool visited[], int& count){
	visited[v] = true;
	count += a[v-1];
	list<int>::iterator it;
	for(it = adj[v].begin(); it != adj[v].end(); it++){
		if(!visited[*it])
			DFSUtil(*it,a,visited,count);
	}
	//cout << v << endl;
}

int Graph::DFS(long long int a[],int size){
	int count, max = 0;
	bool *visited = new bool[100000];
	for(int i = 0; i <= size; i++)
		visited[i] = false;
	
	for(int i = 1; i <= size; i++){
		count = 0;
		if(visited[i] == false)
			DFSUtil(i,a,visited,count);
		if(count > max)
			max = count;
	}
return max;
}

int main(){
	int size,n,m,x,y;
	cin >> size;
	int i = 0;
	long long int *a;
	while(i < size){
		Graph g;
		cin >> n >> m;
		a = new long long int[n];
		for(int j = 0; j < m; j++){
			cin >> x >> y;
			g.addEdge(x,y);
		}
		for(int j = 0; j < n; j++){
			cin >> a[j];
		}	
		cout << g.DFS(a,n) << endl;
		i++;
	}
	return 0;
}
	

			

