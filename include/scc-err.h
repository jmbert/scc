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

#ifndef _SCC_ERR_H
#define _SCC_ERR_H

#include <stdio.h>
#include <stdlib.h>

enum scc_errors
{
	E_UNKNOWN_FATAL = 1,
};

#define LOG_ERR(_err, _args...) fprintf(stderr, _err "\n" __VA_OPT__(,) _args)

#endif