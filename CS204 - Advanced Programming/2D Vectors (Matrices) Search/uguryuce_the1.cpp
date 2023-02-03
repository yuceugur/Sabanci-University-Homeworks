/*
30.07.2022
This code is written by Ugur Yuce for the CS204 Summer 2022 Lecture.
Code try to fine given words in a vector of vector which is matrix. (like a Sunday morning puzzle)
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//UGUR YUCE
//uguryuce 27981

//this function reverses string
//for the search that from south to north it is needed
string reverse(string word) 
{
    char ch;
    for (int index = 0, len = word.length(); index < len/2; index++)
    {
        ch = word[index];
        word[index] = word[len-1-index];
        word[len-1-index] = ch;
   }
   return word;
}

//this function makes search columns from down to up, column search
bool searchNorth(const vector<vector<char> >& mat, string word)
{
    //bool check = false;
    int rowSize = mat.size();
    int colSize = mat[0].size(); 
    
    //cout << "word: " << word << endl; //for debugging
    for(int x=0; x<rowSize; x++)
    {
        int len = word.length();
        //int subV_len = subV.length();
        for(int y=0; y< colSize; y++)
        {
            string subV = "";
            if(word[len-1] == mat[x][y])
            {
                for(int a=x; (a-x<len && a<rowSize); a++)
                {
                    subV += mat[a][y];
                }
                //cout << subV << endl; //it is used for debugging
                if(reverse(subV) == word)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

////this function makes search columns from up to down, reverse column search
bool searchSouth(const vector<vector<char> >& mat, string word)
{
    //bool check = false;
    int rowSize = mat.size();
    int colSize = mat[0].size(); 
    
    //cout << "word: " << word << endl; //for debugging
    for(int x=0; x<rowSize; x++)
    {
        int len = word.length();
        //int subV_len = subV.length();
        for(int y=0; y< colSize; y++)
        {
            string subV = "";
            if(word[0] == mat[x][y])
            {
                for(int a=x; (a-x<len && a<rowSize); a++)
                {
                    subV += mat[a][y];
                }
                //cout << subV << endl; //it is used for debugging
                if(subV == word)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

//this function makes search rows from left to right, row search
bool searchEast(const vector<vector<char> > &mat, string word)
{
    //bool check = false;
    int rowSize = mat.size();
    int colSize = mat[0].size(); 
    
    for (int x = 0; x < rowSize; x++)
    {
        string subV = "";
        int len = word.length();
        //int subV_len = subV.length();
        for (int y = 0; y < colSize; y++)
        {
            if(word[0] == mat[x][y])
            {
                for(int a=y; a-y < len && a<colSize; a++)
                {
                    subV += mat[x][a];
                }
            }
            if(subV == word)
            {
                return true;
            }
            else
            {
                subV = "";
            }
        }
    }
    return false;
}

//this function makes search rows from right to left, reverse row search
bool searchWest(const vector<vector<char> > &mat, string word)
{
    //bool check = false;
    
    int rowSize = mat.size();
    int colSize = mat[0].size();
    
    for (int x = 0; x < rowSize; x++) {
        string subV = "";
        int len = word.length();
        //int subV_len = subV.length();
        
        for (int y = 0; y <colSize; y++)
        {
             if(word[0] == mat[x][y])
            {
                for(int a=y; (y-a < len); a--) //burada bir yerde hata var, my mind is out of index :D
                {
                    subV += mat[x][a];
                }
                //cout << "west sub: " << subV << endl; //just debugging
                if(subV == word)
                {
                    return true;
                }
                else
                {
                    subV = "";
                }
            }
        }
    }
    return false;
}

//this function makes search from left-up to right-down, diagonal search 
bool searchSouthEast(const vector<vector<char> > &mat, string word)
{
    int rowSize = mat.size();
    int colSize = mat[0].size(); 
    
    for (int x = 0; x < rowSize; x++)
    {
        string subV = "";
        //int len = word.length();
        for (int y = 0; y < colSize; y++)
        {
            if(word[0] == mat[x][y])
            {
                int a=x;
                int b=y;
                while(a<rowSize && b<colSize)
                {
                    subV += mat[a][b];
                    if(subV == word)
                    {
                        return true;
                    }
                a++; b++;
                }
            }
        }
    }
    return false;
}


//this function makes search from right-down to left-up, diagonal search, reverse diagonal search
bool searchNorthWest(const vector<vector<char> > &mat, string word)
{
    int rowSize = mat.size();
    int colSize = mat[0].size(); 
    
    for (int x = 0; x < rowSize ; x++) 
    {
        string subV = "";
        //int len = word.length();
        for (int y = 0; y < colSize ; y++)
        {
            if(word[0] == mat[x][y])
            {
                int a=x;
                int b=y;
                while(a>0 && b>0)
                {
                    subV += mat[a][b]; 
                    if(subV == word)
                    {
                        return true;
                    }
                    a--; b--;
                }
            }
        }
    }
    return false;        
}



int main()
{
    int rowNumber;
    // int colNumber;
    int wordNumber;
    string word; //puzzle words which are created by mixing letters
    string searchedWord; // words which are should be found
    vector<vector<char> > mat;
    
    cin >> rowNumber;
    //cout << "rownumber: " << rowNumber <<endl; //to see it is correct, be used just debugging
    for(int u=0; u<rowNumber; u++)
    {
        cin >> word;
        //cout << "word: " << word << endl; //to see it is correct, be used just debugging
        vector<char> temp;
        int length = word.length(); // it is needed since compiler gives missmatched type error
        for(int x=0; x<length; x++) //if you use word.length() instead of length
        {
            temp.push_back(word[x]);
        }
        mat.push_back(temp);
    }
   
    
    cin >> wordNumber; //number of words which should be find in puzzle
    //cout << "wordNumber: " << wordNumber << endl;  ////to see it is correct, be used just debugging
    int score = 0;
    
    cin >> searchedWord;
    do
    {
        //cout << "searchedWord: " <<searchedWord << endl; ////to see it is correct, be used just debugging
        if(searchNorth(mat, searchedWord))
        {
            //cout << "north: "<<searchedWord <<endl;    //when debugging just see if is working or not
            if(searchedWord.length()>5)
            {
                score += searchedWord.length() + 2;
            }
            else
            {
                score += searchedWord.length();
            }
        }
        else if(searchSouth(mat, searchedWord))
        {
            //cout << "south: " << searchedWord << endl; // //when debugging just see if is working or not
            if(searchedWord.length()>5)
            {
                score += searchedWord.length() + 2;
            }
            else
            {
                score += searchedWord.length();
            }
        }
        else if(searchEast(mat, searchedWord))
        {
            //cout << "east: " << searchedWord << endl; // //when debugging just see if is working or not
            if(searchedWord.length()>5)
            {
                score += searchedWord.length() + 2;
            }
            else
            {
                score += searchedWord.length();
            } 
        }
        else if(searchWest(mat, searchedWord))
        {
            //cout << "west: " << searchedWord << endl; // //when debugging just see if is working or not
            if(searchedWord.length()>5)
            {
                score += searchedWord.length() + 2;
            }
            else
            {
                score += searchedWord.length();
            }
        }
        else if(searchSouthEast(mat, searchedWord))
        {
            //cout << "searchSouthEast: " << searchedWord << endl; //when debugging just see if is working or not
            if(searchedWord.length()>5)
            {
                score += (searchedWord.length()*2) + 2;
            }
            else
            {
                score += searchedWord.length()*2;
            }
        }
        else if(searchNorthWest(mat, searchedWord))
        {
            //cout << "searchNorthWest: " << searchedWord << endl; //when debugging just see if is working or not
            if(searchedWord.length()>5)
            {
                score += (searchedWord.length()*2) + 2;
            }
            else
            {
                score += searchedWord.length()*2;
            }    
        }
        else
        {
            score -= 5;
        }
    }while(cin >> searchedWord);
    cout << score;
    
    return 0;
}