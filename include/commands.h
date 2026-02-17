#ifndef COMMANDS_H
#define COMMANDS_H

// Parse command-line arguments
// argc, argv: standard main arguments
// src_file: output parameter for source file path
// exe_file: output parameter for output executable
// Returns 1 if compilation should proceed, 0 if program should exit (e.g., --version)
int parse_commands(int argc, char **argv, char **src_file, char **exe_file);

#endif
