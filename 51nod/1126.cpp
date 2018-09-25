#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define MOD 7
#define N 2
struct M{
	int size;
	int a[N][N];
	M(int s=0){
		size=s;
		memset(a,0,sizeof(a));
	}
	void operator = (const M &t){
		size=t.size;
		memcpy(a,t.a,sizeof(t.a));
	}
	M operator * (const M &t){
		M res = M(size);
		for(int i = 0; i<size; i++){
			for(int k = 0; k<size; k++){
				if(a[i][k])
					for(int j = 0; j<size; j++){
						res.a[i][j]+=a[i][k]*t.a[k][j] ;
						if(res.a[i][j]>=MOD) res.a[i][j]%=MOD;
					}
			}
		}
		return res;
	}
	M operator ^ (int n){
		M tmp = *(this);
		M ans = M(size);
		for(int i = 0; i<size; i++) ans.a[i][i]=1;
		while(n){
			if(n&1) ans=ans*tmp;
			tmp = tmp*tmp;
			n>>=1;
		}
		return ans;
	}
	void debug(){
		cout<<endl;
		for(int i = 0; i<size; i++){
			for(int j = 0; j<size; j++){
				cout<<a[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}
};
int main()
{
	int n;
	int A,B;
	cin>>A>>B>>n; n-=1; 
	while(A<0) A+=MOD;
	while(B<0) B+=MOD;
	M aa = M(2);
	M bb = M(2);
	aa.a[0][0]=1; aa.a[0][1]=1;
	bb.a[0][0]=0; bb.a[0][1]=B; bb.a[1][0]=1; bb.a[1][1]=A;
	bb=bb^n;
	aa=aa*bb;
	int ans = aa.a[0][0];
	while(ans<0) ans+=MOD;
	cout<<ans%MOD<<endl;
	return 0;
}
