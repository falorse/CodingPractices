/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Aaagmnrs.cpp
 * Author: fukuda
 * 
 * Created on 2017/10/29, 16:17
 */


#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

/*
 * 
 */

class charCount{
public:
    int count_[256];
    charCount(int count[]){
        for(int i = 0; i < 256 ; i++){
            count_[i] = count[i];
        }
    }
};
class Aaagmnrs {

public:
    charCount countChars(string str){
        int count[256] = {};
        for(int i = 0; i < str.length() ; i++){
            if(str[i] == 32) continue;
            int p = str[i] < 97 ? str[i] + 32 : str[i];
            count[p]++;
        }
        charCount cc(count);
        return cc;
    }
    
    bool equal(charCount count1, charCount count2){
        for(int i = 0; i < 256 ; i++){
            if(count1.count_[i] != count2.count_[i]) return false;
        }
        return true;
    }
    
    vector<string> anagrams(vector<string> phrases) {
        vector<charCount> counts;
        int size = phrases.size();
        
        bool output[size];
        for(int i = 0; i < size ; i++){
            output[i] = true;
        }
        
        for(int i = 0; i < size; i++){
            counts.push_back(countChars(phrases[i]));
        }
        
        for(int i = 0; i < size - 1; i++){
            for(int j = i + 1 ; j < size;j++){
                if(!output[j]) continue;
                output[j] = !equal(counts[i], counts[j]);
            }
        }

        vector<string> returnPhrases;
        returnPhrases.resize(size);
        for(int i = 0; i < size ; i++){
            if(output[i]) returnPhrases.push_back(phrases[i]);
        }
        
        for(int i = 0; i < returnPhrases.size(); i++){
            cout << returnPhrases[i] <<endl;
        }
        return returnPhrases;
    }
};