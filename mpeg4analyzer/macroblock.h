#ifndef __MACROBLOCK_H__
#define __MACROBLOCK_H__

#include "global.h"
#include "vlc.h"

static	VLC sprite_trajectory_code[32768];

static	VLC sprite_trajectory_len[15] = {
	{ 0x00 , 2},
	{ 0x02 , 3}, { 0x03, 3}, { 0x04, 3}, { 0x05, 3}, { 0x06, 3},
	{ 0x0E , 4}, { 0x1E, 5}, { 0x3E, 6}, { 0x7E, 7}, { 0xFE, 8},
	{ 0x1FE, 9}, {0x3FE,10}, {0x7FE,11}, {0xFFE,12} };
VLC const mcbpc_intra_table[64] = {
	{-1, 0}, {20, 6}, {36, 6}, {52, 6}, {4, 4},  {4, 4},  {4, 4},  {4, 4},
	{19, 3}, {19, 3}, {19, 3}, {19, 3}, {19, 3}, {19, 3}, {19, 3}, {19, 3},
	{35, 3}, {35, 3}, {35, 3}, {35, 3}, {35, 3}, {35, 3}, {35, 3}, {35, 3},
	{51, 3}, {51, 3}, {51, 3}, {51, 3}, {51, 3}, {51, 3}, {51, 3}, {51, 3},
	{3, 1},  {3, 1},  {3, 1},  {3, 1},  {3, 1},  {3, 1},  {3, 1},  {3, 1},
	{3, 1},  {3, 1},  {3, 1},  {3, 1},  {3, 1},  {3, 1},  {3, 1},  {3, 1},
	{3, 1},  {3, 1},  {3, 1},  {3, 1},  {3, 1},  {3, 1},  {3, 1},  {3, 1},
	{3, 1},  {3, 1},  {3, 1},  {3, 1},  {3, 1},  {3, 1},  {3, 1},  {3, 1}
};

