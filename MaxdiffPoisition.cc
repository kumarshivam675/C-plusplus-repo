/*  print max j-i of arr such that  a[j]>a[i] */
#include<iostream>
#include<climits>
using namespace std;
int max(int a,int b)
{
	return a>b?a:b;

}

int min(int a,int b)
{
	return a<b?a:b;

}
int main()
{
	int a[]={9,2,3,4,5,6,7,8,18,0};
	//int a[]={34, 8, 10, 3, 2, 80, 30, 33, 1};
	int n=sizeof(a)/sizeof(a[0]);
	int left[n],right[n];
	left[0]=a[0];
	for(int i=1;i<n;i++)
	{
		left[i]=min(left[i-1],a[i]);
	}
	right[0]=a[n-1];
	for(int i=n-2;i>=0;i--)
	{
		right[i]=max(right[i+1],a[i]);
	
	}
	int i=0,j=0,maxDiff=INT_MIN;
	while(i<n && j<n)
	{
		
		if(left[i]<right[j])
		{
			
			//cout<<left[i]<<" "<<right[j]<<endl;
			
			maxDiff=max(maxDiff,j-i);
			j++;
			
			
		}	
		else
		i++;
	}
	cout<<"max="<<maxDiff<<endl;
	return 0;
}
