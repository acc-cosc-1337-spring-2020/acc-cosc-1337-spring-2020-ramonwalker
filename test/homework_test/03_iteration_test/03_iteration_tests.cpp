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

TEST_CASE("Verify get_reverse_string dna function")
{
	string dna1 = "AGCTATAG";
	string rev1 = "GATATCGA";
	REQUIRE(rev1 == dna1);

	string dna2 = "CGCTATAG";
	string rev2 = "GATATCGC";
	REQUIRE(rev2 == dna2);	
}

TEST_CASE("Verify get dna complement")
{
	//string comp1 = "";
	//string comp2 = "";
	//REQUIRE(comp1 = 'A' += 'T');
}