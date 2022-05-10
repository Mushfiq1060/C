#include<stdio.h>
#include<stdlib.h> 
using namespace std;
int main()
{
  int n,*ptr;
  scanf("%d",&n);
  ptr=(int *)malloc(n*sizeof(int)); /// ptr works as an array
  for(int i=0;i<n;i++){
    scanf("%d",ptr+i);   
  } 
  for(int i=0;i<n;i++){ /// print ptr
    printf("%d ",*(ptr+i));
  }
  printf("\n");
  int m;
  scanf("%d",&m);
  ptr=(int *)realloc(ptr,m*sizeof(int)); /// increase (m-n) size of ptr but not delete previous element
  for(int i=n,j=0;j<m-n;j++,i++){
    scanf("%d",ptr+i);
  }
  for(int i=0;i<m;i++){ /// print ptr after increase size
    printf("%d ",*(ptr+i));
  }
  return 0;
}
