#include <stdio.h>
int main(int argc, char const *argv[])
{
	for(char i='x';i<='z';++i)
		for(char j='x';j<='z';++j)
		{
			if(i!='x' && i!=j)
			for(char k='x';k<='z';++k)
			{
				if(i!=k && j!=k)
				{
					if(i!='x' && k!='x' && k!='z')
						printf("order is a--%c\tb--%c\tc--%c\n",i,j,k);
				}
			}
		}
}