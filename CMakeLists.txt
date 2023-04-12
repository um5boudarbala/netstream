check_include_file_cxx(stdint.h HAVE_STDINT_H)
if(HAVE_STDINT_H)
    add_definitions(-DHAVE_STDINT_H)
endif()

set(examples_as_tests_sources)
if(${ENABLE_EXAMPLES})
    set(examples_as_tests_sources
        #test/netstream-examples-test-suite.cc
        )
endif()

build_lib(
    LIBNAME netstream
    SOURCE_FILES model/netstream.cc
                 helper/netstream-helper.cc
                 model/netstream-storage.cpp
                 model/netstream-socket.cpp
                 model/netstream-sender.cpp
    HEADER_FILES model/netstream.h
                 helper/netstream-helper.h
                 model/netstream-constants.h
                 model/netstream-storage.h
                 model/netstream-socket.h
                 model/netstream-sender.h
    LIBRARIES_TO_LINK ${libcore}
    TEST_SOURCES test/netstream-test-suite.cc
                 ${examples_as_tests_sources}
)

