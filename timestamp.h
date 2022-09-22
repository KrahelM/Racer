#ifndef TIMESTAMP_H
#define TIMESTAMP_H

#include <iostream>
#include <math.h>

using namespace std;

class timestamp {
private:
    int hour;
    int min;
    int sec;
    int milli;
    int totalMilli;

public:
    //constructors
    timestamp();
    timestamp(int&);
    timestamp(int, int, int, int);

    //Overloaded operators
    friend bool operator>>(string&, timestamp&);
    timestamp& operator=(const timestamp&);
    int operator-(timestamp&);
    friend ostream& operator<<(ostream&, timestamp&);
   
    //set/get for private data
    void setHour(int);
    void setMin(int);
    void setSec(int);
    void setMilli(int);
    void setTotalMilli(int);
    
    int getHour() const { return hour; }
    int getMin() const { return min; }
    int getSec() const { return sec; }
    int getMilli() const { return milli; }
    int getTotalMilli() const { return totalMilli; }
    
    //Constant Variables
    const int MILLI_PER_HOUR = 3600000;
    const int MILLI_PER_MIN = 60000;
    const int MILLI_PER_SEC = 1000;
    
    //Functions
    timestamp fillTimestamp(const timestamp&);
   
    //Friend classes
    friend class sensor;
    friend class racer;
};
 

#endif