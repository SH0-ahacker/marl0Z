
int Random()
{
	if (hProv == 0)
		if (!CryptAcquireContext(&hProv, NULL, NULL, PROV_RSA_FULL, CRYPT_SILENT | CRYPT_VERIFYCONTEXT))
			return 0;
      
	int out = 0;
	CryptGenRandom(hProv, sizeof(out), (BYTE *)(&out));

	return out & 0x7FFFFFFF;
}

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	HWND hwnd;
	HDC hdc, hCopy;
	HBITMAP hBitmap;
	int width = 0, height = 0;
  
	for (;;)
	{
		width = GetSystemMetrics(SM_CXSCREEN);
		height = GetSystemMetrics(SM_CYSCREEN);
    
		hwnd = GetDesktopWindow();
		hdc = GetDC(hwnd);
		hCopy = CreateCompatibleDC(hdc);
		hBitmap = CreateCompatibleBitmap(hdc, SIZE_X, height);
		SelectObject(hCopy, hBitmap);
    
		for (int i = 0; i < COUNT; i++)
		{
			int x = Random() % width - SIZE_X / 2;
			BitBlt(hCopy, 0, 0, SIZE_X, height, hdc, x, 0, SRCCOPY);

			for (int ix = 0, depth = 0; ix < SIZE_X; ix++)
			{
				depth = (int)(sin(ix / (double)SIZE_X * PI) * SIZE_Y);
				StretchBlt(hCopy, ix, 0, 1, depth, hCopy, ix, 0, 1, 1, SRCCOPY);
				BitBlt(hCopy, ix, 0, 1, height, hCopy, ix, -depth, SRCCOPY);
			}
			BitBlt(hdc, x, 0, SIZE_X, height, hCopy, 0, 0, SRCCOPY);
			Sleep(50);
		}
		DeleteDC(hCopy);
		DeleteObject(hBitmap);
		ReleaseDC(hwnd, hdc);
	}

	return 0;
}
PayloadInvert

int Random()
{
	if (hProv == 0)
		if (!CryptAcquireContext(&hProv, NULL, NULL, PROV_RSA_FULL, CRYPT_SILENT | CRYPT_VERIFYCONTEXT))
			return 0;
      
	int out = 0;
	CryptGenRandom(hProv, sizeof(out), (BYTE *)(&out));

	return out & 0x7FFFFFFF;
}

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	HWND hwnd;
	HDC hdc, hCopy;
	HBITMAP hBitmap;
	int width = 0, height = 0;
  
	for (;;)
	{
		width = GetSystemMetrics(SM_CXSCREEN);
		height = GetSystemMetrics(SM_CYSCREEN);
    
		hwnd = GetDesktopWindow();
		hdc = GetDC(hwnd);
		hCopy = CreateCompatibleDC(hdc);
		hBitmap = CreateCompatibleBitmap(hdc, SIZE_X, height);
		SelectObject(hCopy, hBitmap);
    
		for (int i = 0; i < COUNT; i++)
		{
			int x = Random() % width - SIZE_X / 2;
			BitBlt(hCopy, 0, 0, SIZE_X, height, hdc, x, 0, SRCCOPY);

			for (int ix = 0, depth = 0; ix < SIZE_X; ix++)
			{
				depth = (int)(sin(ix / (double)SIZE_X * PI) * SIZE_Y);
				StretchBlt(hCopy, ix, 0, 1, depth, hCopy, ix, 0, 1, 1, SRCCOPY);
				BitBlt(hCopy, ix, 0, 1, height, hCopy, ix, -depth, SRCCOPY);
			}
			BitBlt(hdc, x, 0, SIZE_X, height, hCopy, 0, 0, SRCCOPY);
			Sleep(50);
		}
		DeleteDC(hCopy);
		DeleteObject(hBitmap);
		ReleaseDC(hwnd, hdc);
	}

	return 0;
}
