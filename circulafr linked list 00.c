#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node * next;
};
typedef struct node NODE;
NODE *head=NULL,*tail=NULL,*val,*temp,*res;
NODE *delete_head()
{
	NODE *temp;
	if(head==NULL && tail==NULL)
    {
    	return NULL;
	}
	 if(head==tail)
	{
		temp=head;
		head=NULL;
		tail=NULL;
		return temp;
	}
	   temp=head;
	   head=head->next;
	   temp->next=NULL;
	   tail->next=head;
	   return temp;
}
void display()
{
	NODE *temp;
	if(head==NULL && tail==NULL)
	{
		printf("no nodes\n");
	}
	else
	{
		temp=head;
		while(temp->next!=head)
		{
			printf("%d %d %d\n",temp,temp->data,temp->next);
			temp=temp->next;			
		}
		printf("%d %d %d\n",temp,temp->data,temp->next);
		printf("\n");
	}
}
void insert_head(NODE *nn)
{
	if(head==NULL && tail==NULL)
	{
		head=nn;
		tail=nn;
		nn->next=head;
	}
	else
	{
		nn->next=head;
		head=nn;
	    tail->next=head;
	}
	
}
int main()
{
	NODE *nn;
	int ch,val;
	while(1)
	{
		printf("1.insert at head 2.delete at head 3.display 4.exit:");
		scanf("%d",&ch);
		if(ch==1)
		{
			//insert
			scanf("%d",&val);
			nn=(NODE *)malloc(sizeof(NODE));
			nn->data=val;
			nn->next=NULL;
			insert_head(nn);
		}
		else if(ch==2)
		{
			//delete
			res=delete_head();
		    if(res==NULL)
		    {
		    	printf("NO NODES\n");
			}
			else
			{
				printf("%d\n",res->data);
				free(res);
			}
		}
		else if(ch==3)
		{
		   //display
		   display();
		}
		else
		{
			break;
		}
}
}
