#include <iostream>

using namespace std;

template <typename T>
class MyLinkList
{
private:
    T data;
    MyLinkList<T> *next;

public:
    MyLinkList()
    {
        data = (T)NULL;
        next = NULL;
    }

    MyLinkList(T data)
    {
        this->data = data;
        next = NULL;
    }

    MyLinkList(T data, MyLinkList<T> *ll)
    {
        this->data = data;
        next = ll;
    }

    T getData()
    {
        if (data)
            return data;
        else
            return (T)NULL;
    }

    MyLinkList<T> *getNext()
    {
        if (next)
            return next;
        else
            return NULL;
    }

    T setData(T data)
    {
        this->data = data;
        return this->data;
    }

    MyLinkList<T> *setNext(MyLinkList<T> *ll)
    {
        next = ll;
        return next;
    }

    void print()
    {
        MyLinkList<T> *temp = next;
        cout << data << " ";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

template <typename T>
void print(MyLinkList<T> *ll)
{
    while (ll != NULL)
    {
        cout << ll->getData() << " ";
        ll = ll->getNext();
    }
    cout << endl;
}

int main()
{
    MyLinkList<int> *ll1 = new MyLinkList(1);
    MyLinkList<int> *ll2 = new MyLinkList(2);
    MyLinkList<int> *ll3 = new MyLinkList(3);
    MyLinkList<int> *ll4 = new MyLinkList(4);

    ll1->setNext(ll2);
    ll2->setNext(ll3);
    ll3->setNext(ll4);

    print(ll1);
    print(ll2);
    print(ll3);
    print(ll4);
    ll1->print();
    ll2->print();
    ll3->print();
    ll4->print();

    MyLinkList<int> *ll5 = new MyLinkList(5);
    MyLinkList<int> *ll6 = new MyLinkList(6, ll5);
    MyLinkList<int> *ll7 = new MyLinkList(7, ll6);
    MyLinkList<int> *ll8 = new MyLinkList(8, ll7);

    print(ll5);
    print(ll6);
    print(ll7);
    print(ll8);
    ll5->print();
    ll6->print();
    ll7->print();
    ll8->print();

    MyLinkList<int> *head = new MyLinkList<int>;
    MyLinkList<int> *second = new MyLinkList<int>;
    MyLinkList<int> *third = new MyLinkList<int>;

    head->setData(10);
    head->setNext(second);
    second->setData(20);
    second->setNext(third);
    third->setData(30);

    print(head);
    print(second);
    print(third);
    head->print();
    second->print();
    third->print();
}