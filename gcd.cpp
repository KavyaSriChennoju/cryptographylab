#include<gmp.h>
void find_gcd(mpz_t a,mpz_t b,mpz_t gcd)
{
	if(mpz_sgn(a)==0)
	{
		mpz_set(gcd,b);
		return;
	}
	else if(mpz_sgn(b)==0)
	{
		mpz_set(gcd,a);
		return;
	}
	mpz_t temp;
	mpz_init(temp);
	mpz_set(temp,b);
	mpz_mod(b,a,temp);
	mpz_set(a,temp);
	find_gcd(a,b,gcd);
}
int main()
{
	mpz_t gcd,a,b;
	mpz_init(a);
	mpz_init(b);
	mpz_init(gcd);
	gmp_printf("enter numbers \n");
	gmp_scanf("%Zd %Zd",a,b);
	find_gcd(a,b,gcd);
	mpz_abs(gcd,gcd);
	gmp_printf("Gcd is %Zd \n",gcd);
}