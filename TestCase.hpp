/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TestCase.hpp
 * Author: Yoni
 *
 * Created on June 11, 2018, 9:31 PM
 */

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class TestCase{
  
    string Test_name;
    ostream out;
    int passed, failed,total;

public: 
TestCase(string test_name,ostream& os) : out(cout.rdbuf()){
    Test_name=test_name;
    passed=0;
    failed=0;
    total=0;
}

template<typename Temp, typename Temp2>
TestCase& check_equal(Temp a,Temp2 b){
    total++;
    if(a==b)
        passed++;
    else{
        out<<Test_name<<" : Failure in test #"<<total<<" : "<<a<<" should equal "<<b<<"!"<<endl;
        failed++;
    }
    return *this;
}

template<typename Temp, typename Temp2>
TestCase& check_different(Temp a,Temp2 b){
    total++;
    if(a!=b)
        passed++;
    else{
        out<<Test_name<<" : Failure in test #"<<total<<" : "<<a<<" should equal "<<b<<"!"<<endl;
        failed++;
    }
    return *this;
}

template<typename fun_temp,class Temp,class Temp2>
TestCase& check_function(fun_temp fun,const Temp a,const Temp2 b){
     total++;
    int result=(*fun)(a);
            
    if(result == b)
     passed++;
 
    else{
        out<<Test_name<<" : Failure in test #"<<total<<" : "<<a<<" should equal "<<b<<"!"<<endl;
        failed++;
    }
    return *this;

}
template<class Temp>
TestCase& check_output(Temp a,string str){
    total++;
    stringstream ss;
    ss<<a;
    if(ss.str()==str)
     passed++;
 
    else{
        out<<Test_name<<" : Failure in test #"<<total<<" : "<<a<<" should equal "<<str<<"!"<<endl;
        failed++;
    }
    return *this;

}
void print(){
   out<<Test_name<<" : "<<failed<<" Failed ,"<<passed<<" Passed ,"<<total<<" Total "<<endl;

}

};