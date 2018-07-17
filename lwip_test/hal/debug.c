#include "debug.h"
static char* pr_msg = (char *)0;
void
pr_info_const (char *msg)
{
	pr_msg = msg;
}
char *get_last_pr_info_const(void)
{
	char * tmp = pr_msg;
	pr_msg = (char *)0;
	return tmp;
}
