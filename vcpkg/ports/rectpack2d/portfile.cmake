#vcpkg_check_linkage(ONLY_STATIC_LIBRARY)

vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO MasterDrake/rectpack2D
    REF f74989a56269af60159e6e0dd46d1e257d3833e3
    SHA512 817c615b4efd60da528ecd76b89f9486f3bcc607d6e1e18185b87aa38dc14cc8a6b2df284f1f71cf981d19d91a4285a35a2dad05c831c4693355ebad9e115899
    HEAD_REF main
)

vcpkg_cmake_configure(
    SOURCE_PATH "${SOURCE_PATH}"
    OPTIONS
    -DBUILD_EXAMPLES=OFF
)

vcpkg_cmake_install()
vcpkg_cmake_config_fixup(CONFIG_PATH lib/cmake/rectpack2D)
vcpkg_fixup_pkgconfig()

file(REMOVE_RECURSE "${CURRENT_PACKAGES_DIR}/debug/include")

vcpkg_install_copyright(FILE_LIST "${SOURCE_PATH}/LICENCE")
file(INSTALL "${CMAKE_CURRENT_LIST_DIR}/usage" DESTINATION "${CURRENT_PACKAGES_DIR}/share/rectpack2D")