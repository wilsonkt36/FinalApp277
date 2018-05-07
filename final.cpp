//Final App
//Name:Kyle Wilson
//Date:5/7/2018
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
 
//declared a class for the functions
class myWork
{
    public:
        
        int Ex;
        int reps;
        double repsMax;
        double weight;
        float ORM;
        
        
        //Function for journal entry feature
        void getWork()
        
        { 
          //opens/creates the output file
         ofstream file("work.txt", std::ios_base::app);
          if(!file){
          cout<<"Error creating file..";
           return;
        }
        else
       {
         cout<<"work.txt File created successfully.\n"<<endl;
        }
        
          cout << "This part of the program allows you to enter your workout and whatever details you wish to record. This can be sets, reps, weight, percentages, comments, etc. It is simply for journaling purposes." << endl;
          
          
        cout << "--------------------------------------------------------------------------------" << endl;
        
          cout << "Enter how many excersises you will enter: ";
          cin >> Ex;
          
          //declared an array, which is where the entries will be stored
          string ExName[Ex] = {};
          
          cout << "Enter in the following format: ExcersiseName//setsXreps//weight//misc.DO NOT USE SPACES" << endl;
          
          //add string
          
          string journal;
          
          //arrays start with zero so i initialized to 0
          for (int i = 0; i < Ex; i++)
          {
            //this loops for as many times as you entered previously
            cout << "Enter excersise " << i + 1<< ": ";
          
            cin>> journal;
            
            ExName[i] = journal;
          
          }
          
          for (int i = 0; i < Ex; i++)
          {
            //this writes the entry into the text file
           
           file << ExName[i] <<endl;
            
          }
          
          
 
          //closes the file after it is done looping
          file.close();  
    cout<<"\nwork.txt File saved and closed succesfully."<<endl;
           
        }
        
        
        
        
        //function that calculates a one rep max
        void getOneRep()
        {
          cout << "This program takes the weight lifted and for how many reps and uses the Epley formula to calculate a one rep max" << endl;
          cout << "----------------------------------------------" << endl;
          cout << "Enter the weight lifted: " ;
          cin >> weight;
          cout << "Enter the amount of repetitions: ";
          cin >> repsMax;
          ORM = weight * (1 + (repsMax/30));
          cout << " One rep Max (100%): " << ORM;
        }
        
        
        
        
        
        
        
        //funtion that reads the journal entries and displays them on console.
        void getJournal(){
          
          ifstream file1;
    
    
          file1.open("work.txt",ios::in);
    
    
          if(!file1){
                      cout<<"Error in opening file..";
                      return;
                    }
                    else{
                  //cout<<"\nwork.txt File read successfully, here is the list:"<<endl;
                         }
        string line;
        
        while(getline(file1,line))
      {
        cout << line << endl;
      }
        file1.close();
        }
  
};
 
int main()
{
  //declare object s for opening the functions
  myWork s;
 int choice;
    
 //menu that displays choices
  cout << "This program is a multi-purpose weighlifting program. Enter which function you would like to use" << endl;
  cout << "------------------------------------------" << endl;
  cout << "1. Enter in Journal" << endl;
  cout << "2. One Rep Max Calculator" << endl;
  cout << "3. Open Journal" << endl;
  cout << "Enter choice: " ;
  
  cin >> choice;
  
  //switch statement that allows user to pick option
  switch (choice) {
    case 1 : s.getWork();
    break;
    case 2 : s.getOneRep();
    break;
    case 3 : s.getJournal();
    break;
    default : cout << "Error, please enter 1-3" << endl;
    break;
  }
       
 
   
 
    
     
    return 0;
}
