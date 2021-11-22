#include <stdio.h>
#include <sys/neutrino.h>
#include <sys/procmgr.h>
#include <errno.h>

/* on AARCH64, use the MRS and MSR instructions (for *_EL1 system registers) */
int enable_access_qnx_register()
{
    int res = procmgr_ability(0, PROCMGR_ADN_ROOT | PROCMGR_AOP_ALLOW | PROCMGR_AID_IO, PROCMGR_AID_EOL);
    if (res != EOK) {
        printf("add IO ability failed\n");
		return 0;
    }
    int ret = ThreadCtl(_NTO_TCTL_IO_PRIV, 0);
    if (ret == -1) {
        printf("ThreadCtl failed\n");
		return 0;
    }

    return 1;
}
