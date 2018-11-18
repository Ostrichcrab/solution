#define _int64 long long
#define mo 1000000007

int d[10][6000];

int neigh[10][2]={{1,6},{1,8},{2,7},{2,9},{3,4},{3,8},{4,0},{4,9},{6,7},{6,0}};

int doit(int x,int n)
{
  if (n==0) return 1;
  if (d[x][n]!=-1) return d[x][n];
  int i,ans;
  ans=0;
  for (i=0;i<10;i++)
  {
    if (neigh[i][0]==x)
    {
      ans+=doit(neigh[i][1],n-1);
      if (ans>=mo) ans-=mo;
    }
    if (neigh[i][1]==x)
    {
      ans+=doit(neigh[i][0],n-1);
      if (ans>=mo) ans-=mo;
    }
  }
  d[x][n]=ans;
  return ans;
}

class Solution {
public:
    int knightDialer(int n) {
      int i;
      int ans;
      memset(d,-1,sizeof(d));
      ans=0;
      for (i=0;i<10;i++)
      {
        ans+=doit(i,n-1);
        if (ans>=mo) ans-=mo;
      }
      return ans;
    }
};