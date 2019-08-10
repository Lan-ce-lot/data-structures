/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:
 ************************************************************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <cmath>
#include <sstream>
using namespace std;
typedef long long ll;
const double pi = acos(-1.0);
const int eps = 1e-10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 1005;

const int MaxData = INF;
const int MaxSize = maxn;
typedef int ElementType;
typedef struct HeapStruct *MaxHeap;
MaxHeap Create(int MaxSize);
bool IsFull(MaxHeap H);
void Insert(MaxHeap H, ElementType item);
bool IsEmpty(MaxHeap H);
ElementType DeleteMax(MaxHeap H);

/*************************************************************************
最大堆的储存，其实用一个数组进行，这里的指针等价
************************************************************************/
struct HeapStruct
{
    ElementType *Elements;//heap array
    int Size;
    int Capacity;//最大容量
};

class __MaxHeap
{
public:
    MaxHeap ele;
    /*************************************************************************
    创建一个堆
     ************************************************************************/
    MaxHeap Create(int MaxSize)
    {
        MaxHeap H = (MaxHeap)malloc(sizeof(struct HeapStruct));
        H->Elements = (ElementType*)malloc((MaxSize + 1) * sizeof(ElementType));
        H->Size = 0;
        H->Capacity = MaxSize;
        H->Elements[0] = MaxData;//哨兵，大于堆中所有可能元素
        return H;
    }
    /*************************************************************************

     ************************************************************************/
    void Insert(MaxHeap H, ElementType item)
    {
        int i;
        if (IsFull(H))
        {
            printf("最大堆已满\n");
            return;
        }
        i = ++H->Size;
        for (; H->Elements[i / 2] < item; i /= 2)
            H->Elements[i] = H->Elements[i / 2];
        H->Elements[i] = item;
    }
    /*************************************************************************

     ************************************************************************/
    ElementType DeleteMax(MaxHeap H)
    {
        int Parent, Child;
        ElementType MaxItem, temp;
        if (IsEmpty(H))
        {
            printf("最大堆空\n");
            return -1;
        }
        MaxItem = H->Elements[1];
        temp = H->Elements[H->Size--];
        for (Parent = 1; Parent * 2 <= H->Size; Parent = Child)
        {
            Child = Parent * 2;
            if ((Child != H->Size) && (H->Elements[Child] < H->Elements[Child + 1]))
                Child++;
            if (temp >= H->Elements[Child])
                break;
            else
                H->Elements[Parent] = H->Elements[Child];
        }
        H->Elements[Parent] = temp;
        return MaxItem;
    }
    /*************************************************************************

     ************************************************************************/
    bool IsFull(MaxHeap H)
    {
        return (H->Size == H->Capacity);
    }
    /*************************************************************************

     ************************************************************************/
    bool IsEmpty(MaxHeap H)
    {
        return (H->Size == 0);
    }

    /*************************************************************************

     ************************************************************************/
    void Print(MaxHeap H)
    {
        int co = 2;
        for (int i = 1; i <= H->Size; i++)
        {
            i > co - 1?puts(""),co <<= 1:i;
            printf("%d ", H->Elements[i]);
        }
        puts("\n");
        return;
    }
};

/*************************************************************************

 ************************************************************************/
int main()
{
    __MaxHeap H;
    H.ele = H.Create(MaxSize);
    H.Insert(H.ele, 5);
    H.Insert(H.ele, 4);
    H.Insert(H.ele, 10);
    H.Insert(H.ele, 8);
    H.Insert(H.ele, 7);
    H.Insert(H.ele, 9);
    H.Insert(H.ele, 6);
    H.Print(H.ele);
    H.DeleteMax(H.ele);
    H.Print(H.ele);
    H.DeleteMax(H.ele);
    H.Print(H.ele);
    H.DeleteMax(H.ele);
    H.Print(H.ele);
    H.DeleteMax(H.ele);
    H.Print(H.ele);
    H.DeleteMax(H.ele);
    H.Print(H.ele);
    H.DeleteMax(H.ele);
    H.Print(H.ele);
    H.DeleteMax(H.ele);
    H.Print(H.ele);
    H.DeleteMax(H.ele);
    H.Print(H.ele);
    return 0;
}

