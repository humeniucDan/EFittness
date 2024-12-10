# Start with a base image that has a C++ development environment
FROM ubuntu:latest

RUN apt-get update -y
RUN apt-get upgrade -y
# reinstall certificates, otherwise git clone command might result in an error
RUN apt-get install --reinstall ca-certificates -y

RUN apt-get install -y git build-essential cmake --no-install-recommends

# Install essential build tools and dependencies
RUN apt-get install -y \
    build-essential \
    cmake \
    curl \
    git \
    unzip \
    pkg-config \
    bison \
    flex \
    autoconf \
    && rm -rf /var/lib/apt/lists/*

# install vcpkg package manager
RUN git clone https://github.com/microsoft/vcpkg
RUN apt-get update && apt-get install -y curl zip
RUN vcpkg/bootstrap-vcpkg.sh

# Install vcpkg
RUN git clone https://github.com/microsoft/vcpkg.git /opt/vcpkg \
    && /opt/vcpkg/bootstrap-vcpkg.sh

# Set vcpkg path environment variable (Optional)
ENV VCPKG_ROOT=/vcpkg

COPY . .
RUN ls -a

# Install dependencies using vcpkg (replace with your dependencies)
RUN /vcpkg/vcpkg install

# Copy your project files to the container (assuming CMake project)
#WORKDIR /app

# Configure and build the project using CMake and vcpkg
RUN cmake -Bbuild -DCMAKE_TOOLCHAIN_FILE=/vcpkg/scripts/buildsystems/vcpkg.cmake .
RUN cmake --build build

RUN ls -a
RUN ls -a build

# Set the entrypoint or CMD as necessary
CMD ["./build/userdata"]
