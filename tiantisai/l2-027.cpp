#include<bits/stdc++.h>
using namespace std;
int n,g,k;
struct node
{
    string s;
    int sc;
    bool operator <(const node &x)const
    {
        if(sc != x.sc) return sc > x.sc;
        else return s < x.s;
    }
}p[10010];
int main()
{
    cin>>n>>g>>k; 
    int money = 0;
    for(int i = 0; i < n; i++)
    {
        string s; int sc;
        cin>>s>>sc;
        if(sc>=g) money+=50;
        else if(sc>=60) money += 20;
        p[i].s = s;
        p[i].sc = sc; 
    } 
     sort(p,p+n); 
     cout<<money<<endl;
     cout<<"1 "<<p[0].s<<" "<<p[0].sc<<endl; 
     int id=1; int c=0;
     for(int i = 1;  i < n; i++)
    {
        if(p[i].sc!=p[i-1].sc)
        {
            id+=c+1;
            c=0;
        }
        else
        {
            c++;
        }
        if(id>k) break;
        cout<<id<<" "<<p[i].s<<" "<<p[i].sc<<endl;
    }
    return 0;
}