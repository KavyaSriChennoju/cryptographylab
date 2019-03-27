#include<stdio.h>
#include<gmp.h>
#include<iostream>
using namespace std;

void gcd_gen(mpz_t ans,mpz_t a,mpz_t b)
{
	if( mpz_cmpabs_ui(b,0)==0 ) { mpz_set(ans,a); return; }
	mpz_t r;
	mpz_init(r);
	mpz_mod(r,a,b);
	gcd_gen(ans,b,r);	
}


int main()
{
	mpz_t a,b,x,y;
	mpz_inits(a,b,x,y,NULL);
	gmp_randstate_t rstate;
	gmp_randinit_mt(rstate);
	gmp_randseed_ui(rstate, time(NULL));
	mpz_urandomb(a,rstate,7);
	mpz_urandomm(b,rstate,a);
	gmp_printf("a = %Zd\n",a);
	gmp_printf("b = %Zd\n",b);
	
	mpz_gcd(x,a,b);
	gmp_printf("%Zd\n",x);
	gcd_gen(y,a,b);
	gmp_printf("%Zd\n",y);
	if(mpz_cmp(x,y)==0) { cout<<"Correct\n"; }
	else { cout<<"Incorrect\n"; }
	return 0;
}
