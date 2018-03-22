#include "Signal.h"
#include <limits>
#include <cstddef>
signal::signal() : data() {

}

void signal::setData(int size, int* values){
  for(int i=0; i<size; i++)
    data.push_back(values[i]);
}

int signal::getData(int pos){
  return data[pos];
}

float signal::pedestal(){
  return (getData(0)+getData(1)+getData(2))/3.;
}

float signal::maximo(){
  float max=std::numeric_limits<float>::lowest();
  for(unsigned int i=0; i<data.size(); i++){
    if(data[i]>max) max=data[i];
  }
  return max;
}

float signal::charge(){
  float charge=0;
  float ped=pedestal();
  for(unsigned int i=0; i<data.size(); i++){
    charge+=(data[i]-ped);
  }
   return charge;
}

float signal::minimo(){
  float mini=std::numeric_limits<float>::min();
  for(unsigned int i=0; i<data.size(); i++){
    if(data[i]<mini) mini=data[i];
  }
  return mini;
}

float signal::area(){
  float area=0;
  float ped=pedestal();
  for(unsigned int i=0; i<data.size(); i++){
    area+=(data[i]-ped)*0.25;
  }
   return area;
}

