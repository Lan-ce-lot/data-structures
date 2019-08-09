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
int a[maxn];

typedef struct TreeNode *BinTree;
typedef BinTree Position;
typedef int ElementType;
struct TreeNode
{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

class __BST
{
public:

    BinTree BST = NULL;
    /*************************************************************************
    ���ҵݹ�
    ************************************************************************/
    Position Find(ElementType X, BinTree BST)
    {
        if (!BST)
            return NULL;
        if (X > BST->Data)
            return Find(X, BST->Right);
        else if (X < BST->Data)
            return Find(X, BST->Left);
        else
            return BST;
    }
    //����
    Position Find1(ElementType X, BinTree BST)
    {
        if (!BST)
            return NULL;
        if (X > BST->Data)
            return Find1(X, BST->Right);
        else if (X < BST->Data)
            return Find1(X, BST->Left);
        else
            return BST;
    }
    /*************************************************************************
    ������СԪ��
     ************************************************************************/
    Position FindMin(BinTree BST)
    {
        if (!BST)
            return NULL;
        else if (!BST->Left)
            return BST;
        else
            return FindMin(BST->Left);
    }
    /*************************************************************************
    �������Ԫ�ص���
     ************************************************************************/
    Position FindMax(BinTree BST)
    {
        if (BST)
            while (BST->Right)
                BST = BST->Right;
        return BST;
    }

    /*************************************************************************
    ����Ͳ�������
    ************************************************************************/

    BinTree Insert(ElementType X, BinTree BST)
    {
        if (!BST)//��������
        {
            BST = (BinTree)malloc(sizeof(struct TreeNode));
            BST->Data = X;
            BST->Left = BST->Right = NULL;

        }
        else
        {
            if (X < BST->Data)
                BST->Left = Insert(X, BST->Left);
            else if (X > BST->Data)
                BST->Right = Insert(X, BST->Right);
        }
        return BST;
    }
    /*************************************************************************
    ɾ��
    ************************************************************************/
    BinTree Delete(ElementType X, BinTree BST)
    {
        Position Tmp;

        if (!BST)
            puts("δ�ҵ�");
        else if (X < BST->Data)
            BST->Left = Delete(X, BST->Left);
        else if (X > BST->Data)
            BST->Right = Delete(X, BST->Right);
        else if (BST->Left && BST->Right)
        {
            Tmp = FindMin(BST->Right);
            BST->Data = Tmp->Data;
            BST->Right = Delete(BST->Data, BST->Right);
        }
        else
        {
            Tmp = BST;
            if (!BST->Left)
                BST = BST->Right;
            else if (!BST->Right)
                BST = BST->Left;
            free(Tmp);
        }
        return BST;
    }
    /*************************************************************************
    �������(Inorder Traversal (LDR))
    �ǵݹ�ʵ�֣�
    �ڶ������У�����������ȱ�����������
    Ȼ����ʸ���㣬��������������
            A
          /   \
          B    C
         / \  /
        D   E F
    �����DBEAFC
    *************************************************************************/
    void InOrderTraversal(BinTree BT)
    {
        BinTree T = BT;
        stack<BinTree> S;
        while (T || !S.empty())
        {
            while(T)
            {
                S.push(T);
                T = T->Left;
            }
            if (!S.empty())
            {
                T = S.top();
                S.pop();
                printf("%5d", T->Data);
                T = T->Right;
            }
        }
    }
    /*************************************************************************
    ��������ķǵݹ��㷨
    ���ո����ҵ�˳����һ��·������·�������еĽ�㡣
    �ڶ������У��ȸ��������ҡ��ɼǣ������ҡ�
        A
      /   \
      B    C
     / \  /
    D   E F
    �����ABDECF
    ************************************************************************/
    void PreOrderTraversal(BinTree BT)
    {
        BinTree T = BT;
        stack<BinTree> S;
        while (T || !S.empty())
        {
            while(T)
            {
                S.push(T);
                printf("%5d", T->Data);//
                T = T->Left;
            }
            if (!S.empty())
            {
            	T = S.top();
                S.pop();
                //����������
                T = T->Right;
            }
        }
    }

    /*************************************************************************
    ��������ķǵݹ��㷨
    ���������LRD���Ƕ�����������һ�֣�
    Ҳ��������������������Σ��ɼ������Ҹ���
    ��������еݹ��㷨�ͷǵݹ��㷨���֡�
    �ڶ������У���������ٸ��������ȱ�����������
    Ȼ������������������ʸ���㡣
            A
          /   \
          B    C
         / \  /
        D   E F
    �����DEBFCA
    ��֪ǰ��������������������ȷ�����������
     ************************************************************************/
	void PostOrderTraversal(BinTree BT)
	{
		if (BT)
		{
			PostOrderTraversal(BT->Left);
			PostOrderTraversal(BT->Right);
			printf("%5d", BT->Data);
		}
	 } 
    /*************************************************************************
    �������(bfs?)�ķǵݹ��㷨
    ����ʵ��
    ************************************************************************/

    void LevelOrderTraversal(BinTree BT)
    {
        queue<BinTree> Q;
        BinTree T;
        Q.push(BT);
        while (!Q.empty())
        {
        	T = Q.front();
            Q.pop();
            printf("%d\n", T->Data);
            if (T->Left)
                Q.push(T->Left);
            if (T->Right)
                Q.push(T->Right);
        }
    }
};

__BST B;

/*************************************************************************
������
 ************************************************************************/
int main()
{
	B.BST = B.Insert(5, B.BST);
    B.BST = B.Insert(10, B.BST);
    B.BST = B.Insert(2, B.BST);
    B.BST = B.Insert(1, B.BST);
    B.BST = B.Insert(3, B.BST);
    B.BST = B.Insert(6, B.BST);
    puts("\n�������");
    B.InOrderTraversal(B.BST);
    puts("\n�������");
    B.LevelOrderTraversal(B.BST);//
    puts("\n�������");
    B.PreOrderTraversal(B.BST);
    puts("\n�������");
	B.PostOrderTraversal(B.BST);
    return 0;
}
//    1    2    3    5    6   10
//5
//2
//10
//1
//3
//6
//
//    5    2    1    3   10    6
