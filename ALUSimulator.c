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
        Rd = Rt << ShiftAmt; // SLL/NOOP
        break;
        case 2:
        Rd = Rt >> ShiftAmt; // SRL
        break;
        case 3:
        Rd = signed(Rt) >> ShiftAmt; // SRA
        break;
        case 4:
        Rd = Rt << Rs; // SLLV
        break;
        case 6:
        Rd = Rt >> Rs; // SRLV
        break;
        case 16:
        // MFHI
        break;
        case 18:
        // MFLO
        break;
        case 24:
        // MULT
        break;
        case 25:
        // MULTU
        break;
        case 26:
        // DIV
        break;
        case 27:
        // DIVU
        break;
        case 32:
        Rd = Rs + Rt; // ADD
        break;
        case 33:
        Rd = Rs + Rt;// ADDU
        break;
        case 34:
        Rd = Rs - Rt;// SUB
        break;
        case 35:
        Rd = Rs - Rt;// SUBU
        break;
        case 36:
        Rd = Rs & Rt;// AND
        break;
        case 37:
        Rd = Rs | Rt;// OR
        break;
        case 38:
        Rd = Rs ^ Rt;// XOR
        break;
        case 42:
        // SLT
        if (Rs < Rt) {
          Rd = 1;
        }
        else {
          Rd = 0;
        }
        break;
        case 43:
        // SLTU
        if (Rs < Rt) {
          Rd = 1;
        }
        else {
          Rd = 0;
        }
        break;
      }

    }
    else if (OpCode == 8) {
      // ADDI
      Rt = Rs + ImmediateValue;
    }
    else if (OpCode == 9) {
      // ADDIU
      Rt = Rs + ImmediateValue;
    }
    else if (OpCode == 10) {
      // SLTI
      if (Rs < ImmediateValue) {
        Rt = 1;
      }
      else {
        Rt = 0;
      }
    }
    else if (OpCode == 11) {
      //SLTIU
      if (Rs < ImmediateValue) {
        Rt = 1;
      }
      else {
        Rt = 0;
      }
    }
  }
