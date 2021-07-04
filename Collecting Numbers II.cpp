#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m,i,j,tmp,lft,rht,cnt=0;
	cin>>n>>m;
	vector<int>pos(n+2,1e9);
	pos[0]=0;
	pos[n+1]=n+1;
	vector<int>arr(n+1);
	for(i=1;i<=n;i++)
	{
		cin>>arr[i];
		pos[ arr[i] ] = i;
		if( pos[arr[i]-1] > pos[ arr[i] ] ) cnt++;
	}
	//cout<<cnt<<endl;
	cnt++;
	while(m--)
	{
		cin>>lft>>rht;
		if(abs(arr[lft]-arr[rht]) == 1 )
		{
			if(arr[lft]<arr[rht])
			{
				if( pos[ arr[lft]-1 ] < pos[ arr[lft] ] ) cnt++;
				if( pos[ arr[lft] ] < pos[ arr[lft]+1 ] ) cnt++;
				if( pos[ arr[rht] ] < pos[ arr[rht]+1 ] ) cnt++;
			}
			else
			{
				if( pos[ arr[rht]-1 ] < pos[ arr[rht] ] ) cnt++;
				if( pos[ arr[rht] ] < pos[ arr[rht]+1 ] ) cnt++;
				if( pos[ arr[lft] ] < pos[ arr[lft]+1 ] ) cnt++;
			}
		}
		else
		{
			if( pos[ arr[lft]-1 ] < pos[ arr[lft] ] ) cnt++;
			if( pos[ arr[lft] ] < pos[ arr[lft]+1 ] ) cnt++;
			if( pos[ arr[rht]-1 ] < pos[ arr[rht] ] ) cnt++;
			if( pos[ arr[rht] ] < pos[ arr[rht]+1 ] ) cnt++;
		}

		pos[ arr[lft] ] = rht;
		pos[ arr[rht] ] = lft;
		swap(arr[lft],arr[rht]);

		if(abs(arr[lft]-arr[rht]) == 1 )
		{
			if(arr[lft]<arr[rht])
			{
				if( pos[ arr[lft]-1 ] < pos[ arr[lft] ] ) cnt--;
				if( pos[ arr[lft] ] < pos[ arr[lft]+1 ] ) cnt--;
				if( pos[ arr[rht] ] < pos[ arr[rht]+1 ] ) cnt--;
			}
			else
			{
				if( pos[ arr[rht]-1 ] < pos[ arr[rht] ] ) cnt--;
				if( pos[ arr[rht] ] < pos[ arr[rht]+1 ] ) cnt--;
				if( pos[ arr[lft] ] < pos[ arr[lft]+1 ] ) cnt--;
			}
		}
		else
		{
			if( pos[ arr[lft]-1 ] < pos[ arr[lft] ] ) cnt--;
			if( pos[ arr[lft] ] < pos[ arr[lft]+1 ] ) cnt--;
			if( pos[ arr[rht]-1 ] < pos[ arr[rht] ] ) cnt--;
			if( pos[ arr[rht] ] < pos[ arr[rht]+1 ] ) cnt--;
		}
		cout<<cnt<<endl;

	}
	
	return 0;
}
