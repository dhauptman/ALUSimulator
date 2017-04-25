//*****************************************************************************
//
//	Program:		ArithBench2.c
//	Author:			Gary J. Minden <gminden@ittc.ku.edu>
//	Date:			2017-01-30 (B70130)
//	Description:	A simple synthetic benchmark
//
//*****************************************************************************	

#include <stdio.h>
#include <time.h>

main() {

int     IA1, IA2, IA3, IA4, IA5, IA6, IA7, IA8, IA9, IA10;

int     FA1, FA2, FA3, FA4, FA5, FA6, FA7, FA8, FA9, FA10;

long STime, ETime;
long theTime;

long Iteration;

int SampleCount;

        time( &theTime );
        printf( "Start of arithmetic benchmark time = %12ld   %s\n",
                time( &theTime ), ctime( &theTime ) );

        /* Define some random integer data */

        IA1 = rand() / 2000;
        IA2 = rand() / 2000;
        IA3 = rand() / 2000;
        IA4 = rand() / 2000;
        IA5 = rand() / 2000;
        IA6 = rand() / 2000;
        IA7 = rand() / 2000;
        IA8 = rand() / 2000;
        IA9 = rand() / 2000;
        IA10 = rand() / 2000;

        /* Define some random floating data */

        FA1 = ((float) rand())/ 2000.0;
        FA2 = ((float) rand())/ 2000.0;
        FA3 = ((float) rand())/ 2000.0;
        FA4 = ((float) rand())/ 2000.0;
        FA5 = ((float) rand())/ 2000.0;
        FA6 = ((float) rand())/ 2000.0;
        FA7 = ((float) rand())/ 2000.0;
        FA8 = ((float) rand())/ 2000.0;
        FA9 = ((float) rand())/ 2000.0;
        FA10 = ((float) rand())/ 2000.0;


        /* Take 5 samples, waiting till the next clock tick.
                Sleep one second before starting the loop. */

        sleep( 1 );

        for ( SampleCount = 0; SampleCount < 10; SampleCount++ ) {

        sleep( 1 );

        Iteration = 0;

        STime = time( &theTime );
        ETime = time( &theTime );

        for( Iteration = 0; Iteration < 1000000000; Iteration++ ) {

        /* Make sure IA7 and FA7 are not zero */

        IA7 = rand() / 2000 + 23;
        FA7 = ((float) rand())/ 2000.0 + 23.4;

        /* Do some Integer arithmetic */

        IA1 = IA2 + IA3;
        IA2 = IA3 * IA4;
        IA3 = IA4 + IA5;
        IA4 = IA5 * IA6;
        IA5 = IA6 / IA7;
        IA6 = IA7 + IA8;
        IA7 = IA8 + IA9;
        IA8 = IA9 * IA10;

        /* Do some Floating arithmetic */

        FA1 = FA2 + FA3;
        FA2 = FA3 * FA4;
        FA3 = FA4 + FA5;
        FA4 = FA5 * FA6;
        FA5 = FA6 / FA7;
        FA6 = FA7 + FA8;
        FA7 = FA8 * FA9;

        }

        ETime = time( &theTime );
		ETime = ETime - STime;

        printf( "Arithmetic time = %12ld\n", ETime );

        }

        time( &theTime );
        printf( "End of arithmetic benchmark time = %12ld   %s\n",
                time( &theTime ), ctime( &theTime ) );

}

