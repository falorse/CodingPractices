/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AlienAndHumbergers.cpp
 * Author: fukuda
 * 
 * Created on 2017/10/29, 16:38
 */
#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class ScoreCounter{
public:
    vector<int> types_;
    int totalTastes_;
    int score_;
    
    ScoreCounter(){
        totalTastes_ = 0;
        score_ = 0;
    }
    
    bool eatable(int type,int taste){
        bool has = false;
        for(int i = 0; i < types_.size() ; i++){
            if(type == types_[i]) has = true;
        }
        //点数が大きくなるなら食べてtrue
        //減るなら食べずにfalse
        if(has){
            if(taste < 0) return false;
            else{
                totalTastes_ += taste;
        cout << type << " " << taste <<endl;
                score_ = score();
                return true;
            }
        }else{
            if(taste >= 0){
                totalTastes_ += taste;
                types_.push_back(type);
        cout << type << " " << taste <<endl;
                score_ = score();
                return true;
            }else{
                if( ((int)types_.size() + 1) * (totalTastes_ + taste ) >= score_) {
                    types_.push_back(type);
                    totalTastes_ += taste;
        cout << type << " " << taste << " " << totalTastes_<<endl;
                    score_ = score();
                    return true;
                }else{
                    return false;
                }
            }
        }
    }
    
    int score(){
        return types_.size() * totalTastes_;
    }
};

class AlienAndHumbergers{
public:
    int getNumber(vector<int> ty, vector<int> ta){

        ScoreCounter sc;
        int size = ty.size();
        for(int i = size -1 ; i > -1 ; i--){
            if(ta[i] > 0){
                sc.eatable(ty[i],ta[i]);
                ta.erase(ta.begin() + i);
                ty.erase(ty.begin() + i);
            }
        }
        
        bool eat = true;
        while(eat){
            eat = false;
            for(int i =  ta.size() - 1; i > -1; i--){
                if(sc.eatable(ty[i],ta[i])){
                    eat = true;
                    ta.erase(ta.begin() + i);
                    ty.erase(ty.begin() + i);
                }
            }
        }
        
        return sc.score_;
    }
};