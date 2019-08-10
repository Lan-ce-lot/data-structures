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
		int p = (i - 1) / 2;													//p Ϊ���ڵ���
		if(heap[p] <= x)break;													//���ӽڵ�û�д�С�ߵ����˳�
		heap[i] = heap[p];														//���ӻ���
		i = p;
	}
	heap[i] = x;
 }

int pop()
{
	int ret = heap[0];															//*min_element() ����ֵ
	int x = heap[--sz];															//���һ�����ᵽ��
	int i = 0;
	while(i * 2 + 1 < sz)														//�Ӹ���ʼ���½�����
	{
		int a = i * 2 + 1,b = i * 2 + 2;										//ȡ����С���ӽڵ�
		if(b < sz && heap[b] < heap[a] )
		a = b;
		if(heap[a] >= x)														//���ӽڵ��С�ߵ����˳�
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
