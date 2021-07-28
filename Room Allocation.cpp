// I just sort coustomers by arrival time, 
// pick first one, assign day-1, find next one for day-1 using upper_bound of current departure time.
// if found nothing i.e reach end, again start from begin, increase day count, repeat above process. 
//


#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,c;
    cin>>n;
    multimap< int,pair<int,int> >mp;
    for(i=0;i<n;i++)
    {
	    int a,d;
	    cin>>a>>d;
	    mp.insert({a,{d,i}});
    }
    vector<int>ans(n);
    int day=1;


    auto it=mp.begin();
    while(n--)
    {
	    auto b=(*it).second;
	    mp.erase(it);
	    ans[b.second]=day;
	    it=mp.upper_bound(b.first);
	    if(it==mp.end())
	    {
		    it=mp.begin();
		    day++;
	    }
    }
    cout<<day-1<<endl;
    for(int x:ans) cout<<x<<" ";
    cout<<endl;
}
