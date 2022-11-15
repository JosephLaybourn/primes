/******************************************************************************
filename    primes1.c
author      Joey Laybourn
DP email    j.laybourn@digipen.edu
course      CS120
assignment  1
due date    10/19/2017

Brief Description:
This file has the function to return if a number is prime, and also calculates
every even number as a sum of prime numbers.  
******************************************************************************/

#include <stdio.h> /* printf */

#define FALSE 0
#define TRUE  1

/******************************************************************************
       Function: is_prime

    Description: determines if a number is prime

         Inputs: number - The program will return if this number is prime.  

        Outputs: true or false, depending if the input is prime
******************************************************************************/
int is_prime(int number)
{
  int i;                                     /*loop variable                 */

  if (number == 1)                           /*states 1 is not a prime number*/
    return FALSE;
  if (number == 2)                           /*states 2 is a prime number    */
    return TRUE;
  if (number % 2 == 0)                       /*accounts for all even numbers */
    return FALSE;

  /*loops for half the iterations of the number the user enters in*/
  for (i = 3; i <= number / 2; i++)
  {
    if (number % i == 0)         /*if the number divides cleanly for a       */
      return FALSE;              /*value other than 1 or itself, return false*/
  }

  return TRUE;                   /*anything else happens, return true        */
}

/******************************************************************************
       Function: conjecture

    Description: gives all even numbers within a specified range by 
                 adding two prime numbers.  

         Inputs: low  - The minimum sum that will be calculated. If the minimum
                        is too small, then the program will start at the actual
                        minimum sum.  
                 high - The maximum sum that will be calculated.  

        Outputs: true or false, depending if the input is prime
******************************************************************************/
void conjecture(int low, int high)
{
  int loopPrime = 2;                          /*first prime number           */
  int sum;                                    /*the sum of both prime numbers*/

  for (sum = low; sum <= high;)               /*loops until high is reached  */
  {
    int subPrime = sum - loopPrime;          /*the second prime number       */

    /*if both subPrime and loopPrime are prime*/
    if (is_prime(loopPrime) == TRUE && is_prime(subPrime) == TRUE)
    {
      printf("%3i = %3i + %3i\n", sum, loopPrime, subPrime);  /*prints output*/
      loopPrime = 2;                             /*resets loopPrime back to 2*/
      sum += 2;                                  /*next even number          */
    }

    /*will increment sum by 2 if there are no 2 prime numbers that add up to 
    the number. Used to set the minimal sum value since sum can never be low.*/
    if (loopPrime >= sum || subPrime >= sum)
      sum += 2;

    /*if no other conditions are met, tries to find a sum of two prime numbers 
    with loopPrime being a different prime number.                           */
    else
      loopPrime++;
  }
}