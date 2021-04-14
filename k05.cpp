#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;

typedef long long ll;
struct ind
{
    ll l,p,v;
};
struct Less
{
    bool operator()(ind &a,ind &b) const
    {
       if(a.p!=b.p) return a.p>b.p;
       return a.l>b.l;
    }
};
struct Upp
{
    bool operator()(ind a,ind b) const
    {
       if(a.l!=b.l) return a.l<b.l;
       return a.p<b.p;
    }
};
struct
{
    bool operator()(ind a,ind b) const
    {
       if(a.v!=b.v) return a.v>b.v;
       return a.l<b.l;
    }
}Great;
bool check(multiset<ind,Upp> &S)
{
   multiset<ind>::iterator p=S.begin();
   ind q;
   priority_queue<ind,vector<ind>,Less> O;
   ll akt=(*p).l;
   while(true)
   {
       //cout<<"Pl "<<(*p).l<<" Pp "<<(*p).p<<endl;
      // cout<<"AKT "<<akt<<endl;
         while(p!=S.end() && (*p).l<=akt) {O.push((*p));p++;}
         q=O.top();
        // cout<<"Ql "<<q.l<<" Qp "<<q.p<<endl;
        // cout<<"AKT "<<akt<<endl;
       if(akt>=q.p) return false;
       O.pop();
       if(O.empty() && p==S.end()) break;
       akt=max(q.l,akt)+1;
      if(O.empty()) akt=max(akt,(*p).l);
   }
   return true;
}
int main()
{
    ios_base::sync_with_stdio(0);
    ll z;
    cin>>z;
    while(z--)
    {
        ll n;
        cin>>n;
        vector<ind> T(n);
        for(auto &i : T) cin>>i.l>>i.p>>i.v;
        multiset<ind,Upp> S;
        ll suma=0;
        sort(T.begin(),T.end(),Great);
        for(auto i : T)
        {
           auto it=S.insert(i);
           if(check(S))  suma+=i.v;
           else S.erase(it);
         //cout<<endl;
        }
        cout<<suma<<endl;
    }


    return 0;
}