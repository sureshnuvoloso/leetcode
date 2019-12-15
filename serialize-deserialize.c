#include <bits/stdc++.h>
    using namespace std;
    /* A binary tree node has data, pointer to left child
     *    and a pointer to right child */
    struct Node
    {
        int data;
        struct Node *left;
        struct Node *right;

        Node(int x){
            data = x;
            left = NULL;
            right = NULL;
        }
    };
    void serialize(Node *root,vector<int> &);
    Node * deSerialize(vector<int> &);
    /* Computes the number of nodes in a tree. */
    int height(struct Node* node)
    {
        if (node==NULL)
            return 0;
        else
            return 1 + max(height(node->left), height(node->right));
    }
    void inorder(Node *root)
    {
        if (root == NULL)
            return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
    /* Driver program to test size function*/
    int main()
    {
        int t;
        scanf("%d", &t);
        while (t--)
        {
            map<int, Node*> m;
            int n;
            scanf("%d",&n);
            int N = n;
            struct Node *root = NULL;
            struct Node *child;
            while (n--)
            {
                Node *parent;
                char lr;
                int n1, n2;
                scanf("%d %d %c", &n1, &n2, &lr);
                if (m.find(n1) == m.end())
                {
                    parent = new Node(n1);
                    m[n1] = parent;
                    if (root == NULL)
                        root = parent;
                }
                else
                    parent = m[n1];
                child = new Node(n2);
                if (lr == 'L')
                    parent->left = child;
                else
                    parent->right = child;
                m[n2]  = child;
            }
            vector<int> A;
            A.clear();
            serialize(root,A);
            Node *tree_made = deSerialize(A);
            inorder(tree_made);
            cout<<endl;
        }
        return 0;
    }

/*This is a function problem.You only need to complete the function given below*/
/* A binary tree node has data, pointer to left child
   and a pointer to right child  
   struct Node
   {
   int data;
   Node* left;
   Node* right;
   }; */
/*this  function serializes 
  the binary tree and stores 
  it in the vector A*/

#include <iostream> 
#include <queue> 
using namespace std;

void serialize(Node *root,vector<int> &A)
{

    if (!root)
    {
        return;
    }
    int index = 1;
    A[index++] = root->data;
    queue<Node *> q;

    q.push(root);

    while(!q.empty())
    {
        Node * node = q.front();
        q.pop();

        if (node->left)
        {
            A[index++] = node->data;
            q.push(node->left);
        }
        else
        {
            A[index++] = (unsigned int)-1;

        }


        if (node->right)
        {
            A[index++] = node->data;
            q.push(node->right);

        }
        else
        {
            A[index++] = (unsigned int)-1;
        }


    }


    return;

}

Node * get_new_node()
{
    Node * node = (Node*)malloc(sizeof(Node));
    node->left = NULL;
    node->right = NULL;
    return node;
}
/*this function deserializes
  the serialized vector A*/
Node * deSerialize(vector<int> &A)
{
    //Your code here

    if (A.size() == 0)
    {
        return NULL;
    }

    Node * root = get_new_node();
    int i = 1;
    root->data = A[i];

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node * node = q.front();
        q.pop();
        if (A[2*i + 1] != (unsigned int)-1)
        {

            node->left = get_new_node(); 
            node->data = A[2*i+1];
            q.push(node);

        }
        else
        {
            node->left = NULL;
        }
        if (A[2*i+2] != (unsigned int)-1)
        {
            node->right = get_new_node();
            node->data = A[2*i+2];
            q.push(node);

        }
        else
        {
            node->right = NULL;
        }

        i++;


    }

}
