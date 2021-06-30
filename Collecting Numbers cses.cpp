#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	set<int>st;
	for(int i=0;i<n;i++)
	{
		int m;
		cin>>m;
		if(st.find(m-1) == st.end())
		{
			st.insert(m);
		}
		else
		{
			st.erase(m-1);
			st.insert(m);
		}
	}
	cout<<st.size()<<endl;
}
