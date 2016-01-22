/*

Name: Tanuja Mohan

Description: Read from a file and reverse the content of the file, printing each word on a different line. This is problem 5 of CS104 Assingment 1.

*/


#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {

   //check to make sure correct number of arguments given
   if (argc != 2)
   {
      cerr << "Incorrect number of arguments" << endl;
      return -1;
   }
   
   ifstream inFile;
   inFile.open(argv[1]);
   
   //check if file is valid
   if (inFile.fail())
   {
      cerr << "Unable to open file" << endl;
      return -1;
   } 
   
   //read in the starting integer
   int n = 0;
   inFile >> n;
   
   //check if starting integer is present in file
   if (inFile.fail())
   {
     cerr << "Unable to find starting integer in file" << endl; 
     return -1;
   }
   
   //dynamically allocate an array of strings to hold the contents
   string* fileArray = new string[n];
   
   //fill the array with the file
   for (int i = 0; i < n; i++)
   {
      inFile >> fileArray[i];
   }
   
   //print the array in reverse order
   for (int j = n-1; j >= 0; j--)
   {
      cout << fileArray[j] << endl;
   }
   
   //delete the allocated memory for no memory leaks
   delete[] fileArray;
}