VLC const mcbpc_inter_table[257] = {
	{VLC_ERROR, 0}, {255, 9}, {52, 9}, {36, 9}, {20, 9}, {49, 9}, {35, 8}, {35, 8},
	{19, 8}, {19, 8}, {50, 8}, {50, 8}, {51, 7}, {51, 7}, {51, 7}, {51, 7},
	{34, 7}, {34, 7}, {34, 7}, {34, 7}, {18, 7}, {18, 7}, {18, 7}, {18, 7},
	{33, 7}, {33, 7}, {33, 7}, {33, 7}, {17, 7}, {17, 7}, {17, 7}, {17, 7},
	{4, 6}, {4, 6}, {4, 6}, {4, 6}, {4, 6}, {4, 6}, {4, 6}, {4, 6},
	{48, 6}, {48, 6}, {48, 6}, {48, 6}, {48, 6}, {48, 6}, {48, 6}, {48, 6},
	{3, 5}, {3, 5}, {3, 5}, {3, 5}, {3, 5}, {3, 5}, {3, 5}, {3, 5},
	{3, 5}, {3, 5}, {3, 5}, {3, 5}, {3, 5}, {3, 5}, {3, 5}, {3, 5},
	{32, 4}, {32, 4}, {32, 4}, {32, 4}, {32, 4}, {32, 4}, {32, 4}, {32, 4},
	{32, 4}, {32, 4}, {32, 4}, {32, 4}, {32, 4}, {32, 4}, {32, 4}, {32, 4},
	{32, 4}, {32, 4}, {32, 4}, {32, 4}, {32, 4}, {32, 4}, {32, 4}, {32, 4},
	{32, 4}, {32, 4}, {32, 4}, {32, 4}, {32, 4}, {32, 4}, {32, 4}, {32, 4},
	{16, 4}, {16, 4}, {16, 4}, {16, 4}, {16, 4}, {16, 4}, {16, 4}, {16, 4},
	{16, 4}, {16, 4}, {16, 4}, {16, 4}, {16, 4}, {16, 4}, {16, 4}, {16, 4},
	{16, 4}, {16, 4}, {16, 4}, {16, 4}, {16, 4}, {16, 4}, {16, 4}, {16, 4},
	{16, 4}, {16, 4}, {16, 4}, {16, 4}, {16, 4}, {16, 4}, {16, 4}, {16, 4},
	{2, 3}, {2, 3}, {2, 3}, {2, 3}, {2, 3}, {2, 3}, {2, 3}, {2, 3},
	{2, 3}, {2, 3}, {2, 3}, {2, 3}, {2, 3}, {2, 3}, {2, 3}, {2, 3},
	{2, 3}, {2, 3}, {2, 3}, {2, 3}, {2, 3}, {2, 3}, {2, 3}, {2, 3},
	{2, 3}, {2, 3}, {2, 3}, {2, 3}, {2, 3}, {2, 3}, {2, 3}, {2, 3},
	{2, 3}, {2, 3}, {2, 3}, {2, 3}, {2, 3}, {2, 3}, {2, 3}, {2, 3},
	{2, 3}, {2, 3}, {2, 3}, {2, 3}, {2, 3}, {2, 3}, {2, 3}, {2, 3},
	{2, 3}, {2, 3}, {2, 3}, {2, 3}, {2, 3}, {2, 3}, {2, 3}, {2, 3},
	{2, 3}, {2, 3}, {2, 3}, {2, 3}, {2, 3}, {2, 3}, {2, 3}, {2, 3},
	{1, 3}, {1, 3}, {1, 3}, {1, 3}, {1, 3}, {1, 3}, {1, 3}, {1, 3},
	{1, 3}, {1, 3}, {1, 3}, {1, 3}, {1, 3}, {1, 3}, {1, 3}, {1, 3},
	{1, 3}, {1, 3}, {1, 3}, {1, 3}, {1, 3}, {1, 3}, {1, 3}, {1, 3},
	{1, 3}, {1, 3}, {1, 3}, {1, 3}, {1, 3}, {1, 3}, {1, 3}, {1, 3},
	{1, 3}, {1, 3}, {1, 3}, {1, 3}, {1, 3}, {1, 3}, {1, 3}, {1, 3},
	{1, 3}, {1, 3}, {1, 3}, {1, 3}, {1, 3}, {1, 3}, {1, 3}, {1, 3},
	{1, 3}, {1, 3}, {1, 3}, {1, 3}, {1, 3}, {1, 3}, {1, 3}, {1, 3},
	{1, 3}, {1, 3}, {1, 3}, {1, 3}, {1, 3}, {1, 3}, {1, 3}, {1, 3},
	{0, 1}
};

VLC const cbpy_table[64] = {
	{-1, 0}, {-1, 0}, {6, 6},  {9, 6},  {8, 5},  {8, 5},  {4, 5},  {4, 5},
	{2, 5},  {2, 5},  {1, 5},  {1, 5},  {0, 4},  {0, 4},  {0, 4},  {0, 4},
	{12, 4}, {12, 4}, {12, 4}, {12, 4}, {10, 4}, {10, 4}, {10, 4}, {10, 4},
	{14, 4}, {14, 4}, {14, 4}, {14, 4}, {5, 4},  {5, 4},  {5, 4},  {5, 4},
	{13, 4}, {13, 4}, {13, 4}, {13, 4}, {3, 4},  {3, 4},  {3, 4},  {3, 4},
	{11, 4}, {11, 4}, {11, 4}, {11, 4}, {7, 4},  {7, 4},  {7, 4},  {7, 4},
	{15, 2}, {15, 2}, {15, 2}, {15, 2}, {15, 2}, {15, 2}, {15, 2}, {15, 2},
	{15, 2}, {15, 2}, {15, 2}, {15, 2}, {15, 2}, {15, 2}, {15, 2}, {15, 2}
};

VLC const dc_lum_tab[] = {
	{0, 0}, {4, 3}, {3, 3}, {0, 3},
	{2, 2}, {2, 2}, {1, 2}, {1, 2},
};

/*****************************************************************************
 * VLC tables and other constant arrays
 ****************************************************************************/

