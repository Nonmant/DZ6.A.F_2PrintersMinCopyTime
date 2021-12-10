#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include "catch.hpp"

TEST_CASE("Catch operability", "[simple]"){
    REQUIRE(1+1 == 2);
}

#include "funcs.h"

TEST_CASE("test 1, file", "[simple]"){
    std::ofstream inputPrepare;
    inputPrepare.open ("input.txt", std::ofstream::trunc);
    inputPrepare<<
                "4 1 1"
            ;
    inputPrepare.close();

    std::ifstream input( "input.txt", std::ofstream::in);
    std::ofstream output("output.txt", std::ofstream::trunc);
    parseFile(input,output);
    input.close();
    output.close();

    std::ifstream outputCheck("output.txt", std::ofstream::in);
    std::stringstream buffer;
    buffer<<outputCheck.rdbuf();
    outputCheck.close();
    INFO(buffer.str());
    REQUIRE(buffer.str() ==
            "3"
    );
}

TEST_CASE("test 2", ""){
    std::stringstream input(
            "5 1 2"
    );
    std::stringstream output;
    parseFile(input,output);
    REQUIRE(output.str() == "4"
    );
}

TEST_CASE("ranges", ""){
    std::stringstream input(
            "100000000 10 10"
    );
    std::stringstream output;
    parseFile(input,output);
    REQUIRE(output.str() == "500000010"
    );
}

TEST_CASE("one extra copy", ""){
    std::stringstream input(
            "1 10 2"
    );
    std::stringstream output;
    parseFile(input,output);
    REQUIRE(output.str() == "2"
    );
}
