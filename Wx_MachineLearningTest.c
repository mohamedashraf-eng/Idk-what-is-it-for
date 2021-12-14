/*
    Author: Mohamed Ashraf (Wx)
    Date: 10/8/2021
    Type: Machine learning DATASET test.
*/

#include "Wx_ML_H.h"
//=========================================================================

/*         ** Algorithms **      */

// 1: Input DATASET (Could be any data).
// 2: Check data if inputed before.
// 3: Do action with data.

int main(void)
{
  system("COLOR 0A"); // GREEN COLOR [0-BLACK BG] / [A- GRN FONT].
  DS_FILE_NAME(); // Put name for file to save the DATASET.
  uint16_t CHK = 0;

// Program section:
if(ACCESS) // CHECK IF FILE_NAME IS VALID.
{
  while(1)
  {
    n = getch();  // Control Flow by "Single character"
    if(n == 'c') break; // Exit by pressing 'c'.

    //_STYLE(1); //STYLE: Current Gen - Cycle in progress.

    //PHASE_1# GET DATASET:
    INPUT(col,row,in);  // Function to input the DATASET.


    _STYLE(2); //STYLE: DATA frame_1.

    //PHASE_2# SHOW DATASET:
    OUTPUT(col,row,str); // Function to OUTPUT stored DATASET.

    _STYLE(3); //STYLE: DATA frame_2.


    //PHASE_3# COMPARE DATASET:

    // ACT ######
    // ACT ######
    // ACT ######

    // New GEN START:
    // col + INC '2'
    // row + INC '2'
    counter++;
    col += INC_C;  // Inc by INC_C
    row += INC_R; // Inc by INC_R

    _STYLE(4); //STYLE: Last Gen - DATA MAX - Last Cycle.
  }// end while.

  //If 'c' is pressed (Exit the loop).
  // Printing all learnt data (Stored).

  _STYLE(5); //STYLE: ALL data stored [][].

  //PHASE_5# PRINT ALL DATA STORED(FILTERED):
  // All Data Set sstored in the 2d [col][row] matrix.
  //DS_STORED(col,row,str);

  _STYLE(6); //STYLE: FRAME DATA STORED.

  CHK = 10; // VARIABLE TO CHECK.
  printf("\n (Number < %d): (%d out of %d) \n", // DATA
                                CHK,DS_SEARCH(str,CHK),DS_STORED(col,row,str));

  //PHASE_6# SAVE DATASET:
  //          --(TYPE,MODE,STATE)--       --(TESTING)--
  _DS_FILE_SELECT('T','w','c'); //Write to txt with name: "FILE_NAME".


  return EXIT_SUCCESS;
}// end if(ACCESS == TRUE).

  return EXIT_SUCCESS; //EXIT_SUCCESSFUL.
} // end main.
//==================================================================
