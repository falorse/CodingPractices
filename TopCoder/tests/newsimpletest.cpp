/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   newsimpletest.cpp
 * Author: fukuda
 *
 * Created on 2017/10/29, 16:45
 */

#include <stdlib.h>
#include <iostream>
#include <AlienAndHumbergers.cpp>

using namespace std;
/*
 * Simple C++ Test Suite
 */

void test1() {
    std::cout << "newsimpletest test 1" << std::endl;
    AlienAndHumbergers a;
    vector<int> ty;
    vector<int> ta;
    ty.push_back(1);
    ty.push_back(1);
    ta.push_back(-1);
    ta.push_back(-1);
    cout<< a.getNumber(ty,ta) << endl;
    
    
    vector<int> ty2;
    vector<int> ta2;
    ty2.push_back(1);
    ty2.push_back(2);
    ty2.push_back(3);
    ta2.push_back(3);
    ta2.push_back(6);
    ta2.push_back(-2);
    cout << a.getNumber(ty2,ta2) << endl;
}

void test2() {
    std::cout << "newsimpletest test 2" << std::endl;
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% newsimpletest" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% test1 (newsimpletest)" << std::endl;
    test1();
    std::cout << "%TEST_FINISHED% time=0 test1 (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% test2 (newsimpletest)\n" << std::endl;
    test2();
    std::cout << "%TEST_FINISHED% time=0 test2 (newsimpletest)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

