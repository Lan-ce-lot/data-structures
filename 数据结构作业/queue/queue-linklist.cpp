/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description: eg:1-7
 ************************************************************************/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;

queue <int> q;

typedef int Status;
//��
#define ERROR 0
#define OK 1
#define OVERFLOW -2



template <typename Ele>
struct _Queue
{
    typedef struct QNode
    {
        Ele data;
        struct QNode *next;
    } QNode, *LinkQueue;

    LinkQueue front;
    LinkQueue rear;
    Ele e;

    Status InitQueue()
    {
        rear = front = (LinkQueue)malloc(sizeof(QNode));

        if (!front)
            exit(OVERFLOW);

        rear->next = front->next;
        return OK;
    }

    void DestroyQueue()
    {
        LinkQueue L = front;
        while (!Qempty())
        {
            front = front->next;
            free(L);
            L = front;
        }
        rear = NULL;
    }

    Status clear()
    {
        LinkQueue L = front;
        while (!Qempty())
        {
            front = front->next;
            free(L);
            L = front;
        }
        front = rear;
    }


    bool Qempty()
    {
        return rear == front;
    }

    int Qlength()
    {
        int Len = 0;
        LinkQueue L = front;
        while (L)
        {
            L = L->next;
            Len++;
        }
        return Len - 1;
    }

    Status GetHead(Ele &e)
    {
        e = front->next->data;
        return Qempty() ? ERROR : OK;
    }

    Status EnQueue(Ele e)
    {

        rear->next = (LinkQueue)malloc(sizeof (QNode));
        if (!rear->next)
            return ERROR;
        rear = rear->next;
        rear->data= e;

        return OK;
    }

    Status DeQueue(Ele &e)
    {
        if (!Qempty())
        {
            LinkQueue L = front;
            front = front->next;
            free(L);
            return OK;
        }

        return ERROR;
    }

    Status QTraverse()
    {
        LinkQueue L = front;
        cout << "����:";
        while (L != rear)
        {
            cout << L->next->data << ' ';
            L = L->next;
        }
        cout << endl << endl;
    }
};

_Queue<int> Q;
//��������


int main()
{
    int e, n;
    cout << "1:��ʼ��\n" << "2:���\n" << "3:����\n" << "4:����\n" << "5:���\n" << "6:��\n"  << "7:����\n";
    while (1)
    {
        int e;
        cin >> n;
        switch(n)
        {
        case 1:cout << "1:��ʼ��\n";Q.InitQueue();break;
        case 2:cout << "2:���\n";cin >> e ;Q.EnQueue(e);Q.QTraverse();break;
        case 3:cout << "3:����\n";Q.DeQueue(e);Q.QTraverse();break;
        case 4:cout << "4:����:";cout << Q.Qlength() << endl;break;
        case 5:cout << "5:���\n";Q.clear();break;
        case 6:cout << "6:��\n" << (Q.Qempty() ? "��" : "�ǿ�") << endl;break;
        case 7:cout << "7:����\n";Q.QTraverse();break;
        };



    }
    Q.InitQueue();
    Q.EnQueue(2);
    Q.EnQueue(3);
    Q.EnQueue(4);
    Q.QTraverse();
    cout << "����" <<Q.Qlength() << endl;
    Q.DeQueue(e);

    Q.QTraverse();
    Q.DeQueue(e);
    Q.QTraverse();
    cout << (Q.Qempty() ? "��" : "�ǿ�") << endl;
    Q.DeQueue(e);
    cout << (Q.Qempty() ? "��" : "�ǿ�") << endl;
    return 0;
}
