#pragma once

const int RATIO = 60;
const int PIPES = 12;
const int STRIGHT_PIIPE = 0;
const int PIPE_FULL = 1;
const int CORNER_PIPE = 2;
const int CORNER_PIPE_FULL = 3;
const int TPIPE = 4;
const int T_PIPE_FULL = 5;
const int PLUS_PIPE = 6;
const int PLUS_PIPE_FULL = 7;
const int SINK = 8;
const int TAP = 9;
const int WELLDONE = 10;
const int FULLSINK = 11;


struct Position { // first connect with , second full are true
	std::pair <bool, bool> up = std::make_pair(false, false);
	std::pair <bool, bool> down = std::make_pair(false, false);
	std::pair <bool, bool> right = std::make_pair(false, false);
	std::pair <bool, bool> left = std::make_pair(false, false);
};