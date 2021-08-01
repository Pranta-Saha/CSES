//Starting from greater value I just found what is the nearest left available/unremoved value.
//removed means, once I consider a value, remove it from array. Like, for given example, fistly I consider 8, found nearest left unremoved index is 4. Then I removed 8.
//removing is expensive, So used DSU(Disjoint Set Union) to keep track of nearest left available value  


#include<bits/stdc++.h>
using namespace std;

int p[200005];
int Find(int x)
{
	if(p[x]==x) return x;
	return p[x]=Find(p[x]);
}
void Union(int a, int b)
{
	p[Find(b)]=Find(a);
}

bool cmp(pair<int,int> a,pair<int,int> b)
{
	if(a.first==b.first) return a.second < b.second;
	return a.first > b.first;
}

int main()
{
	int n,i,m;
	cin>>n;
	vector<int>ans(n+1);
	vector<int>arr(n+1);
	vector<pair<int,int>>vec;
	for(i=1;i<=n;i++)
	{
		p[i]=i;
		cin>>m;
		arr[i]=m;
		vec.push_back({m,i});
	}
	p[0]=0;
	sort(vec.begin(),vec.end(),cmp);
	for(auto x:vec)
	{
		ans[x.second]=Find(x.second-1);
		Union( x.second-1,x.second);
	}
	for(i=1;i<=n;i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}


