cmake_minimum_required (VERSION 3.1)
project (AG)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(SOURCE_FILES
	src/main.c
	src/chromossome.c
	src/animal.c
	src/tournament.c
	src/util.c
	src/environment.c
	src/config.c
	src/population.c
	)

add_executable (AG ${SOURCE_FILES})
