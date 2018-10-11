/*
Completed By: Derek Braun, 30040032, B01

takes in input of distance and speed of a travelling vehicle.
prints the distance traveled, average speed and total time elapsed.
*/

#include <stdio.h>
#include <math.h>

void get_user_input(double *distance, double *speed);
void travel_time_hours_and_minutes(double distance, double speed, double *hours, double *minutes);
void display_info(double distance, double speed, double hour, double minutes);

int main(void){
	double dist_in;
	double speed_in;
	double total_hours;
	double total_minutes;
	
	get_user_input(&dist_in, &speed_in);
	travel_time_hours_and_minutes(dist_in, speed_in, &total_hours, &total_minutes);
	display_info(dist_in, speed_in, total_hours, total_minutes);
	
	return 0;
}

void get_user_input(double *distance, double *speed){
	printf("Please enter the travel distance in km: ");
	scanf("%lf", distance);
	printf("\nNow enter the vehicles, average speed (km/h): ");
	scanf("%lf", speed);
}

void travel_time_hours_and_minutes(double distance, double speed, double *hours, double *minutes){
	double intermediate_hours;
	intermediate_hours = 1/(speed/distance);
	
	*hours = floor(intermediate_hours);
	*minutes = 60*(intermediate_hours-floor(intermediate_hours));
}

void display_info(double distance, double speed, double hour, double minutes){
	printf("\nYou have traveled %.2lf (km) with a speed of %.2lf in %.2lf hour(s) and %.2lf minutes(s)", distance, speed, hour, minutes);
}