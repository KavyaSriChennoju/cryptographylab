#include <bits/stdc++.h>
#include <gmp.h>
#include <gmpxx.h>
using namespace std;
#define gmt get_mpz_t()

int main(int argc, char const *argv[])
{
	mpz_class q,g,x=0,gcd=0,y,k1=0,k,m,dk,c1,c2,kinverse;
	gmp_randstate_t state;
	gmp_randinit_mt(state);
	gmp_randseed_ui(state,time(NULL));
	cout<<"enter q,g \n";
	cin>>q>>g;
	while(x==0)
	{
		mpz_urandomb(x.gmt,state,10);
		x=x%q;
	}
	mpz_powm(y.gmt,g.gmt,x.gmt,q.gmt);
	cout<<"x= "<<x<<endl;
	cout<<"y= "<<y<<endl;
	while(gcd!=1)
	{
		while(k1==0)
		{
			mpz_urandomb(k1.gmt,state,10);
			k1=k1%q;
		}
		mpz_powm(k.gmt,y.gmt,k1.gmt,q.gmt);
		cout<<" k= "<<k<<endl;
		mpz_gcd(gcd.gmt,k.gmt,q.gmt);
	}
		mpz_powm(c1.gmt,g.gmt,k1.gmt,q.gmt);
		cout<<"enter message \n";
		cin>>m;
		c2=(k*m)%q;
		cout<<" encrypted message "<<c1<<" "<<c2<<endl;
		mpz_powm(dk.gmt,c1.gmt,x.gmt,q.gmt);
		cout<<"keys "<<k<<" "<<dk<<" \n";
		mpz_invert(kinverse.gmt,k.gmt,q.gmt);
		cout<<"decrypted message\n";
		cout<<(c2*kinverse)%q<<endl;
		return 0;

	}
