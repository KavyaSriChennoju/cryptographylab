#include <bits/stdc++.h>
#include <gmp.h>
#include <gmpxx.h>
using namespace std;
#define gmt get_mpz_t()
int main(int argc, char const *argv[])
{
	mpz_class m,n,p,q,phi_n,e,d;
	gmp_randstate_t state;
	gmp_randinit_mt(state);
	gmp_randseed_ui(state,time(NULL));
	int flag=0;
	mpz_urandomb(p.get_mpz_t(),state,10);
	while(flag==0)
	{
		mpz_nextprime(p.get_mpz_t(),p.get_mpz_t());
		flag=mpz_probab_prime_p(p.gmt,25);
	}
	flag=0;
	mpz_urandomb(q.get_mpz_t(),state,10);
	while(flag==0)
	{
		mpz_nextprime(q.get_mpz_t(),q.get_mpz_t());
		flag=mpz_probab_prime_p(q.gmt,25);
	}
	n=p*q;
	phi_n=(p-1)*(q-1);
	mpz_class gcd=0;
	while(gcd!=1)
	{
		mpz_urandomb(e.gmt,state,10);
		mpz_gcd(gcd.gmt,e.gmt,phi_n.gmt);
	}
	mpz_invert(d.gmt,e.gmt,phi_n.gmt);
	cout<<(e*d)%phi_n<<endl;
	cout<<"Emter message \n";
	cin>>m;
	cout<<"encrypted message \n";
	mpz_powm(m.gmt,m.gmt,e.gmt,n.gmt);
	cout<<m<<endl;
	cout<<"Decrypted message \n";
	mpz_powm(m.gmt,m.gmt,d.gmt,n.gmt);
	cout<<m<<endl;

	return 0;
}
