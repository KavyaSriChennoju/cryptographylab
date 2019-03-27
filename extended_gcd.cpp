#include<gmp.h>
void find_gcd(mpz_t a,mpz_t b,mpz_t x,mpz_t y,mpz_t gcd )
{
	if(mpz_sgn(a)==0)
	{
		mpz_set_str(x,"0",10);
		mpz_set_str(y,"1",10);
		mpz_set(gcd,b);
		return;
	}
	mpz_t x1,y1;
	mpz_init(x1);
	mpz_init(y1);
	mpz_t bmoda;
	mpz_init(bmoda);
	mpz_mod(bmoda,b,a);																												
	find_gcd(bmoda,a,x1,y1,gcd);


	mpz_t temp1,temp2;
	mpz_init(temp1);
	mpz_init(temp2);
	mpz_tdiv_q(temp1,b,a);
	mpz_mul(temp2,temp1,x1);
	mpz_sub(x,y1,temp2);
	mpz_set(y,x1);
}
int main()
{
	mpz_t gcd,a,b,x,y;
	mpz_init(a);
	mpz_init(b);
	mpz_init(x);
	mpz_init(y);
	mpz_init(gcd);
	gmp_printf("enter numbers \n");
	gmp_scanf("%Zd %Zd",a,b);
	find_gcd(a,b,x,y,gcd);
	gmp_printf("Gcd is %Zd \n",gcd);
	gmp_printf("x y = %Zd %Zd",x,y);
}