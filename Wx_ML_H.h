
/*
    Author: Mohamed Ashraf (Wx)
    Date: 10/8/2021
    Type: Machine learning DATASET test.
*/

// HEADER GUARDS: ML_H
#ifndef __ML_H_H__
#define __ML_H_H__

// HEADER LIBRARIES USED:
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>
#include <string.h>

//==================================================

/*****************************************************
*                    FUNCTION DECLARED               *
******************************************************/
// TO GET THE DATASET:
void INPUT (uint16_t,uint16_t,uint32_t (*)[2u][2u]);

// TO OUTPUT THE DATASET STORED:
void OUTPUT(uint16_t,uint16_t,uint32_t (*)[2u][2u]);

// TO CHECK IF DATA INPUT IN [(CYCLE+1) != (CYCLE)]:
void CHECK (uint16_t,uint16_t,uint32_t,uint32_t (*)[2u][2u]);

// TO PRESENT ALL DATA STORED IN THE MATRIX [col_MAX][row_MAX]:
uint32_t DS_STORED(uint16_t,uint16_t,uint32_t (*)[2u][2u]);

uint32_t DS_SEARCH(uint32_t (*)[2u][2u],uint8_t );

// FUNCTION TO GENERATE RANDOM NUMBERS: [x2.5 faster than rand()]
uint32_t RANDxF2p5(void); // RANDOM NUM-GEN FASTER x2.5.

// DATASET TO TXT FILE:
uint8_t DS_TXT(char,uint32_t (*)[2u][2u]);

// DATASET TO BINARY FILE:
uint8_t DS_BIN(char,uint32_t (*)[2u][2u]);

// DATASET TO EXCEL FILE:
uint8_t DS_CSV(char,uint32_t(*)[2u][2u]);

// FILE FUNCTIONS:
bool ACCESSIBILITY(FILE *); // FILE POINTER NULL CHECKER.
void DS_TXT_W(uint32_t (*)[2u][2u],FILE *); // WRITING TO TXT FILE.
void DS_TXT_R(uint32_t (*)[2u][2u],FILE *); // READING FROM  TXT FILE.

void DS_BIN_W(uint32_t (*)[2u][2u],FILE *); // WRITING TO BIN FILE.
void DS_BIN_R(uint32_t (*)[2u][2u],FILE *); // READING FROM  BIN FILE.

void DS_CSV_W(uint32_t (*)[2u][2u],FILE *); // WRITING TO CSV FILE.
void DS_CSV_R(uint32_t (*)[2u][2u],FILE *); // READING FROM  CSV FILE.

void DS_FILE_NAME(void); // Pick FILE NAME TO SAVE THE DATASET.

// E2U FUNCTIONS:
void _STYLE(uint8_t); // STYLE FRAMES FOR MAIN - UI
void _DS_FILE_SELECT(char,char,char); // FILE SELECTOR.


/*****************************************************
*                   GLOBAL VARIABLES                 *
******************************************************/

// FILE HANDLE section:
char FILE_NAME[50u] = "DS.txt"; // Global FILE NAME.
char (*F_N)[50u]    = &FILE_NAME; // pointer to character array(shift+50U).
bool ACCESS = false;
char ACCS;
char *_ACCESS = &ACCS;

// DATASET section:
uint32_t IN[2u][2u];  //2d Matrix for input.
uint32_t STR[2u][2u]; //2d Matrix for Storing input.
uint32_t CHK = 0; // CHECKING VAR.

uint32_t (*in) [2u][2u] = &IN;  // Getting the address of 2d array "IN"
uint32_t (*str)[2u][2u] = &STR; // Getting the address of 2d array "STR"

uint8_t counter = 0; // counter for Cycles done.
char n = '\0';  // CF character.

// ML - GEN [INC_COLOUM][INC_ROW]:
const uint8_t
      INC_C = 2U,
      INC_R = 2U;

