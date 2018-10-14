   /*Title : Creating Student Database Using Singly linked list */


#include<stdio.h>
#include<conio.h>

struct Student
{
	int roll;
	char name[30];
	float marks;
	struct Student *next; //Self referential pointer...

};

typedef struct Student Node;


void Linkfloat()
{
	float a=0,*b; //To create link of float to some compiler ...
	b=&a;
	a=*b;

}

void Display(Node *head)
{

	Node *p;
	int i;

	if(head==NULL)
	{
		printf("\nThere are No Records in Database.");

	}

	else
	{
		p=head;
		for(i=0;i<1;i++)
		{

			printf("\n");

		}
		
		printf("\nUpdated Student Database");
		for(i=0;i<1;i++)
		{

			printf("\n");

		}
		printf("");
		printf("\nRoll No.	Name			Marks");
		for(i=0;i<1;i++)
		{

			printf("\n");

		}
		printf("");
		while(p!=NULL)
		{

			printf("\n%d		%s			%0.2f",p->roll,p->name,p->marks);
			printf("");
			for(i=0;i<1;i++)
			{

				printf("\n");

			}	
			printf("");

			flushall();
	
			
			p=p->next; //Go to next node...
		}

	}

}

void DReverse(Node * head)
{
	Node *p;
	int i;
	if(head==NULL)
	{
		printf("\nThere are No Records in Database.");

	}

	else
	{
		p=head;

		if(p->next!=NULL)
		{
		
			DReverse(p->next); //Recursive call...

		}

		
		printf("\n%d		%s			%0.2f",p->roll,p->name,p->marks);
		printf("");
		for(i=0;i<1;i++)
			{

				printf("\n");

			}
		printf("");

		flushall();

		printf("");
	}
}

Node* Create(Node *head)
{
	int n,i;
	Node *nn,*p;

	printf("\nHow Many Entries to Create Database? : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		if(head==NULL)
		{

			nn=(Node*)malloc(sizeof(Node));	//Creating first node...
			printf("\nEnter Roll No. , Name & Marks : ");
			scanf("%d",&(nn->roll));
			flushall();

			gets(nn->name);

			scanf("%f",&(nn->marks));

			nn->next=NULL;	//Set next to NULL...

			head=nn;

		}
		else
		{
			p=nn=head;

			while(nn->next!=NULL)
			{
				nn=nn->next;
			}
			nn->next=(Node*)malloc(sizeof(Node));	//Creating further nodes...
			nn=nn->next;

			printf("\nEnter Roll No. , Name & Marks : ");
			scanf("%d",&(nn->roll));
			flushall();

			gets(nn->name);
			scanf("%f",&(nn->marks));

			nn->next=NULL;     
			nn=p;
		}

	}

		return head;

}

