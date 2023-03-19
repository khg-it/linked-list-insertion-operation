# include <stdio.h>
# include <stdlib.h>

struct node{
     int data;
     struct node *next;


};
struct node *head=NULL;
void printlinkedlist(struct node*ptr)
{

    while(ptr!=NULL)
    {
        printf("%d\n ",ptr->data);
        ptr=ptr->next;
    }
}
void searched(struct node *ptr,int data)
{
         int loc=0;
        while(ptr!=NULL)
        {
           if(data==ptr->data)
           {
             printf("\n %d is sucessfully searched in linked list",data);
             loc++;

           }
           ptr=ptr->next;
          }
            if(loc==0)
            {
               printf("\n %d is not sucessfully searched in linked list",data);

            }}
struct node *insertatfirst(struct node *first,int data)
{
    head=first;
    struct node *start=(struct node *)malloc(sizeof(struct node));
    start->data=data;
    start->next=head;
    head=start;
    return head;
    };
struct node *insertinbetween(struct node *head,int data,int idx)
{
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    struct node *p=head;
    int i=0;
    while(i!=(idx-1))
    {
        p=p->next;
        i++;
    }
    ptr->next=p->next;
    ptr->data=data;
    p->next=ptr;
    return head;

};
struct node *insertatend(struct node *head,int data)
{
    struct node *kt=(struct node *)malloc(sizeof(struct node));
    kt->data=data;
    struct node *p=head;
    while(p->next!=NULL)
    {
        p=p->next;

    }
    kt->next=p->next;
    p->next=kt;
    return head;


};
struct node *insertafter(struct node *previous,struct node *head,int data)
{
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    ptr->next=previous->next;
    previous->next=ptr;
    ptr->data=data;
    return head;
};
int main()
{
    struct node *ptr;
    struct node *second;
    struct node *third;
    ptr=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));

    ptr->data=1;
    ptr->next=second;
    second->data=2;
    second->next=third;
    third->data=3;
    third->next=NULL;
    printf("\n linked list before insertion");
    printlinkedlist(ptr);
    printf("\n linked list after insertion at first");
    ptr=insertatfirst(ptr,11);
    printlinkedlist(ptr);
    searched(ptr,2);
    ptr=insertinbetween(ptr,7,1);
    printf("\n linked list in between");
    printlinkedlist(ptr);
    printf("\n linked list at end");
    ptr=insertatend(head,9);
    printlinkedlist(head);
    printf("n linked list after a node");
    head=insertafter(second,ptr,56);
    printlinkedlist(ptr);


}

