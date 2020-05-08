#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};
class linked_list
{
private:
    node *head, *tail; // Creating two node
public:
    linked_list()
    {
        head = NULL; // Initialize the node to be null
        tail = NULL;
    }
   void addnode(int n) // Function for adding node
    {
        node *tmp = new node; // Creating a temporary pointer
        tmp->data = n;
        tmp->next = NULL;
        if(head == NULL){ // Check if the node is null or not
            head = tmp;
            tail = tmp;
        }
        else{
            tail->next = tmp;
            tail = tail->next;
        }
    }
    void display() // For displaying the node
    {
        node *tmp;
        tmp = head;
        while (tmp != NULL){
            cout << tmp->data << endl;
            tmp = tmp->next;
        }
    }
};
int main()
{
    linked_list a;
    a.addnode(1);
    a.addnode(2);
    a.addnode(3);
    a.display();
    return 0;
}

