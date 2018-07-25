#include<stdio.h>
#include<iostream>
#include <stdlib.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int x=10;
	cout<<__builtin_ctz(x)<<endl;
	return 0;
}