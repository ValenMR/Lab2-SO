#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int reverseString(char *s);
int CountVowelsAndConsonants(char *s);
int replaceSpacesWithUnderscores(char *s);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "usage: cpu <string> \n");
    exit(1);
  }

  char *s = argv[1];
  int sLength = strlen(s);

  if (sLength > 100) {
    fprintf(stderr, "Maximum length 100 characters \n");
    exit(1);
  }
  
  reverseString(s);
  CountVowelsAndConsonants(s);
  replaceSpacesWithUnderscores(s);

  return 0;
}

int reverseString(char *s) {
  char *pointer1 = s;
  char *pointer2 = s + strlen(s) - 1;
  char aux;

  while (pointer1 < pointer2) {
    aux = *pointer1;
    *pointer1 = *pointer2;
    *pointer2 = aux;

    pointer1++;
    pointer2--;
  }
  
  while (*s != '\0') {
    printf("%c", *s);
    s++;
  }

  printf(" ");

  return 1;
}

int CountVowelsAndConsonants(char *s) {
  char *pointer = s;
  int asciiCode, isLowerCaseRange, isUpperCaseRange;

  int numberOfA = 0; 
  int numberOfE = 0; 
  int numberOfI = 0; 
  int numberOfO = 0; 
  int numberOfU = 0; 
  int numberOfConsonants = 0;

  while (*pointer != '\0') {
    asciiCode = *pointer;
    isLowerCaseRange = asciiCode >= 97 && asciiCode <= 122;
    isUpperCaseRange = asciiCode >= 65 && asciiCode <= 90;

    if (isLowerCaseRange || isUpperCaseRange) {
      if (*pointer == 'a' || *pointer == 'A') {
        numberOfA++;
      } 
      else if (*pointer == 'e' || *pointer == 'E') {
        numberOfE++;
      }
      else if (*pointer == 'i' || *pointer == 'I') {
        numberOfI++;
      } 
      else if (*pointer == 'o' || *pointer == 'O') {
        numberOfO++;
      }
      else if (*pointer == 'u' || *pointer == 'U') {
        numberOfU++;
      } 
      else {
        numberOfConsonants++;
      }
    }

    pointer++;
  }

  int totalVowels = numberOfA + numberOfE + numberOfI + numberOfO + numberOfU;

  printf("%d ", totalVowels);

  if (numberOfA != 0) {
    printf("%d ", numberOfA);
  }
  if (numberOfE != 0) {
    printf("%d ", numberOfE);
  }
  if (numberOfI != 0) {
    printf("%d ", numberOfI);
  }
  if (numberOfO != 0) {
    printf("%d ", numberOfO);
  }
  if (numberOfU != 0) {
    printf("%d ", numberOfU);
  }

  printf("%d ", numberOfConsonants);

  return 1;
}

int replaceSpacesWithUnderscores(char *s) {
  char *pointer = s;

  while(*pointer != '\0') {
    
    if (*pointer == ' ') {
      *pointer = '_';
    }

    printf("%c", *pointer);

    pointer++;
  }

  return 1;
}
