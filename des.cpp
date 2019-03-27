#include<bits/stdc++.h>
using namespace std;
int permute_table[64],inv_table[64];
void initial_permutation(int input[],int output[])
{
	for (int i = 0; i < 64; ++i)
	{
		permute_table[i]=i;
		/* code */
	}
	for (int i = 0; i < 64; ++i)
	{
		int j=rand()%64;
		swap(permute_table[i],permute_table[j]);
		/* code */
	}
	for (int i = 0; i < 64; ++i)
	{
		if(i%8==0)cout<<"\n";
		cout<<permute_table[i]<<" ";
		/* code */
	}
	for (int i = 0; i < 64; ++i)
	{
		output[i]=input[permute_table[i]];
		/* code */
	}
}
void inverse_permutation(int input[],int output[])
{
	for (int i = 0; i < 64; ++i)
	{
		inv_table[permute_table
		/* code */
	}
}
void print(int a[])
{
	for (int i = 0; i < 64; ++i)
	{
		if(i%8==0)cout<<"\n";
		cout<<a[i]<<" ";
		/* code */
	}
}
int main(int argc, char const *argv[])
{
	int input[64],output[64];
	srand(time(NULL));
	for (int i = 0; i < 64; ++i)
	{
		input[i]=i;
		/* code */
	}
	initial_permutation(input,output);
	cout<<"permuted table\n";
	print(output);
	/* code */
	return 0;
}
