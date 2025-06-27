#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")

std::string serial() {
    int a = rand() % 90000 + 10000;
    int b = rand() % 90000 + 10000;
    int c = rand() % 90000 + 10000;
    return std::to_string(a) + "-" + std::to_string(b) + "-" + std::to_string(c);
}

void spoof(const std::string& exe, const std::string& cmd, const std::string& val = "") {
    std::string run = "\"" + exe + "\" " + cmd + " " + val;
    system(run.c_str());
}

void kill(const std::string& proc) {
    std::string cmd = "taskkill /f /im " + proc + " >nul 2>&1";
    system(cmd.c_str());
}

bool download(const std::string& url, const std::string& path) {
    return URLDownloadToFileA(NULL, url.c_str(), path.c_str(), 0, NULL) == S_OK;
}

std::string tempdir() {
    char buf[MAX_PATH];
    GetTempPathA(MAX_PATH, buf);
    return std::string(buf);
}

int main() {
    SetConsoleTitleA("IrisDMA Free Spoofer");  
    std::string input;
    std::cout << "License: ";
    std::getline(std::cin, input);

    if (input != "IrisDMA") {
        std::cout << "Incorrect license. Exiting...\n";
        return 1;
    }

    srand(static_cast<unsigned int>(time(0)));

    std::string temp = tempdir();
    std::string exe_url = "https://cdn.discordapp.com/attachments/1373270795299586171/1388154556386508881/AMIDEWINx64.EXE?ex=685ff32c&is=685ea1ac&hm=bda7e1404235789402f99ea5a28ae31200e40647139bb2d5ceb870bc9ece1c2e&";
    std::string sys_url = "https://cdn.discordapp.com/attachments/1373270795299586171/1388154556038512671/amifldrv64.sys?ex=685ff32c&is=685ea1ac&hm=e16061e580b5f8dacc1f31b5f151a246c02ea4635719a3ac12de0310d6c48eda&";
    std::string exe_path = temp + "AMIDEWINx64.EXE";
    std::string sys_path = temp + "amifldrv64.sys";

    std::cout << "[*] Spoofing...\n";
    if (!download(exe_url, exe_path) || !download(sys_url, sys_path)) {
        std::cerr << "[-] Download failed. Exiting...\n";
        return 1;
    }

    std::vector<std::string> targets = {
        "epicgameslauncher.exe", "EpicWebHelper.exe", "FortniteClient-Win64-Shipping_EAC.exe",
        "FortniteClient-Win64-Shipping_BE.exe", "FortniteLauncher.exe", "FortniteClient-Win64-Shipping.exe",
        "EpicGamesLauncher.exe", "EasyAntiCheat.exe", "BEService.exe", "BEServices.exe",
        "BattleEye.exe", "WmiPrvSE.exe"
    };

    for (const auto& p : targets) kill(p);

    spoof(exe_path, "/SU", "AUTO");

    std::vector<std::string> cmds = {
        "/BS", "/CS", "/SS", "/PSN", "/IVN", "/IVN", "/IV", "/SM", "/SP", "/SV",
        "/SS", "/SK", "/SF", "/BM", "/BP", "/BV", "/BS", "/BT", "/BLC",
        "/CM", "/CV", "/CS", "/CA", "/CSK", "/PSN", "/PAT", "/PPN",
        "/OS 1", "/OS 2", "/OS 3", "/OS 4", "/OS 5", "/OS 6", "/OS 7", "/OS 8", "/OS 9", "/OS 10", "/OS 11"
    };

    for (const auto& c : cmds) spoof(exe_path, c, serial());

    std::string iv = std::to_string(rand() % 90000 + 10000) + std::to_string(rand() % 90000 + 10000);
    spoof(exe_path, "/IV", iv);

    std::cout << "[*] Cleaning up...\n";
    DeleteFileA(exe_path.c_str());
    DeleteFileA(sys_path.c_str());

    system("cls");
    std::cout << "[+] Done.\n";
    return 0;
}
