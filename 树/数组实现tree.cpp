/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:
 ************************************************************************/
#include <bits/stdc++.h>

using namespace std;
#define lowbit(x) (x & -x)
#define debug(a) cout << "*" << a << "*" << endl

const int maxn = 1e5 + 5;

typedef int ElemType;

class BinTree
{
public:
    ElemType a[maxn];
    void creat_BinTree(int node = 1)
    {
        cout << "(����ڵ���ֵ((������0ʱ����ʾ�ڵ㲻����))" << endl;
        cin >> a[node];
        if (!a[node])
            return;
        cout << "\n����" << a[node] << "������";
        creat_BinTree(node * 2);
        cout << "\n����" << a[node] << "���Һ���";
        creat_BinTree(node * 2 + 1);
    }
    void preorder(int node = 1)
    {
        if (!a[node])
            return;
        cout << ' ' << a[node] << ' ';
        preorder(node * 2);
        preorder(node * 2 + 1);

    }
    void inorder(int node = 1)
    {
        if (!a[node])
            return;
        preorder(node * 2);
        cout << ' ' << a[node] << ' ';
        preorder(node * 2 + 1);

    }
    void postorder(int node = 1)
    {
        if (!a[node])
            return;
        preorder(node * 2);
        preorder(node * 2 + 1);
        cout << ' ' << a[node] << ' ';
    }
    void levelorder(int node = 1)
    {
        for (int i = 1, co = 1; co <= BinTree_count(); i++)
        {
            if (!a[i])continue;
            cout << ' ' << a[i] << ' ';
            co++;
        }
    }
    int BinTree_hight(int node = 1)
    {
        if (!a[node])
            return 0;
        int l_hight = BinTree_hight(node * 2) +1;
        int r_hight = BinTree_hight(node * 2 + 1) + 1;
        return max(l_hight, r_hight);
    }
    int BinTree_count(int node = 1)
    {
        if (!a[node])
            return 0;
        return BinTree_count(node * 2) + BinTree_count(node * 2 + 1) + 1;
    }
//    void BinTree_rever(int node = 1)
//    {
//        if (!a[node])
//            return;
//        ElemType temp = a[node * 2];
//        a[node * 2] = a[node * 2 + 1];
//        a[node * 2 +1] = temp;
//        BinTree_rever(node * 2);
//        BinTree_rever(node * 2 + 1);
//    }
//����lowbit����ͣ�����2^(n - 1),���ÿ����Ҫ���ĸ���n
    void BinTree_rever(int node = 1)
    {
        cout << "��ת" <<endl;
        for (int i = 0; i < BinTree_hight(); i++)
        {
            int temp = (2 << i + 2)  - (2 << i) - 1;
            for (int j = (2 << i), t = 1; t < (2 << i); j++, t++)
            {
                swap(a[j], a[temp - j]);
            }
        }
    }
} BT;

int main()
{
    BT.creat_BinTree();
    BT.preorder();
    cout << endl << BT.BinTree_hight() << endl;
    cout << BT.BinTree_count() << endl;
    cout << "����\n";
    BT.levelorder();
    BT.BinTree_rever(1);
    cout << "����\n";
    BT.levelorder();
    return 0;
}

