#include<iostream>
using namespace std;
int main()
{
	int n,i,j,c;
	cin>>n;
	c=0;
	while(n>0)
	{
	 	j=n%10;
		c+=j;
		n=n/10;
	}
	if(c%3==0)
	cout<<"Divisible"<<"\n";
	else
	cout<<"Not divisible"<<"\n";
	return 0;
}