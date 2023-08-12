#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Student{

	char *name;
	int roll;
	char telephone[11];
	char *address;
}Student;
typedef struct SReg
{
int counter;
Student **stdArrPtr;
}SReg;

Student *createStudentRecord()
{
	Student *s;
	s=(Student *)malloc(sizeof(Student));
	char tempName[50],tempAdd[50];
	if(s==NULL)
	{
		printf("\n error");
		return;
	}
	else
	{
	getchar();
	
	printf("\n Enter name: ");
	fgets(tempName,49,stdin);
	s->name=(char*)malloc(strlen(tempName)+1);
	strcpy(s->name,tempName);
	
	printf("\n Enter roll: ");
	scanf("%d",&s->roll);
	
	printf("\n Enter phone_no: ");
	scanf("%s",s->telephone);
	getchar();
	
	printf("\n Enter address: ");
	fgets(tempAdd,49,stdin);
	s->address=(char*)malloc(strlen(tempAdd)+1);
	strcpy(s->address,tempAdd);
	
	return s;
}
}
int addRecord(Student *s,SReg *sr)
{
	if(sr->stdArrPtr==NULL)
	{
		printf("\n Error");
		return 0;
	}
	int i;
	for(i=0;i<sr->counter;i++)
	{
	if(sr->stdArrPtr[i]->roll==s->roll)
	{
		return 0;
	}}
	sr->stdArrPtr[sr->counter]=s;
    sr->counter++;
	return 1;
}

void showRecord(SReg sr)
{
	int i;
	for(i=0;i<sr.counter;i++)
	{
	printf("\nName: %s",sr.stdArrPtr[i]->name);
	printf("\nRoll no:%d",sr.stdArrPtr[i]->roll);
	printf("\nPhone no:%s",sr.stdArrPtr[i]->telephone);
	printf("\nAddress:%s",sr.stdArrPtr[i]->address);
	}
}

Student *getStudent(SReg *sr,int r)
{
	int i;
	for(i=0;i<sr->counter;i++)
	{
		if(sr->stdArrPtr[i]->roll==r)
		return sr->stdArrPtr[i];
	}
	return NULL;
}

int deleteStudent(SReg *sr,int r)
{
	int i,j;
	for(i=0;i<sr->counter;i++)
	{
		if(sr->stdArrPtr[i]->roll==r)
		{
			for(j=i+1;j<sr->counter;j++)
			{
				sr->stdArrPtr[j-1]=sr->stdArrPtr[j];
			}
			sr->counter--;
			return 1;
		}
	}
	return 0;
}

int getCount(SReg *sr)
{
	return sr->counter;
}

void sortStudents(SReg *sr)
{
	int i,j;
	Student *temp;
	for(i=0;i<sr->counter;i++)
	{
		for(j=i+1;j<sr->counter;j++)
		{
		   if(strcmp(sr->stdArrPtr[i]->name,sr->stdArrPtr[j]->name)>0)
		   {
		   	temp=sr->stdArrPtr[i]->name;
		   	sr->stdArrPtr[i]->name=sr->stdArrPtr[j]->name;
		   	sr->stdArrPtr[j]->name=temp;
		   }
	    }
	}
}

int modifyRecord(SReg *sr,Student *s)
{
	int i;
	for(i=0;i<sr->counter;i++)
	{
	    if(sr->stdArrPtr[i]->roll==s->roll)
		{
			sr->stdArrPtr[i]=s;
		}	
		return 1;
	}
	return 0;
}

void exportRecordInFile(SReg *sr,char fname[30])
{
	FILE *fp;
	int i;
	fp=fopen(fname,"w");
	for(i=0;i<sr->counter;i++)
	{
		printf("\n name=%s roll=%d phone_no=%s address=%s",sr->stdArrPtr[i]->name,sr->stdArrPtr[i]->roll,sr->stdArrPtr[i]->telephone,sr->stdArrPtr[i]->address);
	    fwrite(&(sr->stdArrPtr[i]),sizeof(sr->stdArrPtr[i]),1,fp);
	}
	fclose(fp);
}

