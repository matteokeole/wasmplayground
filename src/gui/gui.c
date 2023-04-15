#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void centerWindow(HWND);

int main(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PWSTR pCmdLine, int nCmdShow) {

	MSG msg;
	HWND hwnd;
	WNDCLASSW wc;

	wc.style         = CS_HREDRAW | CS_VREDRAW;
	wc.cbClsExtra    = 0;
	wc.cbWndExtra    = 0;
	wc.lpszClassName = L"test";
	wc.hInstance     = hInstance;
	wc.hbrBackground = GetSysColorBrush(COLOR_3DFACE);
	wc.lpszMenuName  = NULL;
	wc.lpfnWndProc   = WndProc;
	wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon         = LoadIcon(NULL, IDI_WARNING);

	RegisterClassW(&wc);
	hwnd = CreateWindowW(wc.lpszClassName, L"test",
				WS_OVERLAPPEDWINDOW | WS_VISIBLE,
				100, 100, 350, 250, NULL, NULL, hInstance, NULL);

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, NULL, 0, 0)) {

		DispatchMessage(&msg);
	}

	return (int) msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg) {
		case WM_CREATE:
			centerWindow(hwnd);

			break;
		case WM_KEYDOWN:
			if (wParam == VK_ESCAPE) {
				int alert = MessageBoxW(
					hwnd,
					L"Are you sure you want to quit?",
					L"Confirmation",
					MB_OKCANCEL
				);

				if (alert == IDOK) SendMessage(hwnd, WM_CLOSE, 0, 0);
			}

			break;
		case WM_DESTROY:
			PostQuitMessage(0);

			break;
	}

	return DefWindowProcW(hwnd, msg, wParam, lParam);
}

void centerWindow(HWND hwnd) {
	RECT rect = {0};

	GetWindowRect(hwnd, &rect);

	int windowWidth = rect.right - rect.left;
	int windowHeight = rect.bottom - rect.top;

	int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);

	SetWindowPos(
		hwnd,
		HWND_TOP,
		(screenWidth - windowWidth) * .5,
		(screenHeight - windowHeight) * .5,
		0,
		0,
		SWP_NOSIZE
	);
}