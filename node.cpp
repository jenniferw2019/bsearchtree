//cpp for node
#include "node.h"
#include <iostream>

using namespace std;

//create binary search tree / insert value into the tree
void insert(node* &root, node* parent, node* current, int value)
{
  //new value becomes the root of the tree
  if (root == NULL)
    {
      node* newNode = new node();
      newNode->data = value;
      root = newNode;
      root->left = NULL;
      root->right = NULL;
    }
  //adding value to the end of the tree (either left or right)
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

//printing values in order from smallest to largest
void print(node* root)
{
  if (root != NULL)
    {
      print(root->left);
      cout << root->data << " ";
      print(root->right);
    }
}

//visualize binary search tree 
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

//search for a specific value in the tree
node* search(node* treeNodeHead, node* parent, node* current, int searchNumber)
{
  //value is not in tree
  if (current == NULL)
    {
      return NULL;
	
    }
  //return the node with the value
  else if (current->data == searchNumber)
    {
      return current;
    }
  
  else
    {	
      parent = current;
      if (parent->data < searchNumber)
	{
	  current = current->right;
	}
      else
	{
	  current = current->left;
	}
      return search(treeNodeHead, parent, current, searchNumber);
    }
}

//search for successor of a node
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

//find parent of a child node
node* getParent(node* root, node* current, node* previous, node* lookParent)
{
  //return null if looking for the parent of the root
  if (root == lookParent)
    {
      return NULL;
    }
  //return parent node
  else if (current == lookParent)
    {
      return previous;
    }
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

//delete node from tree
void deleteNode(node* &root, int deleteNumber)
{
  //search for node with the value user wants to delete
  node* delNode = search(root, root, root, deleteNumber);
  
  if (delNode == NULL)
    {
      cout << "number not in tree" << endl;
      
    }
  else
    {	
      //no child, delete the node
     if (delNode->left == NULL && delNode->right == NULL)
	{
	  //if node is the root, then delete root
	  if (delNode == root)
	    {
	      node* temp = root;
	      root = NULL;
	      delete temp;
	    }
	  else
	    {
	      node* parent = getParent(root, root, root, delNode);
	      //delete node if its a left child
	      if (parent->left == delNode)
		{
		  parent->left = NULL;
		  delete delNode;
		}
	      else
		{
		  //delete node if its a right child
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
	     if (parent->left == delNode)
	       {
		 parent->left = delNode->right;
		 delete delNode;
	       }
	     else
	       {
		 parent->right = delNode->right;
		 delete delNode;
	       }
	  
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
	     if (parent->right == delNode)
	       {
		 parent->right = delNode->left;
		 delete delNode;
	       }
	     else
	       {
		 parent->left = delNode->left;
		 delete delNode;
	       }
	   }
       }
     //two children
     else if (delNode->right != NULL && delNode->left != NULL)
       {
	 node* successor = minimum(delNode->right);
	 node* parent = getParent(root, root, root, successor);
	 delNode->data = successor->data;

	 //no children
	 if (successor->right == NULL && successor->left == NULL)
	   {
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
	     if (parent->left == successor)
	       {
		 parent->left = successor->right;
		 delete successor;
	       }
	     else
	       {
		 parent->right = successor->right;
		 delete successor;
	       }
	   }
	 
       }
     
    }
}

