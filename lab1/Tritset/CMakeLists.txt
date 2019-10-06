project(Tritset)

set(HEADER_FILES
        Tritset.h
        BitManipulationForTrit.h
        )

set(SOURCE_FILES
        Tritset.cpp
        BitManipulationForTrit.cpp
        )

add_library(Tritset STATIC ${SOURCE_FILES} ${HEADER_FILES})