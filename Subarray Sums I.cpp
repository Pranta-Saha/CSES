// Imagine a cumulative sum array of given array. and forget given array.
// Now for each value of cumulative sum array(let m), find how many (m-x) have at the left of m. sum of all count is answer.
// for time efficiency I used map.
// simulate a tastcase as I said for better understanding.

#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long x,n,a,i,cnt=0,sum=0;
	map<long long,long long>mp;
	mp[0]=1;
	cin>>n>>x;
	for(i=0;i<n;i++)
	{
		cin>>a;
		sum += a;
		cnt += mp[sum-x];
		mp[sum]++;
	}
	cout<<cnt<<endl;
}
