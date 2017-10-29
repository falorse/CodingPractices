/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: fukuda
 *
 * Created on 2017/10/29, 16:17
 */

#include <cstdlib>
#include "AddElectricalWires.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    AddElectricalWires aew;
    vector<string> wires;
    vector<int> gridConnections;
    wires.push_back("01000");
    wires.push_back("10100");
    wires.push_back("01010");
    wires.push_back("00100");
    wires.push_back("00000");
    gridConnections.push_back(2);
    gridConnections.push_back(4);
    
    cout << aew.maxNewWires(wires,gridConnections) << endl;
    return 0;
}

