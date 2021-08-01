//I just look at the top of stack. If current value is greather than top of stack value, then index of top will be the answer,
//otherwise continue poping stack untill found a less value than current value.
//If stack is empty output will be 0. 

#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n,i,m;
	cin>>n;
	stack< pair<int,int> >stk;
	for(i=1;i<=n;i++)
	{
		cin>>m;
		while(!stk.empty() && stk.top().first >= m)
		       	stk.pop();
		if(stk.empty())
		       	cout<<0<<" ";
		else 
			cout<<stk.top().second<<" ";
		stk.push({m,i});
	}
	return 0;
}


