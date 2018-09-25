#include<stdio.h>
int n;
int main(){
    scanf("%d",&n);
    if(n<0) n=-n;
    int p=0,t=1,ans=0;
    while(p<n){
        p=p+t;
        ans++;
        t++;
    }
    if((p-n)%2==0){
        printf("%d\n",ans);
    }
    else{
        while((p-n)%2==1){
            p=p+t;
            ans++;
            t++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
