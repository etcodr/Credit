#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int input(char *s, int length);
int get_card_number(char *prompt);

int main(void) {
  long card_number;

  card_number = get_card_number("Number: ");
  if (card_number == -1)
    printf("Bitch..., that ain't no credit card number!");
  else
    printf("Fuckin' A, hombre :)");

  return 0;
}

int get_card_number(char *prompt) {
  char *buffer;
  size_t bufsize = 16;
  size_t characters;
  long number;

  buffer = (char *) malloc(bufsize * sizeof(char));
  if (buffer == NULL) {
    perror("Unable to allocate buffer.");
    exit(1);
  }

  printf("%s", prompt);
  characters = getline(&buffer, &bufsize, stdin);
  
  for (int i = 0; i < strlen(buffer); i++) {
    if (!isdigit(buffer[i]))
      return -1;
  }

  number = atol(buffer);
  return number;
}