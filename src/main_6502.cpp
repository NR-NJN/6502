#include <stdio.h>
#include <stdlib.h>

using Byte = unsigned char;
using Word = unsigned short;
using u32 = unsigned int;
struct Mem
{
	static constexpr u32 MAX_MEM = 1024 * 64;
	Byte Data[MAX_MEM];
	void Initialize()
	{
		for (u32 i = 0; i < MAX_MEM; i++)
		{
			Data[i] = 0;
		}
	}

};
struct CPU
{
	Word PC;
	Word SP;

	Byte A, X, Y; //register
	/*
	  Accumulator 8 bits, arithmetic & logical operations
	  can be stored on stack or memory
	  Index X 8 bit counters or offset for accessing memory, used to get the
	  copy of the stack pointer or change its name
	  Index Y similar to X
	 */
	Byte C : 1;
	Byte Z : 1;
	Byte I : 1;
	Byte D : 1;
	Byte B : 1;
	Byte V : 1;
	Byte N : 1;

	void reset(Mem& memory) // reference to instance of mem deriving Initialize()
	{
		PC = 0xFFFC;
		SP = 0x0100;
		C = Z = I = D = B = V = N = 0;
		A = X = Y = 0;
		memory.Initialize();
	}

};

int main()
{
	Mem mem;
	CPU cpu;
	cpu.reset(mem);
	return 0;
}
