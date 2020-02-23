#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "dna.h"
#include<string>

TEST_CASE("Verify Test Configuration", "verification")
{
	REQUIRE(true == true);
}

TEST_CASE("Verify get_gc_content string dna loop by ref")
{
	string dna1 = "AGCTATAG";
	get_gc_content(dna1);
	REQUIRE(dna1 == "AGCTATAG");

	string dna2 = "CGCTATAG";
	get_gc_content(dna2);
	REQUIRE(dna2 == "CGCTATAG");
}

TEST_CASE("Verify get dna complement")
{
	REQUIRE(get_dna_complement("AAAACCCGGT") == "ACCGGGTTTT");
	REQUIRE(get_dna_complement("CCCGGAAAAT") == "ATTTTCCGGG");
}