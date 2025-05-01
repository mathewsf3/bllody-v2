#include <Windows.h>
#include <hidsdi.h>
#include <hidpi.h>
#pragma comment(lib, "hid.lib")

#define BLOODY_VID 0x09DA
#define BLOODY_PID 0x31F8

extern "C" __declspec(dllexport) void AdjustAim(float dx, float dy, float smooth) {
    BYTE report[64] = {0x0B, 0x02};  // Bloody7 feature report
    float finalDx = dx * smooth;
    float finalDy = dy * smooth;
    
    memcpy(report + 2, &finalDx, sizeof(float));
    memcpy(report + 6, &finalDy, sizeof(float));

    HANDLE hDevice = CreateFileW(
        L"\\\\.\\HID#VID_09DA&PID_31F8",
        GENERIC_WRITE,
        FILE_SHARE_READ | FILE_SHARE_WRITE,
        NULL,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );

    if(hDevice != INVALID_HANDLE_VALUE) {
        HidD_SetFeature(hDevice, report, sizeof(report));
        CloseHandle(hDevice);
    }
}