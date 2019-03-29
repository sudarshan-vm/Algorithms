#include<iostream>
#include<cstring>
#include<stdbool.h>
using namespace std;

bool isSafe(int **a,int row,int col,int n);
bool nQueens(int **a,int row,int n);

int main()
{
	cout<<"\nEnter the size of matrix:\t";
	int n;
	cin>>n;
	int *a[n];
	for(int i=0;i<n;i++)
		a[i]=new int[n];
//	memset(a,0,sizeof(a));

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			a[i][j]=0;
	bool flag;
	//for(int i=0;i<n;i++)	
	 //flag=nQueens(a,0,n);
	//if(flag==0)
		//	cout<<"\nNo safe matrix\n";
	
	nQueens(a,0,n);
	
	return 0;
}

bool nQueens(int **a,int row,int n)
{
	int i,j;
	static int solCounter=0;
	if(row>=n)
		{
		cout<<"Solution "<<(++solCounter)<<":\n";
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
					cout<<a[i][j]<<" ";
				cout<<endl;
			}
			//cout<<"REACHED HERE.."<<endl;
			cout<<endl;
			return true;
		}
	//if(row==0)
		//a[0][col]=1;
		
	for(int i=0;i<n;i++)
	{
	//	if(i!=col)
		//	return true;
		//{
		if(isSafe(a,row,i,n))
		{
			a[row][i]=1;
		//	if(nQueens(a,row+1,n))
			//	return true;
			
			
			nQueens(a,row+1,n);
			/* Backtrack  */
			a[row][i]=0;			
		}
		
	}
	
	return false;

}

bool isSafe(int **a,int row,int col,int n)
{
	int i,j;
	for( i=0;i<n;i++)
		if(a[row][i]==1)
			return false;
	
	for(int i=0;i<n;i++)
		if(a[i][col]==1)
			return false;

	//left-top diagonal
	for(i=row,j=col;i>=0&&j>=0;i--,j--)
		if(a[i][j]==1)
			return false;	
			
	//right-top diagonal
	for(i=row,j=col;i>=0&&j<n;i--,j++)
		if(a[i][j]==1)
			return false;	
	
			//down-left diagonal
	for(i=row,j=col;i<n&&j>=0;i++,j--)
		if(a[i][j]==1)
			return false;	
	
			//down-right diagonal
	for(i=row,j=col;i<n&&j<n;i++,j++)
		if(a[i][j]==1)
			return false;	

}
