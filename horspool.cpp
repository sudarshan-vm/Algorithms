#include<string>   			//Name : SUDARSHAN - (Horspool's Algorithm)
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define SIZE 256

int HorspoolMatching(string pattern,int m,string text,int n,int shift_table[]);

int main()
{
	int m,n,i,j;
	string pattern,text;
	
	cout<<"\n\tEnter the text:\t";
	cin>>text;

	cout<<"\n\tEnter the pattern to be searched:\t";
	cin>>pattern;

	m=pattern.size();
	n=text.size();

	int shift_table[SIZE];
	
	for(i=0;i<SIZE;i++)
		shift_table[i]=m;
	
	for(j=0;j<m-1;j++)
		if(shift_table[(int)(pattern[j])]==m)
		shift_table[(int)(pattern[j])]=m-j-1;

	i=HorspoolMatching(pattern,m,text,n,shift_table);
	
	if(i!=-1)
		cout<<"\n\tSearch string is found from index "<<i<<endl;
	else
		cout<<"\n\tSearch string is not found."<<endl;
	
	return 0;
}

int HorspoolMatching(string pattern, int m, string text, int n, int shift_table[])
{
	//Input: two strings pattern and text; A shift_table to store the shift values .
	//Output: display the index from which the pattern starts in the text.
	
	int i=0,k=0;
	
	i=m-1;
	while(i<n)
	{
		k=0;	
		while(k<m&&pattern[m-1-k]==text[i-k])
		
			k++;	
		
		if(k==m)
			return i-m+1;
		else 
			i+=shift_table[(int)text[i]];
	}

	return -1;
}

