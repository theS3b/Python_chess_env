#pragma once
#include <stdint.h>

//returns true if there was a promotion.
bool check_promotion(uint64_t pawn0, uint64_t pawnc);
// function returning the index to the prob vector returned by the NN.
// In python you'll just need to add to this number the shift from the case.
unsigned int encode_Q_move(uint64_t before, uint64_t after);
unsigned int encode_K_move(uint64_t before, uint64_t after);