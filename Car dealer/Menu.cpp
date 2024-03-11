#include "Menu.h"
#include "Shift.h"
	//конструктор
	Menu::Menu() {}
	//конструктор
	Menu::Menu(const std::vector<std::string>& options, const std::string question) {
		this->question = question;
		this->options = options;
	}
	//ще 1 конструктор
	void Menu::generate(const std::vector<std::string> options, const std::string question)
	{
		this->options = options;
		this->question = question;
	}
	//опять конструктор
	Menu::Menu(string*& options, const string question)
	{
		for (int i=0; options[i].empty(); i++)
		{
			this->options.push_back(options[i]);
		}
		this->question = question;
	}
	//пише те шо зверху
	void Menu::drawQuestion()
	{
		size_t width = question.size() + 2 > getFrameWidth() ? question.size() + 2 : getFrameWidth();
		for (short y = 0; y < 3; y++)
		{
			for (short x = 0; x < width; x++)
			{
				if (x == 0 || x == width - 1 || y == 0 || y == 2) {
					SetCursorPosition(x, y);
					SetColor(ConsoleColor::WHITE, BLUE);
					cout << ' ';
				}
			}
		}
		SetColor(WHITE, BLACK);
		SetCursorPosition(1, 1);
		std::cout << question;
	}
	//рамка
	void Menu::drawFrame() {
		size_t width = getFrameWidth() > question.size() + 2 ? getFrameWidth() : question.size() + 2;
		size_t height = getFrameHeight() + 2;
		drawQuestion();
		for (short y = 0; y < height; y++)
		{
			for (short x = 0; x < width; x++)
			{
				if (x == 0 || x == width - 1 || y == 2 || y == height - 1) {
					SetCursorPosition(x, y);
					SetColor(ConsoleColor::WHITE, BLUE);
					cout << ' ';
				}
			}
		}
		SetColor(WHITE, BLACK);
	}
	void Menu::drawControls()
	{
		short x = (getFrameWidth() > question.size() + 2 ? getFrameWidth() : question.size() + 2) + 3;
		for (int i{}; i < 11; i++)
		{
			SetCursorPosition(x, 1 + i * 2);
			SetColor(GREEN, BLACK);
			std::cout << controls[i];
			SetColor(WHITE, BLACK);
			std::cout << controlmeans[i];
		}
	}
	
	//варіанти і все інше
	void Menu::drawOptions() {
		drawFrame();
		short startX = 3;
		short startY = 4;
		size_t max = getMaxItemSize();
		for (size_t i = 0; i < options.size(); i++)
		{
			SetCursorPosition(startX, startY + (short)i);
			if (activeOption == i) {
				SetColor(RED, WHITE);
			}
			else {
				SetColor(WHITE, BLACK);
			}
			std::string item = options[i];
			item.append(string(max - item.size(), ' '));
			cout << item;
		}
	}
	//вниз
	void Menu::down() {
		activeOption++;
		if (activeOption >= (long long)options.size()) {
			activeOption = 0;
		}
	}
	//вверх
	void Menu::up() {
		activeOption--;
		if (activeOption < 0) {
			activeOption = options.size() - 1;
		}
	}
	//повертає вибраний варіант
	size_t Menu::getSelectedOption() {
		return activeOption;
	}
	//визначає розмір
	size_t Menu::getMaxItemSize()  {
		size_t max = 0;
		for (string item : options)
		{
			if (item.size() > max) {
				max = item.size();
			}
		}
		return max;
	}
	//ширина
	size_t Menu::getFrameWidth()  {
		return getMaxItemSize() + 6;
	}
	//висота
	size_t Menu::getFrameHeight()  {
		return options.size() + 4;
	}
	
