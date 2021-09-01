# BUY-AND-SELL (contributed by F.R. Salvador)
## In this problem, we simulate how we can represent and process data for online buying and selling which has become more prominent
## due to the COVID-19 pandemic.

### Consider two arrays of structures:
+ *SELLERS[]* - with each element storing information about a *seller* in a Buy-and-Sell platform
+ *PRODUCTS[]* - with each element storing information about a *product* being sold in a Buy-and-Sell platform

### Your Tasks:
+ Task 1: Edit the accompanying header file to accomplish the ff:
  + Declare a data type for the seller structure. Use *sellerTag* as tag name
  + Declare a data type for the product structure. Use *productTag* as tag name
+ Task 2: Implement *InputSellers(SELLERS, n_sellers)* 
  + which will initialize the elemets of the SELLERS array via scanf()
+ Task 3: Implement *InputProducts(PRODUCTS, n_products)*
  + which will initialize the elements of the PRODUCT array via scanf()
+ Task 4: Implement *Linear_Search(SELLERS, n_sellers, search_key)* 
  + which should return the index where the seller structure with an ID member matching the search key was found
  + if key is not found, the function should return -1
+ Task 5: Implement *Recommend(SELLERS, PRODUCTS, n_sellers, n_products, item)*
  + function should search for the highest rated seller and who is selling the item at lowest price
+ Rule 1: Only sellers with a rating of at least 3.0 are qualified
+ Rule 2: Tie breakers:
  + Q1: What if there are two or more sellers selling the same product for the same price?
    + A1: It is the seller with the highest Rating who is recommended. We value more Trustworthy people!
  + Q2: What if the situation above happens, and the sellers have the same rating?
    + A2: It is the seller with the samllest ID numer! We respect people who are more senior than us!

### The function prints the name of the recommended seller and the price. In case the item is not found, the function prints "UNAVAILABLE"
