#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int coeff;
	int expone;
	struct Node *next;
};
typedef struct Node node;
node *poly1, *poly2, *poly3 = NULL;
node *p1, *p2, *p3;
node *newnode()
{
	node *p;
	p = (node *)malloc(sizeof(node));
	p->next=NULL;
	return p;
}
void print(node *a)
{
	node *curr;
	curr = a;
	printf("\nf(x) =");
	while(curr!=NULL)
	{
		printf("%d(x^%d)",curr->coeff,curr->expone);
		curr=curr->next;
		if(curr!=NULL)
		{
			printf("+");
		}
	}
}

node *read(node *a)
{
	int i=0,c[10],e[10],ch;
	node *curr, *p;
	printf("\n\nENTER THE COEFF & POWER OF EXPRESSION IN ORDER :-\n");
	do
	{
		printf("ENTER THE COEFFICIENT :");
		scanf("%d",&c[i]);
		printf("ENTER THE POWER :");
		scanf("%d",&e[i]);
		printf("DO YOU WANT TO CONTINUE(1,0) :");
		scanf("%d",&ch);
		i++;
	}while(ch!=0);
	while(i!=0)
	{
		i--;
		p=newnode();
		p->coeff = c[i];
		p->expone = e[i];
		if(a==NULL)
		a=p;
		else
		{
			p->next=a;
			a=p;
		}
	}
	print(a);
	return(a);
}

void Addpoly()
{
	node *p1, *p2, *p3;
	p1=poly1;
	p2=poly2;
	p3=newnode();
	poly3=p3;
	while(p1!=NULL && p2!=NULL)
	{
		if(p1->expone==p2->expone)
		{
			p3->coeff=p1->coeff+p2->coeff;
			p3->expone=p1->expone;
			p1=p1->next;
			p2=p2->next;
		}
		else
		{
			if(p1->expone > p2->expone)
			{
				p3->expone=p1->expone;
				p3->coeff=p1->coeff;
				p1=p1->next;
			}
			else
			{
				p3->expone=p2->expone;
				p3->coeff=p2->coeff;
				p2=p2->next;
			}
		}
		if(p1!=NULL && p2!=NULL)
		{
			p3->next=newnode();
			p3=p3->next;
		}
	}
	while(p1!=NULL)
	{
		p3->next=newnode();
		p3=p3->next;
		p3->expone=p1->expone;
		p3->coeff=p1->coeff;
		p1=p1->next;
	}
	while(p2!=NULL)
	{
		p3->next=newnode();
		p3=p3->next;
		p3->expone=p2->expone;
		p3->coeff=p2->coeff;
		p2=p2->next;
	}
}

void main()
{
	poly1=read(poly1);
	poly2=read(poly2);
	Addpoly();
	printf("\n\nTHE SUM OF POLY1 AND POLY2 IS :\n");
	print(poly3);
}

				
	
