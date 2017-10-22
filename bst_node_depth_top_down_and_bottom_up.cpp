//find depth of a binary tree using top down method.

#include <iostream>
#include <string>

using namespace std;

struct Node
{
    Node *left;
    Node *right;
    int data;

    Node(int dt): data(dt), left(NULL), right(NULL) {
        cout << "Node created with data: " << data << endl;
    }
    ~Node() {
        cout << "Node deleted with data: " << data << endl;
    }
};

class Tree
{
    private:
        Node *root;
        int _td_depth(Node *T, int level, int data);
        int _bu_depth(Node *T, int data);
        void destroy(Node *rt);
    public:
        Tree(Node *rt) { root = rt;}
        ~Tree();

        int td_depth(int data);
        int bu_depth(int data);
};

int Tree::_td_depth(Node *T, int level, int data)
{
    //node not found in tree/subtree. IMP
    if (!T) return 0;

    if (data == T->data) return level;
    else if (data < T->data) {
        return _td_depth(T->left, level + 1, data);
    }
    else {
        return _td_depth(T->right, level + 1, data);
    }
}

int Tree::_bu_depth(Node *T, int data)
{
    int ret = 0;
    //node not found in tree/subtree. IMP
    if (!T) return 0;

    if (data == T->data) return 1;
    else if (data < T->data) {
        ret = _bu_depth(T->left, data);
        //0 return means node not found.
        return ret ? ret + 1 : 0;
    }
    else {
        ret = _bu_depth(T->right, data);
        //0 return means node not found.
        return ret ? ret + 1 : 0;
    }
}

Tree::~Tree()
{
    destroy(root);
}

void Tree::destroy(Node *T) {
    //post order traversal to destroy a tree
    if (!T) return;
    destroy(T->left);
    destroy(T->right);
    delete T;
}

int Tree::bu_depth(int data)
{
    return _bu_depth(root, data);
}

int Tree::td_depth(int data)
{
    return _td_depth(root, 1, data);
}

int main()
{
    /* BST
    //              n1 
    //              / \ 
    //             n2  n3
    //                /  \
    //               n4   n5
    //              /
    //             n6
    //             */
    Node *n1 = new Node(2);
    Node *n2 = new Node(1);
    Node *n3 = new Node(5);
    Node *n4 = new Node(4);
    Node *n5 = new Node(6);
    Node *n6 = new Node(3);
    n1->left = n2; n1->right = n3;
    n3->left = n4; n3-> right = n5;
    n4->left = n6;
    Tree T(n1);
    cout << "Tree Node n4 or 4 Depth top down: "<< T.td_depth(n4->data) << endl;
    cout << "Tree Node n4 or 4 Depth bottom up: "<< T.bu_depth(n4->data) << endl;
    return 0;
}
