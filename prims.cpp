#include <iostream>
#include <cstring>
using namespace std;
 
#define INF 9999999

void prim(int **G,int n);

int main () {
  cout<<"\nEnter number of vertices:\t";
  int n;
  cin>>n;
  int *G[n];
  for(int i=0;i<n;i++)
  	G[i]=new int [n];
  
  cout<<"\nEnter the adjacency matrix:\t";
  for(int i=0;i<n;i++)
  	for(int j=0;j<n;j++)
  		cin>>G[i][j];
  
  prim(G,n);
  return 0;
 }
 
void prim(int **G,int n)
{
  int selected[n],output[n][n],no_edge=0,x,y,min_cost=0;

  memset(output,false,sizeof(output)); //set all values to zero
  memset(selected,false,sizeof(selected)); 
  selected[0] = true;
  
  cout << "Edge" << " : " << "Weight";
  cout << endl;
  while (no_edge < n - 1) {
    int min = INF;
    x = 0;
    y = 0;
 
    for (int i = 0; i < n; i++)
    {
        if (selected[i])
        {
            for (int j = 0; j < n; j++) 
            {
              if (!selected[j] && G[i][j]) 
              { // not in selected and there is an edge
                  if (min > G[i][j])
                  {
                      min = G[i][j];
                      x = i;
                      y = j;
                  }
     
              }
          	}
         }
      }
      cout<<endl;
      cout << x <<  " - " << y << " :  " << G[x][y];
      min_cost+=G[x][y];
      output[x][y]=output[y][x]=G[x][y];
      cout << endl;
      selected[y] = true;
      no_edge++;
    }
 	
 	cout<<"\nAdjacency matrix of prim's MST is:\n";
 	for(int i=0;i<n;i++)
 	{
 		for(int j=0;j<n;j++)
 		{
 			cout<<output[i][j]<<" ";
 		}
 		cout<<endl;
 	}
 	cout<<"Total Cost= "<<min_cost<<endl; 
 }
