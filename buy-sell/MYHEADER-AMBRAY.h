/*
        Encode your Name and Section below.

    LASTNAME, FIRSTNAME: AMBRAY, ALEXIS
    SECTION: S11
*/

#include "buysell.h"

/*
        TO DO #1 [5 points]:

        Declare a structure data type for the Seller structure.

        HARD REQUIREMENTS:
        1. Use  sellerTag as tag name.

        2. The names of each structure members should be EXACTLY the same
           as those given in the table in the PDF file (names are in blue font
   color, and yellow fill color).

        3. You have to make proper use of String30 (declared in buysell.h) for
   string member/s.
*/
struct nameTag {
  String30 first;
  String30 last;
};

struct sellerTag {
  int ID;
  struct nameTag name;
  double rating;
};

struct sellerTag first;
struct sellerTag last;
/*
        TO DO #2 [5 points]:

        Declare a structure data type for the Product structure.

        1. Use productTag as tag name.

        2. The names of the structure member should be EXACTLY the same
           as those given in the table in the PDF file (names are in blue font
   color, and yellow fill color).
        3. You have to make proper use of String30 (declared in buysell.h) for
   string member/s.
*/

struct productTag {
  int ID;
  String30 product_type;
  double price;
};