uint16_t
    col = 2U,  // INIT VALUE for [COLOUM_MATRIX]
    row = 2U; // INIT VALUE for [ROW_MATRIX]

  /*
  Size of elements stored = (NUM_COLOUM * NUM_ROWS)

           0C   1C
      0R [VAR][VAR]  . . +2R
      1R [VAR][VAR] . .  +2R
          .    .
        .    .
      +2C  +2C

    Initial Matrix[2][2] -> [+INC_C][+INC_R] for each generation "Cycle".
*/


/*****************************************************
*                ML - FUNCTION DECLARATION           *
******************************************************/
// Readable logical operators
#define XOR   ^
#define XNOR  !^
#define LSO   <<
#define RSO   >>
#define AND   &
#define OR    |

//DATA SET section:

  // INPUT DATASET:
  void INPUT(uint16_t col, uint16_t row,uint32_t (*in)[2u][2u])
  {
    srand(time(NULL));  // Time function for random numbers each cycle.
    //SEEDRANDOM == time(NULL) (No limit randoming)
    const uint8_t
              SRL = 255U; // Seed random limit

    for(uint16_t i = 0; i < col; i++)
    {
      for(uint16_t j = 0; j < row; j++)
      {
        //Manual Input Mode(MIM):
        //printf(" [%d][%d]: ",i,j);
        //scanf("%d",&(*in)[i][j]);

         //Auto Input Mode(AIM):
           //Randomizing it by XOR:FUNCTION.
          // -RANDOM NUMBER FASTER x2.5 than rand().
         //  -RANDOMING ALGORITHM:
        //Problem: DATASET(TIME) = DATASET(TIME+1). Dataset is the same.

        (*in)[i][j] = ( (((RANDxF2p5()%SRL) XOR j) LSO ((0xDU) AND (0xBU))/(SRL) ));

        //Randoming by rand(). (X *j) to randomizing per gen (FAST CALCULATION)
        //(*in)[i][j] = ( (((rand()%SRL) *j) ^ (0xD & 0xB) ) *i);

                                                          //General Purpose.
        (*str)[i][j] = (*in)[i][j]; // Store INPUT DATASET to STR Mtrx. (GP)

      };// end for(j)
    };// end for(i)

  } // END INPUT.

  // OUTPUT DATA SET:
  void OUTPUT(uint16_t col, uint16_t row,uint32_t (*out)[2u][2u])
  {
    for(uint16_t i = 0; i < col; i++)
    {
      for(uint16_t j = 0; j < row; j++)
      {
        //printf(" [%d][%d]: %d \t",i,j,(*out)[i][j]);

        printf("0x%04x \t",(*out)[i][j]);

      };// end for j
    };// end for i
    printf("\n");
  } // END OUTPUT.

  // DS_STORED:
  uint32_t DS_STORED(uint16_t col, uint16_t row,uint32_t (*strd)[2u][2u])
  {
    uint32_t counter = 0;

    for(uint16_t i = 0; i < (col - INC_C); i++)
    {
      for(uint16_t j = 0; j < (row - INC_R); j++)
      {
        // Printing the data stored [0][0] -> [col][row]:
        // All data set stored in 04HEX format.
        printf("0x%04x \t",(*strd)[i][j]);
        counter++;
      };// end for j
    };// end for i
    //Printing total elements detected in the matrix.
    printf("\n \n TOTAL ELMENTS: %d \n",counter);
    return counter;
  } // END DS_STORED.


  /*****************************************************
  *             SUB - DATASET FUNCTIONS                *
  ******************************************************/
uint32_t DS_SEARCH(uint32_t (*D)[2u][2u],uint8_t test)
{
  uint32_t c = 0;

  //printf("\n (Numbers < %d): ",test);
  for(uint16_t i = 0; i < col - INC_C; i++)
  {
    for(uint16_t j = 0; j <row - INC_R; j++)
    {
      //if DATA < test (10 < 200)
      // counter++ (which means elements found < test) is now (1 + n)
      if((*D)[i][j] < test)
      {
        c++;
        //printf("\n %d",(*D)[i][j]);
      }
      else continue;
    }
  }

  return c; // total (elements < test) found.
} // END DS_SEARCH.


  /*****************************************************
  *           RANDOM NUMBERS GENERATORS                *
  ******************************************************/

