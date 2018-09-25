/*找规律，发现1-9，就是1到9，到10的时候，0放在哪呢？就发现如果放在最后的话，
可以保证以后的20,30,..90都用这个0，这样能把这个0的作用最大化，然后11的时候，
同样一个新的1放在0后面，可以满足21,31...91.101，利益最大化，
于是我们想到按照123456789012345678901234567890....的顺序放，是最优的贪心策略、
然后11……11 22…………22 这种是一个也不能省的，从低到高判断*/
#include<cstdio>
#include<cstring>
#define maxl 10010
 
int nlen,ans;
char n[maxl];
 
bool jug(int x)
{
	for(int i=1;i<=nlen;i++)
	if(n[i]-'0'==x)
		continue;
	else
	if(n[i]-'0'<x)
		return false;
	else
		return true;
	return true;
}
 
int main()
{
    
	scanf("%s",n+1);
		nlen=strlen(n+1);
		ans=10*(nlen-1);
		for(int i=1;i<=9;i++)
		if(jug(i))
			ans++;
		else
			break;
		printf("%d\n",ans);
	
	return 0;
}