#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Node *&head, int data) {
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertattail(Node *&tail, int data) {
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

void insertionatopos(Node *&head, int data, Node *&tail, int pos) {
    if (pos == 1) {
        insertAtHead(head, data);
        return;
    }

    Node *temp = head;
    int cnt = 1;

    while (cnt < pos - 1 && temp != NULL) {
        temp = temp->next;
        cnt++;
    }

    if (temp == NULL) {
        cout << "Position out of bounds" << endl;
        return;
    }

    if (temp->next == NULL) {
        insertattail(tail, data);
        return;
    }

    Node *nodetoinsert = new Node(data);
    nodetoinsert->next = temp->next;
    temp->next = nodetoinsert;
}

void print(Node *head) { 
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    insertattail(tail, 14);
    insertattail(tail, 17);
    insertionatopos(head, 13, tail, 4); 
    print(head); 

    return 0;
}
