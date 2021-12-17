#include<iostream>
#include<queue>
using namespace std;
void printBFS(int**edge, int n, int sv){
	queue<int> pendingVertices;
	bool* visited = new bool[n];
	for(int i=0;i<n;i++){
		visited[i]=false;
	}
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
		printBFS(edge,n,0);
		delete [] visited;
		for(int i=0;i<n;i++){
			delete [] edge[i];
		}
		delete [] edge;
}
