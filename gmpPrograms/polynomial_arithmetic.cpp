#include<stdio.h>
#include<gmp.h>
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a[8],b[8],c[8][8],m[8],ans[8];
	memset(a,0,4*8);
	memset(b,0,4*8);
	memset(m,0,4*8);
	memset(ans,0,4*8);
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++) { c[i][j]=0; }
	}

	cout<<"Enter irreducible polynomial coefficients : \n";
	for(int i=7;i>=0;i--) { cin>>m[i]; }

	cout<<"Enter first polynomial coefficients : \n";
	for(int i=7;i>=0;i--) { cin>>a[i]; }
	cout<<"Enter second polynomial coefficients : \n";
	for(int i=7;i>=0;i--) { cin>>b[i]; }

	cout<<"Addition and Subtraction result : \n";
	for(int i=7;i>=0;i--) { cout<<(a[i]^b[i])<<" "; }
	cout<<"\n\n";

	// Multiplication
	for(int i=0;i<8;i++) { c[0][i] = a[i]; }

	for(int i=1;i<8;i++)
	{
		for(int j=7;j>0;j--) { c[i][j] = c[i-1][j-1]; }
		c[i][0]=0;
		
		if(c[i-1][7])
		{
			for(int j=0;j<7;j++)
			{ c[i][j] = (c[i][j]^m[j]); }
		}
	}

	for(int i=7;i>=0;i--)
	{
		if(b[i])
		{
			for(int j=0;j<8;j++)
			{
				ans[j] = (ans[j]^c[i][j]);
			}
		}
	}

	cout<<"Multiplication result : \n";
	for(int i=7;i>=0;i--) { cout<<ans[i]<<" "; }
	cout<<"\n";

	return 0;
}