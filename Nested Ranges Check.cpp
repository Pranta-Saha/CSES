// I just sort the vector by nondecreasing of left, but
// if some left is same then nonincreasing of right
// then for contains, I go through from n-1 to 0 and keep track of min
// and for contained, I go through from 0 to n-1 and keep track of max 

#include<bits/stdc++.h>
using namespace std;

bool cmp(pair< pair<int,int> ,int> a, pair< pair<int,int> ,int> b)
{
	if(a.first.first == b.first.first)
		return a.first.second > b.first.second;
	return a.first.first < b.first.first;
}

int main()
{
	int n,i,mx=0,l,r,mn=1e9;
	cin>>n;
	vector< pair< pair<int,int> ,int> >vec;
	vector<bool>res1(n,0), res2(n,0);
	for(i=0;i<n;i++)
	{
		cin>>l>>r;
		vec.push_back( {{l,r},i} );
	}
	sort( vec.begin(), vec.end(), cmp);
	
	for(i=n-1; i>=0; i--)
	{
		auto tmp = vec[i].first;
		if( tmp.second >= mn )
		{
			res1[ vec[i].second ]=1;
		}
		mn = min( mn, tmp.second );
	}
	
	for(i=0; i<n; i++)
	{
		auto tmp = vec[i].first;
		if( tmp.second <= mx )
		{
			res2[ vec[i].second ]=1;
		}
		mx = max( mx, tmp.second );
	}
	
	for(i=0;i<n;i++) cout<<res1[i]<<' ';
	cout<<endl;
	for(i=0;i<n;i++) cout<<res2[i]<<' ';
}

