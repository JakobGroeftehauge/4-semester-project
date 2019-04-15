#include "PID_MA.h"
#include "rtcs.h"

int main(void)
{
    init_rtcs();

    start_task(1, PID_task);

    schedule();
	return 0;
}
