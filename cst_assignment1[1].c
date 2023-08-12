#include<stdio.h>
#include<stdlib.h>
#define MAX_STUDENTS 10
typedef struct Student{

	char name[20];
	int roll;
	char telephone[11];
	char address[20];
}Student;
typedef struct SReg
{
int counter;
Student std[MAX_STUDENTS];
}SReg;

int Add(SReg *sr,Student s)
{
	int i;

	for(i=0;i<sr->counter;i++)
	{
		if(sr->std[i].roll==s.roll)
		{
			return 0;
		}
	}
	sr->std[sr->counter++]=s;
	return 1;
}
void show_record(SReg sr)
{
	int i;
	for(i=0;i<sr.counter;i++)
	{
		printf("\n %s",sr.std[i].name);
		printf("\n %d",sr.std[i].roll);
		printf("\n %s",sr.std[i].telephone);
		printf("\n %s",sr.std[i].address);
		printf("\n");
	}
	return;
}
int del(SReg *sr,int r)
{
	int i,j;
	if(sr->counter==0)
	{
		printf("\n no data available.");
		return 0;
	}
	for(i=0;i<sr->counter;i++)
	{
		if(sr->std[i].roll==r)
		{
			for(j=i+1;j<sr->counter;j++)
			{
				sr->std[j-1]=sr->std[j];
			}
			sr->counter--;
			return 1;
		}
	}
	return 0;
}

Student get(SReg *sr,int r)
{
	int i;
	for(i=0;i<sr->counter;i++)
	{
		if(sr->std[i].roll==r)
		return sr->std[i];
	}
	Student def={"",0,"",""};
	return def;
}
int modify(SReg *sr, Student s)
{
	int i;
	for(i=0;i<sr->counter;i++)
	{
		if(sr->std[i].roll==s.roll)
		{
			sr->std[i]=s;
			return 1;
		}
	}
	return 0;
}
void sort(SReg *sr)
{
	Student temp;
	int i,j;
	for(i=0;i<sr->counter;i++)
	{
		for(j=i+1;j<sr->counter;j++)
		{
			if(strcmp(sr->std[i].name,sr->std[j].name)>0)
			{
				temp=sr->std[i];
				sr->std[i]=sr->std[j];
				sr->std[j]=temp;
			}
		}
	}
	return;
}

int get_count(SReg *sr)
{
	return sr->counter;
}

void exprt(SReg *sr,char fname[30])
{
	FILE *fp;
	int i;
	fp=fopen(fname,"w");
	for(i=0;i<sr->counter;i++)
    {
	  	   printf("\n %s %d %s %s",sr->std[i].name,sr->std[i].roll,sr->std[i].telephone,sr->std[i].address);
	       fwrite(&sr->std[i],sizeof(sr->std[i]),1,fp);
    }

	fclose(fp);
}

void fdisp(char fname[30])
{
    Student t;
    FILE *fp;
    fp=fopen(fname,"r");
	while(fread(&t,sizeof(t),1,fp)==1)
    {
			printf("\n %s %d %s %s",t.name,t.roll,t.telephone,t.address);
    }
	fclose(fp);
}

void load(SReg *sr,char fname[30])
{
	Student t;
	FILE *fp;
    fp=fopen(fname,"r");
	while(fread(&t,sizeof(t),1,fp)==1)
    {
			sr->std[sr->counter++]=t;
    }
	fclose(fp);
}

main()
{
	SReg sr;
 sr.counter=0;
 int ch,r,n;
 Student s;
 char fname[30];
 do{
 	printf("\n 1.add \n 2.show record \n 3.delete record \n 4.get_student \n 5.modify record \n 6.sorting in alphabetical order \n 7.total no of students \n 8.export records \n 9.file display \n 10.load \n 11.exit \n ");
 	printf("\n enter ur choice: ");
 	scanf("%d",&ch);
 	switch(ch)
 	{
 		case 1:
 			printf("\n enter student details which u want to add:\n");
 			printf("enter name, roll, phone_no, address\n");
 			scanf("%s %d %s %s",s.name,&s.roll,s.telephone,s.address);
 			n=Add(&sr,s);
 			if(n==1)
 			{
 				printf("\n student record has been added successfully.");
			 }
			 else
			 {
			 	printf("\n unsuccessfull");
			 }
 			break;

 		case 2:
 			show_record(sr);
 			break;

 		case 3:
 			printf("\n enter roll no to delete her/his record: ");
 			scanf("%d",&r);
 			n=del(&sr,r);
 			if(n==1)
 			{
 				printf("\n record has been deleted successfully.");
			 }
			 else
			 {
			 	printf("\n no such student having %d roll no. is found!",r);
			 }
 			show_record(sr);
 			break;

 		case 4:
 			printf("\n enter roll no which u want to get: ");
 			scanf("%d",&r);
 			s=get(&sr,r);
 			printf("\n name \t roll no \t phone_no \t address\n");
 			printf("\n %s \t %ld \t %s \t %s\n",s.name,s.roll,s.telephone,s.address);
 			break;

 		case 5:
 			printf("\n enter student details which u want to modify:\n");
 			printf("\n enter name, roll, phone_no, address\n");
 			scanf("%s %ld %s %s",s.name,&s.roll,s.telephone,s.address);
 			n=modify(&sr,s);
 			if(n==1)
 			{
 				printf("\n modification successfull");
			 }
			 else
			 {
			 	printf("\n modification unsuccessfull");
			 }
 			printf("%d",n);
 			show_record(sr);
 			break;

 		case 6:
 			sort(&sr);
 			break;

 		case 7:
 			n=get_count(&sr);
 			printf("\n total no of records: %d",n);
 			break;

 		case 8:
 			printf("\n enter the file name in which u want to export the reports: ");
 			scanf("%s",fname);
 			exprt(&sr,fname);
 			break;
 			
 		case 9:
 			printf("\n enter the file name: ");
 			scanf("%s",fname);
 			fdisp(fname);
 			break;
 			
 		case 10:
 			printf("\n enter the file name: ");
 			scanf("%s",fname);
 			load(&sr,fname);
 			break;

 		default:
 			printf("\n wrong choice");
 			break;
	 }
 }while(ch!=11);

}
