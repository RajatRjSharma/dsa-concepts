#include <iostream>
using namespace std;

// Custom Link List C++ Class
template <typename T>
class MyLinkList
{

    // Private Attributes
private:
    T data;
    MyLinkList<T> *next;

    // Constructors and Public Methods
public:
    // Default Constructor
    MyLinkList()
    {
        data = (T)NULL;
        next = NULL;
    }

    /**
     * Constructor with Data as parameter
     * @param data: Data to be added to Link List Node of type T.
     */
    MyLinkList(T data)
    {
        this->data = data;
        next = NULL;
    }

    /**
     * Constructor with Data and Next node as parameter
     * @param data: Data to be added to Link List Node of type T.
     * @param ll: Node or Link List to be added to next pointer.
     */
    MyLinkList(T data, MyLinkList<T> *ll)
    {
        this->data = data;
        next = ll;
    }

    /**
     * Getter to get the Data of Link List Node.
     */
    T getData()
    {
        if (data)
            return data;
        else
            return (T)NULL;
    }

    /**
     * Getter to get the Next Node of Link List Node.
     */
    MyLinkList<T> *getNext()
    {
        if (next)
            return next;
        else
            return NULL;
    }

    /**
     * Setter to set the Data of Link List Node.
     * @param data: Data to be added to Link List Node of type T.
     */
    T setData(T data)
    {
        this->data = data;
        return this->data;
    }

    /**
     * Setter to set the Next node of Link List Node.
     * @param ll: Node or Link List to be added to next pointer.
     */
    MyLinkList<T> *setNext(MyLinkList<T> *ll)
    {
        next = ll;
        return next;
    }

    /**
     * Method to traverse the Link List and print data of each node.
     */
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

/**
 * Method to traverse the Link List and print data of each node.
 */
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

/**
 * Method to Insert a node at Beginning of a LL.
 * @param head: Link List in which node is to be inserted.
 * @param node: Node to be inserted.
 */
template <typename T>
MyLinkList<T> *insertAtBeginning(MyLinkList<T> *head, MyLinkList<T> *node)
{
    node->setNext(head);
    head = node;
    return head;
}

/**
 * Method to Insert a node at Index of a LL.
 * @param head: Link List in which node is to be inserted.
 * @param node: Node to be inserted.
 * @param index: Index at which a node is to be inserted.
 */
template <typename T>
MyLinkList<T> *insertAtIndex(MyLinkList<T> *head, MyLinkList<T> *node, int index)
{
    if (index == 0)
    {
        return insertAtBeginning(head, node);
    }
    if (index < 0)
    {
        return head;
    }
    MyLinkList<T> *curr = head;
    while (index > 1 && curr != NULL)
    {
        index--;
        curr = curr->getNext();
    }
    if (curr != NULL)
    {
        node->setNext(curr->getNext());
        curr->setNext(node);
        return head;
    }
    else
    {
        return head;
    }
}

/**
 * Method to Insert a node at End of a LL.
 * @param head: Link List in which node is to be inserted.
 * @param node: Node to be inserted.
 */
template <typename T>
MyLinkList<T> *insertAtEnd(MyLinkList<T> *head, MyLinkList<T> *node)
{
    MyLinkList<T> *curr = head;
    while (curr->getNext() != NULL)
    {
        curr = curr->getNext();
    }
    if (curr->getNext() == NULL)
    {
        node->setNext(curr->getNext());
        curr->setNext(node);
        return head;
    }
    else
    {
        return head;
    }
}

/**
 * Method to Insert a node at a Given node of a LL.
 * @param head: Link List in which node is to be inserted.
 * @param node: Node to be inserted.
 * @param givenNode: Node after which a new node is to be inserted.
 */
template <typename T>
MyLinkList<T> *insertAfterGivenNode(MyLinkList<T> *head, MyLinkList<T> *node, MyLinkList<T> *givenNode)
{
    MyLinkList<T> *curr = head;
    while (curr != givenNode && curr != NULL)
    {
        curr = curr->getNext();
    }
    if (curr == givenNode)
    {
        node->setNext(curr->getNext());
        curr->setNext(node);
        return head;
    }
    else
    {
        return head;
    }
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

    MyLinkList<int> *test = new MyLinkList<int>;
    test->setData(10);

    cout << "Insert At Begin" << endl;
    MyLinkList<int> *node = new MyLinkList<int>;
    node->setData(0);
    head = insertAtBeginning(head, node);
    print(head);
    MyLinkList<int> *nodeTest = new MyLinkList<int>;
    nodeTest->setData(100);
    test = insertAtBeginning(test, nodeTest);
    print(test);

    cout << "Insert At Index" << endl;
    node = new MyLinkList<int>;
    node->setData(25);
    head = insertAtIndex(head, node, 2);
    print(head);
    nodeTest = new MyLinkList<int>;
    nodeTest->setData(100);
    test = new MyLinkList<int>;
    test->setData(10);
    test = insertAtIndex(test, nodeTest, 1);
    print(test);

    cout << "Insert At End" << endl;
    node = new MyLinkList<int>;
    node->setData(40);
    head = insertAtEnd(head, node);
    print(head);
    nodeTest = new MyLinkList<int>;
    nodeTest->setData(100);
    test = new MyLinkList<int>;
    test->setData(10);
    test = insertAtEnd(test, nodeTest);
    print(test);

    cout << "Insert After Given Node" << endl;
    node = new MyLinkList<int>;
    node->setData(35);
    head = insertAfterGivenNode(head, node, third);
    print(head);
    nodeTest = new MyLinkList<int>;
    nodeTest->setData(100);
    test = new MyLinkList<int>;
    test->setData(10);
    test = insertAfterGivenNode(test, nodeTest, third);
    print(test);

    MyLinkList<char> *ll9 = new MyLinkList('A');
    MyLinkList<char> *ll10 = new MyLinkList('B');
    MyLinkList<char> *ll11 = new MyLinkList('C');
    MyLinkList<char> *ll12 = new MyLinkList('D');

    ll9->setNext(ll10);
    ll10->setNext(ll11);
    ll11->setNext(ll12);

    print(ll9);
    print(ll10);
    print(ll11);
    print(ll12);
    ll9->print();
    ll10->print();
    ll11->print();
    ll12->print();
}