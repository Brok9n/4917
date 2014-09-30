#include <stdio.h>

class cpu {
	private:
		char Memory[16];
		char IP, IS, R0, R1;
	public:
		void insert(char ops[], int size);
		void run(void);
		
		char get_ip() { return IP; };
		char get_is() { return IS; };
		char get_r0() { return R0; };
		char get_r1() { return R1; };
		
		char get_op(int pos) { return Memory[pos]; };
		char* get_ops() { return Memory; };
};

void cpu::insert(char ops[], int size)
{
	if (size<=16)
	{
		for (int i=0; i<size; i++){
			Memory[i] = ops[i];
		}
	}
}

void cpu::run(void)
{
	IP = 0, IS = 0, R0 = 0, R1 = 0;
	
	int halt = 0;
	
	for (int i=0; i<16 && !halt; i++){
		IP = Memory[i];
		printf("IP = %c\n", IP);
		
		switch (IP)
		{
			case '0':
			{
				halt = 1;
				break;
			}	
		}
	}
}

int main(void)
{
	cpu test;
	char ops [] = {'7', '0'};
	
	test.insert(ops, 2);
	test.run();
	
	return 0;
}
