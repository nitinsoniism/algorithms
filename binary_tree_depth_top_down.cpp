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
        void _depth(Node *T, int curr_depth, int *p_max_depth);
        void destroy(Node *rt);
    public:
        Tree(Node *rt) { root = rt;}
        ~Tree();

        int depth();
};

void Tree::_depth(Node *T, int curr_depth, int *p_max_depth)
{
    if (!T) return;

    //time to update max depth. We have gone further down than our previous visit
    if (curr_depth > *p_max_depth)
        *p_max_depth = curr_depth;
    
    _depth(T->left, curr_depth + 1, p_max_depth);
    _depth(T->right, curr_depth + 1, p_max_depth);
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

//Maintain a curr_depth for current depth and max_depth for max until now
int Tree::depth()
{
    int max_depth = 0;
    _depth(root, 0/* curr_depth */, &max_depth);
    return max_depth;
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
