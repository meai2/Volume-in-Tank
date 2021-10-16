#include <stdio.h>
#include <math.h>
#include <stdlib.h>
double WIDTH;
double HEIGHT;
double LENGTH;

//Function: y in terms of x
 typedef double (*DFD) (double);
 double f (double x)
 {
 double a = WIDTH / 2.0;
 double b = HEIGHT/ 2.0;
 double y = (b / a) * sqrt (a * a - x * x);

return y;
}

//Integrating the function -> Area
double trapezoidal_int (DFD f ,double a, double b, int n){

 double x, dx, sum=0.0;
 int i=0;
 dx = (b-a)/ n;
 sum = (f(a) + f(b))/2;
 for (i=1, x = a + dx; i < n; i++, x += dx)
  sum += f(x);
 return 2.0 * sum * dx;
 }

int main ()
{
    int h_cm;

    WIDTH = 8.0;                                                
    HEIGHT = 4.0;                                      
    LENGTH = 7.0;

    for (h_cm = 0; h_cm <= HEIGHT * 100; h_cm += 10) {
        double h = h_cm / 100.0;
        double area = 2.0 * trapezoidal_int (&f, HEIGHT / 2 - h,
                                             HEIGHT / 2, 100);
        double volume = area * LENGTH;

        printf ("Depth %d cm:  Volume %.6lf cubic metres\n",
                h_cm, volume);
    }

    return 0;
}