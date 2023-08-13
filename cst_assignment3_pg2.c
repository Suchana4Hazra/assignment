#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct myStack
{
	int *pstorage;
	int max_size;
	int top;
}myStack;

myStack *createIntegerStack(myStack *pStack,int size)
{
	pStack->top=-1;
	pStack->pstorage=(int*)malloc(size*sizeof(int));
	if(pStack->pstorage==NULL)
	{
		printf("\n Error!!");
		return NULL;
	}
	return pStack;
}

int pushIntegerInStack(myStack *pStack,int data,int max_size)
{
	if(pStack->top==max_size-1)
	{
		//printf("\n stack is full.No Entry!!\n");
		return 0;
	}
	pStack->pstorage[++pStack->top]=data;
	return 1;
}

int popStack(myStack *pStack,int *data)
{
	if(pStack->top==-1)
	{
		//printf("\n stack is empty.Delete not possible!!\n");
		return 0;
	}
	*data=pStack->pstorage[pStack->top];
	pStack->top--;
	return 1;
}

void list(myStack *pStack)
{
	int i;
	for(i=0;i<=pStack->top;i++)
	{
		printf("%5d",pStack->pstorage[i]);
	}
	return;
}

void freeIntegerStack(myStack *pStack)
{
	free(pStack->pstorage);
	pStack->pstorage=NULL;
	return;
}

main()
{
	myStack stack1,stack2;
	int size1,size2,ch,n,d,m,data;
	printf("\n Enter the size of the stack1: ");
	scanf("%d",&size1);
	printf("\n Enter the size of the stack2: ");
	scanf("%d",&size2);
	createIntegerStack(&stack1,size1);
	createIntegerStack(&stack2,size2);
	do{
		printf("\nEnter \n 1.push \n 2.pop \n 3.See the stack-list \n 4.free memory \n 5.exit");
		printf("\nEnter the choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\n Enter element: ");
				scanf("%d",&d);
				n=pushIntegerInStack(&stack1,d,size1);
				if(n==0)
				{
					m=pushIntegerInStack(&stack2,d,size2);
					if(m==0)
					printf("\n No Entry!!");
				}
				break;
			case 2:
				n=popStack(&stack2,&data);
				if(n==0)
				{
				m=popStack(&stack1,&data);
				if(m==0)
				printf("\nEmpty Stack!!\n");
			    }
			    if(n!=0 || m!=0)
			    printf("\n popped element is:%d\n",data);
			    break;
			case 3:
				list(&stack1);
				printf("\n\n");
				list(&stack2);
				break;
			case 4:
				freeIntegerStack(&stack1);
				freeIntegerStack(&stack2);
		}
	}while(ch!=5);
}
