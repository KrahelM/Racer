#ifndef RACER_H
#define RACER_H

#include <iostream>
#include <string>
#include <vector>

#include "sensor.h"
#include "timestamp.h"

using namespace std;

class racer {
private:
    timestamp racerTotalTime;
    string rName; //Racers name
    int rNum; //Race number
    vector<sensor> s; //vector of sensors
    bool suspect;
    
public:
    //constructors
    racer();

    //Overloaded operators
    friend istream& operator>>(istream&, racer&); 
    friend ostream& operator<<( ostream&, racer&);
    racer& operator=(const racer&);
    friend bool operator<( const racer&, const racer&);
    
    //Fuctions
    ////bool lessThan( const racer&, const racer&);
    
    //Friend classes
    friend class sensor;
    friend class timestamp;

};


#endif