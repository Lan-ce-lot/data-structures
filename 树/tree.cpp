/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:
 ************************************************************************/
#include <bits/stdc++.h>
#include "queue-linklist.h"
#include "stack.h"
using namespace std;
typedef long long ll;


typedef int ElemType;

class _Binarytree_create
{
private:
    typedef struct treenode
    {
        ElemType data;
        treenode *left, *right;
    }*Btree;

public:
    Btree BT;
    void CreatBiTree_pre(Btree &p)
    {
        int a = 0;
        //cout << "(输入节点数值((当输入0时，表示节点不存在))" << endl;
        cin >> a;
        if (a)
        {
            p = (Btree) malloc (sizeof(treenode));
            if (!p)
                return;
            p->data = a;
            //cout << "\n输入" << a << "的左孩子";
            CreatBiTree_pre(p->left);
            //cout << "\n输入" << a << "的右孩子";
            CreatBiTree_pre(p->right);
        }
        else
        {
            p = NULL;
        }
        return;
    }
    void CreatBT()
    {
        CreatBiTree_pre(BT);
    }
    void CreatBiTree_in(Btree &p)
    {
        int a = 0;
        cout << "(输入节点数值((当输入0时，表示节点不存在))" << endl;
        cin >> a;
        if (a)
        {
            p = (Btree) malloc (sizeof(treenode));
            if (!p)
                return;

            cout << "\n输入" << a << "的左孩子";
            CreatBiTree_pre(p->left);
            p->data = a;
            cout << "\n输入" << a << "的右孩子";
            CreatBiTree_pre(p->right);
        }
        else
        {
            p = NULL;
        }
        return;
    }
    void CreatBiTree_post(Btree &p)
    {
        int a = 0;
        cout << "(输入节点数值((当输入0时，表示节点不存在))" << endl;
        cin >> a;
        if (a)
        {
            p = (Btree) malloc (sizeof(treenode));
            if (!p)
                return;

            cout << "\n输入" << a << "的左孩子";
            CreatBiTree_pre(p->left);
            cout << "\n输入" << a << "的右孩子";
            CreatBiTree_pre(p->right);
            p->data = a;
        }
        else
        {
            p = NULL;
        }
        return;
    }
//    void CreatBT()
//    {
//        Btree p;
//        CreatBiTree(p);
//        BT = p;
//    }
    void preorder(Btree p)
    {
        if (!p)
            return;
        cout << ' ' << p->data << ' ';
        preorder(p->left);
        preorder(p->right);
        return;
    }
    void _preorder(Btree p)
    {
        _Stack<Btree> S;
        while (p || !S.empty())
        {
            while (p)
            {
                S.push(p);
                cout << ' ' << p->data << ' ';
                p = p->left;
            }
            if (!S.empty())
            {
                p = S.gettop();
                S.pop();
                p = p->right;
            }
        }
    }

    void inorder(Btree p)
    {
        if(!p)
            return;
        inorder(p->left);
        cout << ' ' << p->data << ' ';
        inorder(p->right);
        return;
    }

    void _inorder(Btree p)
    {
        _Stack<Btree> S;
        while (p || !S.empty())
        {
            while (p)
            {
                S.push(p);

                p = p->left;

            }
            if (!S.empty())
            {

                p = S.gettop();
                cout << ' ' << p->data << ' ';
                S.pop();
                p = p->right;
            }
        }
    }

    void postorder(Btree p)
    {
        if(!p)
            return;
        postorder(p->left);
        postorder(p->right);
        cout << ' ' << p->data << ' ';
        return;
    }

    void _postorder(Btree p)
    {
        _Stack<Btree> S;
        Btree r;
        while (p || !S.empty())
        {
            if (p)
            {
                S.push(p);
                p = p->left;
            }
            else
            {
                p = S.gettop();
                if (p->right && p->right != r)
                    p = p->right;
                else
                {
                    S.pop();
                    cout << ' ' << p->data << ' ';
                    r = p;
                    p = NULL;
                }
            }


        }
    }

    void levelorder(Btree p)
    {
        _Queue<Btree> q;

        q.InitQueue();
        if (!p)
            return;

        q.EnQueue(p);

        while (!q.Qempty())
        {

            q.DeQueue();
            Btree head = q.front->data;
            cout << ' ' << head->data << ' ';
            if (head->left)
            {
                q.EnQueue(head->left);
            }
            if (head->right)
            {
                q.EnQueue(head->right);
            }
        }
        puts("");
        return;
    }
    int Bit_hight(Btree p)
    {
        if (!p)
            return 0;
        int lH = Bit_hight(p->left);
        int rH = Bit_hight(p->right);
        return lH > rH ? lH + 1: rH + 1;
    }
    int Bit_count(Btree p)
    {
        if (!p)
            return 0;
        int count1 = Bit_count(p->left) + Bit_count(p->right);
        return 1 + count1;
    }
    void Bitree_reverse(Btree &p)
    {
        if (!p || !p->left || !p->right)
            return;
        Btree temp = p->left;
        p->left = p->right;
        p->right = temp;
        Bitree_reverse(p->left);
        Bitree_reverse(p->right);
    }
} Bitr;
int main()
{
    Bitr.CreatBiTree_pre(Bitr.BT);


//    cout << Bitr.Bit_hight(Bitr.BT) << endl << Bitr.Bit_count(Bitr.BT);
    cout << "\n先序";
    puts("");
    Bitr.preorder(Bitr.BT);
    puts("");
    cout << "中序";
    Bitr.inorder(Bitr.BT);
    puts("");
    cout << "后序";
    Bitr.postorder(Bitr.BT);
    puts("");
    cout << "层序";
    Bitr.levelorder(Bitr.BT);
    puts("");
//    cout << "翻转";
//    Bitr.Bitree_reverse(Bitr.BT);
//    cout << "先序";
//    Bitr.preorder(Bitr.BT);
//    puts("");
//    cout << "层序";
//    Bitr.levelorder(Bitr.BT);
//    puts("");
}//1 2 3 0 0 4 5 0 7 0 0 6 0 0 0
