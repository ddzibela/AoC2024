cmake_minimum_required(VERSION 3.29)

project(aoc2024)

set(CMAKE_CXX_STANDARD 23)

file(GLOB DAY_DIRS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}/src "src/day*")


foreach(day_dir ${DAY_DIRS})
    string(REGEX MATCH "day[0-9]+" target_name ${day_dir})

    if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/src/${day_dir})
        add_executable(${target_name}
            src/${day_dir}/main.cpp
            src/${day_dir}/solution.cpp
        )

        target_sources(${target_name}
                PUBLIC FILE_SET modules TYPE CXX_MODULES FILES ${CMAKE_SOURCE_DIR}/src/utils/utils.ixx)
    endif()
endforeach()