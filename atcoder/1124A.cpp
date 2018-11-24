#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<math.h>
using namespace std;
const int N = 109;
int a[N];
int main()
{
    freopen("in.txt","r",stdin);
    int n; cin>>n;
    int sum  = 0;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        sum+=a[i];
    }
    double db = 1.0*sum/n;
    int index = 0;
    double minn = 999999.0;// cout<<db<<endl;
    for(int i = 0; i < n; i++)
    {
        if(fabs(a[i]*1.0-db)<minn) {
            index=i; minn = fabs(a[i]*1.0-db);}
    }
    cout<<index<<endl;
    return 0;
}