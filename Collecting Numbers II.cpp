#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m,i,j,tmp,lft,rht,cnt=0;
	cin>>n>>m;
	map<int,int>mp;
	mp[n+1]=n;
	vector<int>arr(n);
	for(i=0;i<n;i++)
	{
		cin>>tmp;
		arr[i]=tmp;
		if(mp.find(tmp-1) == mp.end())
		{
			cnt++;
		}
		mp[tmp]=i;
	}
cout<<cnt<<endl;
	mp[0]=-1;
	while(m--)
	{
		cin>>lft>>rht;
		lft--;
		rht--;
		{
			if( mp[ arr[lft]-1 ] < mp[ arr[lft] ] )
			{
				cnt++;
			}
			if( mp[ arr[lft] ] < mp[ arr[lft]+1 ] )
			{
				cnt++;
			}
			if( mp[ arr[rht]-1 ] < mp[ arr[rht] ] )
			{
				cnt++;
			}
			if( mp[ arr[rht] ] < mp[ arr[rht]+1 ] )
			{
				cnt++;
			}
		cout<<cnt<<" ";
			mp[ arr[lft] ] = rht;
			mp[ arr[rht] ] = lft;
			swap(arr[lft],arr[rht]);

			if( mp[ arr[lft]-1 ] < mp[ arr[lft] ] )
			{
				cnt--;
			}
			if( mp[ arr[lft] ] < mp[ arr[lft]+1 ] )
			{
				cnt--;
			}
			if( mp[ arr[rht]-1 ] < mp[ arr[rht] ] )
			{
				cnt--;
			}
			if( mp[ arr[rht] ] < mp[ arr[rht]+1 ] )
			{
				cnt--;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
