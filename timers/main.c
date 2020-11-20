// Timers And Time
/* By Kyle 9-5-05*/

#include <pspkernel.h>
#include <pspdebug.h>
#include <pspdisplay.h>
#include <pspctrl.h>
#include <stdio.h>
#include <time.h>

PSP_MODULE_INFO("Timers And Time",0,1,1);

#define MST (-7)
#define CST (-6)
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

void wait ( int secs )
{
  clock_t endwait;
  endwait = clock () + secs * CLK_TCK ;
  while (clock() < endwait) {}
}

int main() {
pspDebugScreenInit();
SetupCallbacks();
int seconds = 0;
SceCtrlData pad;
label0: printf("Press [START] For Countup Timers.\nPress [SELECT] For Countdown Timers.\nPress [L] For Current Time.");
while(1) {
	sceCtrlReadBufferPositive(&pad, 1);
	if(pad.Buttons & PSP_CTRL_START) {
		pspDebugScreenClear();
		goto labelA;}
	if(pad.Buttons & PSP_CTRL_SELECT) {
		pspDebugScreenClear();
		goto labelB;}
	if(pad.Buttons & PSP_CTRL_LTRIGGER) {
		pspDebugScreenClear();
		goto labelI;}
}
printf("COUNTUP TIMERS\n\n");
int counter = 0;
int counter2 = 0;
int i = 0;
labelA: printf("Press [X] To Start Timer #1");
while(1) {
	sceCtrlReadBufferPositive(&pad, 1);
	if(pad.Buttons & PSP_CTRL_CROSS) {
		break;
	}
}
while(1) {
	sceCtrlReadBufferPositive(&pad, 1);
	if(pad.Buttons & PSP_CTRL_CIRCLE) {
		break;
	}
	pspDebugScreenClear();
	printf("Press [O] To Stop Timer #1\n");
	printf("Counter: %i\n", counter);
	counter++;
	for(i=0; i<5; i++) {
		sceDisplayWaitVblankStart();
	}
}
pspDebugScreenClear();
printf("Timer #1 Finished.\n");
printf("Final Count #1: %i\n", counter);
printf("Press [x] To Start Timer #2");
while(1) {
	sceCtrlReadBufferPositive(&pad, 1);
	if(pad.Buttons & PSP_CTRL_CROSS) {
		break;
	}
}
while(1) {
	sceCtrlReadBufferPositive(&pad, 1);
	if(pad.Buttons & PSP_CTRL_CIRCLE) {
		break;
	}
	pspDebugScreenClear();
	printf("Press [O] To Stop The 2nd Timer\n");
printf("Counter2: %i\n", counter2);
counter2++;
for(i=0; i<5; i++) {
	sceDisplayWaitVblankStart();
}
}
pspDebugScreenClear();
printf("Final Count #1: %i\n", counter);
printf("Final Count #2: %i\n\n", counter2);
int a = 0;
a = counter + counter2;
int b = 0;
b = counter * counter2;
printf("The Sum Of The 2 Timers Is: %i\n\n", a);
printf("The Product Of The 2 Timers Is: %i\n\n", b);
printf("Congratulations! The Timers Are Now Complete.  Press [X] To Start\nOver, Or Press [] To Go To The Countdown Timers.");
while(1) {
	sceCtrlReadBufferPositive(&pad, 1);
	if(pad.Buttons & PSP_CTRL_CROSS) {
		counter = 0;
		counter2 = 0;
		pspDebugScreenClear();
		goto labelA;}
	if(pad.Buttons & PSP_CTRL_SQUARE) {
		counter = 0;
		counter2 = 0;
		pspDebugScreenClear();
		goto labelB;}
	
}
labelB: printf("COUNTDOWN TIMERS\n\n");
printf("These Timers Will \nCountdown From A User Selected Time.\n\n");
printf("Press [X] To Countdown From 10 Seconds.\n");
printf("Press [O] To Countdown From 30 Seconds.\n");
printf("Press [^] To Countdown From 60 Seconds.\n");
printf("Press [R] To Countdown From 90 Seconds.\n");
printf("Press [L] To Countdown From 120 Seconds.\n");
while(1) {
	sceCtrlReadBufferPositive(&pad, 1);
	if(pad.Buttons & PSP_CTRL_CROSS) {
		pspDebugScreenClear();
		goto labelC;}
	if(pad.Buttons & PSP_CTRL_CIRCLE) {
		pspDebugScreenClear();
		goto labelD;}
	if(pad.Buttons & PSP_CTRL_TRIANGLE) {
		pspDebugScreenClear();
		goto labelE;}	
	if(pad.Buttons & PSP_CTRL_RTRIGGER) {
		pspDebugScreenClear();
		goto labelF;}
	if(pad.Buttons & PSP_CTRL_LTRIGGER) {
		pspDebugScreenClear();
		goto labelG;}
}

labelC: printf("Press [Start] To Start The Countdown From 10 Seconds.\n");
seconds = 10;
while(1) {
	sceCtrlReadBufferPositive(&pad, 1);
	if(pad.Buttons & PSP_CTRL_START) {
	break;
	}
}
while(1) {
	if(seconds == 0) {
		goto labelH;
	}
	pspDebugScreenClear();
	printf("Time Remaining: %i Seconds", seconds);
	wait (1000);
	seconds--;
	for(i=0; i<5; i++) {
		sceDisplayWaitVblankStart();
	}
}
labelD: printf("Press [Start] To Start The Countdown From 30 Seconds.\n");
seconds = 30;
while(1) {
	sceCtrlReadBufferPositive(&pad, 1);
	if(pad.Buttons & PSP_CTRL_START) {
	break;
	}
}
while(1) {
	if(seconds == 0) {
		goto labelH;
	}
	pspDebugScreenClear();
	printf("Time Remaining: %i Seconds", seconds);
	wait (1000);
	seconds--;
	for(i=0; i<5; i++) {
		sceDisplayWaitVblankStart();
	}
}
labelE: printf("Press [Start] To Start The Countdown From 60 Seconds.\n");
seconds = 60;
while(1) {
	sceCtrlReadBufferPositive(&pad, 1);
	if(pad.Buttons & PSP_CTRL_START) {
	break;
	}
}
while(1) {
	if(seconds == 0) {
		goto labelH;
	}
	pspDebugScreenClear();
	printf("Time Remaining: %i Seconds", seconds);
	wait (1000);
	seconds--;
	for(i=0; i<5; i++) {
		sceDisplayWaitVblankStart();
	}
}
labelF: printf("Press [Start] To Start The Countdown From 90 Seconds.\n");
seconds = 90;
while(1) {
	sceCtrlReadBufferPositive(&pad, 1);
	if(pad.Buttons & PSP_CTRL_START) {
	break;
	}
}
while(1) {
	if(seconds == 0) {
		goto labelH;
	}
	pspDebugScreenClear();
	printf("Time Remaining: %i Seconds", seconds);
	wait (1000);
	seconds--;
	for(i=0; i<5; i++) {
		sceDisplayWaitVblankStart();
	}
}
labelG: printf("Press [Start] To Start The Countdown From 120 Seconds.\n");
seconds = 120;
while(1) {
	sceCtrlReadBufferPositive(&pad, 1);
	if(pad.Buttons & PSP_CTRL_START) {
	break;
	}
}
while(1) {
	if(seconds == 0) {
		goto labelH;
	}
	pspDebugScreenClear();
	printf("Time Remaining: %i Seconds", seconds);
	wait (1000);
	seconds--;
	for(i=0; i<5; i++) {
		sceDisplayWaitVblankStart();
	}
}
labelH: pspDebugScreenClear();
printf("Time Remaining: %i Seconds", seconds);
printf("\n\nThe Countdown Timer Is Complete.\n\n");
printf("If You Would Like To Start Another Countdown, Please Press [].\n\nTo Go To Countup Timers, Press [L]\n\n");
printf("To Get The Time Press [X].");
while(1) {
	sceCtrlReadBufferPositive(&pad, 1);
	if(pad.Buttons & PSP_CTRL_SQUARE) {
		pspDebugScreenClear();
		goto labelB;}
	if(pad.Buttons & PSP_CTRL_LTRIGGER) {
		pspDebugScreenClear();
		goto labelA;}
	if(pad.Buttons & PSP_CTRL_CROSS) {
		pspDebugScreenClear();
		goto labelI;}
}
labelI: pspDebugScreenClear();
while(1) {
	sceCtrlReadBufferPositive(&pad, 1);
	if(pad.Buttons & PSP_CTRL_CIRCLE) {
	pspDebugScreenClear(); break;}
  wait (1000);
  pspDebugScreenClear();
  printf("Press And Hold [O] To Stop Viewing Time\n\n");


}
goto label0;
return 0;
}
