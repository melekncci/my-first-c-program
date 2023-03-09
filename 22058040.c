#include <stdio.h>

void write_polynomial3(double a0, double a1, double a2, double a3) {

  //creating number array for coefficients
  double numbers[4] = {a0, a1, a2, a3};
  //creating variable array for print
  char variable[3][10] = {"x^3", "x^2", "x"};

  //for loop executes 4 times, because we have 4 terms
  for (int i = 0; i < 4; i++) {
    //if number is equal to 1 or -1 and the term is not the last term
    if (((numbers[i] == 1.0) || (numbers[i] == -1.0)) && (i != 3)) {
      //if the term is x^3 and number is 1, do not print +
      if (numbers[i] == 1 && i != 0)
        printf("+");
      else if (numbers[i] == -1.0)
        printf("-");
      printf("%s", variable[i]); //print variable
    } 
    //if number is not equal to 0
    else if (numbers[i] != 0) {
      //if the number is greater than 0 and not in the x^3 term, print + 
      if (numbers[i] > 0 && i != 0)
        printf("+");
      //if the number is integer, print %d
      if (numbers[i] == (int)numbers[i]) {
        printf("%d", (int)numbers[i]);
      } 
      //if the number is not integer, print with 1 digit after .
      else {
        printf("%.1f", numbers[i]);
      }
      printf("%s", variable[i]); //print variable
    }
  }
}

void write_polynomial4(double a0, double a1, double a2, double a3, double a4) {

  //Same operations with above function, but the sizes of arrays are 
  //one more than the previous function
  double numbers[5] = {a0, a1, a2, a3, a4};
  char coefficients[4][10] = {"x^4","x^3", "x^2", "x"};

  for (int i = 0; i < 5; i++) {
    if (((numbers[i] == 1.0) || (numbers[i] == -1.0)) && (i != 4)) {
      if (numbers[i] == 1 && i != 0)
        printf("+");
      else if (numbers[i] == -1.0)
        printf("-");
      printf("%s", coefficients[i]);
    } else if (numbers[i] != 0) {
      if (numbers[i] > 0 && i != 0)
        printf("+");
      if (numbers[i] == (int)numbers[i]) {
        printf("%d", (int)numbers[i]);
      } else {
        printf("%.1f", numbers[i]);
      }
      printf("%s", coefficients[i]);
    }
  }
}

void calculate_fibonacci_sequence(void) {
  int num;
  char c;
  int start = 0;
  while (1) {
    //for first input, we print this statement
    if (start == 0) {
      printf("Please enter term(s) number: ");
      start++;
    }
    //if the number is integer
    if (scanf("%d", &num)){
      //if the number is greater than 0
      if (num > 0) {
        int prev = 0;
        int curr = 1;
        int next;
        printf("Fibonacci Sequence:\n");
        //calculate fibanocci sequence and print them
        for (int i = 1; i <= num; i++) {
          printf("%d\n", curr);
          next = prev + curr;
          prev = curr;
          curr = next;
        }
        start = 0;
      } 
      else {  //if the number is not greater than 0,ask user for input
        printf("Please enter a positive term(s) number: ");
      }      
    }
    //if the number is a character such as *,a,b ..
    else if (scanf("%c", &c) == 1){
        if (c == '*') //if the character is *, exit function with return
          return;
        else     //if is not *, ask user for another input
         printf("Please enter “numeric” term(s) number: "); 
    }
  }
}

void decide_perfect_harmonic_number() {
  while (1) {
    int n;
    char c;
    printf("Please enter input number: ");
    
    // check if the input is a natural number or not
    if (scanf("%d", &n)){
        if (n <= 0) {
          printf("The input must be a natural number.\n");
          continue;
        }
    
        // Compute the divisors of number
        int divisors[n];
        int num_divisors = 0;
        for (int i = 1; i <= n / 2; i++) {
          if (n % i == 0) {
            divisors[num_divisors] = i;
            num_divisors++;
          }
        }
        divisors[num_divisors] = n;
        num_divisors++;
      
        // Print the divisors of number
        printf("Natural Number Divisors: ");
        for (int i = 0; i < num_divisors; i++) {
          printf("%d ", divisors[i]);
        }
        printf("\n");
      
        // Check if n is a perfect number
        int sum = 0;
        for (int i = 0; i < num_divisors-1; i++) {
          sum += divisors[i];
        }
        if (sum == n) {
          printf("Is Perfect Number? : Yes\n");
        } else {
          printf("Is Perfect Number? : No\n");
        }
    
        // Check if n is a harmonic divisor number
        float harmonic_mean = 0;
        for (int i = 0; i < num_divisors; i++) {
          harmonic_mean += 1.0 / divisors[i];
        }
        harmonic_mean = (float)num_divisors / (float)harmonic_mean;
        if (harmonic_mean == (int)harmonic_mean) {
          printf("Is Harmonic Divisor Number? : Yes\n");
        } else {
          printf("Is Harmonic Divisor Number? : No\n");
        }      
     }
     // check if the input is the sentinel value '' 
    else if (scanf("%c", &c) == 1){
        if (c == '*')
          return;
    }    
  }
}

void bmi_calculation()
{
    double weight, height;

    printf("Please enter weight(kg): ");
    scanf("%lf", &weight);
    printf("Please enter height(m): ");
    scanf("%lf", &height);

    double bmi = weight / pow(height, 2);

    if (bmi < 16.0)
    {
        printf("Your category: Severely Underweight\n");
    }
    else if (bmi >= 16.0 && bmi < 18.5)
    {
        printf("Your category: Underweight\n");
    }
    else if (bmi >= 18.5 && bmi < 25.0)
    {
        printf("Your category: Normal\n");
    }
    else if (bmi >= 25.0 && bmi < 30.0)
    {
        printf("Your category: Overweight\n");
    }
    else
    {
        printf("Your category: Obese\n");
    }
}


int main() {
  write_polynomial3(-1.0, -5.0, 2.0, 1.0);
  printf("\n");
  write_polynomial4(1.0, -3.0, 2.0, 0.0, -1);
  printf("\n");
  calculate_fibonacci_sequence();
  printf("\n");
  decide_perfect_harmonic_number();
  printf("\n");
  bmi_calculation();
  printf("\n");
  return 0;
}