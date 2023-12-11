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
#include <scc-err.h>
#include <getopt.h>
#include <stddef.h>
#include <string.h>
#include <scc-run.h>

const char *shortoptlist = "hcEo:";

int long_opt = 0;

unsigned char already_set_stage = 0;

static void print_usage(char *called_name)
{
	printf("Usage %s [options] cfiles...\n", called_name);
	printf("Options:\n");
	printf("\t-h/--help: Print this help screen\n");
	printf("\t--std STANDARD: Select C Standard\n");
	printf("\t-o/--out OUTPUT: Choose output file\n");
	printf("\t-c: Do not link, only compile\n");
	printf("\t-S: Do not assemble, only compile\n");
	printf("\t-E: Only preprocess the file\n");
	printf("\t--cpp PREPROCESSOR: Use specified preprocessor\n");
	printf("\t--as ASSEMBER: Use specified preprocessor\n");
	printf("\t--ld LINKER: Use specified preprocessor\n");

	exit(EXIT_SUCCESS);
}

int parse_options(int argc, char *argv[], options_t *optbuffer)
{
	

	struct option longoptlist[] = {
		(struct option){
			.name = "std",
			.has_arg = required_argument,
			.flag = &long_opt,
			.val = OPT_STD,
		},
		(struct option){
			.name = "help",
			.has_arg = no_argument,
			.flag = &long_opt,
			.val = OPT_HELP,
		},
		(struct option){
			.name = "cpp",
			.has_arg = required_argument,
			.flag = &long_opt,
			.val = OPT_PREPROC,
		},
		(struct option){
			.name = "as",
			.has_arg = required_argument,
			.flag = &long_opt,
			.val = OPT_ASSEMBLER,
		},
		(struct option){
			.name = "ld",
			.has_arg = required_argument,
			.flag = &long_opt,
			.val = OPT_LINKER,
		},
	};

	int opt = 2;
	while ((opt = getopt_long(argc, argv, shortoptlist, longoptlist, NULL)) != -1)
	{
		if (opt)
		{
			switch (opt)
			{

			case 'h':
				print_usage(argv[0]);
				break;
			case 'c':
				if (already_set_stage)
				{
					LOG_ERR("Cannot combine stage arguments");
					return -1;
				}
				optbuffer->stage = SCC_STAGE_COMPILE;
				already_set_stage = 1;
				break;
			case 'S':
				if (already_set_stage)
				{
					LOG_ERR("Cannot combine stage arguments");
					return -1;
				}
				optbuffer->stage = SCC_STAGE_ASSEMBLE;
				already_set_stage = 1;
				break;
			case 'E':
				if (already_set_stage)
				{
					LOG_ERR("Cannot combine stage arguments");
					return -1;
				}
				optbuffer->stage = SCC_STAGE_PREPROCESS;
				already_set_stage = 1;
				break;

			case 'o':
				optbuffer->output = optarg;
				break;

			case ':':
				LOG_ERR("Missing argument", optopt);
				return -1;
			case '?':
			default:
				LOG_ERR("Unknown option: %c", optopt);
				return -1;
				break;
			}
		} else 
		{
			switch (long_opt)
			{
			case OPT_HELP:
				print_usage(argv[0]);
				break;
			case OPT_STD:
				if (!strcmp(optarg, "c89"))
				{
					optbuffer->std = SCC_STD_C89;
				} else
				{
					LOG_ERR("Unknown standard \"%s\"", optarg);
					return -1;
				}
				break;
			case OPT_PREPROC:
				optbuffer->cpp = optarg;
				break;
			case OPT_ASSEMBLER:
				optbuffer->as = optarg;
				break;
			case OPT_LINKER:
				optbuffer->ld = optarg;
				break;
			default:
				LOG_ERR("Unknown option: %c", optopt);
				return -1;
				break;
			}
		}
	}

	optbuffer->c_files = argv+optind;
	optbuffer->n_c_files = argc-optind;

	if (optbuffer->n_c_files == 0)
	{
		LOG_ERR("Must provide C Input files");
		return -1;
	}

	return 0;
}