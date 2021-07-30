// For each pair of values, I just find if there available (x-sum of values of current pair)
// As the index I found can be index of current pair, so checked it three times.

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	ll n,i,j,x,tmp;
	cin>>n>>x;
	vector<ll>vec(n+1);
	multimap<ll,ll>mp;
	for(i=1;i<=n;i++)
	{
		cin>>vec[i];
		mp.insert({vec[i],i});
	}
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			tmp=vec[i]+vec[j];
			auto it=mp.find(x-tmp);
			ll cnt=3;
			while(cnt--)
			{	
				if(it==mp.end()) break;
				if( (*it).first==x-tmp && ( (*it).second!=i && (*it).second!=j ))
				{	cout<<i<<" "<<j<<" "<<(*it).second<<endl; return 0;}
				it++;
			}	
		}
	}
	cout<<"IMPOSSIBLE"<<endl;
}
