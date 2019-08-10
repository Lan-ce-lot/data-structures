#include<bits/stdc++.h>
using namespace std;
#define MAX_N 10000
//priority_queue
int heap[MAX_N],sz = 0;
void push(int x)
{
	int i = sz++;
	while(i > 0)
	{
		int p = (i - 1) / 2;													//p 为父节点编号
		if(heap[p] <= x)break;													//父子节点没有大小颠倒则退出
		heap[i] = heap[p];														//父子互换
		i = p;
	}
	heap[i] = x;
 }

int pop()
{
	int ret = heap[0];															//*min_element() 返回值
	int x = heap[--sz];															//最后一个数提到根
	int i = 0;
	while(i * 2 + 1 < sz)														//从根开始向下交换，
	{
		int a = i * 2 + 1,b = i * 2 + 2;										//取出较小的子节点
		if(b < sz && heap[b] < heap[a] )
		a = b;
		if(heap[a] >= x)														//父子节点大小颠倒则退出
		break;
		heap[i] = heap[a];														//
		i = a;

	}
	heap[i] = x;
	return ret;
}

int main()
{
	push(10);
	push(1);
	push(2);
	cout<<pop()<<endl;
	cout<<heap[0]<<endl;
	priority_queue<int> q;
	q.push(10);
	q.push(1);
	q.push(2);
	cout<<q.top()<<endl;
	q.pop();
	cout<<q.top()<<endl;
//	system("pause");
	return 0;
}