Node* Insert(Node *head)
{
	int ch,r;
	char ans;
	Node *p,*nn,*q;
	do
	{

		printf("\nWhere Do You Want to Enter New Entry? : ");

		printf("\n1. At the Begining\n2. In the Middle\n3. At the End");
		printf("\nEnter Your Choice : ");
		scanf("%d",&ch);	
		switch(ch)
		{
		case 1:		 
			/* Insert at Begining */
			p=head;

			nn=(Node*)malloc(sizeof(Node));

			printf("\nEnter Roll No., Name & Marks");
			scanf("%d",&(nn->roll));
			flushall();

			gets(nn->name);
			scanf("%f",&(nn->marks));

			nn->next=NULL;
		    nn->next=p;
		    head=nn;  //set first node as head...

			printf("\nEntry is Created Successfully.");
			Display(head);

		    break;

			case 2:
				/* Insert at Middle */

				if(head==NULL)
				{
					
					printf("\nYet Database is Not Created.");
					printf("\nDatabase is Empty.");
					printf("\nFirst Create Database.");


				}

				else
				{

					printf("\nAfter Which Roll No. You Want to Insert New Data? : ");
					scanf("%d",&r);

					p=head;

					while(p->roll!=r && p->next!=NULL)
					{
						p=p->next;		//Go upto that Roll No....

					}

					if(p->roll!=r)
					{
						printf("\nThere is No Such Entry.");

					}

					else
					{

						nn=(Node*)malloc(sizeof(Node));

						printf("\nEnter Roll No. , Name & Marks : ");
						scanf("%d",&(nn->roll));
						flushall();
						gets(nn->name);

						scanf("%f",&(nn->marks));
						nn->next=NULL;						
						q=p->next;
						p->next=nn;
						nn->next=q;

						printf("\nEntry is Created Successfully.");
						Display(head);
					}
				}

			break;

			case 3:
		 	/*  Insert at end */
				if(head==NULL)
				{
					
					printf("\nYet Database is Not Created.");
					printf("\nDatabase is Empty.");
					printf("\nFirst Create Database.");


				}

				else
				{

					p=head;

					nn=(Node*)malloc(sizeof(Node));

					printf("\nEnter Roll No. , Name & Marks :  : ");
					scanf("%d",&(nn->roll));
					flushall();
					gets(nn->name);
					scanf("%f",&(nn->marks));

					nn->next=NULL;
					while(p->next!=NULL)
					{
						p=p->next;		//Go upto last node...

					}

					p->next=nn;

					printf("\nEntry is Created Successfully.");
					Display(head);
				}

			break;
		}
		printf("\nDo You Want to Insert More Data (Y/N)? : ");
		flushall();
		scanf("%c",&ans);

	 }while(ans=='y' || ans=='Y');

	 return head;
}


Node* Delete(Node* head)
{
	Node *p,*q,*r;
	char ans;
	int ch,n;

	do{
		printf("\nWhich Entry You Want to Delete? : ");
		printf("\n1. First\n2. Middle\n3. End");
		printf("\nEnter Your Choice : ");
		scanf("%d",&ch);

				if(head==NULL)
				{
					
					printf("\nYet Database is Not Created.");
					printf("\nDatabase is Empty.");
					printf("\nFirst Create Database.");


				}

				else
				{
					switch(ch)
					{
					case 1:

							/*Delete first node */
						p=head;

						head=head->next;	//Set second node as head...
						free(p);

						printf("\nFirst Entry is Deleted.");

						Display(head);

					break;

					case 2:
							/*Delete middle Node*/

						p=head;
						printf("\nEnter Roll No. Which You Want to Delete : ");
						scanf("%d",&n);

						while((p->next)->roll!=n && p->next->next!=NULL)
						{
							p=p->next;		//Go upto -1 node which you want to delete...

						}

						if(p->next->next==NULL)
						{
							printf("\nThere is No Such Entry.");

						}

						else
						{			
							q=p->next;
							r=q->next;
							p->next=r;
							free(q);			//Delete that node...

							printf("\nEntry is Deleted.");
							Display(head);
						}
						break;

					case 3:
							/*	Delete last node */
						p=head;
						while(p->next->next!=NULL)
						{
							p=p->next;  //Go upto -1 node which you want to delete...

						}
							q=p->next;
							free(q);		//Delete last node...

							p->next=NULL;
							printf("\nLast Entry is Deleted.");
							Display(head);			

						break;

					}

				}

			printf("\nDo You Want to Delete More Data (Y/N)? : ");
			flushall();
			scanf("%c",&ans);

		}while(ans=='y'|| ans=='Y');


	return head;

}

