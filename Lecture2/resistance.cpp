#include <stdio.h> // for printf, etc
#include <stdlib.h> // for rand(), etc
#include <math.h> // for sin(),cos(), etc
#include <iostream>// for std::cout, etc
#include <iomanip>//  for std::setprecision()
#include <fstream> // for ifstream/ofstream
#include <time.h>// for time(NULL), etc

long double GetExact(long double x){
  long double result = 10. * exp(-x);
  return result;
}

int NumCalc(long double t_reso){
  //  long double t_reso = 0.1;
  // t = t_0 * \tidle{t}, v = v_0 * \tidle{v}  double t_tidle = 0.;
  long double v_tilde = 0.;
  long double t_tilde_min = 0.;
  long double t_range = 0;
  long double delta_t_tilde = 0;
  int N_step = 0;
  //
  long double v_tilde_init = 10.;
  long double t_tilde_max = 1.e3;
  //
  char fname [128];
  std::ofstream file;
  sprintf(fname,"v_tilde_%Lf.dat", t_reso);
  file.open(fname);
  //
  t_range = t_tilde_max - t_tilde_min;
  delta_t_tilde = t_reso;
  N_step = (int) (t_range/t_reso);
  for(int i=0;i<N_step;i++){
    long double exact_v_tilde = 0.;
    exact_v_tilde = GetExact(i*delta_t_tilde);
    if(i==0){
      v_tilde = v_tilde_init;
    }
    else{
      v_tilde *= 1-delta_t_tilde;
    }
    //    std::cout << std::setprecision(32) << i*delta_t_tilde << "\t" << v_tilde << "\t" << exact_v_tilde << "\t" << abs(v_tilde-exact_v_tilde) << std::endl;;
    file << std::setprecision(32) << i*delta_t_tilde << "\t" << v_tilde << "\t" << exact_v_tilde << "\t" << abs(v_tilde-exact_v_tilde) << std::endl;;
  }
  file.close();
  return 0;
}

int main(void){
  long double reso_1 = 0.1;
  long double reso_2 = 0.01;
  long double reso_3 = 0.001;
  NumCalc(reso_1);
  NumCalc(reso_2);
  NumCalc(reso_3);
  return 0;
}
