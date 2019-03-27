#include<bits/stdc++.h>
using namespace std;

char en[26];
void ceaser(string &s,int shift)
{
	for(int i=0;i<s.length();i++)
	{

		if(s[i]<'a' || s[i]>'z')continue;
		s[i]=(((s[i]-97)+shift)%26)+65;
	}
	//cout<<" Cipher text using ceaser cipher---";
	cout<<s<<"\n";
	//cout<<"Decryption \n";

}
void ceaser_decrypt(string &s,int shift)
{
	for(int i=0;i<s.length();i++)
	{

		if(s[i]<'A' || s[i]>'Z')continue;
		s[i]=(((s[i]-65)+shift+26)%26)+97;
	}
	cout<<s<<"\n";
	//cout<<"Decryption \n";

}
void monoalphabetic(string &s)
{
	for(int i=0;i<26;i++)
	{
		en[i]=(i+3)%26+'A';
	}
	for (int i = 0; i < 26; i++)
	{
		int temp=rand()%26;
		swap(en[i],en[temp]);
	}
	for (int i = 0; i < 26; ++i)
	{
		cout<<en[i]<<" ";
	}
	for(int i=0;i<s.length();i++)
	{
		if(s[i]<'a' || s[i]>'z')continue;
		s[i]=en[s[i]%97];
	}
	cout<<s<<"\n";
}
void monoalphabetic_decrypt(string s)
{
	int j;
	for (int i = 0; i < s.length(); ++i)
	{
		
	for (j= 0; j < 26; ++j)
	{
		if(en[j]==s[i])break;
		/* code */
	}
	s[i]='a'+j;
}
cout<<s<<"\n";
}
int main()
{
	string s;
	cout<<"Enter the plain text \n";
	getline(cin,s);

	ceaser(s,3);
	ceaser_decrypt(s,-3);
	monoalphabetic(s);	
	monoalphabetic_decrypt(s);

}