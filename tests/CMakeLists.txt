cmake_minimum_required(VERSION 3.30)

message("[NOTE]: For PlotGenCpp - if SFML is missing, install using [sudo apt install libsfml-dev]")
CPMAddPackage(
    NAME plotter
    GIT_REPOSITORY "https://github.com/skhelladi/PlotGenCpp.git"
    GIT_TAG main
)

# add_executable(integration_tests integration_tests.cpp)

# target_link_libraries(integration_tests PRIVATE
#     Catch2::Catch2WithMain
#     ds_modems
# )

add_executable(lib_tests lib_tests.cpp)

target_link_libraries(lib_tests PRIVATE
    Catch2::Catch2WithMain
    ds_modems
    PlotGenCpp
)

target_include_directories(lib_tests PRIVATE
    ../src
)

add_test(NAME test_lib COMMAND lib_tests)

