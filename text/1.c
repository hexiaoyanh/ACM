#include<stdio.h>
#include<iostream>
#include <map>
#include <stdlib.h>
#include <vector>
using namespace std;
int main(int argc, char const *argv[])
{
	int j=0;
    while(j++<10)
    {
               printf("%d------",j);
               for(int i=0;i<1000000000l;i++)
               		printf("\r\033k"); 
    }
	return 0;
}
