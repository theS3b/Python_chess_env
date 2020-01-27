#include <iostream>
#include <bitset>
#include "chess_moves.h"


using namespace std;

void printbit(const uint64_t& tmp);
void printboard(const Board& tmp);

int main()
{
	Board b = init_board();
	printboard(b);
	cout << endl << endl;
	Board f[MAX_POSSIBLE_MOVES];

	cout << sizeof(Board) << endl;
	for (long long int i = 0; i < 1000000; i++)
		get_bitboard_children(f, b, WHITE);

	int i = get_bitboard_children(f, b, WHITE);
	for (int j = 0; j < i; j++) {
		printboard(f[j]);
		cout << endl;
	}
	return 0;
}
void printbit(const uint64_t& tmp) {
	bitset<64> myBit(tmp);
	string str = myBit.to_string();
	int count = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++, count++) {
			cout << str[count];
		}
		cout << endl;
	}
}

void printboard(const Board& tmp) {
	string str = "";
	for (int pos = SIZEOF_U64_TIMES_8 - 1; pos >= 0; pos--) {
		unsigned int type = get_type_from_pos(tmp, pos);
		switch (type) {
		case notype:
			str += ".";
			break;
		case wpawn:
			str += "P";
			break;
		case bpawn:
			str += "p";
			break;
		case wrook:
			str += "T";
			break;
		case brook:
			str += "t";
			break;
		case wbishop:
			str += "F";
			break;
		case bbishop:
			str += "f";
			break;
		case wknight:
			str += "C";
			break;
		case bknight:
			str += "c";
			break;
		case wqueen:
			str += "Q";
			break;
		case bqueen:
			str += "q";
			break;
		case wking:
			str += "K";
			break;
		case bking:
			str += "k";
			break;
		}
	}
	int count = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++, count++) {
			cout << str[count];
		}
		cout << endl;
	}
}