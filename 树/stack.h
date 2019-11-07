/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:
 ************************************************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double pi = acos(-1.0);
const int eps = 1e-10;
const int mod = 1e9 + 7;
#define debug(a) cout << "*" << a << "*" << endl

template <typename ElementType>
struct _Stack
{
    typedef struct SNode
    {
        ElementType Data[maxn];
        int base = 0;
        int top = 0;

    }*Stack;

    Stack PtrS = (Stack)malloc(sizeof(SNode));

    void push(ElementType e)
    {
        PtrS->Data[++(PtrS->top)] = e;

    }

    ElementType pop()
    {
        return (PtrS->Data[(PtrS->top)--]);
    }

    void clear()
    {
        PtrS->top = 0;
    }

    void destroystack()
    {
        free(PtrS->Data);
        PtrS->top = 0;
    }

    ElementType gettop()
    {
        return (PtrS->Data[(PtrS->top)]);
    }
    bool empty()
    {
        return bool(!PtrS->top);
    }
    void print()
    {
        int i = 1;
        while (i <= PtrS->top)
        {
            outnode(PtrS->Data[i]);
            //cout << PtrS->Data[i] << (i == PtrS->top ? "\n" : "->");
            i++;
        }
    }
};
