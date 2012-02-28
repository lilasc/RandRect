#include <windows.h>
#include <stdlib.h>

#define OFFSET 200

void DrawRect();
int cxScreen, cyScreen;

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PSTR szCmdLine, int iCmdShow)
{	
	cxScreen = GetSystemMetrics(SM_CXSCREEN);
	cyScreen = GetSystemMetrics(SM_CYSCREEN);
	while (TRUE)
	{
		if (GetAsyncKeyState(VK_ESCAPE) < 0)
			exit(0);
		DrawRect () ;
	}
}

void DrawRect ()
{
	HBRUSH hBrush ;
	HDC    hdc ;
	RECT   rect ;
	

	SetRect (&rect, rand () % cxScreen - OFFSET, rand () % cyScreen - OFFSET,
		rand () % cxScreen + OFFSET, rand () % cyScreen + OFFSET) ;
	
	hBrush = CreateSolidBrush (
		RGB (rand () % 256, rand () % 256, rand () % 256)) ;
	
	hdc = CreateDC(TEXT("DISPLAY"), NULL, NULL, NULL);
	FillRect (hdc, &rect, hBrush) ;
	DeleteDC(hdc);
	DeleteObject (hBrush) ;
}     


