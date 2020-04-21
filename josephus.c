#include <stdio.h>
#include <stdlib.h>
struct listnode  {
    int number;
    struct listnode* next;
};
typedef struct listnode *ListNode;
struct circular_list  {
    ListNode node;
    int size;
};
void list_remove_next(ListNode prev_node,struct circular_list *Circle)  {
    ListNode temp_node,next_node;
    next_node=prev_node->next->next;
    temp_node=prev_node->next;
    prev_node->next=next_node;
    (Circle->size)--;
    free(temp_node);
}
int josephus_function(int size)  {
    struct circular_list *Circle;
    ListNode node;
    Circle=malloc(sizeof(struct circular_list*));
    Circle->node=malloc(sizeof(ListNode));
    Circle->size=1;
    node=Circle->node;
    node->number=1;
    int temp=size;
    int i=2;
    while(temp--!=1)  {
        node->next=malloc(sizeof(ListNode));
        node=node->next;
        node->number=i;
        (Circle->size)++;
        i++;
    }
    node->next=Circle->node;
    ListNode header_node=Circle->node;
    while (1)  {
        list_remove_next(header_node,Circle);
        if (Circle->size!=1)  {
            header_node=header_node->next;
        }
        else  {
            break;
        }
    }
    return header_node->number;
}
void main(void)  {
    int size;
    scanf("%d",&size);
    int i=1;
    while(i++!=size)  {
        printf("%d -> %d \n",i,josephus_function(i));
    }
}