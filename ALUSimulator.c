//*****************************************************************************
//--ALUSimulator.c
//
//		Author: 		Gary J. Minden
//		Organization:	KU/EECS/EECS 645
//		Date:			2017-04-22 (B70422)
//		Version:		1.0
//		Description:	This is the test standin for a simple ALU simulator
//		Notes:
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

extern void ALUSimulator( RegisterFile theRegisterFile,
	uint32_t OpCode,
	uint32_t Rs, uint32_t Rt, uint32_t Rd,
	uint32_t ShiftAmt,
	uint32_t FunctionCode,
	uint32_t ImmediateValue,
	uint32_t* Status ) {

		printf( ">>ALU: Opcode: %02X; Rs: %02X; Rt: %02X; Rd: %02X;\n",
		OpCode,
		Rs,
		Rt,
		Rd );

		printf( ">>>>ALU: ShiftAmt: %02X; FunctionCode: %02X; ImmediateValue: %04X;\n",
		ShiftAmt,
		FunctionCode,
		ImmediateValue );

		if (!OpCode) { // If OpCode = 0x0
			switch (FunctionCode) {
				case 0:
				theRegisterFile[Rd] = theRegisterFile[Rt] << ShiftAmt; // SLL/NOOP
				break;
				case 2:
				theRegisterFile[Rd] = theRegisterFile[Rt] >> ShiftAmt; // SRL
				break;
				case 3:
				theRegisterFile[Rd] = (int32_t)theRegisterFile[Rt] >> ShiftAmt; // SRA
				break;
				case 4:
				theRegisterFile[Rd] = theRegisterFile[Rt] << theRegisterFile[Rs]; // SLLV
				break;
				case 6:
				theRegisterFile[Rd] = theRegisterFile[Rt] >> theRegisterFile[Rs]; // SRLV
				break;
				case 32:
				theRegisterFile[Rd] = (int32_t)theRegisterFile[Rs] + (int32_t)theRegisterFile[Rt]; // ADD
				break;
				case 33:
				theRegisterFile[Rd] = theRegisterFile[Rs] + theRegisterFile[Rt];// ADDU
				break;
				case 34:
				theRegisterFile[Rd] = (int32_t)theRegisterFile[Rs] - (int32_t)theRegisterFile[Rt];// SUB
				break;
				case 35:
				theRegisterFile[Rd] = theRegisterFile[Rs] - theRegisterFile[Rt];// SUBU
				break;
				case 36:
				theRegisterFile[Rd] = theRegisterFile[Rs] & theRegisterFile[Rt];// AND
				break;
				case 37:
				theRegisterFile[Rd] = theRegisterFile[Rs] | theRegisterFile[Rt];// OR
				break;
				case 38:
				theRegisterFile[Rd] = theRegisterFile[Rs] ^ theRegisterFile[Rt];// XOR
				break;
				case 42:
				// SLT
				if (theRegisterFile[Rs] < theRegisterFile[Rt]) {
					theRegisterFile[Rd] = 1;
				}
				else {
					theRegisterFile[Rd] = 0;
				}
				break;
				case 43:
				// SLTU
				if (theRegisterFile[Rs] < theRegisterFile[Rt]) {
					theRegisterFile[Rd] = 1;
				}
				else {
					theRegisterFile[Rd] = 0;
				}
				break;
			}

		}
		else if (OpCode == 8) {
			// ADDI
			theRegisterFile[Rt] = (int32_t)theRegisterFile[Rs] + ImmediateValue;
		}
		else if (OpCode == 9) {
			// ADDIU
			theRegisterFile[Rt] = theRegisterFile[Rs] + ImmediateValue;
		}
		else if (OpCode == 10) {
			// SLTI
			if ((int32_t)theRegisterFile[Rs] < ImmediateValue) {
				theRegisterFile[Rt] = 1;
			}
			else {
				theRegisterFile[Rt] = 0;
			}
		}
		else if (OpCode == 11) {
			//SLTIU
			if (theRegisterFile[Rs] < ImmediateValue) {
				theRegisterFile[Rt] = 1;
			}
			else {
				theRegisterFile[Rt] = 0;
			}
		}
	}
