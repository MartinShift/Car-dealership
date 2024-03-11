#pragma once
#include "console.h"
#include "Shift.h"
const wchar_t keys[]{ L'\x2191',L'\x2193',L'\x2190',L'\x2192' };
const std::string controls[]{ "UP: ","DOWN: ","ESC: ","F1: ","F2: ","F3: ","F4: ","F5: ","F6: ","F7: ","F8: "};
const std::string controlmeans[]{"Up","Down","Exit","Create vehicle","Create pre-built vehicle","Delete vehicle","Clone vehicle","Test drive","Info","Enter shooting mode","Enter driving mode"};
const std::string drivecontrols[]{ "UP: ","DOWN: ","ENTER: ", "ESC: ", "TAB: ","SHIFT: ","BACK: "};
const std::string drivemeans[]{ "Gear up","Gear down","Drive","Exit","Fuel menu","Change road(if not boat)","Clear table"};
using namespace std;
class Menu {
protected:
	long long activeOption = 0;
	vector<string> options;
	string question;
public:
	Menu();
	Menu(const std::vector<std::string>& options, const std::string question);
	Menu(string*& options, const string question);
	void generate(const std::vector<std::string> options, const std::string question);
	void drawControls();
	
	void drawQuestion();
	void drawFrame();
	void drawOptions();
	void down();
	void up();
	size_t getSelectedOption();
	size_t getMaxItemSize();
	size_t getFrameWidth();
	size_t getFrameHeight();
};
void drawDriveControls(std::vector<std::string>mes);
WCHAR keymenu();
void drawnameframe(const size_t width, const size_t height, const size_t startX, const size_t startY, const ConsoleColor color);
void warnmessage(const std::string message, ConsoleColor color);
size_t mainmenu(const std::vector<std::string> mes, const std::string& question);
std::chrono::system_clock::time_point fromString(const std::string& dateStr, const std::string& format);
time_t EnterTime(const std::string& mes);
bool suretable(const std::string& message);
string inputbox(const ConsoleColor color, const string& mes);
void WriteNice(std::vector<std::string> strings, ConsoleColor color);
void wait();

void Progressbar(std::string mes, int sleeptime);