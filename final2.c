# include <stdio.h>
# include <stdlib.h>

struct node{
     int data;
     struct node *next;
};

void traversal(struct node*ptr)
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
struct node *insertatbeg(struct node *start,struct node *head,int data){
         struct node *get=(struct node*)malloc(sizeof(struct node));
         get->data=data;
         start->next=head;
         get->next=start->next;
         start->next=get;
         return get;

};
struct node *insertatend(struct node *head,int data)
{
        struct node *get=(struct node*)malloc(sizeof(struct node));
        get->data=data;
        struct node *ptr=head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        get->next=ptr->next;
        ptr->next=get;
        //return head;


};
struct node *insertinbetween(struct node *head,int data,int idx)
{
        struct node *bone=(struct node *)malloc(sizeof(struct node));
         bone->data=data;
         struct node *pt=head;

        int i;
        for(i=0;i!=idx-1;i++)
        {
             pt=pt->next;

        }
        bone->next=pt->next;
        pt->next=bone;
        return head;

};

int main()
{


    struct node *start=(struct node *)malloc(sizeof(struct node));
    struct node *head;
    struct node *second;
    struct node *third;


    head=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));
    start->next=head;
    head->data=1;
    head->next=second;
    second->data=2;
    second->next=third;
    third->data=3;
    third->next=NULL;
    printf("\n traversal of linked list before operations.");
    traversal(head);
    //searched(head,6);
    printf("\n after insertion at the beginning of linked list.");
    head=insertatbeg(start,head,15);
    traversal(head);
    printf("\n after insertion at the end of linked list.");
    insertatend(head,12);
    traversal(head);
    printf("\n after insertion in between of linked list.");
    head=insertinbetween(head,45,3);
    traversal(head);




}

