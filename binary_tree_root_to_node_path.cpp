//find patth of a node from root in a binary tree using bottom up method.

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
        bool _path(Node *T, int data);
        void destroy(Node *rt);
    public:
        Tree(Node *rt) { root = rt;}
        ~Tree();

        void path(int data);
};

bool Tree::_path(Node *T, int data)
{
    if (!T) return 0;
    
    if (T->data == data) {
        cout << "Path Node: " << T->data << endl;
        return true;
    }
    if (_path(T->left, data)) {
        cout << "Path Node: " << T->data << endl;
        return true;
    }
    if (_path(T->right, data)) {
        cout << "Path Node: " << T->data << endl;
        return true;
    }
    return false;
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

void Tree::path(int data)
{
    _path(root, data);
}

int main()
{
    /*
    //              n1 
    //              / \ 
    //             n2  n3
    //                /  \
    //               n4   n5
    //              /
    //             n6
    //             */
    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);
    Node *n5 = new Node(5);
    Node *n6 = new Node(6);
    n1->left = n2; n1->right = n3;
    n3->left = n4; n3-> right = n5;
    n4->left = n6;
    Tree T(n1);
    cout << "Tree Path for: "<< n6->data << endl;
    T.path(n6->data);
    cout << endl;
    cout << "Tree Path for: "<< n5->data << endl;
    T.path(n5->data);
    cout << endl;
    return 0;
}
