#include <iostream>

using namespace std;

typedef struct Node{
    string songName;
    Node  *link;
}Node;

Node *createNode(string data){
    Node *newNode = new Node;
    newNode->songName = data;
    newNode->link = NULL;

    return newNode;
}

void traverse(Node *head){
    Node *temp = new Node;
    temp = head;
    
    cout << "My Playlist" <<endl;
    while(temp != NULL){
        cout << temp->songName<< "->"<<endl;
        if(temp->link == NULL){
            cout << "NULL"<<endl;
        }
        
        temp = temp->link;
    }
}

Node *insertAtEnd(string data, Node *head){
    if(head == NULL){
        Node *newNode = createNode(data);
        head = newNode;
        cout << "A new node has been inserted at the end \n" << endl;
        return head;
    }
    Node *temp = new Node;
    temp = head;
    
    while(temp->link != NULL){
        temp = temp->link;
    }
    
    Node *newNode = createNode(data);
    temp->link = newNode;
    
    cout << "A new node has been inserted at the end \n" << endl;
    return head;
}

Node *insertAtBeginning(string data, Node *head){
    Node *newNode = createNode(data);
    newNode->link = head;
    
    head = newNode;
    
    cout << "A new node has been inserted at the beginning \n" <<endl;
    
    return head;
}

string insertAfter(string after, string data, Node *head){
    Node *temp = new Node;
    temp = head;
    
    while(temp->songName.compare(after) != 0){
        if(temp == NULL){
            return "No such exist, please try again later.";
        }
        
        temp = temp->link;
    }
    Node *newNode = createNode(data);
    newNode->link = temp->link;
    temp->link = newNode;
    
    return "An new node has been inserted after " + after + "\n";
}

int main(){
    Node *head = createNode("Terrified by Katharine");
    
    head = insertAtEnd("NVMD by Denisse Julia", head);
    head = insertAtEnd("Heaven by Bryan Adams", head);
    head = insertAtEnd("Always by Bon jovi", head);
    head = insertAtEnd("Snooze by Sza", head);
    
    head = insertAtBeginning("Cry Baby by Sza", head);
    head = insertAtBeginning("When Where Young by Adele", head);
    head = insertAtBeginning("Prom Queen by Beach Bunny", head);
    head = insertAtBeginning("One of The Girls by The Weekend", head);
    traverse(head);
    
    insertAfter ("Ipagpatawad Mo by Mayonnaise", "Cry Baby by Sza", head);
    insertAfter ("Ikaw Lang by Nobita", "When Where Young by Adele", head);
    insertAfter ("Salamat by The Dawn", "Prom Queen by Beach Bunny", head);
    traverse(head);
    
    

    return 0;
}
