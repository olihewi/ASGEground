#------------------------------------------------------------------------------
# Enables support for ccache to improve build times.
# v1.0.0
#------------------------------------------------------------------------------
find_program(CCACHE_PROGRAM ccache)
if(CCACHE_PROGRAM)
    set(CMAKE_CXX_COMPILER_LAUNCHER "${CCACHE_PROGRAM}")
endif()