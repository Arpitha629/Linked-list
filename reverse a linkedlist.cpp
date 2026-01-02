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
    Node* tail = NULL;
    
    for(int i = 0; i < n; i++) {
        int value;
        cin >> value;
        
        Node* newNode = new Node(value);
        
        if(head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;
    
    while(current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    head = prev;
    
    Node* temp = head;
    bool first = true;
    while(temp != NULL) {
        if(!first) cout << " ";
        cout << temp->data;
        first = false;
        temp = temp->next;
    }
    cout << "\n";
    
    temp = head;
    while(temp != NULL) {
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }
    
    return 0;
}
