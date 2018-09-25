#include<stdio.h>
#include<math.h>
int euler(int n){ //返回euler(n)   
     int res=n,a=n;  
     for(int i=2;i*i<=a;i++){  
         if(a%i==0){  
             res=res/i*(i-1);//先进行除法是为了防止中间数据的溢出   
             while(a%i==0) a/=i;  
         }  
     }  
     if(a>1) res=res/a*(a-1);  
     return res;  
}
int main()
{
    int T,n,m,ans;
    scanf("%d",&T);
    while(T--)
    {
        ans = 0;
        scanf("%d%d",&n,&m);
        for(int a = 1; a <= sqrt(n); a++)
        {
            if(n % a ==0)
            {
                if( a >= m) ans +=euler(n/a);
                if(n/a >=m && a != n/a) ans +=euler(a);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}