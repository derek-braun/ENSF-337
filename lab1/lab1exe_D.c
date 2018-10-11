/*
*  lab1exe_D.c
*  ENSF - Fall 2018 Lab 1, exercise D
*  Completed by: Student Name
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 9.8   /* gravitation acceleration 9.8 m/s^2 */
#define PI 3.141592654

void create_table(double v);
double Projectile_travel_time(double a, double v);
double Projectile_travel_distance(double a, double v);
double degree_to_radian(double d);

int main(void)
{
    int n;
    double velocity;
    
    printf ("please enter the velocity at which the projectile is launched (m/sec): ");
    n = scanf("%lf" ,&velocity);
    
    if(n != 1)
    {
        printf("Invlid input. Bye...");
        exit(1);
    }
    
    while (velocity < 0 )
    {
        printf ("please enter a positive number for velocity: ");
        n = scanf("%lf", &velocity);
        if(n != 1)
        {
            printf("Invlid input. Bye...");
            exit(1);
        }
    }
    
    create_table(velocity); 
    
    return 0;
}

void create_table(double v){
	int deg = 0;
	double rad;
	double time;
	double dist;
	
	printf("Angle \t\t t \t\t d\n(deg) \t\t (sec) \t\t (m)\n");
	
	while(deg <= 90){
		rad = degree_to_radian(deg);
		time = Projectile_travel_time(rad, v);
		dist = Projectile_travel_distance(rad, v);
		printf("%lf \t %lf \t %lf\n", rad, time, dist);
		
		deg += 5;
	}
}

double Projectile_travel_time(double a, double v){
	double t;
	t = 2*v*sin(a);
	t = t/G;
	return t;
}

double Projectile_travel_distance(double a, double v){
	double d;
	d = pow(v, 2)/G;
	d = d*sin(2*a);
	return d;
}

double degree_to_radian(double d){
	return ((PI/180)*d);
}
/* UNCOMMENT THE CALL TO THE create_table IN THE main FUNCTION, AND COMPLETE THE PROGRAM */

