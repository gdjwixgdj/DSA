#include<iostream>
using namespace std;

class Node
{
        int data;
        Node* left;
        Node* right;
    public:
        Node()
        {
            data = 0;
            left = right = NULL;
        }
        Node (int d)
        {
            data = d;
            left = right = NULL; 
      }
      friend class BST;
};

class BST
{
        Node* root;
    public:
        BST()
        {
            root = NULL;
        }
        Node* getRoot()
        {
            return root;
        }
        void insert(int d)
        {
            Node* p = new Node(d);
            if(root == NULL)
            {
                root = p;
                return;
            }
            Node* q = root;
            while(q)
            {
                if(d < q -> data)
                {
                    if(q -> left == NULL)
                    {
                        q -> left = p;
                        break;
                    }
                    q = q -> left;
                }
                else if(d > q -> data)
                {
                    if(q -> right == NULL)
                    {
                        q -> right = p;
                        break;
                    }
                    q = q -> right;
                }
            }
        }

    void mirror(Node* root)
    {
        if (root != NULL)
        {
            Node* temp = root -> left;
            root -> left = root -> right ;
            root -> right = temp ;

            mirror(root -> left);
            mirror(root -> right);
        }
    }
    void minimm()
    {
        if (root == NULL)
        {
            cout<<"BST is empty";
            return;
        }
        Node* q = root;
        while (q -> left)
            q = q -> left;
        cout << "Minimun element : " << q -> data << endl;
    }
    int height (Node* root)
    {
        int leftHeight , rightHeight;
        if(root == NULL || root -> left == NULL && root-> right == NULL)
            return 0;
        
        leftHeight = height (root -> left);
        rightHeight = height (root -> right);

        if(leftHeight > rightHeight)
            return leftHeight + 1;
        else
            return rightHeight + 1;  
    }
    void search ()
    {
        int key;
        cout<<"Enter a key to be searched : ";
        cin>> key;

        Node* q = root;
        while(q)
        {
            if (key < q -> data)
                q= q-> left;
            else if(key > q -> data)
                q = q -> right;
            else
            {
                cout<< key << " found in BST" << endl;
                return;
            }
        }
        cout << key << " not found" << endl;
    }
    void inOrder(Node* root)
    {
        if(root == NULL)
            return;
        inOrder(root -> left);
        cout << root-> data << " ";
        inOrder(root -> right);
    }
    void display ()
    {
        cout << "BST elements are (inOrder) : ";
        inOrder(root);
        cout << endl;
    }
};

int main()
{
    BST bst;
    bool flag = true;
    int choice , key;

    while (flag)
    {
        cout<<"1. Inserst Node "<<endl;
        cout<<"2. Height of BST "<<endl;
        cout<<"3. Minimum Value "<<endl;
        cout<<"4. Mirror "<<endl;
        cout<<"5. Search a value "<<endl;
        cout<<"6. Display "<<endl;
        cout<<"7. Exit "<<endl;
        cout<< "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
            case 1 :
                int n ;
                cout<<"How many values do you want to insert : ";
                cin >> n;
                for(int i =0; i < n; i++)
                {
                    cout<<"Enter data of node " << (i+1) <<": ";
                    cin>>key;
                    bst.insert(key);
                }
                break;
            case 2 :
                cout << "Height of BST : " << bst.height(bst.getRoot())<<endl;
                break;
            case 3 :
                bst.minimm();
                break;
            case 4 :
                bst.mirror(bst.getRoot());
                cout << "After mirroring ";
                bst.display(); 
                break;
            case 5:
                bst.search();
                break;
            case 6 :
                bst.display();
                break;
            case 7:
                cout << "end of program. " << endl;
                flag = false;
                break;
            default:
                cout << "Invalid Choice!" << endl;
        }
    }
}  
