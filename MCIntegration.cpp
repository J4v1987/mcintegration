/*
Monte Carlo Integration Method Implementation
Integrate f(x)=x^2 sin^2(x) along [0,1), given in line 43 "...sum"
Obtains integral estimage along (-1,1) by multiplying a factor of 2, given in line 44 "...2*sum"

Preconditions:
    f(x)=f(-x)
    Monte Carlo integration to be done along [0,1) due to scope of dran48
    If f:[0,1)→ℝ, f(x) ∀x∈[0,1) ∧ f(x)=-f(-x),
        then f(x) may need to be shifted along x axis to suit integration needs.
        and line 44 output shall be omitted.

Usage:
    Changing f(x) definition in line 23 "INSERT HERE f(x)"
    Changing x(p) definition in line 21 "INSERT HERE x(p)"
    Changing w(x) definition in line 24 "INSERT HERE w(x)"

Drafter: Javier Alonzo ROMO LEON
Based on the works of:
    Prof. Christoph HARTNACK,
    with IMT Atlantique,
    Nantes, France.
*/

# include <stdlib.h>                                // in c for using drand48 ()
# include <stdio.h>                                 // for using printf
# include <math.h>                                  // for using math functions
int main(){                                         // start of program
int i,N;                                            // index, num of events
double x,p,fx,wx,fw,sum,sum2,err;                   // values of x,y f (x)...
printf("Enter number of N events:");
scanf ("%d",&N);                                    // do not forget the pointer of scanf
printf ("\nCalculation using %d events\n",N);       // statistics
sum=0; sum2=0;                                      // initialize sum and sum2

for (i=0; i<N; i++) {                               // loop on event number
    p=drand48();                                    // random number in (0,1)
    x=pow(p,0.2);                                   // INSERT HERE x(p)
    fx=pow(x,2)*pow(sin(x),2);                      // INSERT HERE f(x)
    wx=5*pow(x,4);                                  // INSERT HERE w(x)
    fw=fx/wx;                                       // just the quotient
    sum+=fw;                                        // sum up f/w
    sum2+=fw*fw;                                    // sum up (f/w) **2
};                                                  // end of loop
sum/=N;                                             // average <f/w>
sum2/=N;                                            // average <(f/w) **2>
err=sqrt((sum2-sum*sum)/N);                         // theoretical precision

printf ("Result %f +- %f along [0,1]\n",sum, err);  // print results
printf ("est. result %f along [-1,1]\n",2*sum);
};                                                  // end of the program