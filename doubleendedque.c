#include<stdio.h>
#define size 50
int Q[size],f,r,ele,choice;

void insertrear(int ele)
{
	if(f==(r+1)%size)
	{
		printf("The queue is full");
	}
	else
	{
		printf("Enter the element to be inserted ");
		scanf("%d",&ele);
		r=(r+1)%size;
		if(f==-1)
		{
			f=0;
			Q[r]=ele;
		}
		else
		Q[r]=ele;
	}
}

int deletefront()
{
	if(f==-1)
	printf("The queue is empty");
	else
	{
		printf("Enter the element to be deleted ");
		scanf("%d",&ele);
		Q[f]=ele;
		if(f==r)
		{
			f=r=-1;
		}
		else
		{
			f=f+1;
		}
	}
}
void isfull()
{
	if(f==r+1)
	printf("The queue is full");
	else
	printf("The queue is not full");
}

void isempty()
{
	if(f==-1)
	printf("The queue is empty");
	else
	printf("The queue not empty");
}

void display()
{
	int i=f;
	if(f==-1 && r==-1)
	printf("The queue is full");
	else
	printf("The queue is ");
	while(i!=r-1)
	{
		i=(i+1)%size;
		printf("\n%d",Q[i]);
		
	}
	printf("%d",&Q[r]);
}

void insertfront(int ele)
{
	if(isfull())
	printf("The queue is full");
	else
	{
		if(f==-1)
		f=0,r=0;
		else if(f==0)
		f=size-1;
		else
		f=f-1;
	}	

int main()
{
	int choice;
	do
	{
		
		printf("\n1.insert\n2.delete\n3.isfull\n4.isempty\n5.display\n6.exit\n");
		printf("Enter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: insertrear(ele);
				break;
			case 2: deletefront();
				break;
			case 3: isfull();
				break;
			case 4: isempty();
				break;
			case 5: display();
				break;
			case 6: break;
			default:printf("Invalid choice");
		}
	}
	while(choice!=6);
}


