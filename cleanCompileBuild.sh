#!/bin/bash

set -e  # Exit on error

# Check input
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 [Debug|Release]"
    exit 1
fi

BUILD_TYPE="$1"

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
cmake -DCMAKE_BUILD_TYPE=$BUILD_TYPE ..
echo "Building..."
cmake --build .

echo "✅ Build complete with type: $BUILD_TYPE"