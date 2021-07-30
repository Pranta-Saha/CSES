// I just convert this into sum of two value equal to x by making new array of sum of each pair of given array.


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	ll n,i,j,x,tmp;
	cin>>n>>x;
	vector<ll>vec(n+1);
	multimap<ll,pair<ll,ll>>mp;
	for(i=1;i<=n;i++)
	{
		cin>>vec[i];
	}
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			mp.insert({vec[i]+vec[j],{i,j}});
		}
	}
	for(auto it=mp.begin(); it!=mp.end(); it++)
	{
		ll remain=x-(*it).first;
		for(auto it2=mp.lower_bound(remain); it2!=mp.upper_bound(remain); it2++)
		{
			auto a=(*it).second,b=(*it2).second;
			if(a.first!=b.first && a.first!=b.second  && a.second!=b.first && a.second!=b.second )
			{
				cout<<a.first<<" "<<a.second<<" "<<b.first<<" "<<b.second<<endl;
				return 0;
			}
		}
	}
	cout<<"IMPOSSIBLE"<<endl;
}
