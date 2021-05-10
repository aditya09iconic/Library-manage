#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

int booksearch(char nam[]);
int bsee_record();
int search();
int binsert_record();
int insert_record();
int student_section();

int ma_section();
char st_name[20];
char st_id[20];
char book_id[20];
char book_name[20];
char name[20];

// To see Book
int bsee_record()
{
	FILE *fp;
	int found=1;
	fp=fopen("G://project-demo.txt", "r");
	while(fscanf(fp,"%s %s\n", book_name, book_id )!= EOF)
	{
		found=0;
		printf("..................\n");
		printf("|  %s   |   %d   | \n", book_name, book_id);
		printf("....................\n");
	}
	if(found != 0)
	{
		printf(" Record are  empty\n");
	}
	fclose(fp);
}

// To search  book record
int booksearch(char nam[])
{
	FILE *fp;
	int found=1, res;
	fp=fopen("G://project-demo.txt", "r");
	while(fscanf(fp,"%s %d\n", book_name, book_id )!= EOF)
	{
		res=strcmp(book_name, nam);
		if(res==0)
		{
			found=0;
			printf(".................................\n");
			printf("|  %s   |   %d   | \n", book_name, book_id);
		      printf("....................\n");
			
		}
		if(found !=0)
		{
			printf(" No books are found\n");
		}
		
	}
	fclose(fp);
}

// Inset  Record of Book :
int binsert_record()
{
	FILE *fp;
	printf(" Enter book name (space not allowed)\n");
	scanf(" %s", &book_name);
	fp=fopen("G://project-demo.txt", "a");
	fprintf(fp, "%s %s \n", book_name, book_id);
	printf(" Record added \n");
	fclose(fp);
}

// To  delete the book Record

int bdelete_record()
{
	FILE *fp, *fp1;
	int res, found4=1;
	
	printf(" Enter book name\n");
	scanf("%s", &name);
	fp=fopen ("G://project-demo.txt", "r");
	fp1=fopen("G://temp.txt", "a");
	while(fscanf(fp, "%s %s\n", book_name, book_id)!= EOF)
	{
		res=strcmp(book_name, name);
		if(res==0)
		{
			found4=0;
			printf("name=%s\n ID=%s\n", book_name, book_id);
			printf("/n Is Deleted");
		}
		else
		{
			fprintf(fp1, " %s %s\n", book_name, book_id);
			
		}
		if(found4 !=0)
		printf("no found");
		fclose(fp);
		fclose(fp1);
		
		fp=fopen("G://project-demo.txt", "w");
		fclose(fp);
		
		fp=fopen("G://project-demo.txt", "a");
		fp1=fopen("G://temp1.txt", "r");
		
		while(fscanf(fp1, "%s %s\n", book_name, book_id)!= EOF)
		{
			fprintf(fp, " %s %s\n", book_name, book_id);
		}
	}
	
	fclose(fp);
	fclose(fp1);
	fp1=fopen("G://temp1.txt", "w");
	fclose(fp1);
}

// Boook  Section

int book_section()
{
	int a;
	char c, name[20];
	do
	{
		
		printf("\n");
		printf("...........................................\n");
		printf(" |  Boook section  |\n");
		printf("...........................................\n\n");
		
		printf("\t\t\tPress <1>  to see record\n");
		printf("\t\t\tPress <2>  to insert record\n");
		printf("\t\t\tPress <3>  to delete record\n");
		printf("\t\t\tPress <4>  to search book\n");
		printf("\t\t\tPress <5>  Back to menu\n");
		
		scanf("%d", &a);
		switch(a)
		{
			case 1:
				bsee_record();
				break;
				
		     case 2:
			    binsert_record();
				break;
			
			case 3:
			    bdelete_record();
				break;
				
			case 4:
			    printf(" Enter a book name\n");
				scanf("%s", &name);
				booksearch(name);
				break;
				
		    case 5:
			    ma_section();
			    break;
			    
			    default:
			    	printf ( " Enter correct value\n");
										
		}
		fflush(stdin);
		printf("Press <a> to continue with book section\n\nOr  other key to main menu\n");
		scanf("%c", &c);
		
		
	}
	while(c=='a');
	
}

//To see student Record
int see_record()
{
	FILE *fp;
	int found=1;
	fp=fopen("G://student_section.txt","r");
	while(fscanf(fp, "%s %s\n", st_name, st_id)!=EOF)
	{
		found=0;
		printf("........\n");
		printf("| %s  |  %s   |\n", st_name, st_id );
		printf("..............\n");
	}
	if(found!=0)
	{
		printf("Records  are  empty\n");
	}
	fclose(fp);
}

