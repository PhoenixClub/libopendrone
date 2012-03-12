# CMakeLists for libdrone

set(OPENDRONE_VERSION_MAJOR 0)
set(OPENDRONE_VERSION_MINOR 1)

set(OPENDRONE_HEADERS ATCommand.h ATCommandFactory.h ATSequencer.h)
set(OPENDRONE_SOURCES ATCommand.cpp ATCommandFactory.cpp ATSequencer.cpp)
source_group(opendrone FILES    ${OPENDRONE_HEADERS} ${OPENDRONE_SOURCES})

set(ODTEST_HEADERS )
set(ODTEST_SOURCES odtest.cpp)

include_directories("${PROJECT_SOURCE_DIR}")

add_library(opendrone    ${OPENDRONE_SOURCES} ${OPENDRONE_HEADERS})

target_link_libraries(opendrone)

add_executable(odtest   ${ODTEST_SOURCES} ${ODTEST_HEADERS})

target_link_libraries(odtest opendrone)
