#include <iostream>
using namespace std;

class LinkedList
{
    struct Node
    {
        int data;
        Node *next;

        Node(int val) : data(val), next(nullptr) {}
        Node(int val, Node *ptr) : data(val), next(ptr) {}
    };

    Node *head = nullptr;
    Node *tail = nullptr;
    int SIZE = 0;

    void InsertFirst(int item)
    {
        Node *nn = new Node(item, head);
        head = nn;
        if (tail == nullptr)
            tail = nn;
        SIZE++;
    }

    void InsertLast(int item)
    {
        if (head == nullptr)
        {
            InsertFirst(item);
            return;
        }
        Node *nn = new Node(item);
        tail->next = nn;
        tail = nn;
        SIZE++;
    }

    void DeleteFirst()
    {
        if (head == nullptr)
        {
            cout << "List is empty\n";
            return;
        }

        Node *temp = head;
        head = head->next;

        delete temp;
        SIZE--;

        if (head == nullptr)
            tail = nullptr;
    }

    void DeleteLast()
    {
        if (head == nullptr)
        {
            cout << "List is empty\n";
            return;
        }

        if (head == tail)
        {
            delete head;
            head = tail = nullptr;
            SIZE--;
            return;
        }

        Node *prev = head;
        while (prev->next != tail)
            prev = prev->next;

        delete tail;
        tail = prev;
        tail->next = nullptr;
        SIZE--;
    }

public:
    void Insert(int item, int pos)
    {
        if (pos < 1 || pos > SIZE + 1)
        {
            cout << "Invalid Position\n";
            return;
        }

        if (pos == 1)
        {
            InsertFirst(item);
        }
        else if (pos == SIZE + 1)
        {
            InsertLast(item);
        }
        else
        {
            Node *prev = head;
            for (int i = 1; i < pos - 1; i++)
                prev = prev->next;

            Node *nn = new Node(item, prev->next);
            prev->next = nn;
            SIZE++;
        }
    }

    void Delete(int pos)
    {
        if (pos < 1 || pos > SIZE)
        {
            cout << "Invalid Position\n";
            return;
        }

        if (pos == 1)
            DeleteFirst();
        else if (pos == SIZE)
            DeleteLast();
        else
        {
            Node *prev = head;
            for (int i = 1; i < pos - 1; i++)
                prev = prev->next;

            Node *target = prev->next;
            prev->next = target->next;
            delete target;
            SIZE--;
        }
    }

    void Search(int item)
    {
        Node *ptr = head;
        int pos = 1;
        while (ptr)
        {
            if (ptr->data == item)
            {
                cout << "Found at position: " << pos << endl;
                return;
            }
            ptr = ptr->next;
            pos++;
        }
        cout << "Not found" << endl;
    }

    void display()
    {
        Node *ptr = head;
        if (!ptr)
        {
            cout << "List is empty\n";
            return;
        }
        while (ptr)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
};

int main()
{
    LinkedList l1;
    l1.Insert(10, 1);
    l1.Insert(1000, 2);
    l1.Insert(10000, 3);
    l1.Insert(100, 2);
    l1.Insert(10, 1);
    l1.Insert(1000, 2);
    l1.Insert(10000, 3);
    l1.Insert(100, 2);

    l1.display();

    l1.Search(100);

    l1.Delete(4);

    l1.display();

    return 0;
}
