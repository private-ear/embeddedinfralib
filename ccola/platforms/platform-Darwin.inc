set(CCOLA_ARCH_FAMILY unix)
set(CCOLA_ARCH bsd)
set(CCOLA_CORE none)
set(CCOLA_PROCESSOR_FAMILY x86)
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(CCOLA_PROCESSOR x86_64)
else() 
    set(CCOLA_PROCESSOR x86_32)
endif()

# Suppress warnings about *.a files having no symbols on MacOSX.
# The warning is emitted when *.cpp.o contains no operational code.
set(CMAKE_C_ARCHIVE_CREATE   "<CMAKE_AR> Scr <TARGET> <LINK_FLAGS> <OBJECTS>")
set(CMAKE_CXX_ARCHIVE_CREATE "<CMAKE_AR> Scr <TARGET> <LINK_FLAGS> <OBJECTS>")
set(CMAKE_C_ARCHIVE_FINISH   "<CMAKE_RANLIB> -no_warning_for_no_symbols -c <TARGET>")
set(CMAKE_CXX_ARCHIVE_FINISH "<CMAKE_RANLIB> -no_warning_for_no_symbols -c <TARGET>")

# Use the install RPATH when building, preventing a re-link come install time.
# This enables the protobuf generator to find libprotobuf during the build.
set(CMAKE_BUILD_WITH_INSTALL_RPATH ON)
