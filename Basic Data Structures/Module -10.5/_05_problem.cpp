#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int val;
        Node* next;
        Node* prev;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insert_tail(Node *&head, Node *&tail, int val){
    Node *newNode = new Node(val);
    if(head==NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = tail->next;
}

int size_doubly(Node *head){
    Node *tmp = head;
    int count = 0; 
    while (tmp != NULL)
    {
        count++;
        tmp = tmp->next;
    }
    return count;
    
}
void print(Node *head){
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->val<<" ";
        tmp = tmp->next;
    }
    cout << endl;
    
}

void sort(Node *&head, Node *&tail){
    Node *i = head;
    Node *j = tail;
    while (i != j && i->next != j)
    {
        if(i->val>j->val){
            swap(i->val, j->val);
        }
        i = i->next;
        j = j->prev;
    }
    if(i->val>j->val){
        swap(i->val, j->val);
    }
}
int main()
{


    Node *head = NULL;
    Node *tail = NULL;
    int val;
    while (true)
    {
        cin >> val; 
        if(val == -1) break;
        insert_tail(head, tail, val);
    }
    sort(head,tail);
    print(head);
    

    return 0;
}