#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*link;
};
struct node*head;

void display()
{
	struct node*ptr;
	if(head==NULL)
	printf("LIST IS EMPTY");
	else
	{
		ptr=head;
		printf("ELEMENTS ARE ");
		while(ptr!=NULL)
		{
			printf("%d \t",ptr->data);
			ptr=ptr->link;
		}
	}
}

void insertfront(int x)
{
	struct node*new;
	new=(struct node*)malloc(sizeof(struct node));
	ptr->data=x;
	ptr->head;
	ptr=head;
	display();
}
void insertend(int x,int key)
{
	struct node*new,*ptr;
	if(head==NULL)
	printf("INSERTION IS NOT POSSIBLE");
	else
	{
		ptr=head;
		while(ptr->data!=key && ptr->link!=NULL)
		{
			ptr=ptr->link;
			if(ptr->data!=key)
			printf("INSERTION IS NOT POSSIBLE");
			else
			{
				new=(struct node*)malloc(sizeof(struct node));
				new->data=x;
				new->link=ptr->link;
				ptr->link=new;
			}
		}
	}
}

void deletefront()
{
	struct node*temp;
	if(head==NULL)
	printf("DELETION IS NOT POSSIBLE");
	else
	{
		temp=head;
		head=head->link;
		free(temp);
	}

}

void deleteend()
{
	struct node*prev,*curr,*temp;
	if(head==NULL)
	printf("DELETION IS NOT POSSIBLE");
	else if(head->link==NULL)
	{
		temp=head;
		head=NULL;
		free(temp);
	}
	else
	{
		prev=head;
		curr=head->link;
		while(curr->link!=NULL)
		{
			prev=curr;
			curr=curr->link;
		}
		prev->link=NULL;
		free(curr);
	}

}

void insertafter(int x,int key)
{
	struct node*new,*ptr;
	new=(struct node*)malloc(sizeof(struct node));
	new->data=x;
	new->link=NULL;
	if(head==NULL)
	head=new;
	else
	{
		ptr=head;
		while(ptr->link!=NULL)
		{
			ptr=ptr->link;
			ptr->link=new;
		}
	}
}

void insertbefore(int x,int key)
{
	struct node*new,*ptr,*prev;
	if(head==NULL)
	printf("INSERTION IS NOT POSSIBLE");
	else
	{
		ptr=head;
		while(ptr->link!=NULL)
		{
			prev=ptr;
			ptr=ptr->link;
		}
		if(ptr->data==NULL)
		printf("NO SUCH NODE IS FOUND");
		else
		{
			new=(struct node*)malloc(sizeof(struct node));
			new->data=x;
			new->link=ptr;
		}
		if(ptr==head)
		head=new;
		else
		prev->link=new;
	}
}

void delete(int x)
{
	struct node*curr,*prev;
	if(head==NULL)
	printf("DELETION IS NOT POSSIBLE");
	else
	curr=head;
	while(curr!=NULL && curr->data!=x)
	{
		prev=curr;
		curr=curr->link;
		if(curr==NULL)
		printf("NO SUCH NODE IS FOUND");
		else if(curr==head)
		head=curr->link;
		else
		prev->link=curr->link;
	}
	free(curr);
}

void main()
{
	int choice,x,key;
	do
	{
		printf("\n1.insertfront\n2.insertend\n3.deletefront\n4.deleteend\n5.insertafter\n6.insertbefore\n7.delete\n8.display\n9.exit\n");
		printf("ENTER YOUR CHOICE ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: insertfront(x);
				printf("ENTER THE ELEMENT TO BE INSERTED");
				scanf("%d",&x);
				break;
			case 2: insertend(x,key);
				printf("ENTER THE ELEMENT TO BE INSERTED");
				scanf("%d",&x);
				break;
			case 3: deletefront();
				break;
			case 4: deleteend();
				break;
			case 5: insertafter(x,key);
				printf("ENTER THE KEY");
				scanf("%d",&key);
				printf("ENTER THE ELEMENT TO BE INSERTED");
				scanf("%d",&x);
				break;
			case 6: insertbefore(x,key);
				printf("ENTER THE KEY");
				scanf("%d",&key);
				printf("ENTER THE ELEMENT TO BE INSERTED");
				scanf("%d",&x);
				break;
			case 7: delete(x);
				break;
			case 8: display();
				break;
			case 9: break;
			default:printf("Invalid choice");
		}
	}
	while(choice!=9);
}

		
				
				
