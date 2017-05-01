#!/bin/bash

gcc -c ALUSimulator.c ALUSimulator_Main.c RegisterFile_01.c
gcc -o ALUSim ALUSimulator_Main.o ALUSimulator.o RegisterFile_01.o
