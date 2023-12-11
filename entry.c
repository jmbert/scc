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

#include <scc-opts.h>
#include <stdlib.h>
#include <stdio.h>
#include <scc-run.h>

flags_t current_stage = SCC_STAGE_SETUP;

int main(int argc, char *argv[])
{
	options_t options = {};
	int ret = parse_options(argc, argv, &options);
	if (ret)
	{
		exit(ret);
	}
}