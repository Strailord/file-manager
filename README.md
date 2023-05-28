# file-manager
A small file-manager to clean messy directories

## Requirements
- CMake 3.16 or newer
- Make 1.10.2 or newer
- C++ 20 or newer

## How to build on Windows
1. Clone the repository
2. Go to the project-directory and execute build.bat
3. You'll find the build project in the build directory

## How to build on Linux
1. Clone the repository
2. Go to the project-directory and execute build.sh
3. You'll find the build project in the build directory

## Syntax

file-manager \<option\>

## Commandline options:

No Arguments:\
Current directory will be cleaned with the configuration of used file_manager_config.conf. If no configuration exists nothing will happen.

Options:\
-h : Print the help menu\
-c : Enter the commandline configuration

## Commandline configuration

- ADD <EXT> TO <DIR_NAME> : Add configuration for <EXT>
- REMOVE <EXT> : Remove <EXT> from configuration
- SHOW : List current configuration
- LOAD <CONFIG_PATH> : Load file_manager_config.conf from <CONFIG_PATH>. If no path is given, the current working directory will be used.
- SAVE <CONFIG_PATH> : Save file_manager_config.conf to <CONFIG_PATH>. If no path is given, the current working directory will be used.
- CLEAR : Clear the commandline configuration terminal
- CLEAN : Clean the current working directory with the current configuration
- QUIT : Quit the configuration terminal. Current configuration will be saved to file_manager_config.conf in current working directory

### Examples

- ADD pdf TO pdf_directory
- REMOVE pdf
- LOAD path_of_config
- SAVe path_of_config

## Tips

Add the directory of the binary to your PATH variable to use it as console-command.