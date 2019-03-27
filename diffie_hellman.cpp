#include <bits/stdc++.h>
#include <gmp.h>
#include <gmpxx.h>
using namespace std;
#define gmt get_mpz_t()

int main(int argc, char const *argv[])
{
	mpz_class g,a,b,p,pa,pb,key1,key2;
	cin>>p>>g;
	gmp_randstate_t state;
	gmp_randinit_mt(state);
	gmp_randseed_ui(state,time(NULL));
	mpz_urandomb(a.gmt,state,10);
	mpz_urandomb(b.gmt,state,10);
	cout<<a<<" "<<b<<endl;
	mpz_powm(pa.gmt,g.gmt,a.gmt,p.gmt);
	mpz_powm(pb.gmt,g.gmt,b.gmt,p.gmt);
	cout<<pa<<" "<<pb<<endl;
	mpz_powm(key2.gmt,pa.gmt,b.gmt,p.gmt);
	mpz_powm(key1.gmt,pb.gmt,a.gmt,p.gmt);
	cout<<key1<<" "<<key2<<endl;
	return 0;
}