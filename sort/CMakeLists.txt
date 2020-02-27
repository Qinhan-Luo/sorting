set(sort_SRCS
  sort.cc
  util.cc
  main.cc
  )

set(EXECUTABLE_OUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(sort_test ${sort_SRCS})
