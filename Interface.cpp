#include "VolImage.h"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <vector>

using namespace NKNPET001;

int main(int argc, char *argv[]) {
  
  if (argc == 2){
    VolImage trial;
    trial.readImages(argv[1]);
    cout << "Number of images: " << trial.Nimages << endl;
    cout << "Number of bytes required: "<< trial.volImageSize() << endl;
  }
  
  else if ( argc == 6 ){
    VolImage trial;
  
    if(trial.readImages(argv[1])){
      //cout << "files read" << endl ;
    }
    else{cout << "unfortunately not" << endl ;}
    int i = atoi(argv[3]);
    int j = atoi(argv[4]);
    string fname = argv[5];
    trial.diffmap(i,j,fname);
    //cout << "diff map called" << endl;
    
  }
  
  else if ( argc == 5 ){
    VolImage trial;
    if(trial.readImages(argv[1])){
      //cout << "files read" << endl ;
    }
    
    int i = atoi(argv[3]);
    string fname = argv[4];
    trial.extract(i,fname);
    //cout << "extract called " << endl;
    
  }
  return 0;
  
}