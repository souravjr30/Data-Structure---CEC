#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *prev,*next;
};
struct node *head;
void display()
{
	struct node *ptr;
	if(head==NULL)
	printf("\nLINKED LIST IS EMPTY");
	else
	{
		ptr=head;
		printf("\nLINKED LIST ELEMENTS ARE:");
		while(ptr!=NULL)
		{
			printf("%d\t",ptr->data);
			ptr=ptr->next;
		}
	}
}
void insertfront(int x)
{
	struct node *new;
	new=(struct node *)malloc(sizeof(struct node));
	new->data=x;
	new->prev=new->next=NULL;
	if(head==NULL)
	head=new;
	else
	{
		new->next=head;
		head->prev=new;
		head=new;
	}
	display();
}
void insertend(int x)
{
	struct node *new,*ptr;
	new=(struct node *)malloc(sizeof(struct node));
	new->data=x;
	new->prev=new->next=NULL;
	if(head==NULL)
	head=new;
	else
	{
		ptr=head;
		while(ptr->next!=NULL)
		ptr=ptr->next;
		ptr->next=new;
		new->prev=ptr;
	}
	display();
}
void insertafter(int key,int x)
{
	struct node *new,*ptr;
	if(head==NULL)
	printf("INSERTION IS NOT POSSIBLE");
	else
	{
		ptr=head;
		while(ptr->data!=key && ptr->next!=NULL)
		ptr=ptr->next;
		if(ptr->data!=key)
		printf("INSERTION IS NOT POSSIBLE");
		else
		{
			new=(struct node *)malloc(sizeof(struct node));
			new->data=x;
			new->prev=ptr;
			new->next=ptr->next;
			if(new->next!=NULL)
			new->next->prev=new;
			ptr->next=new;
		}
	}
	display();
}
void deletefront()
{
	struct node *temp;
	if(head==NULL)
	printf("DELETION IS NOT POSSIBLE");
	else if(head->next==NULL)
	{
		temp=head;
		head=NULL;
		free(temp);
	}
	else
		{
		head=head->next;
		free(head->prev);
		head->prev=NULL;
	}
	display();
}
void deleteend()
{
	struct node *ptr,*temp;
	if(head==NULL)
	printf("DELETION IS NOT POSSIBLE");
	else if(head->next==NULL)
	{
		temp=head;
		head=NULL;
		free(temp);
	}
	else
	{
		ptr=head;
		while(ptr->next!=NULL)
		ptr=ptr->next;
		ptr->prev->next=NULL;
		free(ptr);
	}
	display();
}
void deleteany(int pos)
{
	int i=0;
	struct node *temp;
	temp=head;
	while(i<pos)
	{
		temp=temp->next;
		i++;
	}
	temp->prev->next=temp->next;
	temp->next->prev=temp->prev;
	free(temp);
	display();
}
void search(int key)
{
	int count=1;
	struct node *ptr;
	if(head==NULL)
	printf("KEY NOT FOUND");
	else
	{
		ptr=head;
		while(ptr->data!=key && ptr->next!=NULL)
		{
			ptr=ptr->next;
			count++;
		}
		if(ptr->data=key)
		printf("KEY IS FOUND AT %d",count);
		else
		printf("KEY NOT FOUND");
	}
}
void main()
{
	int ch,x,key,pos;
	do
	{
		printf("\n1.INSERT FRONT\n2.INSERT END\n3.INSERT AFTER\n4.DELETE FRONT\n5.DELETE END\n6.DELETE ANY\n7.DISPLAY\n8.SEARCH\n9.EXIT\n");
		printf("ENTER THE CHOICE");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 : printf("ENTER NEW DATA:");
			scanf("%d",&x);
			insertfront(x);
			break;
			case 2 : printf("ENTER NEW DATA:");
			scanf("%d",&x);
			insertend(x);
			break;
			case 3 : printf("ENTER SEARCH KEY:");
			scanf("%d",&key);
			printf("ENTER NEW DATA:");
			scanf("%d",&x);
			insertafter(key,x);
			break;
			case 4 : deletefront();
			break;
			case 5 : deleteend();
			break;
			case 6 : printf("ENTER POSITION OF NODE TO BE DELETED");
			scanf("%d",&pos);
			deleteany(pos);
			break;
			case 7 : display();
			break;
			case 8 : printf("ENTER THE KEY TO BE SEARCHED:");
			scanf("%d",&key);
			search(key);
			break;
			case 9 : break;
			default: printf("INVALID CHOICE");
		}
	}while(ch!=9);
}