// RNG Method#1:
static uint32_t G_S = 0U;
static uint32_t CRND = 0U;

inline uint32_t RANDxF2p5(void)
{
  G_S = (241013U * G_S + 2531011U) XOR CRND;
  CRND += 5;
  return (G_S RSO 16U) AND (0xDEADBEEFU);
} // END RANDxF2p5.

/*****************************************************
*                    FILES FUNCTIONS                 *
******************************************************/

/*****************************************************
*             FILES - SUB FUNCTIONS                  *
******************************************************/

// ACCESSIBILITY TEST FOR F_POINTER != NULL
bool ACCESSIBILITY(FILE *x)
{
  if(x == NULL) // #define NULL '\0' - END STATEMENT.
  {
    printf("\n Can't Type!. \n");
    return false;  // EXIT_FAILED - ERROR HANDLE '-1'
  }// END IF

  else
    return true;

}// END ACCESSIBILITY.

/*****************************************************
*                 FILE_SUB - TXT FILES               *
******************************************************/

// DATASET to FILE.txt section:
uint8_t DS_TXT(char m, uint32_t (*D)[2][2])
{
  //FILE ALLOCATE:
  FILE *DS_WTXT;     // Pointer to windows file address. (to write)
  FILE *DS_RTXT;    // Pointer to windows file address. (to read)

  // if (w) or (r) passed to the function:
    switch(m)
    {
      case 'w': // CASE WRITING:

                // Start allocating the file by address: (WRITE)
                DS_WTXT = fopen(FILE_NAME,"w");

                //IF ACCESSIBILITY == TRUE
                DS_TXT_W(D,DS_WTXT);  // Write the data stored.

                //AT THE END:
                fclose(DS_WTXT);  // Free Allocated (file) Space.
        break;

       case 'r': // CASE READING:

                // Start allocating the file by address: (READ)
                DS_RTXT = fopen(FILE_NAME,"r");

                //IF ACCESSIBILITY == TRUE
                DS_TXT_R(D,DS_RTXT); // Read the data stored.

                //AT THE END:
                fclose(DS_RTXT);  // Free Allocated (file) Space.
        break;

       default:  exit(1);
        break;
      } // END SWITCH.

    return 0;
} // END DS_TXT.

/*=============== SUB TXT FILES ===============*/
// WRITE TO TXT FUNCTION (fprintf(##)):
void DS_TXT_W(uint32_t (*D)[2][2],FILE *FPTR_W)
{
  //IF PASSED:
  if(ACCESSIBILITY(FPTR_W))
  {
    for(uint16_t i = 0; i <= col; i++)
    {
      for(uint16_t j = 0; j <= row; j++)
      {
        //Printing the data in decimal format:
        fprintf(FPTR_W,"%d  \n",(*D)[i][j]);

      };// end for(j).
    };// end for(i).
  }// end if(ACCESSIBILITY).

  else exit(1);
} // END DS_TXT_W

// READ FROM TXT FUNCTION (fgets(##)):
void DS_TXT_R(uint32_t (*D)[2][2],FILE *FPTR_R)
{
  uint16_t result = col*row;
  char x[result];

  if(ACCESSIBILITY(FPTR_R))
  {
    while(!feof(FPTR_R)) // (END OF FILE '\0')
    {
      fgets(x,result,FPTR_R); // Read the data till (FPTR_R == NULL).
      puts(x); // Print the data in terminal.

    }; //END WHILE.
  }// end if(ACCESSIBILITY).

  else exit(1);
} // END DS_TXT_R

