#pragma once

const int PIPES = 8;
const int RATIO = 60;
//to right to left
const int TAP = 0;
const int STRIGHT_PIIPE = 1;
const int CORNER_PIPE = 2;
const int TPIPE = 3;
const int PLUS_PIPE = 4;
const int SINK = 5;
const int FULL_SINK = 6;
const int WHITE = 7;

struct Position { // first connect with , second full are true
	std::pair <bool, bool> up = std::make_pair(false, false);
	std::pair <bool, bool> down = std::make_pair(false, false);
	std::pair <bool, bool> right = std::make_pair(false, false);
	std::pair <bool, bool> left = std::make_pair(false, false);
};