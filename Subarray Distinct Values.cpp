//I kept the count of unique number using set for range [left,i].
//For each value of array, I increamented frequency of the value, and inserted it into set.
//If my set size is greather than k, I decreased the left-th value frequency by 1.
//If that frequency became 0, I removed the value from set.
//And for each new value, we can made (i-left+1) new subarray.

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,i,k,lft=0;
	long long cnt=0;
	cin>>n>>k;
	int arr[n];
	map<int,int>frequency;
	set<int>st;
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
		st.insert(arr[i]);
		frequency[arr[i]]++;
		while(st.size()>k)
		{
			frequency[arr[lft]]--;
			if(frequency[arr[lft]]==0)
			{
				st.erase(arr[lft]);
			}
			lft++;
		}
		cnt+=(i-lft+1);
	}
	cout<<cnt<<endl;
}

