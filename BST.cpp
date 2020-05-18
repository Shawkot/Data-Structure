#include <iostream>
using namespace std;

struct node{
    int data;
    node *leftchild;
    node *rightchild;
};

node* root = NULL;
void insertion(int key)
{
    node *temp = new node;
    node *current;
    node *parent;

    temp->data = key;
    temp->leftchild = NULL;
    temp->rightchild = NULL;
    if(root == NULL){
        root = temp;
    }
    else{
        current = root;
        parent = NULL;
        while(1){
            parent = current;
            if(key < parent->data){
                current = current->leftchild;
                if(current == NULL){
                    parent->leftchild = temp;
                    return;
                }
            }
            else{
                current = current->rightchild;
                if(current == NULL){
                    parent->rightchild = temp;
                    return;
                }
            }
        }
    }
}

struct node* Search(int data) {
   struct node *current = root;
   cout << "visiting elements:" ;

   while(current->data != data) {
      if(current != NULL)
         cout << current->data <<' ';
      //go to left tree
      if(current->data > data) {
         current = current->leftchild;
      }
      //else go to right tree
      else {
         current = current->rightchild;
      }

      //not found
      if(current == NULL) {
         return NULL;
      }
   }

   return current;
}

void Inorder_trav(node* root)
{
    if(root != NULL){
        Inorder_trav(root->leftchild);
        cout << root->data << " ";
        Inorder_trav(root->rightchild);
    }
}

void Preorder_trav(node* root)
{
    if(root != NULL){
        cout <<root->data << " ";
        Preorder_trav(root->leftchild);
        Preorder_trav(root->rightchild);
    }
}

void Postorder_trav(node* root)
{
    if(root != NULL){
        Postorder_trav(root->leftchild);
        Postorder_trav(root->rightchild);
        cout << root->data << " ";
    }
}
int main()
{
    int i;
    int arr[5] = {20,10,35,15,30};
    for(i=0; i<5; i++){
        insertion(arr[i]);
    }
    i = 35;
    node* temp = Search(i);
    if(temp != NULL){
        cout << "\nData found: " << temp->data << endl;
    }
    else{
        cout << "elements not found " << endl;
    }
    cout << "In-order traversal:";
    Inorder_trav(root);
    cout << '\n';
    cout << "Pre-order traversal:";
    Preorder_trav(root);
    cout << '\n';
    cout << "Post-order traversal:";
    Postorder_trav(root);
    return 0;
}
