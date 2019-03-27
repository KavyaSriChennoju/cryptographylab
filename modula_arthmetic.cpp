#include<gmp.h>

void modular_arthmetic(mpz_t a,mpz_t b,mpz_t n)
{
	mpz_t temp1,temp2,temp3,temp4,lftres,rtres,inverse;
	mpz_init(temp1);
	mpz_init(temp2);
	mpz_init(temp3);
	mpz_init(temp4);
	mpz_init(inverse);
	mpz_init(lftres);
	mpz_init(rtres);
	mpz_mod(temp1,a,n);
	mpz_mod(temp2,b,n);

	mpz_add(temp3,temp1,temp2);
	mpz_mod(lftres,temp3,n);
	mpz_add(temp4,a,b);
	mpz_mod(rtres,temp4,n);
	gmp_printf("result of addition is %Zd, %Zd\n",lftres,rtres);


	mpz_sub(temp3,temp1,temp2);
	mpz_mod(lftres,temp3,n);
	mpz_sub(temp4,a,b);
	mpz_mod(rtres,temp4,n);
	gmp_printf("result of subtraction is %Zd, %Zd\n",lftres,rtres);

	mpz_mul(temp3,temp1,temp2);
	mpz_mod(lftres,temp3,n);
	mpz_mul(temp4,a,b);
	mpz_mod(rtres,temp4,n);
	gmp_printf("result of multiplication is %Zd, %Zd\n",lftres,rtres);


	mpz_invert(inverse,temp2,n);
	mpz_mul(temp3,temp1,inverse);
	mpz_mod(lftres,temp3,n);
	mpz_invert(inverse,b,n);
	mpz_mul(temp4,a,inverse);
	mpz_mod(rtres,temp4,n);
	gmp_printf("result of division is %Zd, %Zd\n",lftres,rtres);
	

}
int main()
{
	mpz_t gcd,a,b,n;
	mpz_init(a);
	mpz_init(b);
	mpz_init(n);
	gmp_printf("enter numbers \n");
	gmp_scanf("%Zd %Zd %Zd",a,b,n);
	modular_arthmetic(a,b,n);
}