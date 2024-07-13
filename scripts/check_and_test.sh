#!/bin/bash

set -e

THIS_SCRIPT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &> /dev/null && pwd)

function checks () {
    cd "${THIS_SCRIPT_DIR}/.."
    pre-commit run -a
    cd -
}

function build () {
    debug=$1
    tests=$2

    if [ "$debug" == true]; then
        build_type="Debug"
    else
        build_type="Release"
    fi
    build_type_variable="-DCMAKE_BUILD_TYPE:STRING=${build_type}"

    testing_variable="-DBUILD_TESTING:BOOL="
    if [ "$tests" == true ]; then
        testing_variable+="TRUE"
    else
        testing_variable+="FALSE"
    fi

    cmake_variables="-DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE -DCMAKE_C_COMPILER=/usr/bin/gcc -DCMAKE_CXX_COMPILER:FILEPATH=/usr/bin/g++"

    cd "${THIS_SCRIPT_DIR}/.."

    rm -rf "${THIS_SCRIPT_DIR}/../build/"

    cmake "${build_type_variable}" "${testing_variable}" "${cmake_variables}" -B "./build" -G "Unix Makefiles"
    echo "Starting build"
    cmake --build "./build" --config "${build_type}" --target all -j 14 --

    cd -
}

function test(){
    cd "${THIS_SCRIPT_DIR}/../build"
    echo "Starting ctest"
    ctest --output-on-failure
    cd -
}

function main(){
    debug=false
    tests=true
    checks=true

    while [ "$#" -gt 0 ]; do
        case "$1" in
            -d|--debug)
            debug=true
            shift
            ;;
            *)
            break
        esac
    done

    build $debug $tests

    if [ "$tests" == true ]; then
        test
    fi

    if [ "$checks" == true ]; then
        checks
    fi

    cd "${THIS_SCRIPT_DIR}/../build/package/app"
    ./main

    exit $?
}

main "$@"
read -p "Press any key to continue" x
