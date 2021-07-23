#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

long get_card_number(char *prompt);

int main(void) {
  long card_number;

  do
  {
    card_number = get_card_number("Number: ");
  } while (card_number == -1);
  
  return 0;
}

/*
  Retrieve a card number from the user.
  Ensure that the input received contains only digits.
  Convert the input string to a long.
  Return the long.
*/
long get_card_number(char *prompt) {
  long number;
  char *buffer;

  printf("%s", prompt);
  buffer = (char *) malloc(17 * sizeof(char));
  scanf("%s", buffer);
  
  for (int i = 0; i < strlen(buffer); i++) {
    if (!isdigit(buffer[i]))
      return -1;
  }

  number = atol(buffer);

  free(buffer);
  return number;
}