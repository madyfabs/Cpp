
/*
 * Exercise 09 — Move Semantics Basics
 *
 * Demonstrate the difference between copying and moving a std::string.
 * Explain why the original string can still be used after std::move().
 */

#include <iostream>
#include <string>
#include <utility>

using namespace std;

int main() {

    string original = "Embedded Systems with C++";

    // Copying creates an independent string with the same content.
    string copied = original;

    cout << "Original: " << original << endl;
    cout << "Copied: " << copied << endl;

    // Moving allows the destination to acquire the source's resources.
    // std::move itself does not move anything; it enables move semantics.
    string moved = move(original);

    cout << "\nAfter moving:" << endl;
    cout << "Moved: " << moved << endl;
    cout << "Original: " << original << endl;

    // original is still a valid string object.
    // Its content after the move is unspecified, so we assign a new value.
    original = "New Embedded Project";

    cout << "\nAfter assigning a new value:" << endl;
    cout << "Original: " << original << endl;

    return 0;
}
