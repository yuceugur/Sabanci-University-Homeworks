#include <iostream>
#include <string>
#include "DynTemplatedStack.h"
#include "DynTemplatedStack.cpp"
#include <sstream>
#include <fstream>

using namespace std;

//uguryuce
//27981

template <class f_type>
void optionOne(DynTemplatedStack<f_type> & temp, DynTemplatedStack<f_type> & stack1, DynTemplatedStack<f_type> & stack2) //sorted results according to the first file
{
    f_type temp2, first,second;

    while(!stack1.isEmpty())
    {
        int result1 = 1, result2 = 0;
        stack1.pop(first);
        while(!stack2.isEmpty())
        {
            stack2.pop(second);
            
            if(first == second)
            {
                result2++;
            }
            else
                temp.push(second);
        }
        while(!temp.isEmpty())
        {
            temp.pop(second);
            stack2.push(second);
        }
        
        while(!stack1.isEmpty())
        {
            stack1.pop(temp2);
                
                if(first == temp2)
                {
                    result1++;
                }
                else
				{
                    temp.push(temp2);
				}
        }
        while(!temp.isEmpty())
        {
            temp.pop(temp2);
            stack1.push(temp2);
        }
        
		if( result1 <= result2  && (result1 != 0 && result2 != 0))
		{
            cout << first << " --> " << result1 <<"\n";
		}
        else if ( result1 >= result2  && (result1 != 0 && result2 != 0))
		{
			cout << first << " --> " << result2 << "\n";
		}
    }
}

template <class f_type>
void optionTwo(DynTemplatedStack<f_type> & temp, DynTemplatedStack<f_type> & stack1, DynTemplatedStack<f_type> & stack2)  //sorted results according to the first file
{                                                                                         
    f_type temp2, first,second;
    
    while(!stack2.isEmpty())
    {
        int result1 = 1, result2 = 0;
        stack2.pop(first);
        while(!stack1.isEmpty())
        {
            stack1.pop(second);
            
            if(first == second)
            {
                result2++;
            }
            else
                temp.push(second);
        }
        while(!temp.isEmpty())
        {
            temp.pop(second);
            stack1.push(second);
        }
        
        while(!stack2.isEmpty())
        {
            stack2.pop(temp2);
            
            if(first == temp2)
            {
                result1++;
            }
            else
			{
                temp.push(temp2);
			}
        }
        while(!temp.isEmpty())
        {
            temp.pop(temp2);
            stack2.push(temp2);
        }
        
        if( result1 <= result2  && (result1 != 0 && result2 != 0))
		{
            cout << first << " --> " << result1 <<"\n";
		}
        else if ( result1 >= result2  && (result1 != 0 && result2 != 0))
		{
			cout << first << " --> " << result2 << "\n";
		}
    }
}

template <class f_type>
void stackPusher(ifstream & file1, ifstream & file2, DynTemplatedStack<f_type> & stack1, DynTemplatedStack<f_type> & stack2) //this function fills stack.
{ // This function pushes the stacks.
    string line;
    while(getline(file1, line))
    {
        stringstream ss(line);
        f_type temp2;
        while(ss >> temp2)
        {
            stack1.push(temp2);
        }
    }
	
    while(getline(file2, line))
    {
		stringstream ss(line);
        f_type word;
        while(ss >> word)
        {
            stack2.push(word);
        }
    }
}

template <class f_type>
DynTemplatedStack<f_type> reverseStack(DynTemplatedStack<f_type> & reversedStack) //this function reverses stack.
{
	DynTemplatedStack<f_type> temp;
	while(!reversedStack.isEmpty())
    {
        f_type data;
		reversedStack.pop(data);
        temp.push(data);
    }
	return temp;
}

int main()
{
	string filename1, filename2, priority;
	cin >> filename1;
	ifstream input1;
	input1.open(filename1.c_str());
	cin >> filename2;
	ifstream input2;
	input2.open(filename2.c_str());
	cin >> priority;
	if(input1.fail())
	{
		cout << "File not found." << endl;
	}
	else if(input2.fail())
	{
		cout << "File not found." << endl;
	}
	else if(!(priority == "1" || priority == "2"))
	{
		cout << "Invalid choice." << endl;
	}
	else
	{
		string letter1, letter2; //first letter of file name
		letter1 = filename1[0];
		letter2 = filename2[0];
		cout << "TOKEN --> MINIMUM OCCURRENCE COUNT" << endl;
		cout << "----------" << endl;
		if(letter1 == "i" && letter2 == "i")
		{
			DynTemplatedStack<int> temp, stack1, stack2;
			stackPusher(input1,input2, stack1, stack2);
			stack1 = reverseStack(stack1);
			stack2 = reverseStack(stack2);
			if(priority == "1") //sorted according to the first file
			{
				optionOne(temp, stack1, stack2);
			}
			if(priority == "2") //sorted according to the second file
			{
				optionTwo(temp, stack1, stack2);
			}
		}
		else if(letter1 == "s" && letter2 == "s")
		{
			DynTemplatedStack<string> temp, stack1, stack2;
			stackPusher(input1, input2, stack1, stack2);
			stack1 = reverseStack(stack1);
			stack2 = reverseStack(stack2);
			if(priority == "1") //sorted according to the first file
			{
				optionOne(temp, stack1, stack2);
			}
			if(priority == "2") //sorted according to the second file
			{
				
				optionTwo(temp, stack1, stack2);
			}
		}
		else if(letter1 == "c" && letter2 == "c")
		{
			DynTemplatedStack<char> temp, stack1, stack2;
			stackPusher(input1,input2, stack1, stack2);
			stack1 = reverseStack(stack1);
			stack2 = reverseStack(stack2);
			if(priority == "1") //sorted according to the first file
			{
				optionOne(temp, stack1, stack2);
			}
			if(priority == "2") //sorted according to the second file
			{
				optionTwo(temp, stack1, stack2);
			}
		}
	}
	return 0;
}