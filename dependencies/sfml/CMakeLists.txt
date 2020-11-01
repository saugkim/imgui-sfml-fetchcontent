FetchContent_GetProperties(SFML)

if(NOT SFML_POPULATED)
  if (LINK_DEPS_STATIC)
    set(SFML_STATIC_LIBRARIES TRUE CACHE BOOL "sfml static library on")
  endif()

  set(SFML_INSTALL_PKGCONFIG_FILES OFF CACHE BOOL "sfml install pkgconfig off")

  if (USE_SYSTEM_DEPS)
    find_package(SFML ${SFML_VERSION} COMPONENTS graphics QUIET)
  else()
    FetchContent_Populate(SFML)

    # No need to build audio and network modules
    set(SFML_BUILD_AUDIO FALSE CACHE BOOL "audio off")
    set(SFML_BUILD_NETWORK FALSE CACHE BOOL "network off")
    add_subdirectory(${sfml_SOURCE_DIR} ${sfml_BINARY_DIR} EXCLUDE_FROM_ALL)
  endif()
endif()
