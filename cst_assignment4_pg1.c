#include<stdio.h>
#include<stdlib.h>
struct queue
{
	int front;
	int rear;
	int *pQueue;
	int queueSize;
};
typedef struct queue queue;

int createIntegerQueue(queue *q)
{
	q->front=-1;
	q->rear=-1;
	q->pQueue=(int *)malloc(q->queueSize*sizeof(char));
	if(q->pQueue==NULL)
	{
		return 0;
	}
	return 1;
}

int enqueueInteger(queue *q,int d)
{
	if(q->front==(q->rear+1)%q->queueSize)
	{
		printf("\n queue is full.No Entry!!");
		return 0;
	}
	if(q->front==-1)
	{
		q->front=0;
	}
	q->rear=(q->rear+1)%q->queueSize;
	q->pQueue[q->rear]=d;
	return 1;
}

int dequeueInteger(queue *q,int *d)
{
	if(q->front==-1)
	{
		printf("\n queue is empty ");
		return 0;
	}
	*d=q->pQueue[q->front];
	if(q->front==q->rear)
	{
		q->front=-1;
		q->rear=-1;
	}
	else
	{
		q->front=(q->front+1)%q->queueSize;
	}
	return 1;
}

void freeIntegerQueue(queue *q)
{
	free(q->pQueue);
	q->pQueue=NULL;
}

int isIntegerQueueFull(queue *q)
{
	if(q->front==(q->rear+1)%q->queueSize)
	{
		return 1;
	}
	return 0;
}

int isIntegerQueueEmpty(queue *q)
{
	if(q->front==-1)
	{
		return 1;
	}
	return 0;
}

void list(queue *q)
{
	int i;
	if(q->front!=-1)
	{
	for(i=q->front;i!=q->rear;i=(i+1)%q->queueSize)
	{
		printf("%5d",q->pQueue[i]);
	}
	printf("%5d",q->pQueue[i]);
}}
main()
{
	queue queue1;
	int ch,dig,n;
	printf("\n Enter the size of queue: ");
	scanf("%d",&queue1.queueSize);
	n=createIntegerQueue(&queue1);
	if(n==1)
	printf("\n created successfully");
	do{
		printf("\n Enter \n 1.Enqueue \n 2.Dequeue \n 3.List \n 4.Is queue full? \n 5.Is queue empty? \n 6.Free memory \n 7.Exit");
		printf("\n Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\n Enter Element: ");
				scanf("%d",&dig);
				n=enqueueInteger(&queue1,dig);
				if(n==1)
				printf("\n Insertion Successfull");
				else
				printf("\n Not Possible");
				break;
		   
		    case 2:
		    	n=dequeueInteger(&queue1,&dig);
		    	if(n==1)
		    	{
		    	printf("\n popped element: %d",dig);
		        printf("\n successfully deleted");
				}
		    	else
		        printf("\n Deletion not possible");
				break;
				
			case 3:
				list(&queue1);
				break;
				
			case 4:
				n=isIntegerQueueFull(&queue1);
				if(n==1)
				printf("\n Queue is Full");
				else
				printf("\n Queue is not Full");
				break;
				
			case 5:
				n=isIntegerQueueEmpty(&queue1);
				if(n==1)
				printf("\n Queue is Empty");
				else
				printf("\n Queue is not Empty");
				break;
				
			case 6:
				freeIntegerQueue(&queue1);
				break;
		}
	}while(ch!=7);
}
