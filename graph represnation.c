#include<stdio.h>
#include<stdlib.h>
const int mxn=2e5+10;
int *g[mxn],sz[mxn];
void addEdge(int u,int v)
{
  int s=sz[u]++;
  if(s>=2 && (s&(s-1))==0){
    g[u]=(int *)realloc(g[u],s*2*sizeof *g[u]); /// reallocate memory for every node
  }
  g[u][s]=v;
}
int main()
{
  int n,m;
  scanf("%d%d",&n,&m); /// n=number of node,m=number of edge
  for(int i=0;i<=n;i++){
    g[i]=(int *)malloc(2*sizeof *g[i]); /// memory allocate for every node
    sz[i]=0;
  }
  for(int i=0;i<m;i++){
    int u,v;
    scanf("%d%d",&u,&v);
    addEdge(u,v);
    addEdge(v,u);
  }
  for(int i=1;i<=n;i++){
    printf("%d -> ",i);
    for(int j=0;j<sz[i];j++){
      printf("%d ",g[i][j]);
    }
    printf("\n");
  }
  for(int i=0;i<=n;i++){
    free(g[i]);
    sz[i]=0;
  }
  return 0;
}
