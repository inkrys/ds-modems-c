add_library(ds_modems STATIC
    lib.c
)

target_link_libraries(ds_modems PRIVATE
    dbg_helperz
)

CPMAddPackage(
    NAME dbg_helperz
    GIT_REPOSITORY "git@github.com:inkrys/dbg_helperz.git"
    GIT_TAG main
    # DOWNLOAD_ONLY YES
)

target_include_directories(ds_modems
    PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
    PUBLIC
    ../inc
)