#ifndef VOLIIMAGE_H
#define VOLIIMAGE_H
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <vector>

using namespace std;
namespace NKNPET001{
class VolImage
{
  private: // private members
    int width, height; // width and height of image stack
    std::vector<unsigned char**> slices; // data for each slice, in order
  public: // public members
    int Nimages;
    VolImage(); // default constructor - define in .cpp
    ~VolImage(); // destructor - define in .cpp file
    // populate the object with images in stack and
    //set member variables define in .cpp
    bool readImages(std::string baseName);
    // compute difference map and write out; define in .cpp
    void diffmap(int sliceI, int sliceJ, std::string output_prefix);
    // extract slice sliceId and write to output - define in .cpp
    void extract(int sliceId, std::string output_prefix);
    // number of bytes uses to store image data bytes
    //and pointers (ignore vector<> container, dims etc)
    int volImageSize(void); // define in .cpp
};
}
#endif