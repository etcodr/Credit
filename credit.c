#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int get_card_number(char *prompt);
bool validate_card_number(char text[]);

int main(void) {
  int card_number;

  do
  {
    card_number = get_card_number("Number: ");
  } while (card_number != 0);
  
 
  printf("card_number is %ld\n", card_number);
  
  return 0;
}

// Implement Luhn's algorithm to validate the card number.
int get_card_number(char *prompt) {
  char text[100];
  int number;
  int i;

  // Retrieve a card number from the user.
  printf("%s", prompt);
  fgets(text, 100, stdin);
  text[strlen(text) -1] = '\0';

  // Ensure that the input received contains only digits.
  for (i = 0; i < strlen(text); i++) {
    if (!isdigit(text[i]))
      return 1;
  }

  // Ensure that the input rec'd is a valid card number via Luhn's algorithm.
  if (validate_card_number(text))
  //   number = atol(text);
    return 0;
  else
    return 2;
}

// Implement Luhn's algorithm in order to validate card numbers.
bool validate_card_number(char text[]) {
  int i, j, k, sum1 = 0, sum2 = 0, sum_total = 0, x = 0, size = strlen(text) / 2;
  int temp[size];

  for (i = strlen(text) - 2; i >= 0; i-= 2) {
    // Times every other digit by 2, start with the number's 2nd to last digit.
    temp[x] = (text[i] - '0') * 2;   // Then add it to temp array.
    x++;
  }

  // Add the other digits to the temp2 array.
  for (j = strlen(text) -1; j >= 0; j-= 2)
    sum2 += text[j] - '0';
  
  // Add the products of temp's digits together.
  int num = 0;
  for (k = 0; k < size; k++) {
    num += temp[k];
    while (num > 0) {
      int mod = num % 10;   // Split last digit from number.
      sum1 += mod;          // Add mod to sum1.
      num /= 10;            // Divide num by 10 till num is 0.
    }
  }

  sum_total = sum1 + sum2;

  if (sum_total % 10 == 0)
    return true;

  return false;
}