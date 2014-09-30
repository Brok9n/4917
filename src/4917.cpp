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
	
	for (IP=0; IP<16 && !halt; IP++){
		IS = Memory[(int)IP];
		printf("IP = %d\n", IP);
		printf("IS = %c\n", IS);
		
		switch (IS)
		{
			case '0':
			{
				halt = 1;
				break;
			}
			case '1':
			{
				R0 += R1;
				break;
			}
			case '2':
			{
				R0 -= R1;
				break;
			}
			case '3':
			{
				R0++;
				break;
			}
			case '4':
			{
				R1++;
				break;
			}
			case '5':
			{
				R0--;
				break;
			}
			case '6':
			{
				R1--;
				break;
			}
			case '7':
			{
				printf("BEEP!!!\n");
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
