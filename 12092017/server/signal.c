#include"func.h"
void signal_init()
{
	signal(SIGINT,sig_handle1);
}