#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct myStack
{
	char *pstorage;
	int max_size;
	int top;
}myStack;

myStack *createIntegerStack(myStack *pStack,int size)
{
	pStack->top=-1;
	pStack->pstorage=(char*)malloc(size*sizeof(char));
	if(pStack->pstorage==NULL)
	{
		printf("\n Error!!");
		return NULL;
	}
	return pStack;
}
int pushIntegerInStack(myStack *pStack,char data,int max_size)
{
	if(pStack->top==max_size-1)
	{
		//printf("\n stack is full.No Entry!!\n");
		return 0;
	}
	pStack->pstorage[++pStack->top]=data;
	return 1;
}
int popStack(myStack *pStack,char *data)
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
void freeIntegerStack(myStack *pStack)
{
	free(pStack->pstorage);
	pStack->pstorage=NULL;
	return;
}
main()
{
	myStack stack;
	char str[100],symb,elem;
	int size,i,n,valid=1;
	printf("\n Enter Mathematical Expression: ");
	fgets(str,99,stdin);
	size=strlen(str);
	createIntegerStack(&stack,size);
	for(i=0;i<size;i++)
	{
		symb=str[i];
		if(symb=='(' || symb=='{' || symb=='[')
		  pushIntegerInStack(&stack,symb,size);
		else if(symb==')' || symb=='}' || symb==']')
            {
            	n=popStack(&stack,&elem);
            	if(n==0){
            	  valid=0;
            	  break;
		         }	
				if((symb==')' && elem!='(')|| (symb=='}' && elem!='{') ||( symb=='[' && elem!=']'))
				{
					valid=0;
					break;
			    }
			}
	}
	if(valid==1 && (popStack(&stack,&elem)==0))
	printf("\n Correct");
	else
	printf("\n Incorrect");
	freeIntegerStack(&stack);
	}
