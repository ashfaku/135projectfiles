#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"
int randomShift(int low, int high)
{
	return rand() / (double) RAND_MAX * (high - low) + low;
}
TEST_CASE("Tests with long strings and random shifts")
{
	CHECK(solve(encryptCaesar("Java is more fun than C++", randomShift(0, 26))) == "Java is more fun than C++");
	CHECK(solve(encryptCaesar("Java is more fun than C++", -5)) == "Java is more fun than C++");
	CHECK(solve(encryptCaesar("This message contains a secret missive: please activate the nukes", randomShift(0, 26))) == "This message contains a secret missive: please activate the nukes");
    	CHECK(solve(encryptCaesar("This function is a different way of decryption", randomShift(0, 26))) == "This function is a different way of decryption");
    	CHECK(solve(encryptCaesar("My name is Bob and here is the way", 10)) == "My name is Bob and here is the way");
    	CHECK(solve("UIJT GVODUJPO SPUBUFT 26 UJNFT GPS FWFSZ TUSJOH") == "THIS FUNCTION ROTATES 26 TIMES FOR EVERY STRING");
   	CHECK(solve("j lralun qjb oxda brmnb") == "a circle has four sides");
   	CHECK(solve("l oryh hdwlqj slccd") == "i love eating pizza");
    	CHECK(solve("Iye kbo fobi lokedspev") == "You are very beautiful");
    	CHECK(solve("Pb qdph lv vdp") == "My name is sam");
    	CHECK(solve("Xli woc mw fpyi mr gspsv") == "The sky is blue in color");
    	CHECK(solve("Qerksiw evi waiix erh cippsa mr gspsv.") == "Mangoes are sweet and yellow in color.");
	CHECK(solve(encryptCaesar("Is it a better idea to do jMonkeyEngine or LWJGL after JavaFX :hmm:", 69)) == "Is it a better idea to do jMonkeyEngine or LWJGL after JavaFX :hmm:");
}
TEST_CASE("Testing solve() with short strings, short strings could have a chance of not working, due to too little letters")
{
	CHECK(solve("") == "");
	CHECK(solve("Lipps, qc reqi mw Nslr") == "Hello, my name is John");
	CHECK(solve("Ol pz nvpun ovtl!") == "He is going home!");
	CHECK(solve("Nkx lgbuxozk iurux oy hrak") == "Her favorite color is blue");
}
TEST_CASE("Solving shifts with negative shifts")
{
	CHECK(solve(encryptCaesar("Java is more fun than C++", -1 * randomShift(0, 26))) == "Java is more fun than C++");
        CHECK(solve(encryptCaesar("Java is more fun than C++", -5)) == "Java is more fun than C++");
        CHECK(solve(encryptCaesar("This message contains a secret missive: please activate the nukes", -1 * randomShift(0, 26))) == "This message contains a secret missive: please activate the nukes");
	CHECK(solve(encryptCaesar("This function is a different way of decryption", -25)) == "This function is a different way of decryption");
}

