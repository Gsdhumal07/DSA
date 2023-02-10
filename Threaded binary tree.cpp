#include<iostream>
using namespace std;

class tbt
{
		int data;
    	tbt *left;
    	tbt *right;
    	bool rthread,lthread;
    
public:
    tbt* insert(tbt *,tbt *);
   	tbt* create(int );
    tbt* leftmostnode(tbt *);
    void inorder(tbt *,tbt * );
    tbt* preorder(tbt * ,tbt*);

};

tbt * tbt :: create(int key)
{
    tbt * newnode=new tbt;
    newnode->data = key;
    newnode->left = newnode;
    newnode->right = newnode;
    newnode->lthread = true;
    newnode->rthread = true;
    return newnode;
    
}

tbt * tbt :: insert(tbt * root,tbt *head)
{
    int key;
    tbt * curr;
    cout<<"Enter the element to insert : ";
    cin>>key;
    tbt * newnode = create(key);
    

    if(root==NULL)
    {
        head->left=newnode;
        root=newnode;
        root->left=root->right=head;
        head->lthread=false;
        return root;
    }
    else
    {
        curr=root;
        while(1)
        {
        if (curr->data==key) 
        { 
            cout<<"Element already present !!\n"; 
            return root ;
            break;
             
        } 
            if(key<curr->data)
            {
                if(curr->lthread)
                {
                     break;
                }
                else
                {
                    curr=curr->left;
                }

            }
          
            else
            {
                if(curr->rthread)
                {
                    break;
                }
                curr=curr->right;
            }
        }
        if(key<curr->data)
        {
            newnode->left=curr->left;
            curr->left=newnode;
            newnode->right=curr;
            curr->lthread=false;
        }
        else
        {
            newnode->left=curr;
            newnode->right=curr->right;
            curr->right=newnode;
            curr->rthread=false;
        }
    }
    return root;
}


tbt * tbt :: leftmostnode(tbt *temp) 
{
    if(temp == NULL)
    {
        return NULL;
    }
    else
    {
        while(temp != NULL)
        {
            if(temp->lthread)
            {
                break;
            }
            temp = temp->left;
        }
        return temp;
    }
}

void tbt :: inorder(tbt *root,tbt *head)
{
    tbt * curr;
    curr = leftmostnode(root);
    while(curr != head)
    {
			cout<<"\n";
            cout<<curr->data<<" ";
            if(curr->rthread)
            {
                curr = curr->right;
            }
            else
            {
                curr = leftmostnode(curr->right);
            }

    }
}

tbt * tbt::preorder(tbt * root, tbt* head)
{
    tbt * curr=root;
    while(1)
    {
        cout<<curr->data<<" ";
        if(curr->lthread==false)
            curr=curr->left;
        else if(curr->rthread==false)
            curr=curr->right;
        else
        {
            while(curr->right!=head && curr->rthread==true)
            {
                curr=curr->right;
            }
            if(curr->right!=head)
            	curr=curr->right;
            else
            	break;
        }
    }
}


int main()
{
    tbt * root = NULL;
   
    tbt t;
     tbt * head = t.create(999);
    int ch;

    do
    {

        cout<<"\n1.Create a tree.\n2.Inorder traversal.\n3.Preorder traversal.\n4.Exit. "<<endl;
        cout<<"\nEnter your choice : \n";
        cin>>ch;

        switch(ch)
        {

        case 1:
            root = t.insert(root,head);
            break;
        case 2:
            t.inorder(root,head);
            break;
        case 3:
            t.preorder(root,head);
            break;
        case 4:
            exit(0);
			
			default: cout<<"\nWrong Choice\n";
        }
    }while(ch != 4);
    
    return 0;
}
