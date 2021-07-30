// The optimal way is to process by increasing order of duration of tasks. :)

#include<bits/stdc++.h>
using namespace std; 

int main()
{
	long long n,i,a,d;
	cin>>n;
	vector<pair<long long,long long>>vec(n);
	for(i=0;i<n;i++)
		cin>>vec[i].first>>vec[i].second;
	sort(vec.begin(),vec.end());
	long long ans=0,time=0;
	for(auto x:vec)
	{
		time+=x.first;
		ans+=(x.second-time);
	}
	cout<<ans<<endl;
}

