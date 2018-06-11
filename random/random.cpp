#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>
int main()
{
	freopen("ran.txt","w",stdout);
	cout<<1<<endl;
	int n=rand()%100000;
	cout<<n<<endl;
	for(int i=0;i<n;++i)
		cout<<rand()%10000000<<' '<<rand()%10000000<<endl;
	int q=rand()%100000;
	cout<<q<<endl;
	for (int i=0;i<q;++i)
		cout<<rand()%10000000<<endl;
}
