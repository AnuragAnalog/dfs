#include<iostream>
using namespace std;
template<class T>
int lsearch(T b[20],T x,int n)
{
	int k;
	for(k=0;k<n;k++)
	{
		if(b[k]==x)
		return (1);
	}
	return (0);
}
main()
{
	int a[20],in,ikey;
	int i,ifound;
	cout<<"enter no.of elements to be entered\n";
	cin>>in;
	cout<<"enter elements\n";
	for(i=0;i<in;i++)
	cin>>a[i];
	cout<<"enter element to be searched\n";
	cin>>ikey;
	ifound=lsearch(a,ikey,in);
	if(ifound==1)
	cout<<"element is present\n";
	else
	cout<<"no element is present\n";
}
