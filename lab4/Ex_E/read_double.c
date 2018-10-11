/* read_int.c
 * ENSF 337 Fall 2018 Lab 4 Exercise  E
 *
 * Created By: Derek Braun, 30040032
 * Lab Section: B01
 */

#include "read_input.h"

int read_real(char *digits, int n, double *num)
{
  if(get_string(digits, n)== EOF)
    return EOF;

  if(is_valid_double(digits)){
    if(digits[0] == '-')
      *num = -convert_to_double(digits + 1);
    else if(digits[0] == '+') 
      *num = convert_to_double(digits + 1);
    else
      *num = convert_to_double(digits);
    return 1;
  }

  return 0;
}


int is_valid_double(const char* digits)
{
  int valid = 1;
  int decimal = 0;
  int i;

  /* i = index where first digit should be */
  if(digits[0] == '+' || digits[0] == '-')
    i = 1;
  else
    i = 0;

  /* Must have at least one digit, and no non-digits. */
  if (digits[i] == '\0')
    valid = 0;
  else
    while (valid && (digits[i] != '\0')) {
		if(digits[i] == '.')
			decimal++;
		if((digits[i] < '0' ||  digits[i] > '9') && (digits[i] != '.' || decimal > 1))
			valid = 0;
		i++;
    }
  
  return valid;
}


double convert_to_double(const char* digits)
{
  double sum = 0;
  double dec_sum = 0;
  int i = 0;
  while(digits[i] != '\0') {
	if(digits[i] == '.'){
		while(digits[i] != '\0'){
			digits++;
		}
		digits--;
		while(digits[i] != '.'){
			dec_sum = (0.1)*dec_sum + (digits[i] - '0');
			i--;
		}
		dec_sum *= (0.1);
		break;
	}
	sum = 10 * sum + (digits[i] - '0');
	i++;
  }
  sum += dec_sum;
  return sum;
}