void displayRecord(char fname[30])
{
  	Student *s;
	s=(Student *)malloc(sizeof(Student));
	s->name=(char *)malloc(40*sizeof(char));
	s->address=(char *)malloc(40*sizeof(char));
	
  	FILE *fp;
  	fp=fopen(fname,"r");
  	if(fp==NULL)
  	{
  		printf("\n file doesn't exist ");
  		return;
	  }
	while(fread(&s,sizeof(s),1,fp)==1)
	{
		printf("\n name: %s Roll no:%d phone no:%s address: %s",s->name,s->roll,s->telephone,s->address);
	}
	fclose(fp);
}

void createStudentRecordFromFile(char fname[30],SReg *sr)
{
	Student *s;
	s=(Student *)malloc(sizeof(Student));
	s->name=(char *)malloc(40*sizeof(char));
	s->address=(char *)malloc(40*sizeof(char));
	FILE *fp;
  	fp=fopen(fname,"r");
  	if(fp==NULL)
  	{
  		printf("\n file doesn't exist ");
  		return;
	  }
	while(fread(&s,sizeof(s),1,fp)==1)
	{
		/*printf("\nName:%s",s->name);
		printf("\nRoll:%d",s->roll);
		printf("\nPhone:%s",s->telephone);
		printf("\nAddress:%s",s->address);*/
		sr->stdArrPtr[sr->counter++]=s;
	}
	fclose(fp);
}
void freePointer(Student *s,SReg *sr)
{
	free(s->name);
	free(s->address);
	free(sr->stdArrPtr);
	free(s);
	s=NULL;
	sr->stdArrPtr=NULL;
}
main()
{
	Student *s,*s1;
	SReg sr;
	char fname[30];
	sr.counter=0;
	int size,n,ch,r;
	
	printf("\n Enter no of students: ");
	scanf("%d",&size);
	sr.stdArrPtr=(Student**)malloc(size*sizeof(Student*));
	
	do
	{
	printf("\n Enter \n 1.Add student record \n 2.Show record \n 3.get a particular student by entering roll no \n 4.delete a record \n 5.count no of records \n 6.sorting as per name\n 7.modify student record \n 8.export record in file \n 9.display the recorded file \n 10.create student record from file \n 11.free memory \n 12.exit\n");
	printf("\n enter choice: ");
	scanf("%d",&ch);
	
	switch(ch)
	{
	case 1:
	s=createStudentRecord();
    n=addRecord(s,&sr);
    if(n==1)
    printf("\n Already Exist");
    else
    printf("\n successfully added");
	break;
	
	case 2:
	showRecord(sr);
	break;
	
	case 3:
	s1=(Student*)malloc(sizeof(Student));
	printf("\n Enter the roll no whom u want to get: ");
	scanf("%d",&r);
	s1=getStudent(&sr,r);
	if(s1==NULL)
	{
		printf("\n Not found");
	}
	else{
	printf("\n Name: %s",s1->name);
	printf("\n Roll: %d",s1->roll);
	printf("\n Phone no: %s",s1->telephone);
	printf("\n Address: %s",s1->address);
    }
	break;
	
	case 4:
	printf("\n Enter the roll no whom u want to delete: ");
	scanf("%d",&r);
	n=deleteStudent(&sr,r);
	if(n==1)
	{
		printf("\n Deleted successfully");
	}
	else
	{
		printf("\n Not found");
	}
	break;
	
	case 5:
	n=getCount(&sr);
	printf("\n total no. of students: %d",n);
	break;
	
	case 6:
	sortStudents(&sr);
	showRecord(sr);
	break;
	
	case 7:
	s=(Student*)malloc(sizeof(Student));
	createStudentRecord(s);	
	n=modifyRecord(&sr,s);
	if(n==1)
	{
		printf("\n Modified successfully");
	}
	else
	{
		printf("\n Not found");
	}
	break;
	
	case 8:
	printf("\n enter the file name: ");
	scanf("%s",fname);
	exportRecordInFile(&sr,fname);
	break;
	
	case 9:
	printf("\n enter the file name: ");
	scanf("%s",fname);
	displayRecord(fname);
	break;
	
	case 10:
	printf("\n enter the file name: ");
	scanf("%s",fname);
	createStudentRecordFromFile(fname,&sr);
	break;
	
	case 11:
	freePointer(&sr,s);
	break;
}
}while(ch!=12);
}

