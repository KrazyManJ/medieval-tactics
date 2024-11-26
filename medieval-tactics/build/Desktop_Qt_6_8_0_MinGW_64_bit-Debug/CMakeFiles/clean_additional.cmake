# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\appmedieval-tactics_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\appmedieval-tactics_autogen.dir\\ParseCache.txt"
  "appmedieval-tactics_autogen"
  )
endif()
