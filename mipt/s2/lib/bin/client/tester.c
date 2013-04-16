#include <stdio.h>
#include "bsearch.h"
#include <stdlib.h>

int main ()
{
  double *b,x[100001],f;
  int j,i,n,ans;
  scanf("%d%lf",&n,&f);
  for (i=0; i<n; i++) scanf("%lf",&x[i]);
  scanf("%d",&ans);
  b = bfind(&x[0],n,0,n-1,f);
  if (b==NULL) {if (ans==-1) {printf("YES");} else printf("NO");}
  else {if ((*b)==x[ans]) printf("YES"); else printf("NO");}
  return 0;
}
