#This is a simple makefile. No room for complications here.
volimage: Interface.o VolImage.o
	g++ Interface.o VolImage.o -o volimage

Interface.o:
	g++ -c Interface.cpp
	
VolImage.o: VolImage.cpp VolImage.h
	g++ -c VolImage.cpp
	
clean:
	rm *.o volimage
