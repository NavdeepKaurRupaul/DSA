#include<iostream>
#include<queue>
using namespace std;
void printBFS(int**edge, int n, int sv,bool* visited){
	queue<int> pendingVertices;
	pendingVertices.push(sv);
	visited[sv]=true;
	while(!pendingVertices.empty()){
		int currentVertex=pendingVertices.front();
		pendingVertices.pop();
		cout<<currentVertex<<endl;
			for(int i=0;i<n;i++){
				if(i==currentVertex){
					continue;
				}
				if(edge[currentVertex][i]==1 && !visited[i]){
					pendingVertices.push(i);
					visited[i]=true;
				}
			}
		}
}
void printDFS(int**edge, int n, int sv, bool*visited){
	cout<<sv<<endl;
	visited[sv]=true;
	for(int i=0;i<n;i++){
		if(i==sv){
			continue;
		}
		if(edge[sv][i]==1){
			if(visited[i]){
				continue;
			}
			printDFS(edge,n,i,visited);
	}	
  }
}
void DFS(int** edge,int n){
	bool* visited = new bool[n];
	for(int i=0;i<n;i++){
		visited[i]=false;
	}
	for(int i=0;i<n;i++){
		if(!visited[i]){
			printDFS(edge,n,i,visited);
		}
	}
	delete[] visited;
}
void BFS(int** edge,int n){
	bool* visited = new bool[n];
	for(int i=0;i<n;i++){
		visited[i]=false;
	}
	for(int i=0;i<n;i++){
		if(!visited[i]){
			printBFS(edge,n,i,visited);
		}
	}
	delete[] visited;
}
int main(){
	int n;
	int e;
	cin>>n>>e;
	int**edge=new int*[n];
	for(int i=0;i<n;i++){
		edge[i]=new int[n];
		for(int j=0;j<n;j++){
			edge[i][j]=0;
		}
	}
	for(int i=0;i<e;i++){
		int f,s;
		cin>>f>>s;
		edge[f][s]=1;
		edge[s][f]=1;
	}
		bool* visited=new bool[n];
		for(int i=0;i<n;i++){
			visited[i]=false;
		}
		cout<<"DFS:"<<endl;
		DFS(edge,n);
		cout<<"BFS:"<<endl;
		BFS(edge,n);
		for(int i=0;i<n;i++){
			delete [] edge[i];
		}
		delete [] edge;
}















