// Hello World
/* By Kyle 9-4-05*/

#include <pspkernel.h>
#include <pspdebug.h>

PSP_MODULE_INFO("Hello World",0,1,1);

#define printf pspDebugScreenPrintf
/* Exit callback */
int exit_callback(int arg1, int arg2, void *common) {
	sceKernelExitGame();
	return 0;
}

/* Callback thread */
int CallbackThread(SceSize args, void *argp) {
	int cbid;

	cbid = sceKernelCreateCallback("Exit Callback", exit_callback, NULL);
	sceKernelRegisterExitCallback(cbid);

	sceKernelSleepThreadCB();

	return 0;
}

/* Sets up the callback thread and returns its thread id */
int SetupCallbacks(void) {
	int thid = 0;

	thid = sceKernelCreateThread("update_thread", CallbackThread, 0x11, 0xFA0, 0, 0);
	if(thid >=0) {
		sceKernelStartThread(thid, 0, 0);
	}

	return thid;
}

int main() {
pspDebugScreenInit();
SetupCallbacks();

printf("Hello World");
sceKernelSleepThread();
return 0;
}