VLC_TABLE const coeff_tab[2][102] =
{
	/* intra = 0 */
	{
		{{ 2,  2}, {0, 0, 1}},
		{{15,  4}, {0, 0, 2}},
		{{21,  6}, {0, 0, 3}},
		{{23,  7}, {0, 0, 4}},
		{{31,  8}, {0, 0, 5}},
		{{37,  9}, {0, 0, 6}},
		{{36,  9}, {0, 0, 7}},
		{{33, 10}, {0, 0, 8}},
		{{32, 10}, {0, 0, 9}},
		{{ 7, 11}, {0, 0, 10}},
		{{ 6, 11}, {0, 0, 11}},
		{{32, 11}, {0, 0, 12}},
		{{ 6,  3}, {0, 1, 1}},
		{{20,  6}, {0, 1, 2}},
		{{30,  8}, {0, 1, 3}},
		{{15, 10}, {0, 1, 4}},
		{{33, 11}, {0, 1, 5}},
		{{80, 12}, {0, 1, 6}},
		{{14,  4}, {0, 2, 1}},
		{{29,  8}, {0, 2, 2}},
		{{14, 10}, {0, 2, 3}},
		{{81, 12}, {0, 2, 4}},
		{{13,  5}, {0, 3, 1}},
		{{35,  9}, {0, 3, 2}},
		{{13, 10}, {0, 3, 3}},
		{{12,  5}, {0, 4, 1}},
		{{34,  9}, {0, 4, 2}},
		{{82, 12}, {0, 4, 3}},
		{{11,  5}, {0, 5, 1}},
		{{12, 10}, {0, 5, 2}},
		{{83, 12}, {0, 5, 3}},
		{{19,  6}, {0, 6, 1}},
		{{11, 10}, {0, 6, 2}},
		{{84, 12}, {0, 6, 3}},
		{{18,  6}, {0, 7, 1}},
		{{10, 10}, {0, 7, 2}},
		{{17,  6}, {0, 8, 1}},
		{{ 9, 10}, {0, 8, 2}},
		{{16,  6}, {0, 9, 1}},
		{{ 8, 10}, {0, 9, 2}},
		{{22,  7}, {0, 10, 1}},
		{{85, 12}, {0, 10, 2}},
		{{21,  7}, {0, 11, 1}},
		{{20,  7}, {0, 12, 1}},
		{{28,  8}, {0, 13, 1}},
		{{27,  8}, {0, 14, 1}},
		{{33,  9}, {0, 15, 1}},
		{{32,  9}, {0, 16, 1}},
		{{31,  9}, {0, 17, 1}},
		{{30,  9}, {0, 18, 1}},
		{{29,  9}, {0, 19, 1}},
		{{28,  9}, {0, 20, 1}},
		{{27,  9}, {0, 21, 1}},
		{{26,  9}, {0, 22, 1}},
		{{34, 11}, {0, 23, 1}},
		{{35, 11}, {0, 24, 1}},
		{{86, 12}, {0, 25, 1}},
		{{87, 12}, {0, 26, 1}},
		{{ 7,  4}, {1, 0, 1}},
		{{25,  9}, {1, 0, 2}},
		{{ 5, 11}, {1, 0, 3}},
		{{15,  6}, {1, 1, 1}},
		{{ 4, 11}, {1, 1, 2}},
		{{14,  6}, {1, 2, 1}},
		{{13,  6}, {1, 3, 1}},
		{{12,  6}, {1, 4, 1}},
		{{19,  7}, {1, 5, 1}},
		{{18,  7}, {1, 6, 1}},
		{{17,  7}, {1, 7, 1}},
		{{16,  7}, {1, 8, 1}},
		{{26,  8}, {1, 9, 1}},
		{{25,  8}, {1, 10, 1}},
		{{24,  8}, {1, 11, 1}},
		{{23,  8}, {1, 12, 1}},
		{{22,  8}, {1, 13, 1}},
		{{21,  8}, {1, 14, 1}},
		{{20,  8}, {1, 15, 1}},
		{{19,  8}, {1, 16, 1}},
		{{24,  9}, {1, 17, 1}},
		{{23,  9}, {1, 18, 1}},
		{{22,  9}, {1, 19, 1}},
		{{21,  9}, {1, 20, 1}},
		{{20,  9}, {1, 21, 1}},
		{{19,  9}, {1, 22, 1}},
		{{18,  9}, {1, 23, 1}},
		{{17,  9}, {1, 24, 1}},
		{{ 7, 10}, {1, 25, 1}},
		{{ 6, 10}, {1, 26, 1}},
		{{ 5, 10}, {1, 27, 1}},
		{{ 4, 10}, {1, 28, 1}},
		{{36, 11}, {1, 29, 1}},
		{{37, 11}, {1, 30, 1}},
		{{38, 11}, {1, 31, 1}},
		{{39, 11}, {1, 32, 1}},
		{{88, 12}, {1, 33, 1}},
		{{89, 12}, {1, 34, 1}},
		{{90, 12}, {1, 35, 1}},
		{{91, 12}, {1, 36, 1}},
		{{92, 12}, {1, 37, 1}},
		{{93, 12}, {1, 38, 1}},
		{{94, 12}, {1, 39, 1}},
		{{95, 12}, {1, 40, 1}}
	},
	/* intra = 1 */
	{
		{{ 2,  2}, {0, 0, 1}},
		{{15,  4}, {0, 0, 3}},
		{{21,  6}, {0, 0, 6}},
		{{23,  7}, {0, 0, 9}},
		{{31,  8}, {0, 0, 10}},
		{{37,  9}, {0, 0, 13}},
		{{36,  9}, {0, 0, 14}},
		{{33, 10}, {0, 0, 17}},
		{{32, 10}, {0, 0, 18}},
		{{ 7, 11}, {0, 0, 21}},
		{{ 6, 11}, {0, 0, 22}},
		{{32, 11}, {0, 0, 23}},
		{{ 6,  3}, {0, 0, 2}},
		{{20,  6}, {0, 1, 2}},
		{{30,  8}, {0, 0, 11}},
		{{15, 10}, {0, 0, 19}},
		{{33, 11}, {0, 0, 24}},
		{{80, 12}, {0, 0, 25}},
		{{14,  4}, {0, 1, 1}},
		{{29,  8}, {0, 0, 12}},
		{{14, 10}, {0, 0, 20}},
		{{81, 12}, {0, 0, 26}},
		{{13,  5}, {0, 0, 4}},
		{{35,  9}, {0, 0, 15}},
		{{13, 10}, {0, 1, 7}},
		{{12,  5}, {0, 0, 5}},
		{{34,  9}, {0, 4, 2}},
		{{82, 12}, {0, 0, 27}},
		{{11,  5}, {0, 2, 1}},
		{{12, 10}, {0, 2, 4}},
		{{83, 12}, {0, 1, 9}},
		{{19,  6}, {0, 0, 7}},
		{{11, 10}, {0, 3, 4}},
		{{84, 12}, {0, 6, 3}},
		{{18,  6}, {0, 0, 8}},
		{{10, 10}, {0, 4, 3}},
		{{17,  6}, {0, 3, 1}},
		{{ 9, 10}, {0, 8, 2}},
		{{16,  6}, {0, 4, 1}},
		{{ 8, 10}, {0, 5, 3}},
		{{22,  7}, {0, 1, 3}},
		{{85, 12}, {0, 1, 10}},
		{{21,  7}, {0, 2, 2}},
		{{20,  7}, {0, 7, 1}},
		{{28,  8}, {0, 1, 4}},
		{{27,  8}, {0, 3, 2}},
		{{33,  9}, {0, 0, 16}},
		{{32,  9}, {0, 1, 5}},
		{{31,  9}, {0, 1, 6}},
		{{30,  9}, {0, 2, 3}},
		{{29,  9}, {0, 3, 3}},
		{{28,  9}, {0, 5, 2}},
		{{27,  9}, {0, 6, 2}},
		{{26,  9}, {0, 7, 2}},
		{{34, 11}, {0, 1, 8}},
		{{35, 11}, {0, 9, 2}},
		{{86, 12}, {0, 2, 5}},
		{{87, 12}, {0, 7, 3}},
		{{ 7,  4}, {1, 0, 1}},
		{{25,  9}, {0, 11, 1}},
		{{ 5, 11}, {1, 0, 6}},
		{{15,  6}, {1, 1, 1}},
		{{ 4, 11}, {1, 0, 7}},
		{{14,  6}, {1, 2, 1}},
		{{13,  6}, {0, 5, 1}},
		{{12,  6}, {1, 0, 2}},
		{{19,  7}, {1, 5, 1}},
		{{18,  7}, {0, 6, 1}},
		{{17,  7}, {1, 3, 1}},
		{{16,  7}, {1, 4, 1}},
		{{26,  8}, {1, 9, 1}},
		{{25,  8}, {0, 8, 1}},
		{{24,  8}, {0, 9, 1}},
		{{23,  8}, {0, 10, 1}},
		{{22,  8}, {1, 0, 3}},
		{{21,  8}, {1, 6, 1}},
		{{20,  8}, {1, 7, 1}},
		{{19,  8}, {1, 8, 1}},
		{{24,  9}, {0, 12, 1}},
		{{23,  9}, {1, 0, 4}},
		{{22,  9}, {1, 1, 2}},
		{{21,  9}, {1, 10, 1}},
		{{20,  9}, {1, 11, 1}},
		{{19,  9}, {1, 12, 1}},
		{{18,  9}, {1, 13, 1}},
		{{17,  9}, {1, 14, 1}},
		{{ 7, 10}, {0, 13, 1}},
		{{ 6, 10}, {1, 0, 5}},
		{{ 5, 10}, {1, 1, 3}},
		{{ 4, 10}, {1, 2, 2}},
		{{36, 11}, {1, 3, 2}},
		{{37, 11}, {1, 4, 2}},
		{{38, 11}, {1, 15, 1}},
		{{39, 11}, {1, 16, 1}},
		{{88, 12}, {0, 14, 1}},
		{{89, 12}, {1, 0, 8}},
		{{90, 12}, {1, 5, 2}},
		{{91, 12}, {1, 6, 2}},
		{{92, 12}, {1, 17, 1}},
		{{93, 12}, {1, 18, 1}},
		{{94, 12}, {1, 19, 1}},
		{{95, 12}, {1, 20, 1}}
	}
};

