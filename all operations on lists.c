//L1 student at the university of chlef
#include <stdio.h>
#include <stdlib.h>
struct node{
  int data;
  struct node *link;
};
void add_node_beginning(struct node **head , int data);
void add_at_end(struct node *head , int data);
void add_node_center(struct node *head , int data , int posb);
struct node* delete_first_node(struct node *head);
struct node* delete_the_last_node(struct node *head);
struct node* delete_node_with_position(struct node *head,int posb);
int main()
{
  struct node *head, *ptr;
  head = malloc(sizeof(struct node));
  head->data = 6;
  head->link = NULL;
  
  struct node *temp = malloc(sizeof(struct node));
  temp->data = 28;
  temp->link = NULL;
  head->link = temp;
  
  temp = malloc(sizeof(struct node));
  temp->data = 19;
  temp->link = NULL;
  head->link->link = temp;
  ptr = head;
   printf("{ ");
   while(ptr != NULL){
   printf(" %d, ",ptr->data);
        ptr = ptr->link;
    }  
    printf("}\n\n");
  // the programme
  printf("1.press one to add a node to the beginnig of the list\n\n");
  printf("2.press two to add a node to the end of the list\n\n");
  printf("3.press three to add a node to the center of the list\n\n");
  printf("4.press four to delete the first node form the list \n\n");
  printf("5.press five to delete the last node form the list \n\n");
  printf("6.press six to delete  a node with position in center form the list \n\n");
  int option;
  printf("option >: ");
  scanf("%d",&option);
  
  switch(option){
    
    case 1:
         int x;
         printf("Enter the value of the node: \n");
         printf(">: ");
         scanf("%d",&x);
         add_node_beginning(&head,x);
         ptr = head;
         printf("\nthe result : \n\n");
         printf("{ ");
         while(ptr != NULL){
         printf(" %d, ",ptr->data);
          ptr = ptr->link;
        }  
        printf("}");
        break;
    
     case 2:
         
         printf("Enter the value of the node: \n");
         printf(">: ");
         scanf("%d",&x);
         add_at_end(head,x);
         printf("\nthe result : \n\n");
         printf("{ ");
         while(ptr != NULL){
         printf(" %d, ",ptr->data);
          ptr = ptr->link;
        }  
        printf("}");
        break;
      
      case 3:
          int posb;
          printf("Enter the value of the node: \n");
          printf(">: ");
          scanf("%d",&x);
          
          printf("Enter the position to add the value: \n");
          printf(">: ");
          scanf("%d",&posb);
          
          add_node_center(head,x,posb);
          
          printf("\nthe result : \n\n");
           printf("{ ");
          while(ptr != NULL){
           printf(" %d, ",ptr->data);
           ptr = ptr->link;
          }  
          printf("}");
          break;
          
      case 4:
         head = delete_first_node(head);
         ptr = head;
         printf("\nthe result : \n\n");
         printf("{ ");
         while(ptr != NULL){
         printf(" %d, ",ptr->data);
          ptr = ptr->link;
        }  
        printf("}");
        break;
        
      case 5:
         head = delete_the_last_node(head);
         ptr = head;
         printf("\nthe result : \n\n");
         printf("{ ");
         while(ptr != NULL){
         printf(" %d, ",ptr->data);
          ptr = ptr->link;
        }  
        printf("}");
        break;
      case 6:
         int post;
         printf("Enter the position to delete the value: \n");
         printf(">: ");
         scanf("%d",&post);
         head = delete_node_with_position(head,post);
         ptr = head;
         printf("\nthe result : \n\n");
         printf("{ ");
         while(ptr != NULL){
         printf(" %d, ",ptr->data);
          ptr = ptr->link;
        }  
        printf("}");
        break;
        default:
           printf("invalid option !!");
     } 
     
  return 0;
}
// function to add node at the beginning of the list
void add_node_beginning(struct node **head , int data){
   struct node *ptr;
   ptr = malloc(sizeof(struct node));
   ptr->data = data;
   if(head == NULL){
     ptr->link = NULL;
     *head = ptr;
    }
   else{
     ptr->link = *head;
     *head = ptr;
     }
}
// function to add node the end of the list
void add_at_end(struct node *head , int data){
  struct node *ptr , *temp;
  temp = malloc(sizeof(struct node));
  temp->data = data;
  temp->link = NULL;
  if(head == NULL){
    head->link = temp;
    }
  else{
    ptr = head;
    while(ptr->link != NULL){
      ptr = ptr->link;
    }
    ptr->link = temp;
  }
}
//function to add a node at the center of a list
void add_node_center(struct node *head , int data , int posb){
  struct node *ptr1 , *ptr2;
  ptr1 = head;ptr2 = head;
  struct node *temp = malloc(sizeof(struct node));
  temp->data = data;
  if(head == NULL){
    temp->link = NULL;
    head = temp;
  }
  else{
    while(ptr1->data != posb){
      ptr2 = ptr1;
      ptr1 = ptr1->link;
    }
    temp->link = ptr1;
    ptr2->link = temp;
  }
}
//function to delete the first node from the list
struct node* delete_first_node(struct node *head){
  struct node *temp;
  temp = head;
  head = head->link;
  free(temp);
  temp = NULL;
  return head;
}
//funtion to delete the last node from the list
struct node* delete_the_last_node(struct node *head){
  struct node *ptr1 , *ptr2;
  ptr1 = head; ptr2 = head;
  if(head == NULL){
    printf("the list is already empty");
    return head;
  }
  else if(head->link == NULL){
    free(head);
    head = NULL;
    return head;
  }
  else{
  while(ptr1->link != NULL){
    ptr2 = ptr1;
    ptr1 = ptr1->link;
  }
  ptr2->link = NULL;
  free(ptr1);
  ptr1 = NULL;
  return head;
 }
}
//function to delete a node with given postion of the list
struct node* delete_node_with_position(struct node *head,int posb){
  struct node *ptr1 , *ptr2;
  ptr1= head;
  ptr2= head;
  
  if(head == NULL){
     printf("the list is already empty");
  }
  
  else if(head->link == NULL && head->data == posb){
     head = NULL;
  }
  
  else if(head->link == NULL && head->data != posb){
     printf("this value\' %d \'dosn't inside the list\n",posb);
  }
  
  else{
  while(ptr1->data != posb && ptr1 != NULL){
     ptr2 = ptr1;
     ptr1 = ptr1->link;
   }
   
   if(ptr1 == NULL){
     printf("this %d value doesn't inside this list \n",posb);
   }
   
   else{ 
     ptr2->link = ptr1->link;
     free(ptr1);
     ptr1 = NULL;
    
    }
  }
  return head;
}