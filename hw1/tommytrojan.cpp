#include <iostream>
#include <fstream>
#include <sstream>

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
  while(getline(input, curr)) {
	  stringstream ss;
	  ss << curr;
	  ss >> curr;
	  
	  //MOVEIN
	  if (curr == "MOVEIN") {
		  int i,k;
		  ss >> i;
		  ss >> k;
		  if (ss.fail()) {
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
		        cout << "Error - floor " << i << " does not exist" << endl;
		     }
		     else if (!isEmpty)
		     {
		        cout << "Error - floor " << i << " is not empty" << endl;
		     }
		     //if the floor is empty set floorsizes the k and create an
		     //array of new students to live on that floor
		     else if (isEmpty)
		     {
		        floorsizes[i] = k;
		        trojans[i] = new string*[k];
		        
		        //create possessions array and set each element to NULL
		        for (int s = 0; s < k; s++)
		        {
		           trojans[i][s] = new string[10];
		        }
		     }

		  }
	  }
	  else if (curr == "MOVEOUT") {
	     int i;
	     ss >> i;
	     if (ss.fail())
	     {
	        output << "Error - incorrect command" << endl;
	     }
	  
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
		     cout << "Error - floor " << i << " does not exist" << endl;
		  } 
		  else if (isEmpty)
		  {
		     cout << "Error - floor " << i << " does not have students" << endl;
		  }
		  else if (!isEmpty)
		  {
		     for (int s = 0; s < floorsizes[i]; s++)
		     {
		        delete[] trojans[i][s];
		     }
		     floorsizes[i] = 0;
		         
		  }

	  }
	  else if (curr == "OBTAIN") {

	  }
	  else if (curr == "OUTPUT") {

	  }
	  else {

	  }
  }
  
  for (int f = 0; f < floors; f++)
  {
     for (int s = 0; s < floorsizes[f]; s++)
     {
        delete[] trojans[f][s];
     }
     delete[] trojans[f];
  }
  
  delete[] trojans;
  delete[] floorsizes;
  
  return 0;
}
