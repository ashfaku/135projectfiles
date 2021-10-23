#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "caesar.h"
#include "decrypt.h"
#include "doctest.h"
#include "funcs.h"
#include "vigenere.h"
TEST_CASE("Task B shiftChar Function") {
  CHECK(shiftChar('A', -3) == 'X');
  CHECK(shiftChar('J', 3) == 'M');
  CHECK(shiftChar('@', 100) == '@');
  CHECK(shiftChar('y', 3) == 'b');
  CHECK(shiftChar('g', 10) == 'q');
}
TEST_CASE("Task B Caesar Encryption") {
  CHECK(encryptCaesar("A Light-Year Apart", 5) == "F Qnlmy-Djfw Fufwy");
  CHECK(encryptCaesar("Hello, World!", 10) == "Rovvy, Gybvn!");
  CHECK(encryptCaesar("A Light-Year Apart", 5) == "F Qnlmy-Djfw Fufwy");
  CHECK(encryptCaesar("Way to Go!", 5) == "Bfd yt Lt!");
  CHECK(encryptCaesar("This!%iS,_good.", 17) == "Kyzj!%zJ,_xffu.");
}
TEST_CASE("Task C Vigenere Encryption") {
  CHECK(encryptVigenere("Hello, World!", "cake") == "Jevpq, Wyvnd!");
  CHECK(encryptVigenere("Hello, World!", "CAKE") == "Jevpq, Wyvnd!");
  CHECK(encryptVigenere("This wiLL compilE.", "red") == "Kllj alCP ffqszpH.");
  CHECK(encryptVigenere("VigenEre @iS &#int3r3st!ng*", "table") ==
        "OihprXrf @tW &#bnu3c3wm!nh*");
}
TEST_CASE("Task D Caesar Decryption") {
  CHECK(decryptCaesar("F Qnlmy-Djfw Fufwy", 5) == "A Light-Year Apart");
  CHECK(decryptCaesar("Rovvy, Gybvn!", 10) == "Hello, World!");
  CHECK(decryptCaesar("F Qnlmy-Djfw Fufwy", 5) == "A Light-Year Apart");
  CHECK(decryptCaesar("Bfd yt Lt!", 5) == "Way to Go!");
  CHECK(decryptCaesar("A3zovm_q1kD zB@5xo...", 23) == "D3cryp_t1nG cE@5ar...");
}
TEST_CASE("Task D Vigenere Decryption") {
  CHECK(decryptVigenere("Jevpq, Wyvnd!", "cake") == "Hello, World!");
  CHECK(decryptVigenere("Jevpq, Wyvnd!", "cake") == "Hello, World!");
  CHECK(decryptVigenere("O Girvo-Ypom Aaomt", "oval") == "A Light-Year Apart");
  CHECK(decryptVigenere("Uiwyjrk yfwxnok", "beef") == "Testing testing");
  CHECK(decryptVigenere("ymISQ19k-zW 80 aCt!", "vigenere") ==
        "deCOD19g-iS 80 fUn!");
}
