#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
void quicksort(int a[],int l,int r);
int partition(int a[],int l,int r);

int main()
{
    int *a,n,i;
    cout<<"\nEnter the number of elements:\t";
    cin>>n;
    a= new int [n];
    for(i=0;i<n;i++)
        cin>>a[i];
    cout<<"\nEntered elements are:\t";
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;

    quicksort(a,0,n-1);

    cout<<"\nAfter quicksort:\t";
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;

    return 0;
}

void quicksort(int a[],int l,int r)
{
    int s;
    if(l>=r)
        return ;
    s=partition(a,l,r);
    quicksort(a,l,s-1);
    quicksort(a,s+1,r);
    return;
}

int partition(int a[],int l,int r)
{
    int pivot;
    pivot=a[l];
    int i=l,j=r+1;

    while(1)
    {

    while(a[++i]<pivot)
        if(a[i]==r)
            break;

    while(a[--j]>pivot)
        if(a[j]==l)
            break;

    if(i>j)
        break;
    swap(a[i],a[j]);
    }

    //swap with pivot element
    swap(a[l],a[j]);
    return j;
}
