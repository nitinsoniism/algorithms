//find depth of a binary tree using bottom up method.

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
    public:
        Tree(Node *rt) { root = rt;}
        ~Tree();

        int _depth(Node *T);
        int depth();
        void destroy(Node *rt);
};

int Tree::_depth(Node *T)
{
    int ldepth, rdepth;

    if (!T) return 0;
    if (!T->left && !T->right) return 0;
    
    ldepth = 1 + _depth(T->left);
    rdepth = 1 + _depth(T->right);

    return ldepth >= rdepth ? ldepth : rdepth;
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

int Tree::depth()
{
    return _depth(root);
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
    cout << "Tree Depth: "<< T.depth() << endl;
    return 0;
}
