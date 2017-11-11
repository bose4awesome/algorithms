#include <stdio.h>
//binary search technique
int bin_search(int arr[],int low,int high,int key)
{
	int mid;
	if(low<=high)
	{
		mid=(low+high)/2;
		if(arr[mid]==key)
			return mid;
		else if(arr[mid]>key)
			return bin_search(arr,low,mid-1,key);
		else
			return bin_search(arr,mid+1,high,key);
	}
	else
		return -1;
}
int main()
{
	int a[]={1,2,3,4,5,6,7,8,9,10};
	int input,index,n;
	n=(sizeof(a)/sizeof(a[0]))-1;
	scanf("%d",&input);
	index=bin_search(a,0,n,input);
	printf("Index of Key=%d",index);
	return 0;
}
