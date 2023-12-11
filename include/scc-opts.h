/*    
	Small C Compiler
    Copyright (C) 2023 jmbert

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef _SCC_OPTS_H
#define _SCC_OPTS_H

#include <scc-stds.h>
#include <scc-types.h>

enum _opt_ids
{
	OPT_NOOPT,
	OPT_STD,
	OPT_HELP,
	OPT_PREPROC,
	OPT_ASSEMBLER,
	OPT_LINKER,
};

typedef struct 
{
	flags_t std;
	char *output;

	char **c_files;
	unsigned int n_c_files;

	char *cpp;
	char *as;
	char *ld;
	
	flags_t stage;
}options_t;

int parse_options(int argc, char *argv[], options_t *optbuffer);

#endif