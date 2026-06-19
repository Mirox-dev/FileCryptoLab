cmake_minimum_required(VERSION 3.10)

project(FileCryptoLab)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(FileCryptoLab
    main.cpp

    src/FileManager.cpp
    src/AffineCipher.cpp
    src/HillCipher.cpp
    src/ConsoleMenu.cpp
    src/MathUtils.cpp
    src/GammaCipher.cpp

    tests/TestRunner.cpp
    tests/test_affine.cpp
    tests/test_gamma.cpp
    tests/test_hill.cpp
)

target_include_directories(FileCryptoLab PRIVATE
    include
    tests
)