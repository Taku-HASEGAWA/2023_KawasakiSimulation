#include <stdio.h> // for printf, etc
#include <stdlib.h> // for rand(), etc
#include <math.h> // for sin(),cos(), etc
#include <iostream>// for std::cout, etc
#include <iomanip>//  for std::setprecision()
#include <fstream> // for ifstream/ofstream
#include <time.h>// for time(NULL), etc

int main(void){
  long double t_reso = 0.1;
  // t = t_0 * \tidle{t}, v = v_0 * \tidle{v}  double t_tidle = 0.;
  long double v_tilde = 0.;
  long double t_tilde_min = 0.;
  long double t_range = 0;
  long double delta_t_tilde = 0;
  int N_step = 0;
  //
  long double v_tilde_init = 10.;
  long double t_tilde_max = 1.e4;
  //
  t_range = t_tilde_max - t_tilde_min;
  delta_t_tilde = t_reso;
  N_step = (int) (t_range/t_reso);
  for(int i=0;i<N_step;i++){
    if(i==0){
      v_tilde = v_tilde_init;
    }
    else{
      v_tilde *= 1-delta_t_tilde;
    }
    std::cout << "v_tilde(" << i*delta_t_tilde << ") = " << v_tilde << std::endl;
  }
  return 0;
}

