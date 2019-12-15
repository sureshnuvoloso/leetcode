
/*This is a function problem.You only need to complete the function given below*/
/* A binary tree node has data, pointer to left child
 *    and a pointer to right child  
 *    struct Node
 *    {
 *        int data;
 *            Node* left;
 *                Node* right;
 *                }; */
/*this  function serializes 
 * the binary tree and stores 
 * it in the vector A*/

#include <iostream> 
#include <queue> 
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int _data) {data = _data;}
    Node(){}
};
void serialize(Node *root,vector<int> &A);
Node * deSerialize(vector<int> &A);

Node * create_tree(int &i, int level)
{

    if (level < 0)
        return NULL;

    Node * root = new Node(i++);

    root->left = create_tree(i, level - 1);
    root->right = create_tree(i, level - 1);
 }

 void print_tree(Node *node)
    {
        if (!node)
        {
            return;
        }

        cout << node->data << endl;

        print_tree(node->left);
        print_tree(node->right);
    }


    int main()
    {
        int i = 0;
        const int MAX_LEVEL = 2;

        Node * root = create_tree(i, MAX_LEVEL);
        print_tree(root);

        vector<int> A;
        A.clear();

        serialize(root, A);
        Node * tmp = deSerialize(A);


        cout << "done with de-serialize" << endl;

        print_tree(tmp);

        return 0;

    }

#define MAX_DATA ((unsigned int)-1)

void serialize(Node *root,vector<int> &A)
{
    if (!root)
    {
        return;
    }

    Node tmp;
    tmp.data = MAX_DATA;

    queue<Node *> q;
    q.push(root);

    while(!q.empty())
    {
        Node * node = q.front();
        q.pop();

        A.push_back(node->data);

        if (node->data == MAX_DATA)
            continue;

        if (node->left)
        {
            q.push(node->left);
        }
        else
        {
            q.push(&tmp);
        }


        if (node->right)
        {
            q.push(node->right);
        }
        else
        {
            q.push(&tmp);
        }


    }

    return;
}

Node * get_new_node()
{
    Node * node = new Node();
    node->left = NULL;
    node->right = NULL;
    return node;
}
/*this function deserializes
 *  the serialized vector A*/
Node *deSerialize(vector<int> &A)
{

    if (A.size() == 0)
    {
        return NULL;
    }

    Node tmp;
    tmp.data = MAX_DATA;

    Node * root = get_new_node();
    int i = 0;
    root->data = A[i];

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node * node = q.front();
        q.pop();

        if (node->data == MAX_DATA)
        {
            i++;
            continue;
        }

        node->data = A[i];
        node->left = NULL;
        node->right = NULL;

        if (A[2*i + 1] != (unsigned int)-1)
        {
            node->left = get_new_node(); 
            q.push(node->left);
        }
        else
        {
            q.push(&tmp);
        }

        if (A[2*i+2] != (unsigned int)-1)
        {
            node->right = get_new_node();
            q.push(node->right);
        }
        else
        {
            q.push(&tmp);
        }

        i++;
    }

    return root;
}
