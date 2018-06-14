#include <iostream>
#include <NTL/ZZ.h>
#include "User.hpp"
using namespace NTL;

int main()
{
	std::string alice_msg;
	std::cout << "Type Alice's message:\n\t";
	std::cin >> alice_msg;

	unsigned long prime_bits = alice_msg.length()*2;

	User Alice(prime_bits);
	User Bob(prime_bits);

	Alice.set_original_msg(alice_msg);
	ZZ enc = Alice.send_encrypted_msg_to(&Bob);
	std::cout << "Alice's encrypted message:\n\t" << enc << std::endl;

	Bob.decrypt();
	std::cout << "Alice's message decrypted by Bob:\n\t";
	Bob.announce();

	return 0;
}