Search(Node *head)
{

	Node *p;
	int r,cnt=0;
	if(head==NULL)
	{
		printf("\nYet Database is Not Created.");
		printf("\nDatabase is Empty.");
		printf("\nFirst Create Database");
	}

	else
	{
		p=head;
		printf("\nEnter Roll No. Which You Want to Search : ");
		scanf("%d",&r);

		while(p->roll!=r && p->next!=NULL)		//Search for Roll No...
		{
			p=p->next;
			cnt++;
		}

	if(p->roll!=r)
		printf("\nThere is No Such Entry.");
	else
	{
		printf("\nRoll No. %d is at %d th Position.",r,(cnt+1));
		printf("\nRoll No.	Name		Marks");
		printf("\n%d		%s			%0.2f",p->roll,p->name,p->marks);
	}
	}
return 0;
}

Modify(Node * head)
{
	Node *p;
	int r;

	if(head==NULL)
	{
		printf("\nYet Database is Not Created.");
		printf("\nDatabase is Empty.");
		printf("\nFirst Create Database.");

	}
	else
	{
		p=head;
		printf("\nEnter the Roll No. Whose Data You Want to Modify : ");
		scanf("%d",&r);

		while(p->roll!=r && p->next!=NULL)
		{
	
			p=p->next;
		
		}

		if(p->roll!=r)
		{
			printf("\nThre is No Such Record in Database.");

		}
		else
		{

			printf("\nEntered Roll No's Data is : ");
			printf("\nRoll No.	Name	Marks");			//Displaying Data who is going to modify....
			printf("\n%d		%s		%f",p->roll,p->name,p->marks);

			printf("\nEnter New roll no ,New name & Marks for this entry:");
			scanf("%d",&p->roll);
			flushall();
			gets(p->name);					//Enter new data...

			scanf("%f",&(p->marks));

			printf("\nEntered New Data is:");
			printf("\nRoll No.	Name	Marks");
			printf("\n%d		%s		%f",p->roll,p->name,p->marks);
			Display(head);

		}

	}
return 0;
}

Count(Node *head)
{
	Node *p;
	int cnt=0;

	if(head==NULL)
	{
		printf("\nYet Database is Not Created.");
		printf("\nDatabase is Empty.");
		printf("\nFirst Create Database.");
		printf("\nThere are 0 Records in Database.");
	}

	else
	{

		p=head;
		while(p->next!=NULL)
		{
			p=p->next;
			cnt++;			//Counting records...

		}

		printf("\nThere are %d Records in Database.",(cnt+1));

	}
return 0;
}


void main()
{
	int ch,i;
	char op;
	Node *head;
	head=NULL;
	clrscr();
	printf("\n*----------Student DB Mgmt System By Abhishek-----------*");
	do
	{
		printf("\nOptions Menu\n1.Create Database\n2.Insert\n3.Delete\n4.Search\n5.Modify\n6.Display\n7.Display Reverse\n8.Count Records\n9.Exit");

		printf("\n\nEnter Your Choice : ");
		scanf("%d",&ch);

		switch(ch)
		{
		case 1:
			head=Create(head);			//Call to Create...

		break;

		case 2:

			head=Insert(head);			//Call to Insert...

		break;

		case 3:

			head=Delete(head);			//Call to Delete...

		break;

		case 4:		

			Search(head);				//Call to Search...

		break;

		case 5:

			Modify(head);				//Call to Modify...
		
		break;

		case 6:
			Display(head);				//Call to Display...
		break;

		case 7:

			for(i=0;i<1;i++)
			{

				printf("\n");

			}
			printf("\nUpdated Student Database");
			for(i=0;i<1;i++)
			{

				printf("\n");

			}
			printf("");

			printf("\nRoll No.	Name		Marks");
			for(i=0;i<1;i++)
			{

				printf("\n");

			}
			printf("");

			DReverse(head);		//Call to displaying reversre...

		break;

		case 8:
			Count(head);		//Call to counting records...

		break;

		case 9:
			exit();				//Exit...

		default :
		printf("\nYou entered wrong choice.");

		}

		printf("\nDo you want to Exit(Y/N)? : ");
		flushall();
		scanf("%c",&op);

	}while(op=='n' || op=='N');

}
