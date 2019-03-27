#include<bits/stdc++.h>
#include<gmpxx.h>
using namespace std;
mpz_class gcd(mpz_class a,mpz_class b)
{
	if(a==0)return b;
	return gcd(b%a,a);
}
int main()
{
	int n;
	cin>>n;
	mpz_class num[n],rem[n],inverse[n],pp[n],ans=0;
	mpz_class N=1;

	
	for(int i=0;i<n;i++)
	{
		cin>>num[i]>>rem[i];
		N=N*num[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j< n; j++)
		{
			if((i!=j) && gcd(num[i],num[j])!=1){cout<<"not possible"; return 0;}
		}
	}
	for(int i=0;i<n;i++)
	{
		pp[i]=N/num[i];
		mpz_invert(inverse[i].get_mpz_t() ,pp[i].get_mpz_t(),num[i].get_mpz_t());
		ans=ans+(pp[i]*inverse[i]*rem[i]);
	}
	cout<<ans%N<<"\n";
}