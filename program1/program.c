#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
   int data;
   struct node*left;
   struct node*right;
}*root=NULL;

struct node*newnode(int val){
  struct node*temp=(struct node*)malloc(sizeof(struct node));
  temp->data=val;
  temp->left=NULL;
  temp->right=NULL;
  return temp;
}

struct node*insert_left(struct node* node,int val){
    struct node*n=node;
   if(node==NULL){
      node->data=val;
      node->left=NULL;
      node->right=NULL;
      root=node;
   }
   else{
      while(n->left!=NULL){
         n=n->left;
      }
      struct node*newnod=newnode(val);
      n->left=newnod;
   }
   return n;
}
struct node*insert_right(struct node* node,int val){
    struct node*n=node;
   if(node==NULL){
      node->data=val;
      node->left=NULL;
      node->right=NULL;
      root=node;
   }
   else{
      while(n->right!=NULL){
         n=n->right;
      }
      struct node*newnod=newnode(val);
      n->right=newnod;
   }
   return n;
}

void inorder(struct node*node){

    struct node *n=node;
   while(node!=NULL){
     inorder(node->left);
     printf("  inoerder:%d",node->data);
     inorder(node->right);
   }
}
struct node*insert(struct node*root,int val){
      struct node*node=root;
 printf("\ninserted:%d\n",node->data);
      if(node==NULL){
         node->data=val;
         node->left=NULL;
         node->right=NULL;
        printf("\ninserted:%d\n",node->data);
      }
      return node;

}
void print(char ary[]){
   int i;
   int len=strlen(ary);
   printf("%d %d %d %d \n",'{',',','}','1');
   int count=0;
   printf("%d",ary[2]-48);
   root=insert(root,ary[2]-48);
   for(i=0;i<len-1;i++){
       if(ary[i]==44 && ary[i+1]!=123 && ary[i+4]==125){
           root=insert_left(root,ary[i+1]-48);
           root=insert_right(root,ary[i+3]-48);
       }

      if(ary[i]==123){
        printf("%d",ary[i+1]);
        if(count==0){
          root=insert(root,ary[i+1]-48);
          count++;
        }
        if(count==1){
          root=insert_left(root,ary[i+1]-48);
          count++;
        }
        if(count==2){
          root=insert_right(root,ary[i+1]-48);
          count++;
        }

      }
      //display(root);

   }
   inorder(root);

}
int main(){
    int num,i,j;
    printf("loop:");
    scanf("%d",&num);
    for(i=0;i<num;i++){
       char ary[20];
       for(j=0;j<20;j++){
         scanf("%c",&ary[j]);
       }
       print(ary);

    }

}
