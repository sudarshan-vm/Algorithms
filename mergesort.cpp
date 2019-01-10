#include<iostream>
using namespace std;

void mergesort(int a[],int n);

void merge(int L[],int n1,int R[],int n2,int [],int );

int main()
{
    int *a,i,n;

    cout<<"\nEnter the number of elements:\t";
    cin>>n;

    a=new int[n];

    cout<<"\nEnter the elements:\t";
    for(i=0;i<n;i++)
        cin>>a[i];

    cout<<"\nBefore mergesort:\t";
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";

    mergesort(a,n);

    cout<<"\nAfter mergesort:\t";
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";


    return 0;
}

void mergesort(int a[],int n)
{
    int i,j;
    if(n>1)
    {
    int m=n/2;
    int L[m],R[n-m];
    for( i=0;i<m;i++)
        L[i]=a[i];
    for(i=m, j=0;i<n;i++,j++)
        L[j]=a[i];

    mergesort(L,m);
    mergesort(R,n-m);
    merge(L,m,R,n-m,a,n);
    }
}

void merge(int L[],int n1,int R[],int n2,int a[],int n)
{
    int i,j,k;
    i=j=k=0;
    while(i<n1&&j<n2)
    {
        if(L[i]<=R[j])
        {
            a[k]=L[i++];
        }
        else
        {
            a[k]=R[j++];
        }
        k++;
    }
    while(i<n1)
        a[k++]=L[i++];
    while(j<n2)
        a[k++]=R[j++];
}

