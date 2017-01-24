#include <stdio.h>
#include <stdlib.h>

unsigned char w;
unsigned char x;
unsigned char y;
unsigned char z;

char a;
char b;
char c;
char d;
char string;
int intnum = 1023;

int avg_adc;


unsigned int ADC_value=0; //Will store the value from the ADC array
char* int_to_char(int num);
  //Function:  Converts an integer into a character array


//int main()
//{
//avg_adc = 512; //testing average of 10 samples from 0-1024
//unsigned volatile int avg_adc = 1023;//

//unsigned volatile int number = 1023;
//char str[10];
//sprintf(str, "%d", avg_adc);

//printf(str);

//int x = (number >> (8*n)) & 0xff; //where n is the 1st, 2nd, 3rd, or 4th byte

//int x = (number >> (8)) & 0xff;
//printf(x);




/*
a == avg_adc & 0x000000ff;               //first byte
b == avg_adc & 0x0000ff00 >> 8;          //second byte
c == avg_adc & 0x00ff0000 >> 16;         //third byte
d == avg_adc & 0xff000000 >> 24;         //fourth byte

printf(a);
printf(b);
printf(c);
printf(d);
*/

//char IntToChar = (char)avg_adc;
//printf(IntToChar);

//===================================================
//char character = avg_adc + '0';

//printf("&#37; d %c\n", avg_adc, character);


//Num plus 48 is ascii number.




//a == avg_adc % 1;          //Need to figure this out 1024->1024
//b == avg_adc % 10;         //Need to figure this out 1024->102

//Modulus Operator computes the remainder when divided by a number.

//c == avg_adc % 100;        //Need to figure this out 1024->10
//d == avg_adc % 1000;       //Need to figure this out, 1024->1


//return 0;
//}

char* int_to_char(int num)  {
  char string[5];               // char string/array 1 0 2 3 '0'
  int i, rem, length, n;

  length = 0;
  n = num;

  //printf(num);

  while(n != 0)  { //length of word or integer
    length++;
    n /= 10;
  }

  for(i=0; i<length; i++)  { //remainder to character and stores into the array.
    rem = num%10;
    num = num/10;

    string[length-(i+1)] = rem + '0';
  }

  string[length] = '\0';

  //printf(num);

  //printf(string[0]);

  return (string);
}

void main(){

    string = int_to_char(intnum);

    //a = string;
    //b = string[1];
    //c = string[2];
    //d = string[3];

    printf(string);


    //printf(a);
    //printf(b);
    //printf(c);
    //printf(d);
    return 0;

}
