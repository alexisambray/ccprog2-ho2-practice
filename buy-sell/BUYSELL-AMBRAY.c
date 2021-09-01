/*
    This is the skeleton file that you need to use as base code for the
   BUY-AND-SELL problem.

        Encode your Name and Section below.

    LASTNAME, FIRSTNAME: AMBRAY, ALEXIS
    SECTION: S11

    MAKE SURE THAT the solution/program you are submitting does not have:
       * a compilation error
           * a compilation warning
           * a logical error

        If there is a compilation error, the score will be 0 point.
*/

/* DO NOT CHANGE THE #include below */
#include <stdio.h>
#include <string.h>

/*
   TO DO #1:  change the #include below to the header file with your own
   lastname.  For example if your lastname is SHAZAM, then it should be changed
   to #include "MYHEADER-SHAZAM.h".
*/
#include "MYHEADER-AMBRAY.h"

/*
        TO DO #2 [5 points]:

        Implement InputSellers(SELLERS, n_sellers) function to input using
   scanf() the contents of the SELLERS[] array.

        RESTRICTION: DO NOT USE printf() inside this function!
*/
void InputSellers(struct sellerTag SELLERS[], int n_sellers) {
  for (int i = 0; i < n_sellers; i++) {
    scanf("%d %s %s %lf", &SELLERS[i].ID, SELLERS[i].name.first,
          SELLERS[i].name.last, &SELLERS[i].rating);
  }
}

/*
        TO DO #3 [5 points]:

        Implement InputProducts(PRODUCTS, n_products) function to input using
   scanf() the contents of the PRODUCTS[] array.

        RESTRICTION: DO NOT USE printf() inside this function!
*/
void InputProducts(struct productTag PRODUCTS[], int n_products) {
  for (int i = 0; i < n_products; i++) {
    scanf("%d %s %lf", &PRODUCTS[i].ID, PRODUCTS[i].product_type,
          &PRODUCTS[i].price);
  }
}
/*
        TO DO #4 [5 points]:

        Implement Linear_Search(struct sellerTag SELLERS[], int n_sellers, int
   key) function. It should return the index where a seller ID matching the key
   parameter value was found.  If the key is not found, the function should
   return -1.

        RESTRICTION: DO NOT USE printf() and scanf() inside this function!
*/
int Linear_Search(struct sellerTag SELLERS[], int n_sellers, int key) {
  for (int i = 0; i < n_sellers; i++) {
    if (key == SELLERS[i].ID) {  // found
      return i;
    }
  }
  return -1;
}
/*
        TO DO #5 [25 points]: Deductions ranging from minus 25 to minus 5 will
   be applied depending on the severity of the logical errors.

        Implement Recommend(SELLERS, PRODUCTS, n_sellers, n_products, product)
   function. The function should search and print information about the seller
   who is selling the product (i.e., the search string) at the lowest Price. The
   following rules must be obeyed:

    Rule 1. Only sellers with a rating of at least 3.0 are qualified to be
   considered for recommendation.

        Rule 2. Tie-Breakers:

                        Q1: What if there are two or more sellers selling the
   same product for the same price? A1: It is the seller with the highest Rating
   who is recommended.  We value more Trustworthy people!

                        Q2: What if the situation above happens, and the sellers
   have the same rating? A2: It is the seller with the smallest ID number (the
   lower the number, the more senior is the seller in the community) who is
   recommended. We respect people who are more senior than us!

    You are allowed to define other functions that you can call inside
   Recommend().

        HARD REQUIREMENTS:
        1. you must call Linear_Search() inside Recommend().

        2. You must strictly follow the same output format described below.
           a. If the product is found, the output is in the following sequence:

              product	price	ID	firstname	lastname	rating

           b. If the item is not found, the output should be:

               product NONE


           c. Use printf() to output the required values separated by a tab
   character, i.e. '\t'. Print floating point values with two digits after the
   decimal point.

        3. DO NOT print any other unnecessary string or value.  It will
   interfere with the black box test!!!

        View the contents of the file EXPECTED.txt for the sample expected
   output when the given main() function is executed.
*/
void Recommend(struct sellerTag SELLERS[],
               struct productTag PRODUCTS[],
               int n_sellers,
               int n_products,
               String30 product) {
  int found = 0;

  int r_index;  // recommended seller index
  int c_index;  // challenger index
  int p_index;  // product index
  int s_index;  // search index

  r_index = -1;  // 1st recomm not found

  for (int i = 0; i < n_products; i++) {
    if (strcmp(product, PRODUCTS[i].product_type) == 0) {  // product is found
      s_index =
          Linear_Search(SELLERS, n_sellers,
                        PRODUCTS[i].ID);  // find 1st seller stored in SELLERS[]
                                          // array that sells the product
      if (SELLERS[s_index].rating >=
          3.0) {  // recommend seller only if rating is at least 3.0
        found = 1;
        r_index = s_index;
        p_index = i;
      } else {  // there was a previous recommendation, we have a challenger
        c_index = s_index;
        // 1. Compare Price
        if (PRODUCTS[p_index].price >
            PRODUCTS[i].price) {  // challenger has lower price
          r_index = c_index;      // update recommended index
          p_index = i;
        } else {
          // 2. Same price, compare Rating
          if (PRODUCTS[p_index].price ==
              PRODUCTS[i].price) {  // NOTE: operator '==' is NOT good for
                                    // floating points
            if (SELLERS[c_index].rating >
                SELLERS[r_index].rating) {  // challenger higher rating
              r_index = c_index;            // update recommended index
              p_index = i;                  // update product index
            } else {
              // 3. Same rating, compare ID
              if (SELLERS[c_index].rating ==
                  SELLERS[r_index].rating) {  // equal Rating
                if (SELLERS[c_index].ID <
                    SELLERS[r_index].ID) {  // choose lower ID
                  r_index = c_index;
                  p_index = i;
                }
              }
            }
          }
        }
      }
    }
  }
  if (found)
    printf("%s\t%.2f\t%d\t%s\t%s\t%.2f\n", product, PRODUCTS[p_index].price,
           SELLERS[r_index].ID, SELLERS[r_index].name.first,
           SELLERS[r_index].name.last, SELLERS[r_index].rating);
  else
    printf("%s NONE\n", product);
}
/*******************************************************************************
    WARNING!!!   WARNING!!!   WARNING!!!

        YOU ARE NOT ALLOWED TO DEFINE the main() function in this file.

    The main() is in the accompanying BUYSELL-LASTNAME-main.c source file.

        VIOLATION OF THIS RESTRICTION WILL RESULT TO A DEDUCTION OF 10
points!
********************************************************************************/
