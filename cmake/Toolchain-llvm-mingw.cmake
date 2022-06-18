
# https://github.com/llvm-mirror/llvm/blob/master/cmake/platforms/WinMsvc.cmake

# When configuring CMake with a toolchain file against a top-level CMakeLists.txt,
# it will actually run CMake many times, once for each small test program used to
# determine what features a compiler supports.  Unfortunately, none of these
# invocations share a CMakeCache.txt with the top-level invocation, meaning they
# won't see the value of any arguments the user passed via -D.  Since these are
# necessary to properly configure MSVC in both the top-level configuration as well as
# all feature-test invocations, we set environment variables with the values so that
# these environments get inherited by child invocations. We can switch to
# CMAKE_TRY_COMPILE_PLATFORM_VARIABLES once our minimum supported CMake version
# is 3.6 or greater.
function(init_user_prop prop)
  if(${prop})
    set(ENV{_${prop}} "${${prop}}")
  else()
    set(${prop} "$ENV{_${prop}}" PARENT_SCOPE)
  endif()
endfunction()

set(CMAKE_C_COMPILER   ${LLVM_PREFIX}/bin/clang-cl.exe)
set(CMAKE_CXX_COMPILER ${LLVM_PREFIX}/bin/clang-cl.exe)
SET(CMAKE_LINKER       ${LLVM_PREFIX}/bin/lld-link.exe)
SET(CMAKE_RC_COMPILER  ${LLVM_PREFIX}/bin/llvm-rc.exe)

set(CMAKE_SYSTEM_NAME Windows)
set(CMAKE_SYSTEM_VERSION 10.0)
set(CMAKE_SYSTEM_PROCESSOR AMD64)

init_user_prop(LLVM_NATIVE_TOOLCHAIN)
init_user_prop(MSVC_BASE)
init_user_prop(WINSDK_BASE)

set(MSVC_INCLUDE   "${MSVC_BASE}/include")
set(WINSDK_INCLUDE "${WINSDK_BASE}/Include/10.0.19041.0")
set(ATLMFC_INCLUDE "${MSVC_BASE}/atlmfc/include")
set(MSVC_LIB       "${MSVC_BASE}/lib")
set(WINSDK_LIB     "${WINSDK_BASE}/Lib/10.0.19041.0")
set(ATLMFC_LIB     "${MSVC_BASE}/atlmfc/lib")

# https://en.wikipedia.org/wiki/Microsoft_Visual_C%2B%2B#Internal_version_numbering
# https://clang.llvm.org/docs/UsersManual.html#microsoft-extensions
set(COMPILE_FLAGS                    #   |
    -D_CRT_SECURE_NO_WARNINGS        #   |
    --target=x86_64-windows-msvc     #   |
    -fms-compatibility-version=19.29 # <-/
    -imsvc "${MSVC_INCLUDE}"
    -imsvc "${ATLMFC_INCLUDE}"
    -imsvc "${WINSDK_INCLUDE}/ucrt"
    -imsvc "${WINSDK_INCLUDE}/shared"
    -imsvc "${WINSDK_INCLUDE}/um"
    -imsvc "${WINSDK_INCLUDE}/winrt"
)

string(REPLACE ";" " " COMPILE_FLAGS "${COMPILE_FLAGS}")

# We need to preserve any flags that were passed in by the user. However, we
# can't append to CMAKE_C_FLAGS and friends directly, because toolchain files
# will be re-invoked on each reconfigure and therefore need to be idempotent.
# The assignments to the _INITIAL cache variables don't use FORCE, so they'll
# only be populated on the initial configure, and their values won't change
# afterward.
set(_CMAKE_C_FLAGS_INITIAL "${CMAKE_C_FLAGS}" CACHE STRING "")
set(CMAKE_C_FLAGS "${_CMAKE_C_FLAGS_INITIAL} ${COMPILE_FLAGS}" CACHE STRING "" FORCE)

set(_CMAKE_CXX_FLAGS_INITIAL "${CMAKE_CXX_FLAGS}" CACHE STRING "")
set(CMAKE_CXX_FLAGS "${_CMAKE_CXX_FLAGS_INITIAL} ${COMPILE_FLAGS}" CACHE STRING "" FORCE)

set(LINK_FLAGS
    # Prevent CMake from attempting to invoke mt.exe. It only recognizes the slashed form and not the dashed form.
    /manifest:no

    -libpath:"${MSVC_LIB}/x64"
    -libpath:"${WINSDK_LIB}/ucrt/x64"
    -libpath:"${WINSDK_LIB}/um/x64"
    -libpath:"${ATLMFC_LIB}/x64"
)

string(REPLACE ";" " " LINK_FLAGS "${LINK_FLAGS}")

# See explanation for compiler flags above for the _INITIAL variables.
set(_CMAKE_EXE_LINKER_FLAGS_INITIAL "${CMAKE_EXE_LINKER_FLAGS}" CACHE STRING "")
set(CMAKE_EXE_LINKER_FLAGS "${_CMAKE_EXE_LINKER_FLAGS_INITIAL} ${LINK_FLAGS}" CACHE STRING "" FORCE)

set(_CMAKE_MODULE_LINKER_FLAGS_INITIAL "${CMAKE_MODULE_LINKER_FLAGS}" CACHE STRING "")
set(CMAKE_MODULE_LINKER_FLAGS "${_CMAKE_MODULE_LINKER_FLAGS_INITIAL} ${LINK_FLAGS}" CACHE STRING "" FORCE)

set(_CMAKE_SHARED_LINKER_FLAGS_INITIAL "${CMAKE_SHARED_LINKER_FLAGS}" CACHE STRING "")
set(CMAKE_SHARED_LINKER_FLAGS "${_CMAKE_SHARED_LINKER_FLAGS_INITIAL} ${LINK_FLAGS}" CACHE STRING "" FORCE)

# CMake populates these with a bunch of unnecessary libraries, which requires
# extra case-correcting symlinks and what not. Instead, let projects explicitly
# control which libraries they require.
set(CMAKE_C_STANDARD_LIBRARIES "" CACHE STRING "" FORCE)
set(CMAKE_CXX_STANDARD_LIBRARIES "" CACHE STRING "" FORCE)