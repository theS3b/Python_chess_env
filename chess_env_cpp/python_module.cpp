#pragma once
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "board.h"
#include "chess_attacked.h"
#include "link_nn.h"

namespace py = pybind11;

PYBIND11_MODULE(chess_env, m) {
	py::class_<Board>(m, "Board")
		.def(py::init<>())
		.def_readwrite("bitboard", &Board::bit_board, py::return_value_policy::reference)
		.def_readwrite("player", &Board::player, py::return_value_policy::reference)
		.def_readwrite("check_type", &Board::check_type, py::return_value_policy::reference)
		.def_readwrite("last_pawn_pos", &Board::last_pawn_pos, py::return_value_policy::reference)
		.def_readwrite("king_rook_moved", &Board::king_rook_moved, py::return_value_policy::reference)
		.def_readwrite("last_moves", &Board::last_moves, py::return_value_policy::reference)
		.def_readwrite("counter", &Board::counter, py::return_value_policy::reference)
		.def("get_bitboard_children", &Board::get_bitboard_children_cpp, "A function that returns all the next possible states")
		.def("get_result", &Board::get_result, "A function that tells who wins (+1 WHITE, -1 BLACK, 0 PAT/DEFAULT)", py::arg("player"), py::arg("leaf"))
		.def("string_board", &Board::string_board, "Returns a string representing the board");
	py::enum_<Piece>(m, "Piece")
		.value("wpawn", Piece::wpawn)
		.value("bpawn", Piece::bpawn)
		.value("wrook", Piece::wrook)
		.value("brook", Piece::brook)
		.value("wbishop", Piece::wbishop)
		.value("bbishop", Piece::bbishop)
		.value("wknight", Piece::wknight)
		.value("bknight", Piece::bknight)
		.value("wqueen", Piece::wqueen)
		.value("bqueen", Piece::bqueen)
		.value("wking", Piece::wking)
		.value("bking", Piece::bking)
		.value("notype", Piece::notype)
		.export_values();
	m.def("encode_Q_move", &encode_Q_move, py::return_value_policy::reference)
	 .def("encode_K_move", &encode_K_move, py::return_value_policy::reference)
	 .def("check_promotion", &check_promotion, py::return_value_policy::reference);

#ifdef VERSION_INFO
	m.attr("__version__") = VERSION_INFO;
#else
	m.attr("__version__") = "dev";
#endif
}
