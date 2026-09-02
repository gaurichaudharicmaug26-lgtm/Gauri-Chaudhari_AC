#include <iostream>
using namespace std;

struct Layout1 { char c1; int i; char c2; };
struct Layout2 { int i; char c1; char c2; };


int main() {
	cout<<sizeof(Layout1)<<endl;
	cout<<sizeof(Layout2)<<endl;
	//1. Why the sizes differ
	//ANS:
	//the computer reads the memory in words, which is either 4 bytes in 32 bit systems or 8 bytes in 64 bits systems, this is done
	//so that the execution speed is fast for the CPU, it can easily make jumps from 4->4->4 or 8->8->8 this is why computer stores
	//the first char in 4 bytes than int i with 4 bytes and the last char in 4 bytes too, 4+4+4 - 12 Bytes.

	//2. What padding is and why the compiler adds it
	//ANS:
	//As answered above it is used for speed, so computer can easily find the starting memory address by making 4 byte jumps or 8 byte
	//jumps

	//3. Why member order matters when defining network packet headers or hardware register maps
	//ANS:
	//Reason why it matters is we can save the memory that our memory takes, in case of network packet headers which are small packets
	//that take data across internet, it should be memory effient
	//it does so if we keep the order from biggest to smallest in layout 2 it will first assign 4 bytes to int, after that it sees it
	//has two bytes ahead of 2 chars, it sees that we can fit it into a 8 byte as 4+1+1 = 6, and simply doing +2 will get 8.
	return 0;
}
