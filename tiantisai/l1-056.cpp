#include<iostream>
#include<map>
#include<string>
using namespace std;
int main()
{
  map<string,int> mp;
  int n; cin>>n;
  int i;
  string name;
  int val,avg,sum=0,numMax=1000;
  for(int i = 0; i < n; i++)
  {
    cin>>name>>val;
    mp[name]=val;
    sum += val;
  }
  avg = sum /n /2;
  map<string,int>::iterator iter;
  for(iter = mp.begin(); iter != mp.end(); iter++)
  {
    if(abs(avg-iter->second) < numMax){
      numMax = abs(avg-iter->second);
      name = iter->first;
    }
  }
  cout<<avg<<" "<<name<<endl;
  return 0;
}