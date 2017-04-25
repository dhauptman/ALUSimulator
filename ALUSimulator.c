#include "RegisterFile_01.h"
void ALUSimulator(RegisterFile _RegisterFile,
  uint32_t OpCode,
  uint32_t Rs, uint32_t Rt, uint32_t Rd,
  uint32_t ShiftAmt,
  uint32_t FunctionCode,
  uint32_t ImmediateValue,
  uint32_t* status) {
    if (!OpCode) { // If OpCode = 0x0
      switch (FunctionCode) {
        case 0:
        Rd = Rs << ShiftAmt;
        break;
        case 2:
        Rd = Rs >> ShiftAmt;
        break;
        case 3:
        break;
        case 4:
        break;
        case 6:
        break;
        case 16:
        break;
        case 18:
        break;
        case 24:
        break;
        case 25:
        break;
        case 26:
        break;
        case 27:
        break;
        case 32:
        break;
        case 33:
        break;
        case 34:
        break;
        case 35:
        break;
        case 36:
        break;
        case 37:
        break;
        case 38:
        break;
        case 42:
        break;
        case 43:
        break;
      }

    }
    else if (OpCode == 8) {

    }
    else if (OpCode == 9) {

    }
    else if (OpCode == 10) {

    }
    else if (OpCode == 11) {

    }
  }
