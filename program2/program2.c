#include<stdio.h>
#include<stdlib.h>

void swap(char *a,char *b){
  char *temp;
  temp=*a;
  *a=*b;
  *b=temp;

}
void permute(char *a,int l,int h){
   char ary[10][10];
   int count=0;
  if(l>h){
    printf("%s\n",a);


  }
  else{
      int i=0;
     for(i=0;i<h;i++){
       swap((a+l),(a+i));
       permute(a,l+1,h);
       swap((a+l),(a+i));
     }
  }
}

int main(){
  char a[]="arc";
  int len=strlen(a);
  permute(a,0,len-1);



}
