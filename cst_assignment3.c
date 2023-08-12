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
		printf("\n stack is full.No Entry!!\n");
		return 0;
	}
	pStack->pstorage[++pStack->top]=data;
	return 1;
}
int popStack(myStack *pStack,int *data)
{
	if(pStack->top==-1)
	{
		printf("\n stack is empty.Delete not possible!!\n");
		return 0;
	}
	*data=pStack->pstorage[pStack->top];
	pStack->top--;
	return 1;
}
void freeIntegerStack(myStack *pStack)
{
	free(pStack->pstorage);
	pStack->pstorage=NULL;
	return;
}
int isStackFull(myStack *pStack,int max_size)
{
	if(pStack->top==max_size-1)
	return 1;
	else
	return 0;
}
int isStackEmpty(myStack *pStack)
{
	if(pStack->top==-1)
	return 1;
	else
	return 0;
}
void list(myStack *pStack)
{
	printf("\n List of all elements:\n");
	int i;
	if(pStack->top!=-1)
	{
	for(i=0;i<=pStack->top;i++)
	{
		printf("\n%d",pStack->pstorage[i]);
	}
	return;
}
printf("\n no element");
return;
}

main()
{
	int size,ch,elem,dig,n;
	printf("\n enter size of the stack: ");
	scanf("%d",&size);
	myStack stack1;
	createIntegerStack(&stack1,size);
	do{
		printf("\n 1.push 2.pop 3.free 4.is stack full? 5.is stack empty? 6.list 7.exit");
		printf("\n enter choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\n enter data: ");
				scanf("%d",&elem);
				pushIntegerInStack(&stack1,elem,size);
				list(&stack1);
				break;
			case 2:
				popStack(&stack1,&dig);
				printf("\n popped element is: %d\n",dig);
				list(&stack1);
				break;
			case 3:
				freeIntegerStack(&stack1);
				break;
				
			case 4:
				n=isStackFull(&stack1,size);
				if(n==1)
				printf("\n stack is full");
				else
				printf("\n stack is not full");
				break;
			case 5:
				n=isStackEmpty(&stack1);
				if(n==1)
				printf("\n stack is empty");
				else
				printf("\n stack is not empty");
				break;
			case 6:
				list(&stack1);
				break;
			
		}
	}while(ch!=7);
}
