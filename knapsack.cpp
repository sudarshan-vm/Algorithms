#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>

using namespace std;


void knapsackAlgorithm(int values[],int weight[],int n,int W);

int main()
{	
	int n,cap,matrix[20][20];
	
	cout<<"\nEnter the number of items:\t";
	cin>>n;
	
	int value[n+1],weight[n+1];
	cout<<"\nEnter :";
	for(int i=0;i<n;i++)
			{
				cout<<"\n\tvalue["<<i+1<<"] and weight ["<<i+1<<"]"<<endl;
				cin>>value[i]>>weight[i];
			}
	
	cout<<"\nEnter the capacity of knapsack:\t"<<endl;
	cin>>cap;
	
	
	knapsackAlgorithm(value,weight,n,cap);
	
	return 0;
}

void knapsackAlgorithm(int values[],int weight[],int n,int W)
{
	/* 
	input: an array of n values and another array of n weights , 
			n(number of items) and W(Knapsack Capacity).
	output: a n*W matrix, Maximal value matrix[n][W] and 
			composition of an optimal subset to give maximal value.
	*/
	
	int w,i,j,matrix[n+1][W+1];
	memset(matrix,-1,sizeof(matrix));
	
	cout<<"\nResultant matrix is:\n";
	cout<<"   weight value  item   "<<endl;
	for(i=0;i<=n;i++)
		{
		
		if(i==0)
			printf("             ");
		else
			printf("%6d %6d",weight[i-1],values[i-1]);
		printf("%6d",i);
		for( j=0; j<=W;j++)
			{
				if(i==0||j==0)
					matrix[i][j]=0;
				else if(weight[i-1]<=j)
							matrix[i][j]=max(values[i-1]+matrix[i-1][j-weight[i-1]],matrix[i-1][j]);
				else
					matrix[i][j]=matrix[i-1][j];
				
				printf("%5d ",matrix[i][j]);
			}
			cout<<endl;
		}
		
		cout<<"\nMaximal value is:\t"<<matrix[n][W]<<endl;
				
		/* to display the composition of an optimal subset */
		vector<int>items_included;
		//items_included.push_back(0);
		j=W;
        i=n;
		while(1)
			{
				if(matrix[i][j]>matrix[i-1][j])		
				{
					items_included.push_back(i);
				    j=j-weight[i];
				}
				i--;
				if(i==0)
					break;				
			}
		
		cout<<"\nOptimal subset consists of items:\t";
		for(i=0;i<items_included.size();i++)
			cout<<" "<<items_included[i];
		cout<<endl;
			
			
}
