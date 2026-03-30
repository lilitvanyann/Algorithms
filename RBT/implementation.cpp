#include <iostream>
#include <string>

using namespace std;

enum COLOR { RED, BLACK };
// Node structure with explicit pointers for tree navigation
struct Node {
    int data;
    COLOR color; // "RED" or "BLACK"
    Node* left, * right, * parent;

    Node(int data) : data(data), color(RED),
        left(nullptr), right(nullptr), parent(nullptr) {
    }
};

class RedBlackTree {
private:
    Node* root;
    Node* NIL; //(always BLACK)

    // --- Rotations:

    void LeftRotate(Node* x) {
        if (x->right == NIL) return;
        
        Node* y = x->right;
        x->right = y->left;

        if (y->left != NIL)
            y->left->parent = x;

        y->parent = x->parent;
        
        if (x->parent == NIL)
            root = y;
        else if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;
        
        y->left = x;
        x->parent = y;
    }

    void RightRotate(Node* x) {
        Node* y = x->left;
        x->left = y->right;

        if (y->right != NIL)
            y->right->parent = x;
        y->parent = x->parent;
        if (x->parent == NIL)
            root = y;
        else if (x == x->parent->right)
            x->parent->right = y;
        else
            x->parent->left = y;
        y->right = x;
        x->parent = y;
    }
    //------Inorder_Traversal------

    void inorder(Node* node) {
        if (node != NIL) {
            inorder(node->left);
            cout << node->data << "(" << node->color << ") ";
            inorder(node->right);
        }
    }

    //------Fixup-Insert--------
    void InsertFixup(Node* z) {
        while (z->parent->color == RED)
        {
            if (z->parent == z->parent->parent->left) {
                Node* uncle = z->parent->parent->right;

                if (uncle->color == RED) {
                    z->parent->color = BLACK;
                    uncle->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                }

                else {

                    if (z == z->parent->right) {
                        z = z->parent;
                        LeftRotate(z);  //triangle->line
                    }
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    RightRotate(z->parent->parent);
                }
            }
            // Mirror Case: Parent is the right child
            else {
                Node* uncle  = z->parent->parent->left;

                if (uncle->color == RED) {
                    z->parent->color = BLACK;
                    uncle->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                }

                else {

                    if (z == z->parent->left) {
                        z = z->parent;
                        RightRotate(z);  //triangle->line
                    }
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    LeftRotate(z->parent->parent);
                }
            }
        }
        root->color = BLACK;
    }

    //-----------Minimum----------

    Node* TreeMinimum(Node* node) {
        while (node->left != NIL)
            node = node->left;
        return node;
    }
    //-----------Deletion-------

    void Transplant(Node* u, Node* v)
    {
        if (u->parent == NIL)
            root = v;
        else if (u == u->parent->left)
            u->parent->left = v;
        else u->parent->right = v;
        v->parent = u->parent;
    }


    void DeleteFixup(Node* x) {
        while (x != root && x->color == BLACK) {

            if (x == x->parent->left) {
                Node* w = x->parent->right; // sibling

                // Case 1: sibling RED
                if (w->color == RED) {
                    w->color = BLACK;
                    x->parent->color = RED;
                    LeftRotate(x->parent);
                    w = x->parent->right;
                }

                // Case 2: both children BLACK
                if (w->left->color == BLACK && w->right->color == BLACK) {
                    w->color = RED;
                    x = x->parent;
                }
                else {
                    // Case 3: right child BLACK
                    if (w->right->color == BLACK) {
                        w->left->color = BLACK;
                        w->color = RED;
                        RightRotate(w);
                        w = x->parent->right;
                    }

                    // Case 4
                    w->color = x->parent->color;
                    x->parent->color = BLACK;
                    w->right->color = BLACK;
                    LeftRotate(x->parent);
                    x = root;
                }
            }

            //  Mirror (copy-paste almost same)
            else {
                Node* w = x->parent->left;

                if (w->color == RED) {
                    w->color = BLACK;
                    x->parent->color = RED;
                    RightRotate(x->parent);
                    w = x->parent->left;
                }

                if (w->right->color == BLACK && w->left->color == BLACK) {
                    w->color = RED;
                    x = x->parent;
                }
                else {
                    if (w->left->color == BLACK) {
                        w->right->color = BLACK;
                        w->color = RED;
                        LeftRotate(w);
                        w = x->parent->left;
                    }

                    w->color = x->parent->color;
                    x->parent->color = BLACK;
                    w->left->color = BLACK;
                    RightRotate(x->parent);
                    x = root;
                }
            }
        }
        x->color = BLACK;
    }
    void Delete(Node* z) {
        Node* y = z;
        Node* x;
        COLOR y_original_color = y->color;

        if (z->left == NIL) {
            x = z->right;
            Transplant(z, z->right);
        }
        else if (z->right == NIL) {
            x = z->left;
            Transplant(z, z->left);
        }
        else {
            y = TreeMinimum(z->right); // successor
            y_original_color = y->color;
            x = y->right;

            if (y->parent == z) {
                x->parent = y;
            }
            else {
                Transplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }

            Transplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }

        // եթե սև node ենք ջնջել → fixup
        if (y_original_color == BLACK) {
            DeleteFixup(x);
        }
    }

public:
    RedBlackTree() {
        NIL = new Node(0);
        NIL->color = BLACK;
        NIL->left = NIL;
        NIL->right = NIL;
        NIL->parent = NIL;

        root = NIL;
    }

    void inorder() {
        inorder(root);
    }

    void insert(int data) {
        Node* node = new Node(data);
        node->left = node->right = NIL;

        Node* parent = NIL;
        Node* current = root;

        // Step 1: Standard Binary Search Tree insertion
        while (current != NIL) {
            parent = current;
            if (node->data < current->data) current = current->left;
            else current = current->right;
        }

        node->parent = parent;

        if (parent == NIL)      root = node;
        else if (node->data < parent->data) parent->left = node;
        else                               parent->right = node;

        // Step 2: Handle edge cases and fix RB properties
        if (node->parent == NIL) {
            node->color = BLACK;
            return;

        }
        if (node->parent->parent == NIL) return;

        InsertFixup(node);
    }

    void deleteValue(int data) {
        Node* current = root;

        while (current != NIL) {
            if (data == current->data) {
                Delete(current);
                return;
            }
            else if (data < current->data)
                current = current->left;
            else
                current = current->right;
        }
    }
    
    
};


int main() {
    RedBlackTree tree;
    tree.insert(1);
    tree.insert(10);
    tree.insert(12);
    tree.insert(14);
    tree.insert(20);
    tree.insert(13);
    tree.inorder();
}
