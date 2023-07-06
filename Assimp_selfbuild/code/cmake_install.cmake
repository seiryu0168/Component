# Install script for directory: D:/seiryu/program/CMake/assimp-master/code

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "D:/seiryu/program/ComponentTest/Assimp_selfbuild")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "libassimp5.2.5-dev" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/seiryu/program/ComponentTest/Assimp_selfbuild/lib/Debug/assimp-vc143-mtd.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/seiryu/program/ComponentTest/Assimp_selfbuild/lib/Release/assimp-vc143-mt.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/seiryu/program/ComponentTest/Assimp_selfbuild/lib/MinSizeRel/assimp-vc143-mt.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/seiryu/program/ComponentTest/Assimp_selfbuild/lib/RelWithDebInfo/assimp-vc143-mt.lib")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "libassimp5.2.5" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/seiryu/program/ComponentTest/Assimp_selfbuild/bin/Debug/assimp-vc143-mtd.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/seiryu/program/ComponentTest/Assimp_selfbuild/bin/Release/assimp-vc143-mt.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/seiryu/program/ComponentTest/Assimp_selfbuild/bin/MinSizeRel/assimp-vc143-mt.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/seiryu/program/ComponentTest/Assimp_selfbuild/bin/RelWithDebInfo/assimp-vc143-mt.dll")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "assimp-dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp" TYPE FILE FILES
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/anim.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/aabb.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/ai_assert.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/camera.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/color4.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/color4.inl"
    "D:/seiryu/program/ComponentTest/Assimp_selfbuild/code/../include/assimp/config.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/ColladaMetaData.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/commonMetaData.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/defs.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/cfileio.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/light.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/material.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/material.inl"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/matrix3x3.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/matrix3x3.inl"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/matrix4x4.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/matrix4x4.inl"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/mesh.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/ObjMaterial.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/pbrmaterial.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/GltfMaterial.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/postprocess.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/quaternion.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/quaternion.inl"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/scene.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/metadata.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/texture.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/types.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/vector2.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/vector2.inl"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/vector3.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/vector3.inl"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/version.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/cimport.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/AssertHandler.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/importerdesc.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/Importer.hpp"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/DefaultLogger.hpp"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/ProgressHandler.hpp"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/IOStream.hpp"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/IOSystem.hpp"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/Logger.hpp"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/LogStream.hpp"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/NullLogger.hpp"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/cexport.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/Exporter.hpp"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/DefaultIOStream.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/DefaultIOSystem.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/ZipArchiveIOSystem.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/SceneCombiner.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/fast_atof.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/qnan.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/BaseImporter.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/Hash.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/MemoryIOWrapper.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/ParsingUtils.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/StreamReader.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/StreamWriter.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/StringComparison.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/StringUtils.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/SGSpatialSort.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/GenericProperty.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/SpatialSort.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/SkeletonMeshBuilder.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/SmallVector.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/SmoothingGroups.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/SmoothingGroups.inl"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/StandardShapes.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/RemoveComments.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/Subdivision.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/Vertex.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/LineSplitter.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/TinyFormatter.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/Profiler.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/LogAux.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/Bitmap.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/XMLTools.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/IOStreamBuffer.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/CreateAnimMesh.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/XmlParser.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/BlobIOSystem.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/MathFunctions.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/Exceptional.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/ByteSwapper.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/Base64.hpp"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "assimp-dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp/Compiler" TYPE FILE FILES
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/Compiler/pushpack1.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/Compiler/poppack1.h"
    "D:/seiryu/program/CMake/assimp-master/code/../include/assimp/Compiler/pstdint.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE FILES "D:/seiryu/program/ComponentTest/Assimp_selfbuild/code/Debug/assimp-vc143-mtd.pdb")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE FILES "D:/seiryu/program/ComponentTest/Assimp_selfbuild/code/RelWithDebInfo/assimp-vc143-mt.pdb")
  endif()
endif()

