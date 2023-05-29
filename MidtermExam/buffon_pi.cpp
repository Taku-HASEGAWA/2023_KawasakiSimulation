#include <stdio.h> // for printf, etc
#include <stdlib.h> // for rand(), etc
#include <math.h> // for sin(),cos(), etc
#include <iostream>// for std::cout, etc
#include <iomanip>//  for std::setprecision()
#include <fstream> // for ifstream/ofstream
#include <time.h>// for time(NULL), etc

int main(void){
  long int i, count = 0;
  long int max = 5e+14;
  long double theta, y_c, z, pi,out=1.e+2;
  char fname[128];
  std::ofstream file;
  srand(time(NULL));
  sprintf(fname,"buffon-pi-error.dat");
  file.open(fname);
  for(i=0;i<max;i++){
    theta = (long double)rand()*0.5*M_PI/RAND_MAX;
    y_c = (long double)rand()/RAND_MAX;
    z = cos(theta);
    if(y_c<=z)
      count++;
    if(i>=(long int)out){
      pi= (long double)i * 2. / (long double)count;
      file<<std::setprecision(32)<<i<<"\t"<<pi<<"\t"<<abs(pi-M_PI)<<std::endl;;
      std::cout<<std::setprecision(32)<<i<<"\t"<<pi<<"\t"<<abs(pi-M_PI)<<std::endl;
      out*=1.00001;
    }
  }
  file.close();
  return 0;
}
