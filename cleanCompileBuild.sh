#!/bin/bash

set -e  # Exit on error

# Set default build type
BUILD_TYPE="Debug"

# Check input
if [ "$#" -eq 1 ]; then
    BUILD_TYPE="$1"
elif [ "$#" -gt 1 ]; then
    echo "Usage: $0 [Debug|Release]"
    exit 1
fi

# Validate input
if [[ "$BUILD_TYPE" != "Debug" && "$BUILD_TYPE" != "Release" ]]; then
    echo "Invalid build type: $BUILD_TYPE"
    echo "Please use 'Debug' or 'Release'"
    exit 1
fi

# Create build directory
mkdir -p build
cd build

# Clean previous build if CMake cache exists
if [ -f "CMakeCache.txt" ]; then
    echo "Cleaning previous build..."
    cmake --build . --target clean
fi

# Configure and build
echo "Configuring with build type: $BUILD_TYPE"
cmake -DCMAKE_BUILD_TYPE=$BUILD_TYPE -DCMAKE_EXPORT_COMPILE_COMMANDS=ON ..
echo "Building..."
cmake --build .

echo "✅ Build complete with type: $BUILD_TYPE"