//*****************************************************************************
//--ALUSimulator.c
//
//		Author: 			Dustin Hauptman, Lucas Suchy
//		Organization:	KU/EECS/EECS 645
//		Date:					2017-05-04
//		Version:			1.0
//		Description:	This program simulates a simple ALU.
//		Notes: 				The initial print statements and function parameters
//									were provided by Dr. Gary Minden.
//
//*****************************************************************************
//

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdarg.h>

#include <stdio.h>

#include "RegisterFile_01.h"
#include "ALUSimulator.h"

//
// Function simulates an ALU
//
extern void ALUSimulator( RegisterFile theRegisterFile,
	uint32_t OpCode,
	uint32_t Rs, uint32_t Rt, uint32_t Rd,
	uint32_t ShiftAmt,
	uint32_t FunctionCode,
	uint32_t ImmediateValue,
	uint32_t* Status ) {

		//
		// Print the inputted OpCode, Rs, Rt, and Rd values
		//
		printf( ">>ALU: Opcode: %02X; Rs: %02X; Rt: %02X; Rd: %02X;\n",
		OpCode,
		Rs,
		Rt,
		Rd );

		//
		// Print the inputted ShiftAmt, FunctionCode, and the ImmediateValue
		//
		printf( ">>>>ALU: ShiftAmt: %02X; FunctionCode: %02X; ImmediateValue: %04X;\n",
		ShiftAmt,
		FunctionCode,
		ImmediateValue );

		//
		// Checks the OpCode value. If it is 0, then it is a register type
		// instruction and the function code is used to determine which to perform
		//
		if (!OpCode) {

			//
			// Check the value of the provided function code and execute
			// the proper instruction based on its value
			//
			switch (FunctionCode) {
				case 0:
				//
				// SLL/NOOP MIPS instruction
				//
				theRegisterFile[Rd] = theRegisterFile[Rt] << ShiftAmt;
				break;
				case 2:
				//
				// SRL MIPS instruction
				//
				theRegisterFile[Rd] = theRegisterFile[Rt] >> ShiftAmt;
				break;
				case 3:
				//
				// SRA MIPS instruction
				//
				theRegisterFile[Rd] = (int32_t)theRegisterFile[Rt] >> ShiftAmt;
				break;
				case 4:
				//
				// SLLV MIPS instruction
				//
				theRegisterFile[Rd] = theRegisterFile[Rt] << theRegisterFile[Rs];
				break;
				case 6:
				//
				// SRLV MIPS instruction
				//
				theRegisterFile[Rd] = theRegisterFile[Rt] >> theRegisterFile[Rs];
				break;
				case 32:
				//
				// ADD MIPS instruction
				//
				theRegisterFile[Rd] = (int32_t)theRegisterFile[Rs] + (int32_t)theRegisterFile[Rt];
				break;
				case 33:
				//
				// ADDU MIPS instruction
				//
				theRegisterFile[Rd] = theRegisterFile[Rs] + theRegisterFile[Rt];
				break;
				case 34:
				//
				// SUB MIPS instruction
				//
				theRegisterFile[Rd] = (int32_t)theRegisterFile[Rs] - (int32_t)theRegisterFile[Rt];
				break;
				case 35:
				//
				// SUBU MIPS instruction
				//
				theRegisterFile[Rd] = theRegisterFile[Rs] - theRegisterFile[Rt];
				break;
				case 36:
				//
				// AND MIPS instruction
				//
				theRegisterFile[Rd] = theRegisterFile[Rs] & theRegisterFile[Rt];
				break;
				case 37:
				//
				// OR MIPS instruction
				//
				theRegisterFile[Rd] = theRegisterFile[Rs] | theRegisterFile[Rt];
				break;
				case 38:
				//
				// XOR MIPS instruction
				//
				theRegisterFile[Rd] = theRegisterFile[Rs] ^ theRegisterFile[Rt];
				break;
				case 42:
				//
				// SLT MIPS instruction
				//
				if (theRegisterFile[Rs] < theRegisterFile[Rt]) {
					theRegisterFile[Rd] = 1;
				}
				else {
					theRegisterFile[Rd] = 0;
				}
				break;
				case 43:
				//
				// SLTU MIPS instruction
				//
				if (theRegisterFile[Rs] < theRegisterFile[Rt]) {
					theRegisterFile[Rd] = 1;
				}
				else {
					theRegisterFile[Rd] = 0;
				}
				break;
				default:
				break;
			}

		}

		//
		// ADDI MIPS instruction
		//
		else if (OpCode == 8) {
			theRegisterFile[Rt] = (int32_t)theRegisterFile[Rs] + (int32_t)(int16_t)ImmediateValue;
		}

		//
		// ADDIU MIPS instruction
		//
		else if (OpCode == 9) {
			theRegisterFile[Rt] = theRegisterFile[Rs] + ImmediateValue;
		}

		//
		// SLTI MIPS instruction
		//
		else if (OpCode == 10) {
			if ((int32_t)theRegisterFile[Rs] < (int32_t)(int16_t)ImmediateValue) {
				theRegisterFile[Rt] = 1;
			}
			else {
				theRegisterFile[Rt] = 0;
			}
		}

		//
		//SLTIU MIPS instruction
		//
		else if (OpCode == 11) {
			if (theRegisterFile[Rs] < ImmediateValue) {
				theRegisterFile[Rt] = 1;
			}
			else {
				theRegisterFile[Rt] = 0;
			}
		}
	}