/* constants taken from momusys/vm_common/inlcude/max_level.h */
uint8_t const max_level[2][2][64] = {
	{
		/* intra = 0, last = 0 */
		{
			12, 6, 4, 3, 3, 3, 3, 2,
			2, 2, 2, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0
		},
		/* intra = 0, last = 1 */
		{
			3, 2, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1,
			1, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0
		}
	},
	{
		/* intra = 1, last = 0 */
		{
			27, 10, 5, 4, 3, 3, 3, 3,
			2, 2, 1, 1, 1, 1, 1, 0,
			0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0
		},
		/* intra = 1, last = 1 */
		{
			8, 3, 2, 2, 2, 2, 2, 1,
			1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0
		}
	}
};

uint8_t const max_run[2][2][64] = {
	{
		/* intra = 0, last = 0 */
		{
			0, 26, 10, 6, 2, 1, 1, 0,
			0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0,
		},
		/* intra = 0, last = 1 */
		{
			0, 40, 1, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0,
		}
	},
	{
		/* intra = 1, last = 0 */
		{
			0, 14, 9, 7, 3, 2, 1, 1,
			1, 1, 1, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0,
		},
		/* intra = 1, last = 1 */
		{
			0, 20, 6, 1, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0,
		}
	}
};


VLC const TMNMVtab0[] = {
	{3, 4}, {-3, 4}, {2, 3}, {2, 3}, {-2, 3}, {-2, 3}, {1, 2},
	{1, 2}, {1, 2}, {1, 2}, {-1, 2}, {-1, 2}, {-1, 2}, {-1, 2}
};

