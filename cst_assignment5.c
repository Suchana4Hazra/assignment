#include<stdio.h>
#include<stdlib.h>

struct intNode
{
	int element;
	struct intNode *next;
};
typedef struct intNode node;

node* insert(node *start,int data)
{
	node *newnode,*p,*c;
	
	newnode=(node*)malloc(sizeof(node));
	newnode->element=data;
	newnode->next=NULL;
	
	if(start==NULL)
	{
		start=newnode;
		return start;
	}
	p=start;
	for(c=start;c!=NULL;c=c->next)
	{
		if(c->element>data)
		{
			if(c==p)
			{
				newnode->next=start;
				start=newnode;
				return start;
			}
			else
			{
				p->next=newnode;
				newnode->next=c;
				return start;
			}
		}
		p=c;
	}
	if(c==NULL)
	{
		p->next=newnode;
		return start;
	}
}


node *deleteNode(node *start,int data)
{
	node *p,*c,*t;
	if(start==NULL)
	
	{
		printf("\n list empty");
		return start;
	}
	p=start;
	for(c=start;c!=NULL;c=c->next)
	{
		if(c->element==data)
		{
			if(c==p)
			{
				start=c->next;
				free(c);
				return start;
			}
			else
			{
				t=c;
				p->next=t->next;
				free(t);
				return start;
			}
		}
		p=c;
	}
	if(c==NULL)
	{
		if(c->element==data)
		{
		    free(p);
			return start;	
		}
	}
}
int isPresentNodeSorted(node *start,int elem)
{
	int count=1;
	node *c;
	for(c=start;c!=NULL;c=c->next)
	{
		if(c->element==elem)
		return count;
		else
		count++;
	}
	if(c==NULL)
	return -1;
}


void list(node *start)
{
	node *c;
	for(c=start;c!=NULL;c=c->next)
	{
		printf("%5d",c->element);
	}
}

node *freeIntNodeSorted(node *start)
{
	node *c,*p;
	p=start;
	c=start;
	while(c!=NULL)
	{
		c=c->next;
		free(p);
		p=NULL;
		p=c;
	}
	return NULL;
}

void updateIntNode(node *start)
{
	node *c;
	int rValue;
	for(c=start;c!=NULL;c=c->next)
	{
	   rValue=rand()%10;
	  printf("\n %d",rValue);
	   c->element+=rValue;
	  	srand(0);
	}
}

node *reverseIntNodeSorted(node *start)
{
	node *c1,*c2,*c3;
	c1=start;
	c2=start->next;
	start->next=NULL;
	while(c2!=NULL)
	{
		c3=c2->next;
		c2->next=c1;
		c1=c2;
		c2=c3;
	}
	start=c1;
	return start;
}

node *sortIntNode (node *start)
{
	node *i,*j,*prei,*prej,*temp;
	
	if(start==NULL)
	return;
	
	top:
	for(i=start;i->next!=NULL;i=i->next)
	{
		for(j=i->next;j!=NULL;j=j->next)
		{
			if(i->element>j->element)
			{
				if(j==i->next)
				{
					i->next=j->next;
					j->next=i;
				}
				else
				{
					temp=i->next;
					i->next=j->next;
					j->next=temp;
					prej->next=i;
				}
				   if(i==start)
				    start=j;
				   else
				    prei->next=j;
				goto top;
			}
			prej=j;
		}
		prei=i;
	}
	return start;
}
// for inserting elements in new list after doing merge sort
node *insertAfter(node *start,int data)
{
	node *newnode,*c;
	newnode=(node*)malloc(sizeof(node));
	newnode->element=data;
	newnode->next=NULL;
    
	if(start==NULL)
	{
		start=newnode;
		return start;
	}
	c=start;
	while(c->next!=NULL)
	{
		c=c->next;
	}
	c->next=newnode;
	return start;
}

node *mergeSNodeSorted(node *start1,node *start2)
{
	node *start=NULL;
	node *c=start1;
	node *p=start2;
	while(c!=NULL && p!=NULL)
	{
		if(c->element<p->element)
		{
			start=insertAfter(start,c->element);
			c=c->next;
		}
		else
		{
		    start=insertAfter(start,p->element);
		    p=p->next;	
		}
	}
	while(c!=NULL)
	{
			start=insertAfter(start,c->element);
			c=c->next;
	}
	while(p!=NULL)
	{
			start=insertAfter(start,p->element);
			p=p->next;
	}
	return start;		
}
main()
{
    node *start=NULL,*start1=NULL,*start2=NULL,*ranlist=NULL;
	int ch,d,n;
	do{
		printf("\n enter \n 1.1st insert \n 2.delete \n 3.1st list show \n 4.search an element in list \n 5.free \n 6.update node \n 7.reverse list \n 8.insert in 2nd list \n 9.merge \n 10.2nd list show \n 11.insert random number in list \n 12.sort the random list 13.exit \n");
		printf("\n enter choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\n enter in the 1st list:\n");
				printf("\n enter data: ");
				scanf("%d",&d);
				start1=insert(start1,d);
				break;
				
			case 2:
				printf("\n enter data: ");
				scanf("%d",&d);
				start1=deleteNode(start1,d);
				break;
				
			case 3:
				printf("\n 1st list\n");
				list(start1);
				break;
			
			case 4:
				printf("\n enter an element to search: ");
				scanf("%d",&d);
				n=isPresentNodeSorted(start1,d);
				printf("\n the element is present at %dth pos.",n);
				break;
				
			case 5:
				start1=freeIntNodeSorted(start1);
				break;
				
			case 6:
				updateIntNode(start1);
				break;	
				
			case 7:
			    start=reverseIntNodeSorted(start1);
				break;	
				
			case 8:
				printf("\n enter in the 2nd list:\n");
				printf("\n enter data: ");
				scanf("%d",&d);
				start2=insert(start2,d);
				break;
				
			case 9:
				start=mergeSNodeSorted(start1,start2);
				list(start);
				break;
			
			case 10:
				printf("\n 2nd list\n");
				list(start2);
				break;
				
			case 11:
			    printf("\n enter rand element in list: ");
			    scanf("%d",&d);
			    ranlist=insertAfter(ranlist,d);
			    list(ranlist);
			    break;
			    
			case 12:
				ranlist=sortIntNode(ranlist);
				list(ranlist);
				break;
				
		}
	}while(ch!=13);
}
