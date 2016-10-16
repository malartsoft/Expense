#pragma once
#include "Resource.h"
#include <CommCtrl.h>>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <fcntl.h>
#include <codecvt>

using namespace std;
class Expense
{
private:
	struct item{
		wstring stt;
		wstring kindExpense;
		wstring content;
		wstring money;
	};
	vector<item>data;
	HWND hWnd;
	HINSTANCE hInst;

	HWND hWndComboBox;
	HWND hWndButtonAdd;
	HWND hWndStatic;
	HWND hWndTextboxContent;
	HWND hWndTextboxMoney;
	HWND hWndTextboxSum;

	HWND hWndTextboxEat;
	HWND hWndTextboxMove;
	HWND hWndTextboxHouse;
	HWND hWndTextboxCar;
	HWND hWndTextboxNeed;
	HWND hWndTextboxService;

	HWND hWndListView;
	int stt;
	int sumExpense;
public:

	void Create(HWND hWnd, HINSTANCE hInst);
	void ProcessAdd();
	void Init4ColumListview();
	void WriteDatabase();
	void ReadDatabase();
	void LoadListView();
	void CalcSum();
	void DrawChart(HDC hdc);

	bool IsChar(WCHAR *s);
	bool CheckElement(WCHAR * kindExpense, WCHAR *content, WCHAR* money);
};

