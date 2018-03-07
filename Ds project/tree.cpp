#include "tree.h"
#include <vector>


tree::tree()
{
	rootptr = NULL;
}
bool tree::isempty()
{
	if (rootptr == NULL)
		return true;
	else return false;
}
treenode* tree::getroot()
{
	return rootptr;
}
void tree::setroot(treenode* k){
 this->rootptr=k;
 cout<<"root is now :"<<rootptr->getdata()->getid()<<endl;
}
treenode* tree::search(int ID)
{
	if (rootptr == NULL) return NULL;
	treenode* ptr = rootptr;
	while (ptr != NULL)
	{
		int a = ptr->c.getid();
		if (a == ID) return ptr;
		if (ID < a) ptr = ptr->left;
		if (ID > a) ptr = ptr->right;
	}
	return NULL;
}
bool tree::insert(client a)
{
	  generateID(a);
	if (rootptr == NULL)
	{
		treenode* m = new treenode(a);
		rootptr = m;
		return true;
	}

	treenode* ptr = rootptr;
	while (ptr != NULL)
	{
		int ID = ptr->c.getid();
		if (ID == a.getid()) return false;
		else if (a.getid() < ID)
		{
			if (ptr->left == NULL)
			{
				treenode* m = new treenode(a);
				ptr->left = m;
				return true;

			}
			else ptr = ptr->left;
		}
		else if (a.getid() > ID) {

			if (ptr->right == NULL)
			{
				treenode* m = new treenode(a);
				ptr->right = m;
				return true;

			}
			else ptr = ptr->right;
		}
	}
}

void tree::printalltree()
{
	
	traverseinorder(rootptr);
}

void tree::traverseinorder(treenode* p)
{
	if (rootptr == NULL)
	{
		cout << "the tree is empty!!" << endl;
		return;
	}

	if (p == NULL)
	{
		return;
	}


	traverseinorder(p->left);
    p->c.printallclientinfo();
	cout << endl;
	traverseinorder(p->right);
}
string tree::parsetree(treenode* p)
{
	string result = ""; 

	if (rootptr == NULL)
	{
		
		return"" ;
	}

	if (p == NULL)
	{
		return"";
	}


   result +=	parsetree( p->left);
	result += parsetree( p->right);
	 result = result + p->c.parseclient();
	 return result; 
}
string tree::parsetree2(treenode* p)
{
	string result = "";

	if (rootptr == NULL)
	{

		return"";
	}

	if (p == NULL)
	{
		return"";
	}


	result += parsetree2(p->left);
	result += parsetree2(p->right);
	result = result + p->c.parseclient2();
	return result;
}

    bool tree:: remove(int x){//remove client by id
        if (isempty()) return false;
     treenode *p= rootptr;
     treenode *parent=NULL;
     char whatChild;
     while(p!=NULL)
     {
         int a=p->getdata()->getid();
         if(a==x) break;
         else if(x<a){
            parent=p;   p=p->getleft(); whatChild='L';
         }
         else{
            parent=p;   p=p->getright();   whatChild='R';
         }
     }
	 
     if(p==NULL) return false; // value not found in the tree
     //if delete leaf node
     if(p->getright()==NULL && p->getleft()==NULL)
     {
         if(parent!=NULL)
         {
             if(whatChild=='L')
                parent->setleft(NULL);
             else if(whatChild=='R')
                parent->setright(NULL);
         }
         else rootptr=NULL;
		// delete p;
		 ids.clear();
		 levelOrder(rootptr);
         return true;
     }


    //parent has one child -right child
    else if(p->getleft()==NULL)
    {
         if(parent!=NULL)
         {
             if(whatChild=='L')
                 parent->setleft(p->getright());
             else if(whatChild=='R')
                parent->setright(p->getright());
			
         }

       else rootptr=p->getright();
	     //delete p;
		 ids.clear();
		 levelOrder(rootptr);
         return true;

    }
    //parent has one child -left child
        else if(p->getright()==NULL)
    {
         if(parent!=NULL)
         {
             if(whatChild=='L')
                 parent->setleft(p->getleft());
             else if(whatChild=='R')
                parent->setright(p->getleft());
			 return true;
         }
       else rootptr=p->getleft();

	  // delete p;
		 ids.clear();
		 levelOrder(rootptr);
         return true;

    }
    //if  p has two children
    else{//take the bigest element in left side to put it in place of element that want to remove
       treenode* returnNode=new treenode(*p); // copy p as make overwrite on it
       treenode* leftChild = p->getleft();
       if(leftChild->getright()==NULL){ //leftChild has no right child
        p->setdata(*leftChild->getdata());
        p->setleft(leftChild->getleft());
        delete leftChild;
		 ids.clear();
		 levelOrder(rootptr);
        return true;
       }
       treenode* maxLeft = leftChild->getright();
       treenode* parent2 = p;
       while(maxLeft->getright()!=NULL){
        parent2=maxLeft; maxLeft=maxLeft->getright();
       }
       //now maxLeft has the most number on the left side of p
       p->setdata(*maxLeft->getdata());
       if(maxLeft->getleft()==NULL) parent2->setright(NULL);//maxleft is leaf
       else parent2->setright(maxLeft->getleft());//maxleft is not leaf
       delete maxLeft;
	   	ids.clear();
	    levelOrder(rootptr);
       return true;
    }
    }
	int tree :: heightplusone(treenode* t)
{
	if (t == NULL) return 0;
	else
	{
		int x = heightplusone(t->left);
		int y = heightplusone(t->right);
		return x > y ? x+1 : y+1 ;

	}
}
bool tree::isleaf(treenode* p){
	if((p->getleft()==NULL) && (p->getright()==NULL)) return true;
	else return false;
}
void tree::generateID(client& a){

	if(isempty()){
		a.setid(500000);//put large id if there is no element in tree and become a root
		ids.push_back(500000);
		return ;
	}
	treenode* p=rootptr;
	if(isleaf(p) || (p->left==NULL)){// if tree has rottptr only  or has on chilren in right, put it in the left
		int val=500000-(500000/2);
		a.setid(val);
		ids.push_back(val);
		return;
	}
   if(p->right==NULL){
	  int val=500000+(500000/2);
		a.setid(val);
		ids.push_back(val);
		return;
	}
   float heigh;
   int h;
   int n=ids.size(); int val;
   heigh=(n-1)/(2*1.0);
   h=heigh;
   int heighttree;
   heighttree=heightplusone(p)-1;
      float siz1=log(n+1)/(log(2)*1.0); //log of base 2
	  int siz2=siz1;
	  if(siz2==siz1){//that tree become complete tree and you want to another element and increase to add it 
		  heighttree++;
	  }
   if(h==heigh){
	   val=ids.at(h)-(500000/pow(2,heighttree));
	   	a.setid(val);
		ids.push_back(val);
	   return ;
   }
   else if(h<heigh){
	   val=ids.at(h)+(500000/pow(2,heighttree));
	   	 a.setid(val);
		ids.push_back(val);
	   return ;
   }
}
void tree::levelOrder(treenode* t){
	int h =heightplusone(t);
	    int i;
    for (i=1; i<=h; i++)
        givenlevel(t, i);
}
void tree::givenlevel(treenode* t,int level){
	if (t == NULL){
        return;
	}
	if (level == 1)
	{
			ids.push_back(t->getdata()->getid());
	}
	 else if (level > 1)
    {
        givenlevel(t->getleft() , level-1);
        givenlevel(t->getright(), level-1);
    }
        
}

