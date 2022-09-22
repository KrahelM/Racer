#include <iostream>
#include <math.h>
#include <iomanip>
#include "timestamp.h"

using namespace std;

//Default Constructor
timestamp::timestamp(){
    hour = 0;
    min = 0;
    sec = 0;
    milli = 0;
    totalMilli = 0;
} 

//1 arg constructor
//Parameters: 
//  total total milliseconds
timestamp::timestamp(int& total){
    hour = floor(total / MILLI_PER_HOUR);
    min = ((total % MILLI_PER_HOUR) / MILLI_PER_MIN);
    sec = (((total % MILLI_PER_HOUR) % MILLI_PER_MIN) / MILLI_PER_SEC);
    milli = (((total % MILLI_PER_HOUR) % MILLI_PER_MIN) % MILLI_PER_SEC);
    totalMilli = total;
}

//5 arg constructor
//Parameters: 
//  h  hours
//  m  minutes
//  s  seconds
//  mil  milliseconds
timestamp::timestamp(int h, int m, int s, int mil){
    hour = h;
    min = m;
    sec = s;
    milli = mil;
    totalMilli = (( hour * MILLI_PER_HOUR) + ( min * MILLI_PER_MIN) + (sec * MILLI_PER_SEC) + (milli));
} 

/* setHour sets timestamp hours
 * Parameters integer of hour
 * Returns: nothing
 */
void timestamp::setHour(int h){
    hour = h;

}

/* setMin sets timestamp minutes
 * Parameters integer of minutes
 * Returns: nothing
 */
void timestamp::setMin(int m){
    min = m;
}

/* setSec sets timestamp seconds
 * Parameters integer of seconds
 * Returns: nothing
 */
void timestamp::setSec(int s){
    sec = s;
}

/* setMilli sets timestamp milliseconds
 * Parameters integer of milliseconds
 * Returns: nothing
 */
void timestamp::setMilli(int m){
    milli = m;
}

/* setTotalMillis sets timestamp total milliseconds
 * Parameters integer of milliseconds
 * Returns: nothing
 */
void timestamp::setTotalMilli(int m){
    totalMilli = m;
}

/* fillTimestamp fills a timestamp from other timestamp (similar to overloading = operator)
 * Parameters:
 * timestamp member to be filled
 * full timestamp (t)
 * Returns: the filled timestamp member
 */
timestamp timestamp::fillTimestamp(const timestamp& t){
    hour = t.hour;
    min = t.min;
    sec = t.sec;
    milli = t.milli;
    totalMilli = t.totalMilli;
    return *this;
}

/* operator- overloaded for timestamp object
 * Parameters:
 *    timestamp on right side of - to be subtracted from timestamp of left side of -
 * Returns integer of difference between timestamps
 */
int timestamp::operator-(timestamp& t1){
    int i;
    i = totalMilli - t1.totalMilli;
    timestamp tempT(i);
    return i;
}

/* operator>> overloaded for timestamp object
 * Parameters:
 *    string of timestamp info that stops at a ; (acts as an input)
 *    t the timestamp
 * Returns true
 */
bool operator>>(string& entireLine, timestamp& t){
    int lengthOfVar;
    const int MILLI_PER_HOUR = 3600000;
    const int MILLI_PER_MIN = 60000;
    const int MILLI_PER_SEC = 1000;
    
    //Get hour
    lengthOfVar = entireLine.find(':');
    t.hour = stoi(entireLine.substr(0, lengthOfVar));
    entireLine.erase(0, (lengthOfVar + 1));
    
    //Get Minutes
    lengthOfVar = entireLine.find(':');
    t.min = stoi(entireLine.substr(0, lengthOfVar));
    entireLine.erase(0, (lengthOfVar + 1));
    
    //Get Seconds
    lengthOfVar = entireLine.find(':');
    t.sec = stoi(entireLine.substr(0, lengthOfVar));
    entireLine.erase(0, (lengthOfVar + 1));   
    
    //Get Milliseconds
    lengthOfVar = entireLine.find(';');
    t.milli = stoi(entireLine.substr(0, lengthOfVar));
    entireLine.erase(0, (lengthOfVar + 1));
    
    //Get Total Milliseconds
    t.totalMilli = (( t.hour * MILLI_PER_HOUR) + ( t.min * MILLI_PER_MIN) + (t.sec * MILLI_PER_SEC) + (t.milli));
    
    return true;
}

/* overloaded assignment operator
 * Parameter: 
 * current timestamp member 
 * timestamp on right-hand side of =
 * Returns: the timestamp on the left-hand side of the = 
 */
timestamp& timestamp::operator=(const timestamp& t){

    hour = t.hour;
    min = t.min;
    sec = t.sec;
    milli = t.milli;
    totalMilli = t.totalMilli;

    return *this;
}
    
/* operator<< overloaded for timestamp object
 * Parameters:
 *    outStream the output stream
 *    t the timestamp
 * Returns the output stream
 */
ostream& operator<<(ostream& outStream, timestamp& t){
    setprecision(-2);
    outStream.fill('0');
    
    outStream << "    ";
    outStream << setw(2) << right << t.hour << ":";
    outStream << setw(2) << right << t.min << ":";
    outStream << setw(2) << right << t.sec << ":";
    outStream << setw(2) << right << t.milli;
    
    return outStream;
}