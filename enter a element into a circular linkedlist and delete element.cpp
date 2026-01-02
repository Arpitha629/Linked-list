#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int value) {
        data = value;
        next = NULL;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    Node* head = NULL;
    
    for(int i = 0; i < n; i++) {
        int value;
        cin >> value;
        
        Node* newNode = new Node(value);
        
        if(head == NULL) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while(temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }
    
    int k;
    if(cin >> k) {
        Node* current = head;
        Node* prev = NULL;
        
        do {
            if(current->data == k) {
                if(head->next == head) {
                    delete head;
                    head = NULL;
                } else if(current == head) {
                    Node* tail = head;
                    while(tail->next != head) {
                        tail = tail->next;
                    }
                    tail->next = head->next;
                    head = head->next;
                    delete current;
                } else {
                    prev->next = current->next;
                    delete current;
                }
                break;
            }
            prev = current;
            current = current->next;
        } while(current != head);
    }
    
    if(head != NULL) {
        Node* temp = head;
        bool first = true;
        do {
            if(!first) cout << " ";
            cout << temp->data;
            first = false;
            temp = temp->next;
        } while(temp != head);
    }
    cout << "\n";
    
    if(head != NULL) {
        Node* current = head->next;
        while(current != head) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        delete head;
    }
    
    return 0;
}
