#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
  int mp[200][200]={0},a[200][200]={0},n,m,maxx=0;
  cin>>n;
  for(int i = 0; i < n; i++)
  {
    cin>>m;
    maxx = max(m,maxx);
    for(int j = 0; j < 10 * m; j++) mp[i][j] = 1;
  }
  int num=1,flag=-1;
  for(int i = 0; i < 10 * maxx; i++)
  {
    for(int j = 0; j < n; j++)
    {
      if(mp[j][i])
      {
        if(flag!=j)
        {
          a[j][i]=num++;
          flag=j;
        }
        else
        {
          num+=1;
          a[j][i]=num++;
          flag=j;
        }
      }
    }
  }
  for(int i = 0; i < n; i++)
  {
    cout<<"#"<<i+1<<endl;
    for(int j = 0; j < 10*maxx; j++)
    {
      if(a[i][j])
      {
        if((j+1)%10==0) cout<<a[i][j]<<endl;
        else cout<<a[i][j]<<" ";
      }
    }
    
  }
  return 0;
}