VLC const TMNMVtab1[] = {
	{12, 10}, {-12, 10}, {11, 10}, {-11, 10},
	{10, 9}, {10, 9}, {-10, 9}, {-10, 9},
	{9, 9}, {9, 9}, {-9, 9}, {-9, 9},
	{8, 9}, {8, 9}, {-8, 9}, {-8, 9},
	{7, 7}, {7, 7}, {7, 7}, {7, 7},
	{7, 7}, {7, 7}, {7, 7}, {7, 7},
	{-7, 7}, {-7, 7}, {-7, 7}, {-7, 7},
	{-7, 7}, {-7, 7}, {-7, 7}, {-7, 7},
	{6, 7}, {6, 7}, {6, 7}, {6, 7},
	{6, 7}, {6, 7}, {6, 7}, {6, 7},
	{-6, 7}, {-6, 7}, {-6, 7}, {-6, 7},
	{-6, 7}, {-6, 7}, {-6, 7}, {-6, 7},
	{5, 7}, {5, 7}, {5, 7}, {5, 7},
	{5, 7}, {5, 7}, {5, 7}, {5, 7},
	{-5, 7}, {-5, 7}, {-5, 7}, {-5, 7},
	{-5, 7}, {-5, 7}, {-5, 7}, {-5, 7},
	{4, 6}, {4, 6}, {4, 6}, {4, 6},
	{4, 6}, {4, 6}, {4, 6}, {4, 6},
	{4, 6}, {4, 6}, {4, 6}, {4, 6},
	{4, 6}, {4, 6}, {4, 6}, {4, 6},
	{-4, 6}, {-4, 6}, {-4, 6}, {-4, 6},
	{-4, 6}, {-4, 6}, {-4, 6}, {-4, 6},
	{-4, 6}, {-4, 6}, {-4, 6}, {-4, 6},
	{-4, 6}, {-4, 6}, {-4, 6}, {-4, 6}
};

