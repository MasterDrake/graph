#vcpkg_check_linkage(ONLY_STATIC_LIBRARY)

vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO MasterDrake/NetworkNext
    REF abc445440b74427a69efe2a3b77383d8f378540b
    SHA512 be1f7d64ac682cdb5444834e4f6c7c3ece26d2ae8bc4fa7bdeb17e5178c73145d66f36e9312d71271465f784c24980d3d6d5d87a377369010bf5fedd341c91d2
    HEAD_REF main
)

vcpkg_cmake_configure(
    SOURCE_PATH "${SOURCE_PATH}"
    OPTIONS
    -DBUILD_EXAMPLES=OFF
    -DBUILD_TEST=OFF
    -DBUILD_SOAK=OFF
    -DBUILD_FUZZ=OFF
)

vcpkg_cmake_install()
vcpkg_cmake_config_fixup(CONFIG_PATH lib/cmake/network-next)
vcpkg_fixup_pkgconfig()

file(REMOVE_RECURSE "${CURRENT_PACKAGES_DIR}/debug/include")

vcpkg_install_copyright(FILE_LIST "${SOURCE_PATH}/LICENCE")
file(INSTALL "${CMAKE_CURRENT_LIST_DIR}/usage" DESTINATION "${CURRENT_PACKAGES_DIR}/share/${PORT}")