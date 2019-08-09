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
    查找递归
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
    //迭代
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
    查找最小元素
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
    查找最大元素迭代
     ************************************************************************/
    Position FindMax(BinTree BST)
    {
        if (BST)
            while (BST->Right)
                BST = BST->Right;
        return BST;
    }

    /*************************************************************************
    插入和查找相似
    ************************************************************************/

    BinTree Insert(ElementType X, BinTree BST)
    {
        if (!BST)//空树生成
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
    删除
    ************************************************************************/
    BinTree Delete(ElementType X, BinTree BST)
    {
        Position Tmp;

        if (!BST)
            puts("未找到");
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
    中序遍历(Inorder Traversal (LDR))
    非递归实现：
    在二叉树中，中序遍历首先遍历左子树，
    然后访问根结点，最后遍历右子树。
            A
          /   \
          B    C
         / \  /
        D   E F
    结果：DBEAFC
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
    先序遍历的非递归算法
    按照根左右的顺序沿一定路径经过路径上所有的结点。
    在二叉树中，先根后左再右。巧记：根左右。
        A
      /   \
      B    C
     / \  /
    D   E F
    结果：ABDECF
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
                //区别在这里
                T = T->Right;
            }
        }
    }

    /*************************************************************************
    后序遍历的非递归算法
    后序遍历（LRD）是二叉树遍历的一种，
    也叫做后根遍历、后序周游，可记做左右根。
    后序遍历有递归算法和非递归算法两种。
    在二叉树中，先左后右再根，即首先遍历左子树，
    然后遍历右子树，最后访问根结点。
            A
          /   \
          B    C
         / \  /
        D   E F
    结果：DEBFCA
    已知前序遍历和中序遍历，就能确定后序遍历。
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
    层序遍历(bfs?)的非递归算法
    队列实现
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
主函数
 ************************************************************************/
int main()
{
	B.BST = B.Insert(5, B.BST);
    B.BST = B.Insert(10, B.BST);
    B.BST = B.Insert(2, B.BST);
    B.BST = B.Insert(1, B.BST);
    B.BST = B.Insert(3, B.BST);
    B.BST = B.Insert(6, B.BST);
    puts("\n中序遍历");
    B.InOrderTraversal(B.BST);
    puts("\n层序遍历");
    B.LevelOrderTraversal(B.BST);//
    puts("\n先序遍历");
    B.PreOrderTraversal(B.BST);
    puts("\n后序遍历");
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