/*****************************************************
*                 FILE_SUB - BIN FILES               *
******************************************************/

// DATASET to FILE.bin section:
uint8_t DS_BIN(char m, uint32_t (*D)[2][2])
{
  //FILE ALLOCATE:
  FILE *DS_WBIN;     // Pointer to windows file address. (to write)
  FILE *DS_RBIN;    // Pointer to windows file address. (to read)

  // if (w) or (r) passed to the function:
  switch(m)
  {
    case 'w': // CASE WRITING:
              // Start allocating the file by address:
              DS_WBIN = fopen(FILE_NAME,"wb");

              //IF ACCESSIBILITY == TRUE
              DS_BIN_W(D,DS_WBIN);

              //AT THE END:
              fclose(DS_WBIN);  // Free Allocated (file) Space.
      break;

     case 'r': // CASE READING:
              // Start allocating the file by address:
              DS_RBIN = fopen(FILE_NAME,"rb");

              //IF ACCESSIBILITY == TRUE
              DS_BIN_R(D,DS_RBIN);

              //AT THE END:
              fclose(DS_RBIN);  // Free Allocated (file) Space.
      break;

     default:  return -1;
               exit(1);
      break;
    } // END SWITCH.

  return 0;
}// END DS_BIN.

/*=============== SUB BIN FILES ===============*/

// DATASET WRITE TO BINARY FILES:
void DS_BIN_W(uint32_t (*D)[2][2],FILE *FPTR_W)
{

  if(ACCESSIBILITY(FPTR_W))
  {
    for(uint16_t i = 0; i < col; i++)
    {
      for(uint16_t j = 0; j < row; j++)
      {
        //Writing the data in binary file.
        fwrite(D,sizeof((*D)[i][j]),1,FPTR_W);

      };// end for(j).
    };// end for(i).
  }// end if(ACCESSIBILITY).

  else exit(1);
} // END DS_BIN_W.


// DATASET READ FROM BINARY FILES:
void DS_BIN_R(uint32_t (*D)[2][2],FILE *FPTR_R)
{
  uint16_t result = col*row;
  char x[result];

  if(ACCESSIBILITY(FPTR_R))
  {
    while((fread(&x,sizeof(x),1,FPTR_R)) == 1)
    {
      printf("%s",x); // Printing the data if found.

    }; // end while.
  }// end if(ACCESSIBILITY).

  else exit(1);
}// END DS_BIN_W.

/*****************************************************
*                 FILE_SUB - CSV FILES               *
******************************************************/

//DATA SET TO EXCEL SHEET section:
uint8_t DS_CSV(char m,uint32_t(*D)[2][2])
{
  //FILE ALLOCATE:
  FILE *DS_WEX;     // Pointer to windows file address. (to write)
  FILE *DS_REX;    // Pointer to windows file address. (to read)

  // if (w) or (r) passed to the function:
  switch(m)
  {
    case 'w': // CASE WRITING:
              // Start allocating the file by address:
              DS_WEX = fopen(FILE_NAME,"w");

              //IF ACCESSIBILITY == TRUE
              DS_CSV_W(D,DS_WEX);

              //AT THE END:
              fclose(DS_WEX);  // Free Allocated (file) Space.
      break;

     case 'r': // CASE READING:
              // Start allocating the file by address:
              DS_REX = fopen(FILE_NAME,"r");

              //IF ACCESSIBILITY == TRUE
              //DS_CSV_R(D,DS_REX);

              //AT THE END:
              fclose(DS_REX);  // Free Allocated (file) Space.
      break;

     default:  return -1;
               exit(1);
      break;
    } // END SWITCH.

  return 0;
}

/*=============== SUB TXT FILES ===============*/

