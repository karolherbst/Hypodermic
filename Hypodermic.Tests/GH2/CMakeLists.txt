include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
)

set(HypodermicTests_GH2_lib_sources
	lib.cpp
)
set(HypodermicTests_GH2_sources
	exe.cpp
)

add_library(Hypodermic.GH2.lib SHARED ${HypodermicTests_GH2_lib_sources})
target_link_libraries(Hypodermic.GH2.lib
    Hypodermic
    ${Boost_SYSTEM_LIBRARIES}
)

add_executable(Hypodermic.GH2.Tests ${HypodermicTests_GH2_sources})
target_link_libraries(Hypodermic.GH2.Tests
    Hypodermic.GH2.lib
    Hypodermic
    ${Boost_LIBRARIES}
)

add_test(cmake_Hypodermic.GH2.Tests 
    ${CMAKE_CURRENT_BINARY_DIR}/Hypodermic.GH2.Tests --result_code=no --report_level=no
)
