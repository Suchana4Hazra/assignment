#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct myStack
{
	int *pstorage;
	int max_size;
	int top;
}myStack;

typedef struct myQueue
{
    myStack s1;
    myStack s2;
}myQueue;

myStack *createIntegerStack(myStack *pStack)
{
	pStack->top=-1;
	pStack->pstorage=(int*)malloc(pStack->max_size*sizeof(int));
	if(pStack->pstorage==NULL)
	{
		printf("\n Error!!");
		return NULL;
	}
	return pStack;
}
int pushIntegerInStack(myStack *pStack,int data)
{
	if(pStack->top==pStack->max_size-1)
	{
		printf("\n stack is full.No Entry!!\n");
		return 0;
	}
	pStack->pstorage[++pStack->top]=data;
	return 1;
}
int popStack(myStack *pStack)
{
	int data;
	data=pStack->pstorage[pStack->top];
	pStack->top--;
	return data;
}
int isStackEmpty(myStack *s1)
{
	if(s1->top==-1)
	return 1;
	return 0;
}
int isStackFull(myStack *s1)
{
	if(s1->top==s1->max_size-1)
	return 1;
	return 0;
}
void freeIntegerStack(myQueue *qu)
{
	free(qu->s1.pstorage);
	qu->s1.pstorage=NULL;
	
	free(qu->s2.pstorage);
	qu->s2.pstorage=NULL;
	
	return;
}

void enqueue(myQueue *qu)
{
	int data,n;
	printf("\n enter the element: ");
	scanf("%d",&data);
	n=pushIntegerInStack(&qu->s1,data);
	if(n==1)
	{
		printf("\n enqueue successfull");
	}
	else
	printf("\n enqueue is not successfull");
}

int dequeue(myQueue *qu,int *data)
{
	if(isStackEmpty(&qu->s1)==1 && isStackEmpty(&qu->s2)==1)
	{
		printf("\n no element in list");
		return 0;
	}
	if(isStackEmpty(&qu->s2)==1)
	{
		while(qu->s1.top!=-1)
		{
			pushIntegerInStack(&qu->s2,popStack(&qu->s1));
		}
	}
	*data=popStack(&qu->s2);
	return 1;
}
void list(myQueue qu)
{
	int i;
	for(i=qu.s2.top;i>=0;i--)
	{
	    //printf("\n for 2nd stack:\n");
		printf("%5d",qu.s2.pstorage[i]);
	}
	for(i=0;i<=qu.s1.top;i++)
	{
		//printf("\n for 1st stack:\n");
		printf("%5d",qu.s1.pstorage[i]);
	}
	return;
}
main()
{
	myQueue qu;
	qu.s1.top=-1;
	qu.s2.top=-1;
	int data,ch;
	printf("\n enter size for 1st stack: ");
	scanf("%d",&qu.s1.max_size);
	printf("\n enter size for 2nd stack: ");
	scanf("%d",&qu.s2.max_size);
	createIntegerStack(&qu.s1);
	createIntegerStack(&qu.s2);
	
do{
	printf("\n enter \n 1.enqueue \n 2.dequeue \n 3.list \n 4.Free dynamic memory \n 5.exit\n");
	printf("\n enter the choice: ");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1:
		enqueue(&qu);
		break;
	case 2:
		dequeue(&qu,&data);
		printf("\n the dequeued element is %d",data);
		break;
	case 3:
		list(qu);
		break;
	case 4:
		freeIntegerStack(&qu);
		break;
	}
}while(ch!=5);
}
