#include <stdio.h> // for printf, etc
#include <stdlib.h> // for rand(), etc
#include <math.h> // for sin(),cos(), etc
#include <iostream>// for std::cout, etc
#include <iomanip>//  for std::setprecision()
#include <fstream> // for ifstream/ofstream
#include <time.h>// for time(NULL), etc


long double Return_v(long double v, long double x, long double delta_t){
  return v-x*delta_t;
}

long double ReturnEuler_x(long double v, long double x, long double delta_t){
  return v*delta_t+x;
}

long double ReturnSemiEuler_x(long double v, long double x, long double delta_t){
  return v*delta_t+x*(1-delta_t*delta_t);
}

int IntegrateEuler(long double v_0, long double x_0, long double t_max, long double delta_t){
  int N = (int)(t_max/delta_t);
  long double v[N];
  long double x[N];
  v[0] = v_0;
  x[0] = x_0;
  //
  char fname [128];
  std::ofstream file;
  sprintf(fname,"Euler_%Lf.dat",delta_t);
  file.open(fname);
  //
  for(int i=0;i<N;i++){
    v[i+1] = Return_v(v[i],x[i],delta_t);
    x[i+1] = ReturnEuler_x(v[i],x[i],delta_t);
    file<<std::setprecision(32)<<
      i <<"\t"<<
      v[i] <<"\t"<<
      x[i] <<"\t"<<
      v[i]*v[i]+x[i]*x[i] <<"\t"<<
      (v_0*v_0+x_0*x_0)-(v[i]*v[i]+x[i]*x[i]) <<
      std::endl;
  }
  return 0;
}

int IntegrateSemiEuler(long double v_0, long double x_0, long double t_max, long double delta_t){
  int N = (int)(t_max/delta_t);
  long double v[N];
  long double x[N];
  v[0] = v_0;
  x[0] = x_0;
  //
  char fname [128];
  std::ofstream file;
  sprintf(fname,"SemiEuler_%Lf.dat",delta_t);
  file.open(fname);
  //
  for(int i=0;i<N;i++){
    v[i+1] = Return_v(v[i],x[i],delta_t);
    x[i+1] = ReturnSemiEuler_x(v[i],x[i],delta_t);
    file<<std::setprecision(32)<<
      i <<"\t"<<
      v[i] <<"\t"<<
      x[i] <<"\t"<<
      v[i]*v[i]+x[i]*x[i] <<"\t"<<
      (v_0*v_0+x_0*x_0)-(v[i]*v[i]+x[i]*x[i]) <<
      std::endl;
  }
  return 0;
}

int main(void){
  long double a = 1.;
  long double t_max = 100.;
  long double v_0 = 0.;
  long double x_0 = a;
  long double delta_t[] = {1.0, 0.75, 0.5, 0.25, 0.1, 0.05, 0.025, 0.01, 0.005, 0.001, 0.0001, 0.00001};
  for(int i=0;i<(int)(sizeof(delta_t))/(sizeof(long double));i++){
    IntegrateEuler(v_0, x_0, t_max, delta_t[i]);
    IntegrateSemiEuler(v_0, x_0, t_max, delta_t[i]);
  }
  return 0;
}
