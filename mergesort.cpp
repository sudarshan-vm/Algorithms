#include<iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include<cstdio>

using namespace std;

int mergesort(int *a,int n);
int merge(int L[],int n1,int R[],int n2,int a[],int n);
void perf_Mergesort();
void complexity();



int main()
{
    int ch;

    cout<<"\nChoose an option:\n\t1.Mergesort\n\t2.Complexity"<<endl;
    cin>>ch;

    if(ch==1)
        perf_Mergesort();
    else
       complexity();

    return 0;
}


void perf_Mergesort()
{


	int c,n,i,*a;
	cout<<"\nEnter the number of elements:\t";
	cin>>n;
	a= new int [n];

	cout<<"\nEnter the elements:\t";
	for(i=0;i<n;i++)
		cin>>a[i];

	cout<<"\nBefore mergesort:\t";

	for(i=0;i<n;i++)
		cout<<a[i]<<" ";

	c=mergesort(a,n);

	cout<<"\nafter mergesort:\t";

	for(i=0;i<n;i++)
		cout<<a[i]<<" ";

	cout<<"\ncomparisons made: "<<c;




}

void complexity()
{


	int a[16400],n,i,c1,c2,c3;

        cout<<setw(6)<<"size\t";
        cout<<setw(6)<<"n*log n\t";
        cout<<setw(6)<<"ascending\t";
        cout<<setw(6)<<"nlogn/asc\t";
		cout<<setw(6)<<"descending\t";
		cout<<setw(6)<<"nlogn/desc.\t";
		cout<<setw(6)<<"random\t";
		cout<<setw(6)<<"nlogn/rand."<<endl;
	for(n=8;n<16400;n=n*2)
	{
		float g=n*log2(n);
		for(i=0;i<n;i++)
			a[i]=i;
		c1=mergesort(a,n);

		for(i=0;i<n;i++)
			a[i]=n-i;
		c2=mergesort(a,n);

		for(i=0;i<n;i++)
			a[i]=(int)rand()%1000;
		c3=mergesort(a,n);



		cout<<setw(6)<<n<<"\t";
		printf("%9.1f\t",g);
		cout<<setw(6)<<c1<<"\t";
		printf("%9.1f\t",g/c1);
		cout<<setw(6)<<c2<<"\t";
		printf("%9.1f\t",g/c2);
		cout<<setw(6)<<c3<<"\t";
		printf("%9.1f\t",g/c3);
		cout<<endl;
	}

}

//performs mergesort and return the number of comparisons made
int mergesort(int *a,int n)
{
	if(n<=1)
		return 0;
	int m=n/2;
	int L[m],R[n-m];
	int i,j,x,y,z;
	for(i=0;i<m;i++)
		L[i]=a[i];
	for(i=m,j=0;i<n;i++,j++)
		R[j]=a[i];
	x=mergesort(L,m);
	y=mergesort(R,n-m);
	z=merge(L,m,R,n-m,a,n);
	return x+y+z;
}

//merges left and right subarrays and returns the number of comparisons made.
int merge(int L[],int n1,int R[],int n2,int a[],int n)
{
	int k,i,j,x=0;
	i=j=k=0;
	while(i<n1&&j<n2)
	{
		x++;
		if(L[i]<=R[j])
			a[k]=L[i++];
		else
			a[k]=R[j++];
		k++;
	}
	//if elements left in left subarray
	while(i<n1)
	{
		a[k]=L[i];
		k++; i++;
	}
	//if elements left in right subarray
	while(j<n2)
	{
		a[k]=R[j];
		k++; j++;
	}
	return x;
}

