#include <iostream>
#include <stack>
using namespace std;

// Node Struct 

struct Node {
    int data;
    Node* left;
    Node* right;
    Node* parent;

    Node(int val, Node* par = nullptr) {
        data = val;
        left = nullptr;
        right = nullptr;
        parent = par;
    }
};

class BST {
private:
    Node* root;

public:
    BST() { root = nullptr; }

    Node* getRoot() {
        return root;
    }

    //-----------TRAVERSALS-------------

    //Inorder_walk

    void Inorder(Node* root) {
        if (root != NULL)
        {
            Inorder(root->left);
            cout << root->data << " ";
            Inorder(root->right);

        }
    }
    void InorderPrint() {
        Inorder(root);
        cout << endl;
    }

    void InorderIterative() {
        stack<Node*> st;
        Node* current = root;

        while (current != nullptr || !st.empty()) {

            while (current != nullptr) {
                st.push(current);
                current = current->left;
            }

            current = st.top();
            st.pop();

            cout << current->data << " ";

            current = current->right;
        }
    }


    //Postorder_walk

    void Postorder(Node* root) {
        if (root != NULL)
        {

            Postorder(root->left);
            Postorder(root->right);
            cout << root->data << " ";

        }
    }
    void PostorderPrint() {
        Postorder(root);
        cout << endl;
    }

    //Preorder_walk

    void Preorder(Node* root) {
        if (root != NULL)
        {
            cout << root->data << " ";
            Preorder(root->left);
            Preorder(root->right);

        }
    }
    void PreorderPrint() {
        Preorder(root);
        cout << endl;
    }

    //---------------------------------------------------------------------


    //--------SEARCHING---------

    Node* Search(Node* root, int k) {
        if (root == nullptr || root->data == k)
            return root;

        if (k < root->data)
            return(Search(root->left, k));
        else return (Search(root->right, k));
    }

    //-------SEARCHING_without_recursion-------

    Node* Search2(Node* root, int k) {
        while (root != nullptr && root->data != k)
            if (k < root->data)
                root = root->left;
            else
                root = root->right;
        return root;
    }



    //-------Minimum----------------------

    Node* Minimum(Node* root) {
        if (root->left != nullptr)
            return Minimum(root->left);

        return root;
    }
    void FindMin() {
        Node* m = Minimum(root);
        cout << m->data;
        cout << endl;
    }

    //-----Maximum_without_recursion-------

    Node* Maximum(Node* root) {
        while (root->right != nullptr)
            root = root->right;
        return root;
    }
    void FindMax() {
        Node* m = Maximum(root);
        cout << m->data;
        cout << endl;
    }

    //-------Successor-------

    Node* Successor(Node* x) {

        if (x->right != nullptr)
            return Minimum(x->right);

        Node* y = x->parent;

        while (y != nullptr && x == y->right) {

            x = y;
            y = y->parent;
        }
        return y;

    }


    //-------Predecessor-------

    Node* Predecessor(Node* x) {

        if (x->left != nullptr)
            return Maximum(x->left);

        Node* y = x->parent;

        while (y != nullptr && x == y->left) {

            x = y;
            y = y->parent;
        }
        return y;

    }
    //--------INSERT-------------------------

    void insert(int value) {
        Node* z = new Node(value);  // 1. ստեղծում ենք նոր node
        Node* y = nullptr;          // parent-ի համար
        Node* x = root;             // ներկայիս node

        // 2. գտնում ենք որտեղ պետք է նստեցնել node-ը
        while (x != nullptr) {
            y = x;                  // պահում ենք parent
            if (z->data < x->data)
                x = x->left;        // ձախ կողմ ենք գնում
            else
                x = x->right;       // աջ կողմ ենք գնում
        }

        // 3. կցում ենք node-ին parent-ին
        z->parent = y;

        if (y == nullptr)
            root = z;               // եթե ծառը բաց էր, նոր node-ն root է
        else if (z->data < y->data)
            y->left = z;            // ձախ child
        else
            y->right = z;           // աջ child
    }

    //--------DELETE-------------------------

        //--------transplant-------------------------

    void Transplant(Node* u, Node* v)
    {
        if (u->parent == nullptr)
            root = v;
        else if (u == u->parent->left)
            u->parent->left = v;
        else u->parent->right = v;
        if (v != nullptr)
            v->parent = u->parent;
    }

    void Delete(Node* z) {
        Node* y;
        if (z->left == nullptr)
            Transplant(z, z->right);
        else if (z->right == nullptr)
            Transplant(z, z->left);
        else {
            y = Minimum(z->right);
            if (y->parent != z) {
                Transplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;

            }
            Transplant(z, y);
            y->left = z->left;
            y->left->parent = y;
        }

    }

};

int main() {
    BST tree;

    tree.insert(20);
    tree.insert(15);
    tree.insert(22);
    tree.insert(24);
    tree.insert(21);
    tree.insert(23);
    tree.insert(25);

    tree.InorderPrint();
    cout << "tree min - "; tree.FindMin();
    cout << "tree max - "; tree.FindMax();

    //Finding value and deleting
    Node* node = tree.Search(tree.getRoot(), 25);
    if (node != nullptr) {
        tree.Delete(node);
        cout << "the node is deleted" << endl;
    }
    else {
        std::cout << "Node not found!\n";
    }
    tree.InorderIterative();

    //Finding Successor
    Node* suc = tree.Successor(tree.getRoot()->right);
    cout << "The successor is - " << suc->data;


}
