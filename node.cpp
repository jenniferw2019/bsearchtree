#include "node.h"
#include <iostream>

using namespace std;


void insert(node* &root, node* parent, node* current, int value)
{
  if (root == NULL)
    {
      node* newNode = new node();
      newNode->data = value;
      root = newNode;
      root->left = NULL;
      root->right = NULL;
    }
  else if (current == NULL)
    {
      node* newNode = new node();
      newNode->data = value;
      current = newNode;
      if (value < parent->data)
	{
	  parent->left = current;
	}
      if (value > parent->data)
	{
	  parent->right = current;
	}
    }
  else
    {
      parent = current;
      if (current->data > value)
	{
	  current = current->left;
	}
      else if (current->data < value)
	{
	  current = current->right;
	}
      insert(root, parent, current, value);
    }
}

void print(node* root)
{
  if (root != NULL)
    {
      print(root->left);
      cout << root->data << " ";
      print(root->right);
    }
}

void visualize(node* root, int level)
{
  if (root != NULL)
    {
      visualize(root->right, level + 1);
      for (int i = 0; i < level; i++)
	{
	  cout << '\t';
	}
      cout << root->data << endl;
      visualize(root->left, level + 1);
    }
}

node* search(node* treeNodeHead, node* parent, node* current, int searchNumber)
{
  
  if (current == NULL)
    {
      return NULL;
	
    }
  
  else if (current->data == searchNumber)
    {
      return current;
    }
  
  else
    {	
      //cout << "line 99" << endl;
      parent = current;
      if (parent->data < searchNumber)
	{
	  //cout << "line 103" << endl;
	  current = current->right;
	}
      else
	{
	  current = current->left;
	}
      //cout << "line 111" << endl;
      return search(treeNodeHead, parent, current, searchNumber);
    }
}

node* minimum(node* root)
{
  if (root->left != NULL)
    {
      root = root->left;
      return minimum(root);
    }
  else
    {
      return root;
    }
}

node* getParent(node* root, node* current, node* previous, node* lookParent)
{
  if (root == lookParent)
    {
      return NULL;
    }
  else if (current == lookParent)
    {
      return previous;
    }
  /*
  else if (current == NULL)
    {
      if (previous == lookParent)
	{
	  return previous;
	}
      else
	{
	  return NULL;
	}
    }
  */
  else 
    {
      previous = current;
      if (previous->data < lookParent->data)
	{
	  current = current->right;
	}
      else
	{
	  current = current->left;
	}
      return getParent(root, current, previous, lookParent);
    }
}


void deleteNode(node* &root, int deleteNumber)
{
  node* delNode = search(root, root, root, deleteNumber);
  //cout << delNode->data << endl;
  if (delNode == NULL)
    {
      cout << "number not in tree" << endl;
      
    }
  else
    {	
      //no child
     if (delNode->left == NULL && delNode->right == NULL)
	{
	  if (delNode == root)
	    {
	      node* temp = root;
	      root = NULL;
	      delete temp;
	    }
	  else
	    {
	      node* parent = getParent(root, root, root, delNode);
	      if (parent->left == delNode)
		{
		  parent->left = NULL;
		  delete delNode;
		}
	      else
		{
		  parent->right = NULL;
		  delete delNode;
		}
	    }
	}
     //one child: right
     else if (delNode->right != NULL && delNode->left == NULL)
       {
	 if (delNode == root)
	   {
	     node* temp = root;
	     root = delNode->right;
	     delete temp;
	   }
	 else
	   {
	     node* parent = getParent(root, root, root, delNode);
	     parent->right = delNode->right;
	     delete delNode;
	  
	   }
       }
     //one child: left
     else if (delNode->right == NULL && delNode->left != NULL)
       {
	 if (delNode == root)
	   {
	     node* temp = root;
	     root = delNode->left;
	     delete temp;
	   }
	 else
	   {
	     node* parent = getParent(root, root, root, delNode);
	     parent->left = delNode->left;
	     delete delNode;
	   }
       }
     //two children
     else if (delNode->right != NULL && delNode->left != NULL)
       {
	 node* successor = minimum(delNode->right);
	 node* parent = getParent(root, root, root, successor);
	 cout << successor->data << endl;
	 cout << parent->data << endl;
	 delNode->data = successor->data;

	 cout << "line 280" << endl;
	 //no children
	 if (successor->right == NULL && successor->left == NULL)
	   {
	     cout << "line 284" << endl;
	     //node* parent = getParent(root, root, root, successor);
	     //cout << parent->data << endl;
	     
	     if (parent->left == successor)
	       {
		 parent->left = NULL;
		 delete successor;
	       }
	     else
	       {
		 parent->right = NULL;
		 delete successor;
	       }
	     
	   }
	 
	 //right children
	 else if (successor->right != NULL && successor->left == NULL)
	   {
	     //node* parent = getParent(root, root, root, successor);
	     parent->right = successor->right;
	     delete successor;
	   }
	 //left children
	 else if (successor->right == NULL && successor->left != NULL)
	   {
	     //node* parent = getParent(root, root, root, successor);
	     parent->left = successor->left;
	     delete successor;
	   }
	 
       }
     
    }
}