// DATA SET TO CSV WRITE FUNCTION:
void DS_CSV_W(uint32_t (*D)[2][2],FILE *FPTR_W)
{
  if(ACCESSIBILITY(FPTR_W))
  {
    for(uint16_t i = 0; i < col; i++)
    {
      for(uint16_t j = 0; j < row; j++)
      {
        //Writing the data in excel file.
        fprintf(FPTR_W,"%d \n",((*D)[i][j]));

      };// end for(j).
    };// end for(i).
  } //end if(ACCESSIBILITY).

  else exit(1);
} //END DS_CSV_W

// DATA SET FROM CSV READ FUNCTION:
void DS_CSV_R(uint32_t (*D)[2][2],FILE *FPTR_R)
{
  if(ACCESSIBILITY(FPTR_R))
  {

  } //end if(ACCESSIBILITY).

  else exit(1);
}//END DS_CSV_W

/*****************************************************
*                EASY TO USE - FUNCTIONS             *
******************************************************/

// STYLE FRAMES FOR EASY UI:
void _STYLE(uint8_t NUM_STYLE)
{
  switch(NUM_STYLE)
  {
    case 1:
    printf("\n ML - Current Gen '%d' - DATA_MAX[%d][%d] ",counter,(col),(row));
    printf("\n Cycle %d - In Progress. ",(counter+1));
    printf("\n============================\n");
      break;

    case 2:
    printf("\n==================== \n");
    printf("\n ML - Data Stored: \n");
      break;

    case 3:
    printf("\n\n==================== \n");
    printf("\n=================================\n");
      break;

    case 4:
    printf("\n ML - Last Gen '%d' - DATA_MAX[%d][%d] ",(counter-1),(col-INC_C),(row-INC_R));
    printf("\n Cycle %d - Done. \n",(counter));
    printf("\n=================================\n");
      break;
    case 5:
    printf("\n--------- --------- --------- --------- --------- ---------\n");
    printf("\n \n All Data set stored [0][0] -> [%d][%d],\n",(col - INC_C),(row - INC_R));
    printf("\n--------- --------- --------- --------- --------- ---------\n");
      break;

    case 6:
    printf("\n \n--------- --------- --------- --------- --------- ---------\n");
      break;

    default: exit(1);
      break;
  }; // end switch.

}// end _STYLE().

/*
#define T1 ((strcmp(CHKR,".txt"))
#define T2 ((strcmp(CHKR,".txt"))

#define B1 ((strcmp(CHKR,".bin"))
#define B2 ((strcmp(CHKR,".bin"))

#define C1 ((strcmp(CHKR,".csv"))
#define C2 ((strcmp(CHKR,".csv"))
*/

// FILE NAME AS INPUT (SAVE DATASET).
void DS_FILE_NAME()
{
  printf("\n Current path <FOLDER>.\n");
  printf("\n ENTER FILE NAME: ");
  scanf("%s",*F_N); // Get the file name from user.

  // EXTINSION CHECKER:
  char *CHKR = (strrchr(*F_N,'.')); // CHECK IF FILE_NAME has extinsion.
  if(!strrchr(*F_N,'.')) {printf("\n Error File Extinsion.\n"); exit(1);}

  // EXTINSION VALIDITY CHECKER:

  // CHECK IF FILE_NAME (.txt):
  if( ((strcmp(CHKR,".txt")) == 0) ||
      ((strcmp(CHKR,".TXT")) == 0) ) // CHECK IF FILE_NAME (.txt)
  {
    // PASS:
    ACCESS = true;
   //*_ACCESS = '3'; //(.txt code == 3).
  }// end if(.tct).

  // CHECK IF FILE_NAME (.bin):
  else if( ((strcmp(CHKR,".bin")) == 0) ||
           ((strcmp(CHKR,".BIN")) == 0) ) // CHECK IF FILE_NAME (.bin)
  {
    // PASS:
    ACCESS = true;
   //*_ACCESS = '4'; //(.bin code == 4).
  }// end if(.bin).

  // CHECK IF FILE_NAME (.csv):
  else if( ((strcmp(CHKR,".csv")) == 0) ||
           ((strcmp(CHKR,".CSV")) == 0) )
  {
    // PASS:
    ACCESS = true;
   //*_ACCESS = '5'; //(.csv code == 5).
  }// end if(.csv).

  //else if file name != (txt,bin,csv):
  else
  {
    printf("\n Unkown extinsion for this file. \n");
    ACCESS = false;
   //*_ACCESS = '0';
    exit(1);
  }; // end else.

  system("cls");
} // end DS_FILE_NAME.


