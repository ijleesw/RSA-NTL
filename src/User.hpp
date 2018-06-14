#ifndef USER_HPP_
#define USER_HPP_

#define ERR 80

#include <iostream>
#include <NTL/ZZ.h>
using namespace NTL;


/*
class User
{
private:
	ZZ n, phi_n, e, d;
	long logn;
	ZZ original_msg;
	ZZ encrypted_msg;
	ZZ decrypted_msg;

public:
	ZZ get_e();
	ZZ get_n();

	User(const unsigned long BITS);
	User(const ZZ p, const ZZ q);
	~User() {}

	void set_original_msg(const std::string msg);
	ZZ send_encrypted_msg_to(User* user);
	void receive(ZZ msg);
	void decrypt();
	void announce();
};
*/


class User
{
private:
	ZZ n, phi_n, e, d;
	long logn;
	ZZ original_msg;
	ZZ encrypted_msg;
	ZZ decrypted_msg;

public:
	ZZ get_e() { return e; }
	ZZ get_n() { return n; }

	User(const unsigned long BITS) {
		ZZ p, q, tmp;

		p = GenPrime_ZZ(BITS, ERR);
		q = GenPrime_ZZ(BITS, ERR);
		n = p*q;
		phi_n = (p-1)*(q-1);

		tmp=1; logn=0;
		while (tmp <= n) { tmp *= 10; logn++; }
		e = GenPrime_ZZ(logn/2, ERR);
		XGCD(tmp, d, tmp, e, phi_n);
	}

	User(const ZZ p, const ZZ q) {
		ZZ tmp;

		n = p*q;
		phi_n = (p-1)*(q-1);

		tmp=1; logn=0;
		while (tmp <= n) { tmp *= 10; logn++; }
		e = GenPrime_ZZ(logn/2, ERR);
		XGCD(tmp, d, tmp, e, phi_n);
	}

	~User() {}

	void set_original_msg(const std::string msg) {
		original_msg = conv<ZZ>(msg.c_str());
	}

	ZZ send_encrypted_msg_to(User* user) {
		ZZ target_e, target_n;

		target_e = user->get_e();
		target_n = user->get_n();

		ZZ enc_msg;
		enc_msg = PowerMod(original_msg%target_n, target_e, target_n);
		user->receive(enc_msg);

		return enc_msg;
	}

	void receive(ZZ msg) {
		encrypted_msg = msg;
	}

	void decrypt() {
		decrypted_msg = PowerMod(encrypted_msg, d, n);
	}

	void announce() {
		std::cout << decrypted_msg << std::endl;
	}
};


#endif /* USER_HPP_ */