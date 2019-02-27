#include "VolImage.h"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace NKNPET001;
  VolImage::VolImage() {
    
  }
  VolImage::~VolImage() {
    
    for(int h=0;h<Nimages;h++){
      for(int i=0;i<height;i++){
      delete[] slices[h][i];
    }
      delete[] slices[h];
    }
  }
  
  bool VolImage::readImages(std::string baseName){
    
    int pos = 0;
    string m = baseName+".dat";
    std::ifstream choice(m.c_str());
    std::string hold; 
    while(std::getline(choice, hold)){
      //cout << hold << endl;
    }
    pos = hold.find(" ");
    width = atoi(hold.substr(0, pos).c_str());
    hold.erase(0, pos + 1);
    pos = hold.find(" ");
    height = atoi(hold.substr(0, pos).c_str());
    hold.erase(0, pos + 1);
    Nimages = atoi(hold.substr(0, pos).c_str());
    
    unsigned char** Rows;
    unsigned char* Columns;
    
    streampos size;
    char * memblock;
    int c = 0;
    string help = baseName;
    ostringstream convert;
    int me = 0;
    
    for(int T = 0;T<Nimages;T++){
      
       convert << me;
      string answer = convert.str();
      help = help + answer + ".raw";
      ifstream file ( help.c_str() , ios::in|ios::binary|ios::ate);
      if (file.is_open())
        {
          //cout << "Reading: " << help << endl;
          size = file.tellg();
          memblock = new char [size];
          file.seekg (0, ios::beg);
          file.read (memblock, size);
          file.close();
          Rows = new unsigned char * [height];
          for(int h=0;h<height;h++){
            Columns = new unsigned char [width];
            for(int w=0;w<width;w++){ 
              Columns[w] = (unsigned int8_t)memblock[c];
              //cout << (unsigned int8_t)memblock[(h)*10+w] << " " ;
             c++; 
           }
           Rows[h] = Columns;  
          }
          //cout << "Pixels are : " << c << endl;
         delete[] memblock;
      
         slices.push_back(Rows);
         c = 0;
        }
      
      else {
        cout << "Unable to open file "<< help << endl;
        return false;      
     }
    
      me++;
      convert.str("");
      help= "brain_mri_raws/MRI";
    
    }
    return true;
  }
  
  void VolImage::diffmap(int sliceI, int sliceJ, std::string output_prefix){
    //cout << "diffmap method called" << endl;
    int c = 0;
    char * holder;
    holder = new char [height*width];
    unsigned char sets;
    ofstream outfile;
    outfile.open (output_prefix.c_str(), ios::out | ios::binary);
    for(int h=0;h<height;h++){
        //cout << "Reading line "<< endl;
      for(int w=0;w<width;w++){
        sets = (unsigned char)(fabs((float)slices[sliceI][h][w] - (float)slices[sliceJ][h][w])/2);
        holder[c] = (char)sets;
        c++;
      }
    
    }
    outfile.write((char*)holder, height*width);
    outfile.close();
    delete [] holder;
    //cout << "done now" << endl;
    cout << "Difference written to: " << output_prefix.c_str() << endl;
  }

  void VolImage::extract(int sliceId, std::string output_prefix){ 
    
    int c = 0;
    char * holder;
    holder = new char [height*width];
    ofstream outfile;
    outfile.open (output_prefix.c_str(), ios::out | ios::binary);
    for(int h=0;h<height;h++){
        //cout << "Reading line "<< endl;
      for(int w=0;w<width;w++){
            
        holder[c] = slices[sliceId][h][w];
        c++;
      }
    
    }
    outfile.write((char*)holder, height*width);
    outfile.close();
    delete [] holder;
    
    cout << "Image extracted to: " << output_prefix.c_str() << endl;
  }
  
  int VolImage::volImageSize(void){
    
    return sizeof(slices[0][0][0])*height*width*Nimages;
    
  }

