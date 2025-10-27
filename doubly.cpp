#include <bits/stdc++.h>
using namespace std;

class doublyList
{
    struct Node
    {
        int data;
        Node *prev;
        Node *next;
        Node(int val)
        {
            data = val;
            prev = nullptr;
            next = nullptr;
        }
    };

    Node *head = nullptr;
    Node *tail = nullptr;
    int SIZE = 0;

    void InsertFirst(int item)
    {
        Node *nn = new Node(item);
        nn->next = head;
        if (head != nullptr) /////First Mistake if head is NULL
        {
            head->prev = nn;
            head = nn;
        }
        else
        {
            head = nn;
            tail = nn;
        }
    }
    void InsertLast(int item)
    {
        if (head == nullptr)
        {
            InsertFirst(item);
            return;
        }
        Node *nn = new Node(item);
        nn->prev = tail;
        tail->next = nn;
        tail = nn;
    }

    void DeleteFirst()
    {
        if (head == nullptr)
        {
            cout << "Can't delete\n";
            return;
        }
        if (head == tail) //// Its not mandatory here as we can do it in Delete() but it could be dengerous
        {
            delete head;
            head = tail = nullptr;
            return;
        }

        Node *temp = head;
        head = head->next;
        head->prev = nullptr;
        temp->next = nullptr;
        delete temp;
    }

    void DeleteLast()
    {
        if (head == nullptr)
        {
            cout << "Can't delete\n";
            return;
        }
        if (head == tail) //// Its not mandatory here as we can do it in Delete() but it could be dengerous
        {
            delete head;
            head = tail = nullptr;
            return;
        }

        Node *temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        temp->next = nullptr;
        delete temp;
    }

public:
    void Insert(int item, int pos)
    {
        if (pos < 1 || pos > SIZE + 1)
        {
            cout << "Invalid position\n";
            return;
        }
        SIZE++;
        if (pos == 1)
        {
            InsertFirst(item);
            return;
        }
        else if (pos == SIZE)
        {
            InsertLast(item);
            return;
        }
        Node *target = head;
        for (int i = 0; i < pos - 1; i++)
            target = target->next;

        Node *nn = new Node(item);

        nn->prev = target->prev;
        target->prev->next = nn;

        nn->next = target;
        target->prev = nn; ///// 2nd Mistake target -> next = nn X
    }

    void Delete(int pos)
    {
        if (pos < 1 || pos > SIZE) //////  3rd Mistake SIZE + 1 X
        {
            cout << "Invalid position\n";
            return;
        }
        SIZE--;
        if (pos == 1)
        {
            DeleteFirst();
            return;
        }
        else if (pos == SIZE)
        {
            DeleteLast();
            return;
        }
        Node *target = head;

        for (int i = 0; i < pos - 1; i++)
            target = target->next;

        target->prev->next = target->next;
        target->next->prev = target->prev;

        delete target;
    }
    void Search(int item)
    {
        Node *ptr = head;
        int pos = 1;
        while (ptr)
        {
            if (ptr->data == item)
            {
                cout << "Item found at:" << pos << " number position\n";
                return;
            }
            ptr = ptr->next;
            pos++;
        }
        cout << "Item couldn't found\n";
    }
    void Display()
    {
        Node *ptr = head;

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
    doublyList dll;
    dll.Insert(1, 1);
    dll.Insert(4, 2);
    dll.Insert(5, 3);
    dll.Insert(3, 2);

    dll.Display();

    dll.Search(4);

    dll.Delete(2);
    dll.Delete(1);

    dll.Display();

    dll.Search(3);

    return 0;
}