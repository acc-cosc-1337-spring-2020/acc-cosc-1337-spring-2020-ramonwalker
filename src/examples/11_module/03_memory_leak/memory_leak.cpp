#include "memory_leak.h"

void memory_leak()
{
	int* ptr_num = new int(5);
	// other code here; NOTE: if it was a while loop then it will keep creating addresses because it wasn't release
}
