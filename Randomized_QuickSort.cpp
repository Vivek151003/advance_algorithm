
#include <bits/stdc++.h>
using namespace std;
int partition(int arr[],int p,int r)
{
	int x=arr[r];
	int i=p-1;
	int j;
	for(int j=p;j<=r-1;j++)
	{
    	if(arr[j]<=x)
    	{
        	i++;
        	swap(arr[j],arr[i]);
    	}
	}
	swap(arr[i+1],arr[r]);
	return i+1;
}
int R_partition(int arr[],int p,int r)
{
    
	int i=p+rand()%(r-p+1);
	swap(arr[i],arr[r]);
	return partition(arr,p,r);
}

void Random_quick(int arr[],int p,int r)
{
	if(p<r)
	{
    	int q=R_partition(arr,p,r);
    	Random_quick(arr,p,q-1);
    	Random_quick(arr,q+1,r);
	}
}
int main()
{
	int n;
	cin>>n;
   int arr[n];
   for(int i=0;i<n;i++)
   {
   	cin>>arr[i];
   }
   Random_quick(arr,0,n-1);
   
   for(int i=0;i<n;i++)
   {
   	cout<<arr[i]<<" ";
   }
}







