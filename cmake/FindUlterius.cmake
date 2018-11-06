find_path(Ulterius_INCLUDE_DIR
    NAMES ulterius.h
    PATHS "C:/Program Files (x86)/sdk610/ulterius/inc"
)
find_library(Ulterius_LIBRARY
    NAMES ulterius_old
    PATHS "C:/Program Files (x86)/sdk610/ulterius/lib"
)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Ulterius
    DEFAULT_MSG
    Ulterius_INCLUDE_DIR Ulterius_LIBRARY
)
