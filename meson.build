project('scc', 'c')

add_global_arguments('--std=gnu2x', language : 'c')

executable('scc', 
	'entry.c',
	'options/parse_options.c',
	dependencies: dependency('threads'),
	include_directories: include_directories('include'))