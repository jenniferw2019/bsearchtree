#include "node.h"

using namespace std;

int main()
{
  bool runProgram = true;
  char option[20];
  char option2[20];
  char strInput[100];
  int spaceCount = 0;
  int tokenCount = 0;
  int* numberArray;
  node* BST = NULL;
  
  cout << "do you want to insert through a console or file?" << endl;
  cout << "type CONSOLE for console insert or FILE for file insert" << endl;
  cin.get(option, 20);
  cin.get();

  if (strcmp(option, "CONSOLE") == 0)
    {
      cout << "Enter a series of numbers between 1 and 999" << endl;
      cin.get(strInput, 100);
      cin.get();

      int a = 0;
      while (strInput[a] != '\0')
	{
	  if (strInput[a] == ' ')
	    {
	      spaceCount++;
	    }
	  a++;
	}
      tokenCount = spaceCount + 1;
      a = 0;
      numberArray = new int[tokenCount];
      char* token;
      token = strtok(strInput, " ");
      while (token != NULL)
	{
	  numberArray[a] = atoi(token);
	  token = strtok(NULL, " ");
	  a = a + 1;
	}
      /*
      for (int i = 0; i < tokenCount; i++)
	{
	  cout << numberArray[i] << endl;
	}
      */

      for (int i = 0; i < tokenCount; i++)
	{
	  insert(BST, BST, BST, numberArray[i]);
	}
      //cout << BST->data << endl;

      print(BST);
      cout << endl;
    }
  if (strcmp(option, "FILE") == 0)
    {

    }

  while (runProgram == true)
    {
      cout << "Type ADD, VISUALIZE, SEARCH" << endl;
      cin.get(option2, 20);
      cin.get();

      if (strcmp(option2, "ADD") == 0)
	{

	}

      if (strcmp(option2, "VISUALIZE") == 0)
	{

	}

      if (strcmp(option2, "SEARCH") == 0)
	{

	}
    }
 
}
