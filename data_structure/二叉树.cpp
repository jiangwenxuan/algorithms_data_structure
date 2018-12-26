#include<iostream>
using namespace std;
#include<stdio.h>
static int i=1;

class BtreeNode
{
public:
	BtreeNode * left;
	BtreeNode * right;
	char ccc;
	int num;
public:

	BtreeNode(char c=NULL,BtreeNode * a=NULL,BtreeNode * b=NULL)
	{
		
		ccc=c;
		left=a;
		right=b;
	}


	void dataout()
	{
		cout<<ccc;
	}
	
	void Setleft(BtreeNode * a=NULL)
	{
		left=a;
	}

	void Setright(BtreeNode * a=NULL)
	{
		right=a;
	}


	void Setdata(char c=NULL)
	{
		ccc=c;
	}

};



class BinTree
{
public:
	BtreeNode * root;
public:
	BinTree(BtreeNode * t=NULL):root(t){}
	
    


   virtual ~BinTree()
   {
        Del(root);
   }


   void Del(BtreeNode * t)
   {
		if(t!=NULL)
		{
			Del(t->left);
			Del(t->right);
			delete t;
		}	
   }

   BtreeNode * Father(BtreeNode * t,BtreeNode * p)
   {
	   BtreeNode * q;
	   if(t==NULL||p==NULL) return NULL;
	   if(t->left==p||t->right==p) return t;
	   
	   if((q=Father(t->left,p))!=NULL) return q;
	   else return Father(t->right,p);
   }
    

   BtreeNode * Create()
   {
	   BtreeNode * t,*t1,*t2;
	   char item;
	   cin>>item;
	   if(item=='#')
	   {
		   t=NULL;
		   return t;
	   }
	   else
	   {
		   t=new BtreeNode (item,NULL,NULL);
		   t->num=i;
		   i++;
		   t1=Create();
		   t->Setleft(t1);
		   t2=Create();
		   t->Setright(t2);
		   return t;

	   }


   }


   void PreOrder(BtreeNode * t)
   {
	   if(t!=NULL) 
	   {
		   t->dataout();
		   PreOrder(t->left);
		   PreOrder(t->right);
	   }
   }

   void InOrder(BtreeNode * t)
	{
       if(t!=NULL)
	   {
		   InOrder(t->left);
		   t->dataout();
		   InOrder(t->right);
	   }
	}


    void PostOrder(BtreeNode * t)
   {
	   if(t!=NULL) 
	   {
		   PostOrder(t->left);
		   PostOrder(t->right);
		   t->dataout();
	   }
   }

	BtreeNode * Find(BtreeNode * t,char x)
	{
		BtreeNode * p;
		if(t==NULL) return NULL;
		if(t->ccc==x) return t;
		if((p=Find(t->left,x))!=NULL) return p;
		else return Find(t->right,x);
	}




};






int main()
{
	
    BinTree t1;
	t1.root=t1.Create();
	cout<<"二叉树的根T1为：";
    t1.root->dataout();
    cout<<endl;
	cout<<"先根遍历为：";
    t1.PreOrder(t1.root);cout<<endl;
	cout<<"中根遍历为：";
	t1.InOrder(t1.root);cout<<endl;
	cout<<"后根遍历为：";
	t1.PostOrder(t1.root);cout<<endl;
	
	
    BtreeNode * t2;
    char c;
    cout<<"请输入查找结点"; 
    cin>>c;
    t2=t1.Find(t1.root,c);
	
	cout<<"在先根遍历中的第"<<t2->num<<"位"<<endl;
	
	t2=t1.Father(t1.root,t2);
	
	
	cout<<"其父节点在"<<t2->num<<"位"<<endl;
	return 0;

}
