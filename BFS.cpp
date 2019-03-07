#include<iostream>				
#include<queue>
#include<cstdlib>
using namespace std;


void BFS(int a[10][10],int n);
void bfs(int a[10][10],int n,int v,int visited[],queue<int> q);

int main()
{
	int V,a[10][10];
	
	cout<<"\n\tEnter the number of vertices:\t";
	cin>>V;
	
	cout<<"\n\tEnter the adjacency matrix:\t";
	for(int i=0;i<V;i++)
		for(int j=0;j<V;j++)
			cin>>a[i][j];
	
	BFS(a,V);
	
	return 0;
}

void BFS(int a[10][10],int n)
{
	//input: adjacency matrix of graph and no of vertices
	//output: initialization function for dfs traversal 
	//displays number of components of the graph
	
	int visited[n],v;
	queue<int>q;
	int count=0;
	
	for(int i=0;i<n;i++)
		visited[i]=0;
		
	cout<<"\n\tEnter the starting vertex:\t";
	cin>>v;
	int i=v;
	cout<<"\nBFS traversal is : ";
	
	do //in case of more than one components of graph
	{
		//count++;
		if(!visited[i]==1)
		{
			count++;
		//else
			bfs(a,n,i,visited,q);
		}
		i=(i+1)%n;
	}while(i!=v);
	
	if(count>1)
		cout<<"\n\tGraph is disconnected.\n\tNumber of componets = "<<count<<endl;
	else
		cout<<"\n\tGraph is connected.\n";
}

void bfs(int a[10][10],int n,int v,int visited[],queue<int> q)
{
	//input: adjacency matrix, order, a queue to store the vertices
	//visited[] array to keep track of all visited/unvisited vertices
	//v is the current vertex being visited
	//Output: displays the bfs traversal of the graph.
	if(visited[v]==1)
		return ;
			
	q.push(v);
	visited[v]=1;
	
	int count=0;

	while(!q.empty())
	{
		int top=q.front();
		cout<<" "<<top;
		q.pop();
			
			
		for(int w=0;w<n;w++)
			
			if(visited[w]==0&&a[top][w]==1)
				{
					q.push(w);
					visited[w]=1;
				}
				
	}	
}


