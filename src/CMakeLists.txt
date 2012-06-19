add_subdirectory(core)

set(HEADERS
	${HEADERS}
	PARENT_SCOPE)

set(SOURCE
	${SOURCE}
	${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
	PARENT_SCOPE)