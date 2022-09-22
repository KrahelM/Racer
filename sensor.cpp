#include <iostream>
#include <vector>
#include <string>
#include "timestamp.h"
#include "sensor.h"



using namespace std;

//Default Constructor
sensor::sensor(){
    sensorNum = 0;
    mileMarker = 0;
    time = timestamp();
}

//3 arg constructor
//Parameters: 
//  num  sensor's sensor Number
//  mile  sensor's mile marker 
//  t  sensor's timestamp
sensor::sensor(int num, double mile, timestamp t){
    sensorNum = num;
    mileMarker = mile;
    time = t;
}

/* setSensorNum sets sensor's sensor number
 * Parameter sensor's sensor number
 * Returns: nothing
 */
void sensor::setSensorNum(int i){
    if(i > 0){
        sensorNum = i;
    }
}
 
/* setMileMarker sets sensor's mile marker
 * Parameter sensor's mile marker
 * Returns: nothing
 */   
void sensor::setMileMarker(double m){
    if(m > 0){
        mileMarker = m;
    }
}
    
/* setTime sets sensor's timestamp
 * Parameter sensor's time timestamp
 * Returns: nothing
 */  
void sensor::setTime(timestamp t){
    cout << "test 15";
    time = t;
    ////time = fillTimestamp(t);
    cout << "test \n\n\n\n ffff \n\n\n";
    
}


/* operator+= overloaded for sensor object to compare one sensor
 * for if sensor's are sequential
 * Parameters:
 *    current sensor member and the following sensor s1
 * Returns true if sequential, false if not sequential
 */
bool sensor::operator+=(const sensor& s1){
    return ((s1.sensorNum) == (sensorNum + 1));
}

/* overloaded assignment operator
 * Parameter: 
 * current sensor member 
 * sensor on right-hand side of =
 * Returns: the sensor on the left-hand side of the =
 */
sensor& sensor::operator=( const sensor& s1){

    this->setSensorNum(s1.sensorNum);
    this->setMileMarker(s1.mileMarker);
    this->setTime(s1.time);
    
    return *this;
}

/* testMPH test's if the MPH between 2 sensors is too fast (>14 MPH)
 * Parameter:
 * Sensor member and following sensor (s1)
 * Returns: true if the speed between the two sensors is less than the 14 MPH,
 * or returns false if faster than the 14 MPH
 */
bool sensor::testMPH(sensor& s1){
    bool test;
    int i = (s1.time - time);
    if( ((s1.mileMarker - mileMarker) * 3600000 / (i)) > 14){
        test = false;
    } else test = true;
    
    return test;
}


/* operator>> overloaded for sensor object
 * Parameters:
 *    string of sensor info that stops at a ; (acts as an input)
 *    s the sensor
 * Returns the input stream
 */
bool operator>>(string& entireLine, sensor& tempS){
    int lengthOfVar;
    
    //Get Sensor number from string
    lengthOfVar = entireLine.find(';');
    tempS.sensorNum = stoi(entireLine.substr(0, lengthOfVar));
    entireLine.erase(0, (lengthOfVar + 1));
 
    //Get mile marker from string
    lengthOfVar = entireLine.find(';');
    tempS.mileMarker = stod(entireLine.substr(0, lengthOfVar));
    entireLine.erase(0, (lengthOfVar + 1));

    //Get timestamp from string
    entireLine >> tempS.time;
    
    
    return 1;
}

/* operator<< overloaded for sensor object
 * Parameters:
 *    outStream the output stream
 *    s the sensor
 * Returns the output stream
 */
ostream& operator<<(ostream& outStream, sensor& s){
    outStream << "\n Sensor Number: " << s.sensorNum;
    outStream << "\n Sensor time: " << s.time.getSec();
    
    return outStream;
}

/* getTotalTime returns the time between 2 sensors (similar to operator -)
 * Parameter:
 * timestamp operator= and operator- are overloaded
 * timestamp has getTotalMilli funtion defined
 * sensor member and sensor number
 * Returns: an int of total milliseconds between the 2 sensors
 */
int sensor::getTotalTime(const sensor& s1){
    int t1;
    int t2;
    
    t1 = s1.time.getTotalMilli();
    t2 = time.getTotalMilli();
    return (t2 - t1);
}