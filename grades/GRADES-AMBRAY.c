/*
    This is the skeleton file that you need to use as base code for the GRADES
problem.

        Encode your Name and Section below.

    LASTNAME, FIRSTNAME: AMBRAY, ALEXIS
    SECTION: S11
        DO NOT define a main() function in this file.  The main() function
definition is provided in the accompanying file main.c. ß MAKE SURE THAT the
solution/program you are submitting does not have:
       * a compilation error
           * a compilation warning
           * a logical error

        If there is a compilation error, the score will be 0 point.
*/

#include "grades.h"  // READ and UNDERSTAND the contents of this header file.  DO NOT change this line.

/*
    TO DO TASK #1: [for 10 points]

        Define Print_Student_List() function which will printf() the values of
   all data in the list of student records starting from the first index to the
   last index in sequence.

        REQUIRED OUTPUT FORMAT: You should printf() the members of the same
   structure on  the same line separated by at least one white space.

        RESTRICTION: Do NOT print any extraneous or unnecessary string.
*/
void Print_Student_List(struct studentTag STUDENTS[], int nStudents) {
  // Encode your solution.
  for (int i = 0; i < nStudents; i++) {
    printf("%s %s %d %d\n", STUDENTS[i].name.last, STUDENTS[i].name.first,
           STUDENTS[i].practice_score, STUDENTS[i].midterm_score);
  }
}

/*
    TO DO TASK #2: [for 10 POINTS]

        Define Append_Student_List() function that will append new data in the
   list of student structures. Append means to add new elements (student data)
   at the end of the list.  The function should return the updated number of
   students stored in the list.

        ASSUMPTIONS:
          1.  There is available memory space in STUDENTS[] array to accomodate
   new data.
          2.  The new student data values are different from those that are
   already stored in STUDENTS[] array, (i.e., all students are unique).

        RESTRICTION: You should NOT call printf() or scanf() inside this
   function.
*/
int Append_Student_List(struct studentTag STUDENTS[],
                        int nStudents,
                        String lastname,
                        String firstname,
                        int practice,
                        int midterms) {
  // Encode your solution.
  strcpy(STUDENTS[nStudents].name.last, lastname);
  strcpy(STUDENTS[nStudents].name.first, firstname);
  STUDENTS[nStudents].practice_score = practice;
  STUDENTS[nStudents].midterm_score = midterms;

  // Do NOT forget the return statement!
  return nStudents + 1;
}

void Swap(struct studentTag STUDENTS[], int indexOne, int indexTwo) {
  struct studentTag temp;

  strcpy(temp.name.last, STUDENTS[indexOne].name.last);
  strcpy(temp.name.first, STUDENTS[indexOne].name.first);
  temp.practice_score = STUDENTS[indexOne].practice_score;
  temp.midterm_score = STUDENTS[indexOne].midterm_score;

  strcpy(STUDENTS[indexOne].name.last, STUDENTS[indexTwo].name.last);
  strcpy(STUDENTS[indexOne].name.first, STUDENTS[indexTwo].name.first);
  STUDENTS[indexOne].practice_score = STUDENTS[indexTwo].practice_score;
  STUDENTS[indexOne].midterm_score = STUDENTS[indexTwo].midterm_score;

  strcpy(STUDENTS[indexTwo].name.last, temp.name.last);
  strcpy(STUDENTS[indexTwo].name.first, temp.name.first);
  STUDENTS[indexTwo].practice_score = temp.practice_score;
  STUDENTS[indexTwo].midterm_score = temp.midterm_score;
}
/*
    TO DO TASK #3: [for 10 points]

        Define Selection_Sort() such that it will sort the list of structures by
   LAST NAME and FIRST NAME in alphabetical order.� � Be careful in formulating
   your sorting function for students with the same last names (for example
   SUZUKI SHINTAROU and SUZUKI KEIKO).�Note that SUZUKI KEIKO must appear before
   SUZUKI SHINTAROU in the sorted list. Hint: you�ll need to use strcat().

        RESTRICTION:
        1. You are required to use straight SELECTION SORT ALGORITHM.
   Non-compliance will result into a score of 0 for this requirement.
        2. You should NOT call printf() or scanf() inside this function.
*/
void Selection_Sort(struct studentTag STUDENTS[], int nStudents) {
  // Encode your solution.
  int i, j, min;
  String fullName1, fullName2;

  for (i = 0; i < nStudents - 1; i++) {
    min = i;  // index of the lowest element

    for (j = i + 1; j < nStudents; j++) {
      strcpy(fullName1, STUDENTS[min].name.last);
      strcat(fullName1, STUDENTS[min].name.first);
      strcpy(fullName2, STUDENTS[j].name.last);
      strcat(fullName2, STUDENTS[j].name.first);
      if (strcmp(fullName1, fullName2) > 0) {
        min = j;
      }
    }
    if (i != min) {
      Swap(STUDENTS, i, min);
    }
  }
  // NOTE: you may define a separate function for swapping two structures.
}

