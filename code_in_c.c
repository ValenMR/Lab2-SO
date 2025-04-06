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
  
  printf("- Reversed string: ");

  while (*s != '\0') {
    printf("%c", *s);
    s++;
  }

  printf("\n");

  return 1;
}

int CountVowelsAndConsonants(char *s) {
  char *pointer = s;
  int asciiCode, isLowerCaseRange, isUpperCaseRange, isSpace;

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
    isSpace = asciiCode == 32;

    if (!(isLowerCaseRange || isUpperCaseRange || isSpace)) {
      fprintf(stderr, "The string can only contain alphabetical values \n");
      exit(1);
    }

    if(*pointer == ' '){

    }
    else if (*pointer == 'a' || *pointer == 'A') {
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

    pointer++;
  }

  printf("- Number of vowels: %d\n", numberOfA + numberOfE + numberOfI + numberOfO + numberOfU);
  printf("  - Number of \"a\": %d\n", numberOfA);
  printf("  - Number of \"e\": %d\n", numberOfE);
  printf("  - Number of \"i\": %d\n", numberOfI);
  printf("  - Number of \"o\": %d\n", numberOfO);
  printf("  - Number of \"u\": %d\n", numberOfU);
  printf("- Number of consonants: %d\n", numberOfConsonants);

  return 1;
}

int replaceSpacesWithUnderscores(char *s) {
  char *pointer = s;
  printf("- Modified string: ");

  while(*pointer != '\0') {
    
    if (*pointer == ' ') {
      *pointer = '_';
    }

    printf("%c", *pointer);

    pointer++;
  }
  printf("\n");

  return 1;
}
