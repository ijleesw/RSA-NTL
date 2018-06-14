# Implementation of RSA Cryptosystem using NTL Library

## 1. How to Run

Compile cpp file with the following command:

```bash
$ make
```

You need [NTL library](http://www.shoup.net/ntl/) and [GMP library](https://gmplib.org/manual/index.html#Top) to compile `main.cpp`.



The program receives your input message and dynamically generates prime numbers _p_ and _q_ for RSA cryptosystem.



For each variable initialized with `GenPrime_ZZ`, the probability of the variable not being a prime is bounded by 2^(-ERR). `ERR` is defined in the first line of the source file.



Each user in the cryptosystem is represented by `class User` so it's easy to extend the code to multi-user cases. The class has following public methods:

```c++
public:
	ZZ get_e();
	ZZ get_n();

	void set_original_msg(const std::string msg);
	ZZ send_encrypted_msg_to(User* user);
	void receive(ZZ msg);
	void decrypt();
	void announce();
```

Each method's functionality is easy to understand when you see the code, so detailed explanation omitted. Detailed usage can be found in `main.cpp`



## 2. Sample Output

```bash
$ ./RSA
Type Alice's message: 	1125899906842624
Alice's encrypted message: 	5277132820350435844
Bob's decrypted message: 	1125899906842624
```

