#include<cstdio>
const int MAX_N = 1000001;

int N, K;
int arr[MAX_N];
int qu[MAX_N];
int index[MAX_N];
int ans[MAX_N];

void getMins()
{
	int tail = 0, head = 1;	//初始化tail<head表示为空列
	for (int i = 1; i < K; i++)	//初始化单调队列
	{
		while (tail >= head && qu[tail] >= arr[i]) tail--;
		qu[++tail] = arr[i];		//记录可能的答案值
		index[tail] = i;	//记录额外需要判断的信息
	}
	for (int i = K; i <= N; i++)
	{
		while (tail >= head && qu[tail] >= arr[i]) tail--; //不符合条件出列
		qu[++tail] = arr[i];
		index[tail] = i;
		while (index[head] <= i-K) head++;
		ans[i-K] = qu[head];	//ans从下标0开始记录
	}
}

void getMaxs()
{
	int tail = 0, head = 1;
	for (int i = 1; i < K; i++)	//初始化单调队列
	{
		while (tail >= head && qu[tail] <= arr[i]) tail--;
		qu[++tail] = arr[i];
		index[tail] = i;
	}
	for (int i = K; i <= N; i++)
	{
		while (tail >= head && qu[tail] <= arr[i]) tail--; //不符合条件出列
		qu[++tail] = arr[i];
		index[tail] = i;
		while (index[head] <= i-K) head++;
		ans[i-K] = qu[head];	//ans从下标0开始记录
	}
}

int main()
{
	while (~scanf("%d %d", &N, &K))
	{
		for (int i = 1; i <= N; i++) 
			scanf("%d", &arr[i]);
		
		getMins();
		
		for (int i = 0; i <= N-K; i++) 
			printf("%d ", ans[i]);
		
		putchar('\n');
		
		getMaxs();
		
		for (int i = 0; i <= N-K; i++) 
			printf("%d ", ans[i]);
		
		putchar('\n');
	}
	return 0;
}