// EASY DATASET FILE SELECT:
  // WORK MAP CHART:
/* [                           Write/Read      Open/Close    ]
   [  TYPE: 'T' => FILE.TXT, MOD:('w','r'), STATE:('o','c'). ]
   [  TYPE: 'B' => FILE.BIN, MOD:('w','r'), STATE:('o','c'). ]
   [  TYPE: 'C' => FILE.CSV, MOD:('w','r'), STATE:('o','c'). ]
*/
void _DS_FILE_SELECT(char DSFS , char DSFM, char DSFST)
{
  if(ACCESS) // CHECK IF FILE_NAME IS VALID.
  {
    // FILE WRITE COMMANDS.
    if(DSFM == 'w')
    {
      switch(DSFS)
      {
        case 'T':
                    DS_TXT('w',str);   // DATASET WRITE IN TEXT FILE.
                     // CHECK IF 'open' command is true: 1 & 1 &1 :> 1
                    if( (DSFST == 'o') )
                      {system(FILE_NAME);} // Open the file after.

          break;

        case 'B':
                    DS_BIN('w',str);   // DATASET WRITE IN TEXT FILE.
                    // CHECK IF 'open' command is true: 1 & 1 &1 :> 1
                    if( (DSFST == 'o') )
                      {system(FILE_NAME);} // Open the file after.

        break;

        case 'C':
                    DS_CSV('w',str);   // DATASET WRITE IN TEXT FILE.
                    // CHECK IF 'open' command is true: 1 & 1 &1 :> 1
                    if( (DSFST == 'o') )
                      {system(FILE_NAME);} // Open the file after.

        break;

        default: exit(1);
        break;
      }; // end switch.
    } // end if(DFSF)

    // FILE READ COMMANDS:
    else if(DSFM == 'r')
    {
      switch(DSFS)
      {
        case 'T':
                    DS_TXT('r',str);   // DATASET WRITE IN TEXT FILE.
                    // CHECK IF 'open' command is true: 1 & 1 &1 :> 1
                    if( (DSFST == 'o') )
                      {system(FILE_NAME);} // Open the file after.

                  //else exit(1);
          break;

        case 'B':
                    DS_BIN('r',str);   // DATASET WRITE IN TEXT FILE.
                    // CHECK IF 'open' command is true: 1 & 1 &1 :> 1
                    if( (DSFST == 'o') )
                      {system(FILE_NAME);} // Open the file after.

                  else exit(1);
        break;

        case 'C':
                    DS_CSV('r',str);   // DATASET WRITE IN TEXT FILE.
                    // CHECK IF 'open' command is true: 1 & 1 &1 :> 1
                    if( (DSFST == 'o') )
                      {system(FILE_NAME);} // Open the file after.

                  else exit(1);
          break;

        default: exit(1);
          break;
        }; // end switch.
      } // end if(DSFM).

    else exit(1);
  }// end if(DS_FILE_NAME()).

  else exit(1);
}// end _DS_FILE_SELECT.


/*****************************************************
*                ERROR HANDLER SECTION               *
******************************************************/
/*****************************************************
*                DS-FUNCTIONS ERRORS                 *
******************************************************/


/*****************************************************
*                FILES-FUNCTIONS ERRORS              *
******************************************************/
//#define F5 _ERROR__FILES_DS_FILE_SELECT_

/*****************************************************
*                E2U-FUNCTIONS ERRORS                *
******************************************************/

#endif // __ML_H_H__
