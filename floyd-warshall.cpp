#include<iostream>
#include<algorithm>
using namespace std;

void floyds(int a[10][10],int n);

void warshall(int a[10][10],int n);

int main()
{
	int a[10][10],n,ch;
	
	cout<<"\nEnter your choice:\n\t1.Floyds's\n\t2.Warshall's"<<endl;
		cin>>ch;
		
	cout<<"\nEnter the size of matrix:\t";
	cin>>n;
	
	cout<<"\nEnter the matrix values:\t";
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>a[i][j];
	
	
	if(ch==1)
		floyds(a,n);
	else if(ch==2)
		warshall(a,n);
	else 
		cout<<"\nInvalid input, Try again."<<endl;
		
	return 0;
}

void floyds(int a[10][10],int n)
{
	int i,j,k;
	int d[n][n];
	
	for(i=0;i<n;i++)
		for(int j=0;j<n;j++)
			d[i][j]=a[i][j];
		
	for(k=0;k<n;k++)
		{
			for(i=0;i<n;i++)
				for(j=0;j<n;j++)
					d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
		
		}
		
	cout<<"\nAfter applying floyds algorithm, Resulting distance matrix is:\n";

	for(i=0;i<n;i++)
		{
		for(int j=0;j<n;j++)
			cout<<d[i][j]<<" ";
		cout<<endl;
		}
		
}


void warshall(int a[10][10],int n)
{
	int i,j,k;
	int d[n][n];
	
	for(i=0;i<n;i++)
		for(int j=0;j<n;j++)
			d[i][j]=a[i][j];
		
	for(k=0;k<n;k++)
		{
			for(i=0;i<n;i++)
				for(j=0;j<n;j++)
					d[i][j]=d[i][j]||(d[i][k]&&d[k][j]);
		
		}
		
	cout<<"\nAfter applying warshall algorithm:\n";

	for(i=0;i<n;i++)
		{
		for(int j=0;j<n;j++)
			cout<<d[i][j]<<" ";
		cout<<endl;
		}
		
}
