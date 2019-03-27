#include<bits/stdc++.h>
#include<gmpxx.h>
using namespace std;
class poly{
public:
	int degree;
int prime;
vector<mpz_class>coe;
	poly()
	{
		degree=0;prime=0;
		coe.clear();

	}
};

void input(poly &a)
{
	cin>>a.degree;
	cin>>a.prime;
	a.coe.resize(a.degree+1);
	cout<<"Enter coefficients:";
	for(int i=0;i<=a.degree;i++)
	{
		cin>>a.coe[i];
	}
}

void output(poly& a)
{
	cout<<"degree:"<<a.degree<<endl;
	for (int i = a.degree; i >=0; i--)
	{
		cout<<a.coe[i]<<" x"<<i<<"\n";
		/* code */
	}
	cout<<endl;
}
poly add(poly& a,poly &b)
{

	poly c;
	if(a.prime!=b.prime)
	{
		cout<<"not possible";return c;
	}
	c.degree=max(a.degree,b.degree);
	c.coe.resize(c.degree+1);
	int i;
	for (i = 0; i <= min(a.degree,b.degree); ++i)
	{
		c.coe[i]=(a.coe[i]+b.coe[i])%a.prime;
	}
	for(;i<=a.degree;++i)
	{
		c.coe[i]=(a.coe[i])%a.prime;
	}
	for(;i<=b.degree;++i)
	{
		c.coe[i]=(b.coe[i])%a.prime;
	}
	return c;
}
poly mul(poly& a,poly &b)
{

	poly c;
	if(a.prime!=b.prime)
	{
		cout<<"not possible";return c;
	}
	c.degree=(a.degree+b.degree);
	c.coe.resize(c.degree+1);
	
	for (int i = 0; i <= a.degree; ++i)
	{
		for (int j= 0; j<=b.degree; ++j)
		{
			c.coe[i+j]=(c.coe[i+j]+a.coe[i]*b.coe[j])%a.prime;
		}
		
	}
	return c;
}
int main(int argc, char const *argv[])
{
	poly pol1,pol2,pol3;
	input(pol1);
	input(pol2);
	cout<<"Addition:\n";
	pol3=add(pol1,pol2);
    
	output(pol3);
	cout<<"Multiplication:\n";
	pol3=mul(pol1,pol2);
	output(pol3);
	return 0;
}