//повертає нажату клавішу
WCHAR keymenu()
{
	WCHAR key;
	while (true)
	{
		SetColor(WHITE, BLACK);
		key = GetKey();
		if (key == -1) {
			Sleep(10);
			continue;
		}
		else return key;
	}
}
//малює квадрат
 void drawnameframe(const size_t width, const size_t height, const size_t startX, const size_t startY, const ConsoleColor color)
{
	for (size_t y = startY; y < height; y++)
	{
		for (size_t x = startX; x < width; x++)
		{
			if (x == startX or x == width - 1 or y == startY or y == height - 1) {
				SetCursorPosition((short)x, (short)y);
				SetColor(ConsoleColor::WHITE, color);
				std::cout << ' ';
			}
		}
	}
	SetCursorPosition((short)startX + 1, (short)startY + 1);
	SetColor(WHITE, BLACK);
}
//квадрат з текстом посередині
void warnmessage(const std::string message, ConsoleColor color)
{
	system("cls");
	std::string mes = message + " Press Enter:";
	drawnameframe(75, 12, 35, 8, color);
	SetCursorPosition(55 - (short)message.size() / 2, 10);
	SetColor(color, BLACK);
	std::cout << message;
	WCHAR key = -1;
	while (true)
	{
		key = GetKey();
		if (key == ENTER or key == ESC) {
			SetColor(WHITE, BLACK);
			system("cls");
			return;
		}
	}
}
//меню в 1 функції
size_t mainmenu(const std::vector<std::string> mes, const std::string& question)
{
	Menu menu(mes, question);
	menu.drawOptions();
	while (true)
	{	
		switch (keymenu())
		{
		case VK_UP:
		{
			menu.up();
			menu.drawOptions();
			break;
		}
		case VK_DOWN:
		{
			menu.down();
			menu.drawOptions();
			break;
		}
		case ENTER:
		{
			system("cls");
			return menu.getSelectedOption();
		}
		}
	}
}
//перетворює строку в час
std::chrono::system_clock::time_point fromString(const std::string& dateStr, const std::string& format) {
	std::stringstream ss{ dateStr };
	std::chrono::system_clock::time_point tp;
	ss >> std::chrono::parse(format, tp);
	if (ss.fail()) {
		warnmessage("Wrong data!", RED);
	}
	return tp;
}
//ввести час
time_t EnterTime(const std::string& mes)
{
	system("cls");
	std::string tim;
	switch (mainmenu({ "Enter time","Current time" }, mes))
	{
	case 0:
		system("cls");
		drawnameframe(75, 11, 35, 8, GRAY);
		SetCursorPosition(36, 9);
		std::cout << "Enter time(in DD.MM.YYYY): ";
		std::getline(std::cin, tim);
		system("cls");
		return std::chrono::system_clock::to_time_t(fromString(tim, "%d.%m.%Y"));
	}
	return time(0);
}
//підтвердження
bool suretable(const std::string& message) {
	WCHAR key;
	bool sure = false;
	const size_t width = 76;
	const size_t height = 12;
	const short startX = 35;
	const short startY = 7;
	drawnameframe(width, height, startX, startY,ConsoleColor::TEAL_FADE);
	SetColor(WHITE, BLACK);
	SetCursorPosition((55 - (short)message.size() / 2), startY + 1);
	std::cout << message;
	SetCursorPosition((width + startX) / 2 - 5, height - 2);
	SetColor(RED, BLACK);
	std::cout << "No";
	SetColor(GREEN, BLACK);
	SetCursorPosition((width + startX) / 2 + 3, height - 2);
	std::cout << "Yes";
	while (true)
	{
		key = GetKey();
		if (key == -1) {
			Sleep(10);
			continue;
		}
		switch (key)
		{
		case VK_LEFT:
			SetCursorPosition((width + startX) / 2 + 3, height - 2);
			SetColor(GREEN, BLACK);
			std::cout << "Yes";
			SetCursorPosition((width + startX) / 2 - 5, height - 2);
			SetColor(BLACK, RED);
			std::cout << "No";
			sure = false;
			break;
		case VK_RIGHT:
			SetCursorPosition((width + startX) / 2 - 5, height - 2);
			SetColor(RED, BLACK);
			std::cout << "No";
			SetCursorPosition((width + startX) / 2 + 3, height - 2);
			SetColor(BLACK, GREEN);
			std::cout << "Yes";
			sure = true;
			break;
		case ENTER:
			SetColor(WHITE, BLACK);
			system("cls");
			return sure;
		}
	}
}

string inputbox(const ConsoleColor color, const string& mes)
{
	string res;
	drawnameframe(90, 11, 40, 8, color);
	cout << mes;
	getline(cin, res);
	system("cls");
	return res;
}
void WriteNice(std::vector<std::string> strings, ConsoleColor color)
{
	drawnameframe(strings[shift::biggest(strings)].size() + 5, strings.size() + 2, 0, 0, color);
	for (size_t i{}; i < strings.size(); i++)
	{
		SetCursorPosition(1, (short)i + 1);
		std::cout << strings[i];
	}
	SetCursorPosition(0,  (short)strings.size() + 3);
}
void wait()
{
	int key=-1;
	while (true)
	{
		key = GetKey();
		if (key == ENTER or key == ESC) {
			SetColor(WHITE, BLACK);
			system("cls");
			return;
		}
	}
}
void Progressbar(std::string mes, int sleeptime)
{
	drawnameframe(111, 8, 9, 5, GRAY);
	SetCursorPosition(60 - (short)mes.size() / 2, 6);
	std::cout << mes;
	drawnameframe(111, 10, 9, 7, GRAY);
	SetColor(GREEN, GREEN);
	sleeptime -= 200;
	SetCursorPosition(10, 8);
	for (short i{}; i < 100; i++)
	{
		std::cout << " ";
		Sleep(sleeptime / 100);
	}
	SetColor(WHITE, BLACK);
	system("cls");
}

void drawDriveControls(std::vector<std::string> mes)
	{
		short x = mes[shift::biggest(mes)].size()+10;
		for (int i{}; i < 7; i++)
		{
			SetCursorPosition(x, 1 + i * 2);
			SetColor(GREEN, BLACK);
			std::cout << drivecontrols[i];
			SetColor(WHITE, BLACK);
			std::cout << drivemeans[i];
		}
	}