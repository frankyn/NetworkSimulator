#ifndef POISSON_FORMULA
#define POISSON_FORMULA

double poissonFormula(double k){
 
  double e=2.71828;
  double lambda=0.5;

  //calculate lambda^k
  int power=2;
  double a=lambda;
  double fa=lambda;
  while(power <= k){
    fa=fa*a;
    power++;
  }

  //calculate k!  
  double c=k-1;
  double fc=k;
  while(c!=0){
    fc=fc*c;
    c--;
  }

  double answer=(fa*0.60653)/fc;

  return answer;
}//end formula

#endif