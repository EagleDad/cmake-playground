project(Doxygen)

set(DOC_NAME "doxygen")

# TODO: The base path to the external tool should be configured from outside
# E.G. a batch file checking if the files are in the user folder and donwload them eventually.

# find_program(DOXYGEN_EXECUTABLE
	# NAMES doxygen doxygen.exe
	# PATHS "C:/Users/dirk.adler/.externalTools/Doxygen/doxygen-1.9.3.windows.x64"
	# DOC "Path to Doxygen"
# )

# find_program(DOXYGEN_DOT_EXECUTABLE
	# NAMES dot dot.exe
	# PATHS "C:/Users/dirk.adler/.externalTools/Graphviz/graphviz-3.0.0-win32/bin"
	# DOC "Path to Graphviz"
# )

# find_package(Doxygen)

# if (DOXYGEN_FOUND)
	# message(STATUS "Doxygen found.")
	
	# set(DOXYGEN_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/")
	# set(DOXYGEN_GENERATE_HTML YES)
	# set(DOXYGEN_GENERATE_MAN NO)
	# set(DOXYGEN_EXCLUDE_PATTERNS "*/test/* */.txt/*")
	# set(DOXYGEN_PROJECT_NAME "Image Processing Core")
	
	# get_filename_component(PARENT_DIR ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)
	# set(SOURCE_DIR "${PARENT_DIR}/libraries")
	# file(TO_NATIVE_PATH ${SOURCE_DIR} SOURCE_DIR)
	
	# doxygen_add_docs(
		# ${DOC_NAME}
		# ${SOURCE_DIR}
		# COMMENT "Generate man pages"
	# )
	
# else(DOXYGEN_FOUND)
	# message(WARNING "No doxygen found. Documentation will be skipped ...")
# endif(DOXYGEN_FOUND)