/*
    TO DO TASK #4: [for 10 POINTS]

        Define Binary_Search() to answer the question:

                Q: Is there a <param_lastname> <param_firstname> in the list?

        The function should perform a BINARY SEARCH to determine if a student
   with matching names to <param_lastname> and <param_firstname> is in the list
   of structures or not. If it is found, it should return the index
   corresponding to where it was found; otherwise, it should return -1.

        For this task, assume that the STUDENTS[] array is already sorted by
   name.

    RESTRICTION: You should NOT call printf() or scanf() inside this function.
*/
int Binary_Search(String param_lastname,
                  String param_firstname,
                  struct studentTag STUDENTS[],
                  int nStudents) {
  // Encode your solution.

  // Do NOT call Selection_Sort() here.  Assume that the STUDENTS[] array is
  // already sorted alphabetically by name.
  int low = 0, high = nStudents - 1, mid;
  String fullNameKey, fullName;

  while (low <= high) {
    mid = low + (high - low) / 2;
    strcpy(fullNameKey, param_lastname);
    strcat(fullNameKey, param_firstname);
    strcpy(fullName, STUDENTS[mid].name.last);
    strcat(fullName, STUDENTS[mid].name.first);
    if (strcmp(fullNameKey, fullName) == 0) {
      return mid;
    } else if (strcmp(fullNameKey, fullName) < 0) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  // Do NOT forget the return statement!
  return -1;
}

/*
    TO DO TASK #5: [for 10 points]

        Define Build_List() that will compute the answer to the following
   question:

        Q: Who are the students whose Midterm Exam score is lower than
   <param_score> and who did NOT solve the Practice Quiz.

        The function should build a list of students structures where all
   structure data meet the query conditions.

        You must use the sorted STUDENTS[] array.

        For this task, assume that the STUDENTS[] array is already sorted by
   name.

        The function should return the number of student records stored in the
   newList[] array.

    RESTRICTION: You should NOT call printf() or scanf() inside this function.
*/
int Build_List(int param_score,
               struct studentTag STUDENTS[],
               int nStudents,
               struct studentTag newList[]) {
  // Encode your solution.

  // Do NOT call Selection_Sort() here.  Assume that the STUDENTS[] array is
  // already sorted alphabetically by name.
  int nNewList = 0;
  for (int i = 0; i < nStudents; i++) {
    if (STUDENTS[i].midterm_score < param_score &&
        STUDENTS[i].practice_score == 0) {
      nNewList = Append_Student_List(newList, nNewList, STUDENTS[i].name.last,
                                     STUDENTS[i].name.first, 0,
                                     STUDENTS[i].midterm_score);
    }
  }
  // Do NOT forget the return statement!
  return nNewList;
}

/*******************************************************************************
    WARNING!!!   WARNING!!!   WARNING!!!

        YOU ARE NOT ALLOWED TO DEFINE the main() function in this file.

    The main() is in the accompanying main.c source file.

        VIOLATION OF THIS RESTRICTION WILL RESULT TO A DEDUCTION OF 10 points!
********************************************************************************/
