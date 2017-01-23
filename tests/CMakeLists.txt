
include_directories("${PROJECT_SOURCE_DIR}/src")
add_executable(test_hsluv test_hsluv.c snapshot.h ../src/hsluv.h ../src/hsluv.c)
