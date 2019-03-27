#include<bits/stdc++.h>
#include<gmpxx.h>
using namespace std;
class poly{
public:
	int degree;
int prime;
vector<mpz_class>coeffs;
	poly()
	{
		degree=0;prime=0;
		coeffs.clear();

	}
};

void input(poly &a)
{
	cin>>a.degree;
	cin>>a.prime;
	a.coeffs.resize(a.degree+1);
	cout<<"Enter coefficients:";
	for(int i=0;i<=a.degree;i++)
	{
		cin>>a.coeffs[i];
	}
}

void output(poly& a)
{
	out<<"degree:"<<a.degree<<endl;
	for (int i = a.degree; i >=0; i--)
	{
		cout<<a.coeffs[i]<<<<" "<<i<<" ";
		/* code */
	}
	cout<<endl;
}
void add(poly& a,poly &b)
{

	poly c;
	if(a.prime!=b.prime)
	{
		cout<<"not possible";return c;
	}
	c.degree=max(a.degree,b.degree);
	c.coeffs.resize(c.degree+1);
	int i;
	for (i = 0; i <= min(a.degree,b.degree); ++i)
	{
		c.coeffs[i]=(a.coeffs[i]+b.coeffs[i])%a.prime;
	}
	for(;i<=a.degree;++i)
	{
		c.coeffs[i]=(a.coeffs[i])%a.prime;
	}
	for(;i<=b.degree;++i)
	{
		c.coeffs[i]=(b.coeffs[i])%a.prime;
	}
	return c;
}
void mul(poly& a,poly &b)
{

	poly c;
	if(a.prime!=b.prime)
	{
		cout<<"not possible";return c;
	}
	c.degree=(a.degree+b.degree);
	c.coeffs.resize(c.degree+1);
	
	for (int i = 0; i <= a.degree; ++i)
	{
		for (int j= 0; j<=b.degree; ++j)
		{
			c.coeffs[i+j]=(c.coeffs[i+j]+a.coeffs[i]*b.coeffs[j])%a.prime;
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
	pol3=add(po11,pol2);
    
	output(pol3);
	cout<<"Multiplication:\n";
	pol3=mul(pol3,pol4);
	output(pol3);
	return 0;
}