/*
Name: Tanuja Mohan
Description: Question 6 for HW1

*/


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[])
{
  if(argc < 3){
    cerr << "Please provide an input and output file." << endl;
    return 1;
  }
  ifstream input(argv[1]);
  ofstream output(argv[2]);

  int floors;
  int *floorsizes;
  string ***trojans;
  string curr;

  input >> floors;
  trojans = new string**[floors];

  //you will need to keep track of how many people are on each floor.
  floorsizes = new int[floors];

  for (int i = 0; i < floors; i++) {
	  floorsizes[i] = 0;
	  trojans[i] = NULL;
  }
  
  //used to allow the first line in the file (the floor number) to not 
  //be considered an incorrect line
  int counter = 0;
  
  while(getline(input, curr)) {
     counter++;
	  stringstream ss;
	  ss << curr;
	  ss >> curr;
	  
	  //MOVEIN
	  if (curr == "MOVEIN") {
		  int i,k, dummy;
		  ss >> i;
		  ss >> k;
		  if (ss.fail()) {
			  output << "Error - incorrect command" << endl;
		  }
		  
		  ss >> dummy;
		  if (!ss.fail())
		  {
		     output << "Error - incorrect command" << endl;
		  }
		  else {
		  
		     //check if the floor exists and is empty
		     bool floorExists = false;
		     bool isEmpty = false;
		     for (int f = 0; f < floors; f++)
		     {
		        if ( i == f )
		        {
		           floorExists = true;
		           if ( floorsizes[i] == 0 )
		           {
		              isEmpty = true;
		           }
		        }  
		     }
		     
		     if (!floorExists)
		     {
		        output << "Error - floor " << i << " does not exist" << endl;
		     }
		     else if (!isEmpty)
		     {
		        output << "Error - floor " << i << " is not empty" << endl;
		     }
		     //if the floor is empty, set floorsizes to k and create an
		     //array of new students to live on that floor
		     else if (isEmpty)
		     {
		        floorsizes[i] = k;
		        trojans[i] = new string*[k];
		        for (int s = 0; s < k; s++)
		        {
		           trojans[i][s] = NULL;
		        }
		     }

		  }
	  }
	  //MOVEOUT
	  else if (curr == "MOVEOUT") {
	     int i, dummy;
	     ss >> i;
	     bool isValue = true;
	     if (ss.fail())
	     {
	        output << "Error - incorrect command" << endl;
	        isValue = false;
	     }
	     
	     ss >> dummy;
	     if (!ss.fail())
	     {
	        output << "Error - incorrect command" << endl;
	     }
	     if (isValue)
	     {
	        //check if the floor exists and is empty
		     bool floorExists = false;
		     bool isEmpty = false;
		     for (int f = 0; f < floors; f++)
		     {
		        if ( i == f )
		        {
		           floorExists = true;
		           if ( floorsizes[i] == 0 )
		           {
		              isEmpty = true;
		           }
		        }  
		     }
		     
		     if (!floorExists)
		     {
		        output << "Error - floor " << i << " does not exist" << endl;
		     } 
		     else if (isEmpty)
		     {
		        output << "Error - floor " << i;
		        output << " does not have students" << endl;
		     }
		     else if (!isEmpty)
		     { 
		        //clear out the entire floor by deallocating memory
		        for (int s = 0; s < floorsizes[i]; s++)
		        {
		           if (trojans[i][s] == NULL)
		           {
		             delete[] trojans[i][s];
		             trojans[i][s] = NULL;
		           }
		           else if (trojans[i][s] != NULL)
		           {
		              delete[] trojans[i][s];
		              trojans[i][s] = NULL;
		           }
		        } 
		        delete[] trojans[i];
		        trojans[i] = NULL;
		        floorsizes[i] = 0;
		     }
		  }

	  }
	  //OBTAIN
	  else if (curr == "OBTAIN") {
	     int i, j, k;
	     ss >> i;
	     if (ss.fail()) {
			  output << "Error - incorrect command" << endl;
		  }
	     ss >> j;
	     if (ss.fail()) {
			  output << "Error - incorrect command" << endl;
		  }
	     ss >> k;
	     if (ss.fail()) {
			  output << "Error - incorrect command" << endl;
		  }
		  
	     //check if the floor exists and that the student exists
	     bool floorExists = false;
	     bool studentExists = false;
		  for (int f = 0; f < floors; f++)
		  {
		     if ( i == f )
		     {
		        floorExists = true;
		        if (floorsizes[i] >= j)
		           studentExists = true;
		     }  
		  }
		  //check if the student already has possessions
		  bool hasPossessions = false;
		  if (studentExists)
		  {
		     if (trojans[i][j] != NULL)
		     {
		        hasPossessions = true;
		     }
		  }
		  
		  if (!floorExists)
		  {
		     output << "Error - floor " << i << " does not exist" << endl;
		  }
		  else if (!studentExists)
		  {
		     output << "Error - student " << j << " does not exist";
		     output << " on this floor" << endl;
		  }
		  else if (hasPossessions)
		  {
		     output << "Error - student " << j << " has possessions" << endl;
		  }
		  else
		  {
		      //add the possessions to the student
		      trojans[i][j] = new string[k + 1];
		      stringstream convert;
		      convert << k + 1;
		      trojans[i][j][0] = convert.str();
		      for (int p = 1; p < k + 1; p++)
		      {
		         ss >> trojans[i][j][p];
		      }
		  }
		  
 
	  }
	  //OUTPUT
	  else if (curr == "OUTPUT") {
        int i, j;
        ss >> i;
        ss >> j;
        if (ss.fail())
        {
           output << "Error - incorrect command" << endl;
        }
        
        int dummy;
        ss >> dummy;
        if (!ss.fail())
        {
           output << "Error - incorrect command" << endl;
        }
    
        //check if the student exists
        bool studentExists = false;
        for (int s = 0; s < floorsizes[i]; s++)
        {
           if ( s == j )
           {
              studentExists = true;
           }
        }
        
        //check if the student has possessions
		  bool hasPossessions = false;
		  if (studentExists)
		  {
		     if (trojans[i][j] != NULL)
		     {
		        hasPossessions = true;
		     }
		  }
 
        if (!studentExists)
        {
           output << "Error - student " << j << " does not exist";
           output << " on floor " << i << endl;
        }
        else if (!hasPossessions)
        {
           output << "Error - student " << j << " has no possessions" << endl;
        }
        else if (studentExists && hasPossessions)
        {
           output << "Floor " << i << " Student " << j << " possessions: ";
           output << endl;
           
           for (int p = 1; p < atoi(trojans[i][j][0].c_str()); p++)
           {
              //print out the possessions for the student
              output << trojans[i][j][p] << endl;
           }
      
        }
        
	  }
	  else {
	     if (counter != 1)
	        output << "Incorrect command" << endl;

	  }
  }
  
  //deallocating all memory at conclusion of program
  for (int f = 0; f < floors; f++)
  {
     for (int s = 0; s < floorsizes[f]; s++)
     {
        delete[] trojans[f][s];
        trojans[f][s] = NULL;
     }
     delete[] trojans[f];
  }

  delete[] trojans;
  delete[] floorsizes;
  trojans = NULL;
  floorsizes = NULL;

  
  return 0;
}
