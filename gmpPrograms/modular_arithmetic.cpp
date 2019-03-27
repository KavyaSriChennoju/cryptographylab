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
	mpz_t a,b,x,y,gcd,z,ans;
	mpz_inits(a,b,x,y,z,gcd,ans,NULL);

	int bits;
	cout<<"Enter number of bits : ";
	cin>>bits;
	gmp_randstate_t rstate;
	gmp_randinit_mt(rstate);
	gmp_randseed_ui(rstate, time(NULL));

	mpz_urandomb(a,rstate,bits);
	mpz_urandomb(b,rstate,bits);
	mpz_urandomb(y,rstate,bits);
	mpz_nextprime(z,y);

	gmp_printf("A = %Zd , B = %Zd , z = %Zd\n",a,b,z);

	extended_gcd_gen(b,z,x,y,gcd);

	mpz_invert(gcd,b,z);

	mpz_add(ans,a,b);
	mpz_mod(ans,ans,z);
	gmp_printf("A+B mod Z == %Zd\n",ans);

	mpz_sub(ans,a,b);
	mpz_mod(ans,ans,z);
	gmp_printf("A-B mod Z == %Zd\n",ans);

	mpz_mul(ans,a,b);
	mpz_mod(ans,ans,z);
	gmp_printf("A*B mod Z == %Zd\n",ans);

	mpz_mul(ans,a,x);
	mpz_mod(ans,ans,z);
	gmp_printf("A/B mod Z == %Zd\n",ans);

	return 0;
}