# AMI-Spoofer-Source
IrisDMA Free Spoofer is a lightweight C++ Windows tool that uses AMI to spoof SMBIOS serials and other system identifiers.
---

## Features

- Automatically downloads AMIDEWIN tools to the temp directory
- Spoofs a wide range of SMBIOS fields using randomized serials
- Terminates known anticheat related processes
- Cleans up all files after spoofing

---

## How It Works

1. Prompts for a license key (`IrisDMA`)
2. Downloads `AMIDEWINx64.EXE` and `amifldrv64.sys` to `%TEMP%`
3. Kills common anticheat and related processes
4. Executes spoofing logic
5. Deletes both downloaded files after spoofing is complete
6. Clears the console and exits

---

## Compilation Instructions (Windows)

### Requirements

- Visual Studio (Community Edition recommended)
- C++ Desktop Development workload installed
- TPM/Secureboot Disabled
- (Optional) Disable Windows Defender/Other Anti Viruses

### Guide

### Self Build
1. Clone or download this repository
2. Open Visual Studio and create a new "Console Application" project
3. Replace `main.cpp` with the provided source code
4. Link `urlmon.lib`:
   - Open **Project Properties**
   - Navigate to: `Linker > Input > Additional Dependencies`
   - Add: `urlmon.lib`
5. Set language standard to **C++17** or higher
6. Compile the project in **Release x64** mode
7. Update CDN Links if required. Get AMI Tool from [here](https://www.ami.com/bios-uefi-utilities/)

### Precompiled
1. Download file from releases
2. Run as administraitor

### Optional
Supported Motherboards: AsRock / MSI / Gigabyte / ASUS / Microstar / Biostar / Lenovo
To disable warnings about `system()` and similar functions, add this at the top of your file:

```cpp
#define _CRT_SECURE_NO_WARNINGS

