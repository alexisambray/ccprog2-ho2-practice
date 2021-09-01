/*
    TXTMSG problem.

*/

/* DO NOT CHANGE THE #include below.  You are NOT allowed to include other
 * files. */
#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "inbox.h"
#include "loader-txtmsg.c"

/*
    TO DO #1:

    Implement the 5 functions that will compute and return a number that
   correspond as answer for each question from Q1 to Q5.

        You may define other functions if you want, which can be called by one
   or more of the required functions.

        RESTRICTIONS:
        1. Do NOT call printf() in any of the required function definition.
        2. Do NOT use any unnecessary parameter.  The function parameters should
   only be those that are necessary to implement the function.

    See for example the function for answering Q1 below...
*/

/*
        Q1: Is inbox <inbox_number> full? Return 1 to mean yes it is full,
   otherwise return 0.

        Assume that the array of structures Inbox[] already have contents.

        RESTRICTION: Do not use scanf() or printf().
*/
int Q1(struct inboxTag Inbox[], int inbox_number) {
  return Inbox[inbox_number].n_msgs == MAX_INBOX_SIZE;
}

/*
        Q2: Who sent the most recent message in inbox <inbox_number>?  (answer
   is the cel number of the sender)

        Assume that the array of structures Inbox[] already have contents.

        RESTRICTION: Do not use scanf() or printf().
*/
int Q2(struct inboxTag Inbox[], int ibn) {
  // note: ibn is the inbox_number parameter

  int last_index;

  last_index = Inbox[ibn].n_msgs - 1;  // note: ibn means inbox number

  return Inbox[ibn].Msg[last_index].sender;
}

/*
        Q3: How many unread messages are there in inbox <inbox_number>?

        Assume that the array of structures Inbox[] already have contents.

        RESTRICTION: Do not use scanf() or printf().
*/
int Q3(struct inboxTag Inbox[], int ibn) {
  int i;
  int ctr = 0;
  int n_msgs = Inbox[ibn].n_msgs;

  for (i = 0; i < n_msgs; i++)
    if (Inbox[ibn].Msg[i].read_flag == 0)  // or read_flag != 1
      ctr++;

  return ctr;
}

/*
        Q4: What is the string length of the most recent message in inbox
   <inbox_number>?

        Assume that the array of structures Inbox[] already have contents.

        RESTRICTION: Do not use scanf() or printf().
*/
int Q4(struct inboxTag Inbox[], int ibn) {
  int last_index;

  last_index = Inbox[ibn].n_msgs - 1;

  return strlen(Inbox[ibn].Msg[last_index].msg);
}

/*
   IsEqualDate() is a helper function that returns 1 if the two date parameters
   have the same value; otherwise, it returns 0. This is used in answering Q5.
*/
int IsEqualDate(struct dateTag date1, struct dateTag date2) {
  return date1.day == date2.day && date1.month == date2.month &&
         date1.year == date2.year;
}

/*
        Q5: How many messages were received from <sender> on <date> in inbox
   <inbox number>?

    Assume that the array of structures Inbox[] already have contents.

        RESTRICTION: Do not use scanf() or printf().
*/
int Q5(struct inboxTag Inbox[],
       int ibn,
       int sender_key,
       struct dateTag date_key) {
  int i;
  int ctr = 0;
  int n_msgs = Inbox[ibn].n_msgs;

  struct msgTag msg;

  for (i = 0; i < n_msgs; i++) {
    msg = Inbox[ibn].Msg[i];
    if (msg.sender == sender_key && IsEqualDate(msg.date, date_key))
      ctr++;
  }

  return ctr;
}

/*******************************************************************************
    WARNING!!!   WARNING!!!   WARNING!!!

        YOU ARE NOT ALLOWED TO DEFINE the main() function in this file.

    The main() is in the accompanying TXTMSG-main.c source file.

        VIOLATION OF THIS RESTRICTION WILL RESULT TO A DEDUCTION OF 10 points!
********************************************************************************/
