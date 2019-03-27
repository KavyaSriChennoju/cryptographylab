#include<bits/stdc++.h>
#include<gmpxx.h>
using namespace std;
mpz_class gcdExtended(mpz_class a, mpz_class b, mpz_class  *x, mpz_class  *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }
 
    mpz_class x1, y1; // To store results of recursive call
    mpz_class gcd = gcdExtended(b%a, a, &x1, &y1);
 
    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd;
}
 
// Driver Program
int main()
{
    mpz_class x, y,a,b;
    cin>>a>>b;
    mpz_class  g = gcdExtended(abs(a), abs(b), &x, &y);
    if(a<0)x=-x;
    if(b<0)y=-y;
    cout<<g<<" "<<x<<" " <<y<<"\n";
    return 0;
}