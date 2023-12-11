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

#ifndef _SCC_RUN_H
#define _SCC_RUN_H

#include <scc-types.h>


enum _stage
{
	SCC_STAGE_SETUP,
	SCC_STAGE_PREPROCESS,
	SCC_STAGE_PARSE,
	SCC_STAGE_COMPILE,
	SCC_STAGE_CODEGEN,
	SCC_STAGE_ASSEMBLE,
	SCC_STAGE_LINK,
};

extern flags_t current_stage;

#endif