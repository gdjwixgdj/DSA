#include<iostream>
#include <string>
#include<stack>
using namespace std;
class Node
{
    char data;
    Node* left;
    Node* right;
    Node(char d) : data(d), left(NULL), right(NULL) {}
    friend class ExpressionTree;
};
class ExpressionTree
{
        Node* root;
    public:
        void createTree(string prefix)
        {
            int j = prefix.length() - 1;
            stack<Node*> st;
            while(j >= 0)
            {
                //Operand
                if(prefix[j] >= 65 && prefix[j] <= 90 || prefix[j] >= 97 && prefix[j] <= 122)
                {
                    Node* newNode = new Node(prefix[j]);
                    st.push(newNode); 
                    //st.push(new Node(prefix[j]))
                }
                //Operator
                else 
                {
                    Node* parent = new Node(prefix[j]); 
                    parent -> left = st.top();
                    st.pop();
                    
                    parent -> right = st.top();
                    st.pop();

                    st.push(parent);
                }
                j--;
            }
            root = st.top();
            st.pop();
        }
        Node* getRoot()
        {
            return root;
        }
        void postOrderNonRecursive()
        {
            stack<Node*> st;
            Node* root = this -> root;
            while(root != NULL || !st.empty())
            {
                while(root != NULL)
                {
                    if(root->right)
                        st.push(root->right);
                    st.push(root);
                    root = root -> left;
                }
                root = st.top();
                st.pop();
                if(root->right && !st.empty() && st.top() == root->right)
                {
                    Node* temp = st.top();
                    st.pop();
                    st.push(root);
                    root = temp;
                }            
                else
                {
                    cout << root->data << " ";
                    root = NULL;
                }
            }
        }
        void delAllNodes(Node* root)
        {
            if(root)
            {
                delAllNodes(root->left);
                delAllNodes(root->right);
                delete root;
            }
        }
        ~ExpressionTree()
        {
            cout << "Deleting all Nodes\n";
            delAllNodes(root);
        }
};
int main()
{
    ExpressionTree exptree;
    string prefix;
    cout << "Enter a Prefix Expression : ";
    getline(cin, prefix);
    exptree.createTree(prefix);
    cout << "Postorder traversal(Non-recursive) : ";
    exptree.postOrderNonRecursive();
}