VLC const TMNMVtab2[] = {
	{32, 12}, {-32, 12}, {31, 12}, {-31, 12},
	{30, 11}, {30, 11}, {-30, 11}, {-30, 11},
	{29, 11}, {29, 11}, {-29, 11}, {-29, 11},
	{28, 11}, {28, 11}, {-28, 11}, {-28, 11},
	{27, 11}, {27, 11}, {-27, 11}, {-27, 11},
	{26, 11}, {26, 11}, {-26, 11}, {-26, 11},
	{25, 11}, {25, 11}, {-25, 11}, {-25, 11},
	{24, 10}, {24, 10}, {24, 10}, {24, 10},
	{-24, 10}, {-24, 10}, {-24, 10}, {-24, 10},
	{23, 10}, {23, 10}, {23, 10}, {23, 10},
	{-23, 10}, {-23, 10}, {-23, 10}, {-23, 10},
	{22, 10}, {22, 10}, {22, 10}, {22, 10},
	{-22, 10}, {-22, 10}, {-22, 10}, {-22, 10},
	{21, 10}, {21, 10}, {21, 10}, {21, 10},
	{-21, 10}, {-21, 10}, {-21, 10}, {-21, 10},
	{20, 10}, {20, 10}, {20, 10}, {20, 10},
	{-20, 10}, {-20, 10}, {-20, 10}, {-20, 10},
	{19, 10}, {19, 10}, {19, 10}, {19, 10},
	{-19, 10}, {-19, 10}, {-19, 10}, {-19, 10},
	{18, 10}, {18, 10}, {18, 10}, {18, 10},
	{-18, 10}, {-18, 10}, {-18, 10}, {-18, 10},
	{17, 10}, {17, 10}, {17, 10}, {17, 10},
	{-17, 10}, {-17, 10}, {-17, 10}, {-17, 10},
	{16, 10}, {16, 10}, {16, 10}, {16, 10},
	{-16, 10}, {-16, 10}, {-16, 10}, {-16, 10},
	{15, 10}, {15, 10}, {15, 10}, {15, 10},
	{-15, 10}, {-15, 10}, {-15, 10}, {-15, 10},
	{14, 10}, {14, 10}, {14, 10}, {14, 10},
	{-14, 10}, {-14, 10}, {-14, 10}, {-14, 10},
	{13, 10}, {13, 10}, {13, 10}, {13, 10},
	{-13, 10}, {-13, 10}, {-13, 10}, {-13, 10}
};
#endif