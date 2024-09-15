#include<iostream>
using namespace std;

class Hero{
//properties
int health; // by default - Private

public:
char level;

int gethealth(){
  return health;
}

int getlevel(){
  return level;
}

void sethealth(int h){
  health = h;
}

void setlevel(char ch){
  level = ch;
}

};

int main(){
Hero royce;
  
  // cout<<"Before - any garbage value "<<endl;
  // cout<<"After put in the values"<<endl;
  
  // cout<<"Health is "<< royce.health<<endl;
  // cout<<"Level is "<<royce.level<<endl;

  // //put in the values

  // royce.health = 80;
  // royce.level = 'A';

  cout<<"Using getter and setter method "<<endl;
  cout<<"Health is (any garbage value)"<< royce.gethealth()<<endl;

  cout<<"setter use"<<endl;

  royce.sethealth(60);
  royce.setlevel('B');

  cout<<"Health now is "<<royce.gethealth()<<endl;
  cout<<"Level now is "<<royce.getlevel()<<endl;

}
