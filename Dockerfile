FROM ubuntu:24.04

# Install build essentials and CMake
RUN apt-get update && \
    apt-get install -y build-essential cmake gdb cppcheck && \
    apt-get clean

# Set the working directory
WORKDIR /app

# Copy your source code into the container
COPY . /app

# Default command (can be changed)
CMD ["/bin/bash"]