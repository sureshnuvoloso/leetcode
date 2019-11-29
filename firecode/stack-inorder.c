#include <stdio.h>



#define visited(x) { printf("%d\t", (x)->value) };
// Add any helper functions(if needed) above.
void preorder_itr(treeNode* root) 
{     
    stackTreeNode stk;
    stack_treenode_init(&stk);

    treeNode * t = root;

    while(1)
    {

        while (t)
        {
            visited(t);
            treenode_push(&stk, t);
            t = t->left;
        }

        t = treenode_pop(&stk);

        if (!t)
        {
            break;
        }

        t = t->right;

    }
}





