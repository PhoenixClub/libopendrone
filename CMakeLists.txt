# CMakeLists for libdrone
cmake_minimum_required(VERSION 2.8)

# prefix each element of list by ${prefix}element
macro(addprefix list_name prefix)
    # create empty list - necessary?
    set(${list_name}_TMP)

    # prefix and suffix elements
    foreach(l IN LISTS ${list_name})
        list(APPEND ${list_name}_TMP ${prefix}${l})
    endforeach()

    # replace list by tmp list
    set(${list_name} "${${list_name}_TMP}")
    unset("${list_name}_TMP")
endmacro(addprefix)

set(OPENDRONE_VERSION_MAJOR 0)
set(OPENDRONE_VERSION_MINOR 1)

set(OPENDRONE_HEADERS ATCommand.h ATCommandFactory.h ATSequencer.h)
set(OPENDRONE_SOURCES ATCommand.cpp ATCommandFactory.cpp ATSequencer.cpp)

addprefix(OPENDRONE_HEADERS libopendrone/)
addprefix(OPENDRONE_SOURCES libopendrone/)

source_group(opendrone FILES ${OPENDRONE_HEADERS} ${OPENDRONE_SOURCES})

set(ODTEST_HEADERS )
set(ODTEST_SOURCES odtest.cpp)

include_directories("${PROJECT_SOURCE_DIR}")

add_library(opendrone ${OPENDRONE_SOURCES} ${OPENDRONE_HEADERS})

target_link_libraries(opendrone)

add_executable(odtest ${ODTEST_SOURCES} ${ODTEST_HEADERS})

target_link_libraries(odtest opendrone)
