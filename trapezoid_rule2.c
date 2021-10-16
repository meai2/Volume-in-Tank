# include<stdio.h>
# include<conio.h>
# include<math.h>
#include<iostream>

// Declare global variables
double tank_width=0;
double tank_height=0;
double tank_length=0;

// Function: ty in terms of tx
typedef double (*DFD) (double);

// Method to calculate function()
double f(double tx)
{
    double v_a = tank_width / 2.0;
    double v_b = tank_height / 2.0;
    double ty = (v_b / v_a) * sqrt (v_a * v_a - tx * tx);
    return ty;
}

// Method to integrating the function -> Area
double trapezoidal_int(DFD f, double v_a, double v_b, int n)
{
    double tx, dx, sum = 0.0;
    int li = 0;
      dx = (v_b - v_a) / n;
    sum = (f(v_a) + f(v_b)) / 2;
    for (li = 1, tx = v_a + dx; li < n; li++, tx += dx)
        sum += f(tx);
    return 2.0 * sum * dx;
}
// Main method
int main()
{
   // Declare the required variable
    int height_cm;
  
   // Read the user input
    printf("Enter the width of the tank(in m):\n");
    scanf("%lf", &tank_width);

    printf("Enter the height of the tank(in m):\n");
    scanf("%lf", &tank_height);

    printf("Enter the length of the tank (in m):\n");
    scanf("%lf", &tank_length);

    printf("\n");

   // Call the method and calculate the tank capacity
  //  for (height_cm = 10; height_cm <= tank_height * 100; height_cm += 10){
        double hei = height_cm / 100.0;
        double area = trapezoidal_int (&f, tank_height / 2 - hei, tank_height / 2,100);
        double volume = area * tank_length;

        printf ("Depth %d cm: Volume %.6lf cubic metres\n",
                height_cm, volume);
    //}
  // system("pause");
    return 0;
}