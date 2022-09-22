/* File: main.cpp
 * Description: This application initially reads 
 * racer data from a text file that contains data 
 * from electronic mats for a race and computes 
 * statistics for each racer
 */ 


#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include "racer.h"
#include "sensor.h"
#include "timestamp.h"


using std::vector;
using namespace std;




int main()
{
	string fileName;
    string headerLine;
    int i = 0;
    ifstream in;
    int j = 0;
    string junk;
    int lengthOfVar;
    int numRaceSensors;
    vector<racer> r;
    double raceDistance;
    timestamp raceTotal;
    racer tempR;
    racer tempR2;
    
    

    
    //Output header and get filename
    cout << "\nWelcome to Racers Central \n";
    cout << "Enter race file: ";
    cin >> fileName;
    cout << "\n";
    
    //Open File
    in.open( fileName, ios::in );
    
    //Test if file opened
    if ( !in.fail() ) {
        //read race data
        //Header line
        
        //Total Race time
        getline(in, headerLine);
        headerLine >> raceTotal;
        
        //Total number of sensors
        lengthOfVar = headerLine.find(';');
        
        numRaceSensors = stoi(headerLine.substr(0, lengthOfVar));
        
        headerLine.erase(0, (lengthOfVar + 1));
        
        
        //Total Race Distance
        raceDistance = stod(headerLine);
        
        
        //Get racers
        while(!in.eof()){
            i++;
            in >> tempR;
            r.push_back(tempR);
        }
        
        //Sort Racers
        sort(r.begin(), r.end());

        
        
        
        //Print Race Results
        //Print Header
        cout << "\n" << setw(30) << left << "Name";
        cout << setw(6) << right << "Number";
        cout << setw(16) << left << "       Time";
        cout << "\n----------------------------------------------------\n";
        
        //Print Racers
        while(j < r.size()){
            cout.fill(' ');
            cout << r[j];
            cout << "\n";
            
            j++;
        }
        
        //Print Exit Message
        cout << "\nThank you for using Racers Central, Knoxville's Best Racing Software \n \n";
        
            
        
    } else{ //File not loaded
        cout << "error loading file \n";
    }
    in.close();

    
	return 0;
}
