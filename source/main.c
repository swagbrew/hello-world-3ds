#include <3ds.h>

#include <stdio.h>

int main(int argc, char **argv) {
    gfxInitDefault();
    consoleInit(GFX_TOP, NULL);

    printf("Hi!\n");
    printf("This is my homebrew app!\n");

    while (aptMainLoop()) {
        hidScanInput();

        u32 keyDown = hidKeysDown();
        if (keyDown & KEY_START) break;

        gfxFlushBuffers();
		gfxSwapBuffers();

        gspWaitForVBlank();
    }

    gfxExit();
	return 0;
}