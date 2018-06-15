//============================================================================
// Name        : CombSum.cpp
// Author      : fabrice
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<vector>
#include<stack>
using namespace std;
/*
Author: RANAMPY Fabrice Guyau
Version: 1.0
*/
static std::vector<int> a;

 int n,to,t,from;
//////////////////////////////////////
////////////////////////////////////////

void comb(int st,int sum)
{
	int i=0,s=sum;

	for(i=st;i<=n;i++)
	{
		sum+=i;
		a.push_back(i);
		if(sum==n)
		{
			for(int item:a)
				std::cout<<item<<" ";
			std::cout<<"\n";
			break;
		}
		else if(sum>n)
			break;
		else
			comb(i,sum);
		sum=s;
	}

	to= a.size();
	t=to-2;
	from=t>0?t:0;
	a.erase(a.begin()+from,a.begin()+to);
}
//////////////////////////////////////////
struct data{
	int psum;
	int st;
};
std::stack<data> stk;

void comb()
{
	int i=1,sum=0;
	struct data tmp= {sum,i};
	stk.push(tmp);

	while(!stk.empty())
	{

	   struct data	tmp1=stk.top();
		i=tmp1.st;
		sum=tmp1.psum;
		stk.pop();
		while(true)
			{
				sum+=i;
				a.push_back(i);
				if(sum==n)
				{
					for(int it:a)
					{
						std::cout<<it<<" ";

					}
					std::cout<<std::endl;
				}
				else if(sum<n)
				{

				   struct data  tmp{sum-i,i+1};
				    stk.push(tmp);
				    continue;

				}
				to=a.size();
				t=to-2;
				from=t>0?t:0;
				a.erase(a.begin()+from,a.begin()+to);
				break;
	       }
	}
}
////////////////////////////////////////////
int main() {
	n=50;
	std::cout<<"Possible combination are:"<<std::endl;
	comb();
	
	return 0;
}
