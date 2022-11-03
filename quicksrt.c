#include<stdio.h>
void swap(int *p,int *q);
int partition(int a[],int left,int right)
{
	int i,j,key;
	key=a[left];
	i=left+1;
	j=right;
	do
	{
		while(a[i]<=key && i<right)
		i++;
		while(a[j]>key && j>left)
		j--;
		if(i<=j)
		swap(&a[i],&a[j]);
	}
	while(i<j);
	swap(&a[left],&a[j]);
	return j;
}
void quicksrt(int a[],int left,int right)
{
	int pos;
	if(left<right)
	{
		pos=partition(a,left,right);
		quicksrt(a,left,pos-1);
		quicksrt(a,pos+1,right);
	}
}

void readnum(int a[],int n)
{	
	int i;
	printf("Enter the elements in the array: ");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
}

void printnum(int a[],int n)
{	
	int i;
	printf("The sorted array is ");
	for(i=0;i<n;i++)
	printf("%d \n",a[i]);
}
void main()
{
	int a[100],n;
	printf("Enter the number of elements in the array: ");
	scanf("%d",&n);
	readnum(a,n);
	quicksrt(a,0,n-1);
	printnum(a,n);
}
void swap(int *p,int *q)
{
int t;
t=*p;
*p=*q;
*q=t;
}