// To search  student
int search (char nam[])
{
	FILE *fp;
	int found=1 , res;
	fp=fopen("G://student_section.txt", "r");
	while(fscanf(fp ,"%s %s\n",st_name,st_id)!=EOF)
	{
		res=strcmp(st_name, nam);
		if(res=0)
		{
			found=0;
			printf(".................\n");
			printf("|   %s    |   %s    |\n", st_name,st_id);
			printf("....................\n");
			
			if(found!=0)
			{
				printf(" Records not found\n");
			}
			
		}
		
	}
	fclose(fp);
}

//Insert record of student
int insert_record()
{
	FILE *fp;
	char ch;
	int found, res;
	char st_id1[20];
	
	fp=fopen("G:// Student_section.txt","a");
	printf(" Enter student name(space not allowed)\n");
	scanf("%s",&st_name);
	printf(" Enter student ID\n");
	scanf("%s",&st_id);
	
	fprintf(fp, "%s %s\n",st_name, st_id);
	printf(" Record added\n");
	fclose(fp);
}

// To delete the student record

int delete_record(char na[])
{
	int res, found4=1;
	FILE *fp, *fp1;
	fp=fopen("G:// Student_record.txt ", "r");
	fp1=fopen("G://temp.txt", "a");
	while(fscanf(fp, "%s %s\n", st_name, st_id)!=EOF)
	{
		res=strcmp(st_name, na);
		if(res==0)
		{
			found4=0;
			printf("name=%s\nID=%s\n",st_name, st_id);
			printf("/n Is Deleted");
		}
		else
		{
			fprintf(fp,"%s %s\n",st_name, st_id);
		}
		
		if(found4!=0)
		printf(" Not found");
		fclose(fp);
		fclose(fp1);
		
		fp=fopen("G://student_section.txt","w");
		fclose(fp);
		
		fp=fopen("G://student_section.txt", "a");
		fp1=fopen("G://temp.txt","r");
		
		while(fscanf(fp, "%s %s\n",st_name, st_id)!=EOF)
		{
			fprintf(fp,"%s %s\n",st_name,st_id);
		}
	}
	fclose(fp);
	fclose(fp1);
	fp1=fopen("G:// temp.txt","w");
	fclose(fp1);
}

//Student section
int student_section()
{
	int a;
	char c, nam[20];
	do
	{
		char name[20];
		
		printf("\n");
		printf(".........................\n");
		printf("| student  section  |  \n");
		printf("....................\n\n");
		
		printf("\t\t\tPress <1> to see record\n");
		printf("\t\t\tPress <2>to insert record\n");
		printf("\t\t\tPress <3>to delete record\n");
		printf("\t\t\tPress <4>to to search student \n");
		printf("\t\t\tPress <5>to Back to menu\n");
		
		scanf("%d", &a);
		switch(a)
		{
			case 1:
				see_record();
				break;
				
		    case 2:
			    insert_record();
				break;
				
		    case 3:
			     printf("Enter a student name\n");
				 scanf("%s", &nam);
				 delete_record(nam);
				 break;
				 
			case 4:
			     printf(" Enter name of student\n");
				 scanf("%s", &name);
				 search(name);
				 break;
				 
			case 5:
			     ma_section();
				 break;
				 
		    default:
			   printf(" Enter correct  value\n");		 	 	 				
		}
		fflush(stdin);
		printf(" Press <a> to continue with student  section\n");
		scanf("%c", &c);
	}
	while(c=='a');
}

int ma_section()
{
	int n;
	char ch;
	do
	{
		printf("\t\t\t.....................................\n");
		printf("\t\t\t |     LIBRARY Managemet        |\n");
		printf("\t\t\t...................................\n");
		printf("\n Press<1> for  student  section \n  Press <2> For Book section \n Press<3> to  exit\n");
		scanf("%d", &n);
		switch(n)
		{
			case 1:
				student_section();
				break;
				
		     case 2:
			    book_section();
				break;
				
			
				
			case 3:
			    exit(0);
				
				default:
				
				printf("  Please Enter  a correct  choice\n");				
		}
		printf(" For main menu press any key\n");
		scanf("%c",&ch);
	}
	while(ch!='-');
}

int main()
{
	printf("\t\t\t......................\n");
	printf("\t\t\t |     LIbrary  Management    |\n");
	printf("\t\t\t..............................\n");
	ma_section();
	getch();
}
		
	
	

