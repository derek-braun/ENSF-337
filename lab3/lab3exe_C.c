/*
 *  lab3exe_C.c
 *  ENSF 337 Fall 2018 lab3 Exercise C
 *  Completed By: Derek Braun, 30040032
 *  Section: B01
 *
 *  In this program the implementatiom of function pascal_trangle is missing.
 *  Studtent must complete this function.
 */

#include <stdio.h>
#include <stdlib.h>

void pascal_triangle(int n);
/* REQUIRES: n > 0 and n <= 20
 PROMISES: displays a pascal_triangle. the first 5 line of the function's output
 should have the following format:
 row 0:  1
 row 1:  1   1
 row 2:  1   2   1
 row 3:  1   3   3   1
 row 4:  1   4   6   4   1
 */

int main() {
    int nrow;
    // These are ALL of the variables you need!
    printf("Enter the number of rows (Max 20): ");
    scanf("%d", &nrow);
    if(nrow <= 0 || nrow > 20) {
        printf("Error: the maximum number of rows can be 20.\n");
        exit(1);
    }
    
    pascal_triangle(nrow);
    return 0;
}

void pascal_triangle(int n) {
    int row = 0;
	int index = 0;
	int print_ind = 0;
	int previous[20] = {1};
	int current[20] = {0};
	
	while(row < n){
		while(index <= row){
			if(index == row || index == 0){
				current[index] = 1;
			}
			else{
				current[index] = previous[index-1] + previous[index];
			}
			index++;
		}
		index  = 0;
		printf("\nRow %d:", row);
		while(current[print_ind]){
			printf("\t%d", current[print_ind]);
			previous[print_ind] = current[print_ind];
			print_ind++;
		}
		print_ind = 0;
		printf("\n");
		row++;
	}
}
