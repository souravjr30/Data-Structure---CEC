#include<stdio.h>
int size=50;
int stack[50],ch,ele,top;
int isempty()
{
	if(top==0)
	{
	printf("\n The stack is empty");
	return(1);
	}
	else
	{
	printf("\n The stack is not empty");
	return(0);
	}
}

int isfull()
{
	if(top==50)
	{
	printf("Stack is full");
	return(1);
	}
	else
	{
	printf("The stack is not full");
	return(0);
	}
}
void push(int ele)
{
	if(!isfull())
	{
		stack[top++]=ele;	
	}
}
int pop()
{
	if(!isempty())
	{
		return(stack[top--]);
	}
}

int peek()
{
	if(!isempty())
	{
		printf("Stack is empty");
	}
	else
	{
		ele=stack[top-1];
		return(ele);
	}
}
int display()
{
	int i;
	printf("\n \n");
	for(i=0;i<top;i++)
	printf("\n %d ",stack[i]);
}

int main()
{
	do
	{
		printf("\n 1.push\n 2.pop\n 3.peek\n 4.isfull\n 5.isempty\n 6.display\n 7.exit");
		printf("\n Enter your choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: if(! isfull())
				{
					printf("\n Enter the element to be pushed");
					scanf("%d",&ele);
					push(ele);
				}
				break;
			case 2: if(! isempty())
				{
					ele=pop();
					printf("\n Element is %d",ele);
				}
				break;
			case 3: peek();
				break;
			case 4: isfull();
				break;
			case 5: isempty();
				break;
			case 6: display();
				break;
			case 7: break;
			default:printf("Invalid choice");
		}
	}while(ch!=7);
}
		




