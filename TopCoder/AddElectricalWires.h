/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AddElectricalWires.h
 * Author: fukuda
 *
 * Created on 2017/10/29, 19:03
 */

#ifndef ADDELECTRICALWIRES_H
#define ADDELECTRICALWIRES_H


#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

typedef vector<string> svec;
typedef vector<int> ivec;


class Node{
public:
    int id_;
    vector<Node*> connect_;
    int elec_;
    bool visited_;
    
    Node(int id){
        elec_ = -1;
        id_ = id;
        visited_ = false;
    }
    
    int connectElec(int elec,int num){
        if(elec_ == -1){
            elec_ = elec;
            num++;
            for(int i = 0; i < connect_.size() ; i++){
                num = connect_[i]->connectElec(elec,num);
            }
        }
        return num;
    }
    
    int countConnect(int count){
        if(!visited_){
            count++;
            visited_ = true;
            for(int i = 0; i < connect_.size() ; i++){
                if(!connect_[i]->visited_) count = connect_[i]->countConnect(count);
            }
        }
        return count;
    }
};

class AddElectricalWires {
public:
    AddElectricalWires();
    AddElectricalWires(const AddElectricalWires& orig);
    virtual ~AddElectricalWires();
    int maxNewWires(svec wires, ivec gridConnections){
        vector<Node*> nodes;
        
        for(int i = 0; i < wires.size() ; i++){
            Node* n = new Node(i+1);
            nodes.push_back(n);
        }
        
        for(int i = 0; i < wires.size() ; i++){
            for(int j = 0; j < wires[i].length(); j++){
                if(wires[i][j] == '1') nodes[i]->connect_.push_back(nodes[j]);
            }
        }
        
        int maxSubNetNum = -1;
        int maxSubNetConnect = 0;
        for(int i = 0; i < gridConnections.size(); i++){
            int num = nodes[gridConnections[i]]->connectElec(gridConnections[i],0);
            if(maxSubNetNum < num){
                maxSubNetNum = num;
                int count = 0;
                for(int j = 0; j < nodes.size() ; j++){
                    if(nodes[j]->elec_ == gridConnections[i]) count += nodes[j]->connect_.size();
                }
                maxSubNetConnect = count / 2;
            }
        }
        
        for(int i = 0; i < nodes.size(); i++){
            if(nodes[i]->elec_ == -1) maxSubNetNum++;
        }
        
        return maxSubNetNum * (maxSubNetNum - 1) / 2 - maxSubNetConnect;
    }
private:

};

#endif /* ADDELECTRICALWIRES_H */

