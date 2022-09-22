/* File: racer.cpp 
 * Author: Matthew Krahel
 * Description: implements a Racer class
 */


#include <string>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "racer.h"
#include "sensor.h"

using namespace std;

//Default Constructor
racer::racer(){
    rName = "";
    rNum = 0;
    suspect = true;
}

/* operator>> overloaded for racer object
 * Parameters:
 *    inStream the input stream
 *    r the racer
 * Returns the input stream
 */
istream& operator>>(istream& in, racer& r){
    string entireLine;
    string junk;
    sensor tempS;
    int lengthOfVar;
    int i = 0;
    int numSensors;
    int k;
    int l = 0;
    int m = 0;
    timestamp tempT;
    
    //Get Racer info into string
    getline(in, entireLine);
    
    //Get Racer Name from string
    lengthOfVar = entireLine.find(';');
    r.rName = entireLine.substr(0, lengthOfVar);
    entireLine.erase(0, (lengthOfVar + 1));
    
    //Get Racer Number from string
    lengthOfVar = entireLine.find(';');
    r.rNum = stoi(entireLine.substr(0, lengthOfVar));
    entireLine.erase(0, (lengthOfVar + 1));
    
    //Create Sensors
    r.s.clear();
    while((entireLine.find(';') != -1) && i < 100){ //loop until end of the racers info
        //get sensor number, mile marker number, and time 
        entireLine >> tempS;
        r.s.push_back(tempS);
        i++;
    }
    
    //getRacerTotalTime
    numSensors = (r.s.size());
    k = (r.s[numSensors-1].getTotalTime(r.s[0]));
    timestamp racerTotalTime(k);
    r.racerTotalTime = racerTotalTime;
    
    //test if racer is suspect
    //Test if each sensor is following the next
    numSensors = (r.s.size());
    r.suspect = true;
    while (l < (numSensors - 1) && r.suspect == true){
        r.suspect = r.s[l] += r.s[l+1];
        l++;
    }

    //Test if speed between 2 sensor is too fast
    while (m < (numSensors - 1) && r.suspect == true){
        r.suspect = r.s[m].testMPH(r.s[m+1]);
        m++;
    }
    
    //Add asterick to cheater
    if(r.suspect == false){
        r.rName.insert(0, "*");
    }
    
    return in;
}

/* operator<< overloaded for racer object
 * Parameters:
 *    outStream the output stream
 *    r the racer
 * Returns the output stream
 */
ostream& operator<<( ostream& outStream, racer& r) {
    
    outStream << setw(30) << left << r.rName;
    outStream << setw(6) << right << r.rNum;
    outStream << r.racerTotalTime;
    

    return outStream;
}

/* overloaded assignment operator
 * Parameter racer on right-hand side of =
 * Returns: the racer on the left-hand side of the =
 */
racer& racer::operator=( const racer& r1){
    ////int i = 0;
    rName = r1.rName;
    rNum = r1.rNum;
    racerTotalTime = r1.racerTotalTime;
    suspect = r1.suspect;
    
    ////while( i < (r1.s.size())){
        ////s[i] = r1.s[i];
        ////i++;
    ////}
    
    return *this;
}

/* operator< returns true if one racer r1 < r2  (if one racer's total milliseconds < another)
 * Parameters two racers
 * Returns true if b1.racerTotalTime < b2.racerTotalTime
 */
bool operator<( const racer& r1, const racer& r2){
    
    if(r1.racerTotalTime.getTotalMilli() < r2.racerTotalTime.getTotalMilli()){
        return (true);
    } else {
        return (false);
    }
}


////bool racer::lessThan( const racer& r1, const racer& r2){
    ////if(r1.racerTotalTime.getTotalMilli() < r2.racerTotalTime.getTotalMilli()){
        ////return (true);
    ////} else {
        ////return (false);
    ////}
////}