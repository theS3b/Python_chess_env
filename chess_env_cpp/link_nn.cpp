#include "link_nn.h"
#include "consts.h"

bool check_promotion(uint64_t pawn0, uint64_t pawnc) {
	return (POPCNT(pawn0) != POPCNT(pawnc));
}

unsigned int encode_Q_move(uint64_t before, uint64_t after) {
	uint64_t tmp = before;
	before &= before ^ after;
	after &= tmp ^ after;
	unsigned int tzb = CTZ(before);
	unsigned int tza = CTZ(after);
	unsigned int init_shift = tzb * 64;

	// magic nbr calculated w/ 7 * x -1
	// in the order : N, S, E, O, NE, NO, SE, SO
	//            x : 0, 1, 2, 3, 4,  5,  6,  7
	if (tzb % 8 == tza % 8) {
		if (before > after)
			return init_shift + 6 + (tzb - tza + 1) / 8;
		else
			return init_shift + ((tza - tzb + 1) / 8) - 1;
	}
	else if ((int)(tzb / 8) == (int)(tza / 8)) {
		if (before > after)
			return init_shift + 13 + tzb - tza;
		else
			return init_shift + 20 + tza - tzb;
	}
	else {
		if (before > after) {
			if (tzb % 8 > tza % 8)
				return init_shift + 41 + (int)((tzb - tza + 1) / 8);
			else
				return init_shift + 48 + (int)((tzb - tza + 1) / 8);
		}
		else {
			if (tzb % 8 > tza % 8)
				return init_shift + 27 + (int)((tza - tzb + 1) / 8);
			else
				return init_shift + 34 + (int)((tza - tzb + 1) / 8);
		}
	}
	return 4100; // error because the max length of the table is 4098
}

unsigned int encode_K_move(uint64_t before, uint64_t after)
{
	uint64_t tmp = before;
	before &= before ^ after;
	after &= tmp ^ after;
	unsigned int init_shift = 55 + (CTZ(before) * 64); // 7 * 8 -1 + case shift
	
	// shift in the clockwise order starting at 12h
	if (before << 15 == after)
		return init_shift + 1;
	else if (before << 6 == after)
		return init_shift + 2;
	else if (before >> 10 == after)
		return init_shift + 3;
	else if (before >> 17 == after)
		return init_shift + 4;
	else if (before >> 15 == after)
		return init_shift + 5;
	else if (before >> 6 == after)
		return init_shift + 6;
	else if (before << 10 == after)
		return init_shift + 7;
	else if (before << 17 == after)
		return init_shift + 8;
	return 4100;
}

