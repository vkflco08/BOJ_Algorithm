#include<stdio.h>
int d[41];
int fibonacci(int n) {
   if(n == 0)
   {
        return 0;
   }
   else if(n==1)
   {
        return 1;
   }
   else if(n < 0)
     return 1;
   else
   {
          if(d[n]> 0) return d[n];
          d[n] = fibonacci(n-1) + fibonacci(n-2);
          return d[n];
   }
}
int main()
{
    int n;
    int T;
    int one;
    int zero;
    scanf("%d",&T);
    for(int i =0; i<T; i++)
    {
        scanf("%d",&n);
        one = fibonacci(n);
        zero = fibonacci(n-1);
        
        printf("%d %d\n",zero,one);
    }
}
 
 