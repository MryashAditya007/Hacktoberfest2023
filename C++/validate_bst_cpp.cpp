//recurssion method have been used here
//the program contains the class function

#include <bits/stdc++.h>
using namespace std;

class node{
    public: 

    node *left;
    node *right;
    int data;

    node(int d)
    {
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }

};

//building of the bst 

node* buildtree(node *root)
{
    cout<<"enter the data ";
    int data;
    cin>>data;

    root= new node(data);

    if(data==-1)
    {
        return NULL;
    }
    cout<<"enter data for insertion in left of "<<data<<endl;
    root->left = buildtree(root -> left);
    cout<<"enter data for insertion of right of "<<data<<endl;
    root->right = buildtree(root -> right);


    return root;

}

//level order traversal of the ttree

void levelordertraversal(node* root)
{
   queue<node*>q;
   q.push(root);
   q.push(NULL);


   while(!q.empty())
   {
    node* temp=q.front();
    
    q.pop();

    
    if(temp==NULL)
    {
        //purana level complete ho chuka hai 
        cout<<endl;
        if(!q.empty())
        {
            //queue still has some child nodes

            q.push(NULL);

        }
    }
    else{
        cout<< temp->data<<" ";
        if(temp->left)
        {
            q.push(temp->left);
        }

        if(temp->right)
        {
            q.push(temp->right);
        }
    }

   }
}

//main solving function

bool isbst(node* root,int min ,int max){

    //base case
    if(root==NULL){
        return true;
    }

    if(root->data<max && root->data>min){
        bool left=isbst(root->left,min,root->data);
        bool right=isbst(root->right,root->data,max);
        return left && right;
    }
    else{
        return false;
    }
}

int main()
{
    node* root=NULL;

    root=buildtree(root);
    levelordertraversal(root);
    cout<<"validate the binary search tree "<< isbst(root,INT_MIN,INT_MAX)<<endl;
    // 4 5 1 -1 -1 123 -1 -1 5 -1 -1
}
