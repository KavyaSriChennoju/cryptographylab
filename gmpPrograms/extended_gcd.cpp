#include<stdio.h>
#include<gmp.h>
#include<iostream>
using namespace std;

void extended_gcd_gen(mpz_t a, mpz_t b,mpz_t x,mpz_t y,mpz_t gcd)
{
	if(mpz_cmpabs_ui(b,0)==0) 
	{
		mpz_set(gcd,a);
		mpz_set_ui(x,1);
		mpz_set_ui(y,0);
		return; 
	}

	mpz_t x1,y1,r,t,d;
	mpz_inits(x1,y1,r,t,d,NULL);
	mpz_mod(r,a,b);
	extended_gcd_gen(b,r,x1,y1,gcd);

	mpz_set(x,y1);

	mpz_fdiv_q(d,a,b);
	mpz_mul(t,d,y1);
	mpz_sub(y,x1,t);
}

int main()
{
	mpz_t a,b,x,y,gcd;
	mpz_inits(a,b,x,y,gcd,NULL);
	// mpz_inp_str(a,stdin,10);
	// mpz_inp_str(b,stdin,10);

	int bits;
	cout<<"Enter number of bits : ";
	cin>>bits;
	gmp_randstate_t rstate;
	gmp_randinit_mt(rstate);
	gmp_randseed_ui(rstate, time(NULL));
	mpz_urandomb(a,rstate,bits);
	mpz_urandomb(b,rstate,bits);
	gmp_printf("a = %Zd\n",a);
	gmp_printf("b = %Zd\n",b);

	extended_gcd_gen(a,b,x,y,gcd);
	gmp_printf("gcd = %Zd , x = %Zd , y = %Zd\n",gcd,x,y);
	return 0;
}