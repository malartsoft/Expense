#include "stdafx.h"
#include "Expense.h"

void Expense::Create(HWND hWnd, HINSTANCE hInst) {
	stt = 0;
	sumExpense = 0;
	Expense::hWnd = hWnd;
	Expense::hInst = hInst;
	LOGFONT lf;
	GetObject(GetStockObject(DEFAULT_GUI_FONT), sizeof(LOGFONT), &lf);
	HFONT hFont = CreateFont(19, lf.lfWidth,
		lf.lfEscapement, lf.lfOrientation, lf.lfWeight,
		lf.lfItalic, lf.lfUnderline, lf.lfStrikeOut, lf.lfCharSet,
		lf.lfOutPrecision, lf.lfClipPrecision, lf.lfQuality,
		lf.lfPitchAndFamily, lf.lfFaceName);
	TCHAR* listTargets[6] = { TEXT("Ăn uống"),TEXT("Di chuyển"),TEXT("Nhà cửa"),TEXT("Xe cộ"),TEXT("Nhu yếu"),TEXT("Dịch vụ") };

	//create button, static, edit
	hWndStatic = CreateWindowEx(0, L"BUTTON", L"Thêm một loại chi tiêu", BS_GROUPBOX | WS_CHILD | WS_VISIBLE, 30, 10, 620, 120, hWnd, (HMENU)IDI_COMBOMOX, hInst, NULL);
	SendMessage(hWndStatic, WM_SETFONT, WPARAM(hFont), TRUE);
	hWndStatic = CreateWindowEx(0, L"STATIC", L"Loại chi tiêu:", WS_CHILD | WS_VISIBLE | SS_LEFT, 50, 50, 100, 50, hWnd, NULL, hInst, NULL);
	SendMessage(hWndStatic, WM_SETFONT, WPARAM(hFont), TRUE);
	hWndStatic = CreateWindowEx(0, L"STATIC", L"Nội dung:", WS_CHILD | WS_VISIBLE | SS_LEFT, 220, 50, 100, 40, hWnd, NULL, hInst, NULL);
	SendMessage(hWndStatic, WM_SETFONT, WPARAM(hFont), TRUE);
	hWndStatic = CreateWindowEx(0, L"STATIC", L"Số tiền ($):", WS_CHILD | WS_VISIBLE | SS_LEFT, 370, 50, 100, 40, hWnd, NULL, hInst, NULL);
	SendMessage(hWndStatic, WM_SETFONT, WPARAM(hFont), TRUE);
	hWndButtonAdd = CreateWindowEx(0, L"BUTTON", L"Thêm", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_FLAT, 520, 75, 100, 25, hWnd, (HMENU)IDI_ADDBUTTON, hInst, NULL);
	SendMessage(hWndButtonAdd, WM_SETFONT, WPARAM(hFont), TRUE);


	hWndComboBox = CreateWindowEx(0, L"COMBOBOX", NULL, CBS_DROPDOWN | WS_CHILD | WS_VISIBLE, 50, 80, 150, 400, hWnd, (HMENU)IDI_COMBOMOX, hInst, NULL);
	SendMessage(hWndComboBox, WM_SETFONT, WPARAM(hFont), TRUE);
	hWndTextboxContent = CreateWindowEx(0, L"EDIT", L"", WS_CHILD | WS_VISIBLE | WS_BORDER | WS_VSCROLL |ES_MULTILINE , 220, 80, 120, 20, hWnd, NULL, hInst, NULL);
	SendMessage(hWndTextboxContent, WM_SETFONT, WPARAM(hFont), TRUE);
	hWndTextboxMoney = CreateWindowEx(0, L"EDIT", L"", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_CENTER, 370, 80, 120, 20, hWnd, NULL, hInst, NULL);
	SendMessage(hWndTextboxMoney, WM_SETFONT, WPARAM(hFont), TRUE);

	hWndStatic = CreateWindowEx(0, L"BUTTON", L"Toàn bộ danh sách chi tiêu", BS_GROUPBOX | WS_CHILD | WS_VISIBLE, 30, 160, 620, 350, hWnd, (HMENU)IDI_COMBOMOX, hInst, NULL);
	SendMessage(hWndStatic, WM_SETFONT, WPARAM(hFont), TRUE);

	hWndListView=CreateWindowEx(0, WC_LISTVIEW, NULL,LVS_SHOWSELALWAYS|WS_VISIBLE | WS_CHILD | WS_BORDER| WS_VSCROLL | WS_TABSTOP, 50, 190, 580, 300, hWnd,( HMENU) IDI_LISTVIEW, hInst, NULL);
	Init4ColumListview();
	LoadListView();

	hWndStatic = CreateWindowEx(0, L"BUTTON", L"Thông tin thống kê", BS_GROUPBOX | WS_CHILD | WS_VISIBLE, 680, 10, 420, 500, hWnd, (HMENU)IDI_COMBOMOX, hInst, NULL);
	SendMessage(hWndStatic, WM_SETFONT, WPARAM(hFont), TRUE);
	hWndStatic = CreateWindowEx(0, L"STATIC", L"Tổng cộng tất cả:", WS_CHILD | WS_VISIBLE | SS_LEFT, 750, 40, 130, 20, hWnd, NULL, hInst, NULL);
	SendMessage(hWndStatic, WM_SETFONT, WPARAM(hFont), TRUE);
	hWndTextboxSum = CreateWindowEx(0, L"EDIT", L"", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_CENTER, 880, 40, 120, 20, hWnd, NULL, hInst, NULL);
	SendMessage(hWndTextboxSum, WM_SETFONT, WPARAM(hFont), TRUE);

	hWndStatic = CreateWindowEx(0, L"STATIC", L"Ăn uống:", WS_CHILD | WS_VISIBLE | SS_LEFT, 740, 80, 85, 20, hWnd, NULL, hInst, NULL);
	SendMessage(hWndStatic, WM_SETFONT, WPARAM(hFont), TRUE);
	hWndTextboxEat = CreateWindowEx(0, L"EDIT", L"", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_CENTER, 800, 80, 80, 20, hWnd, NULL, hInst, NULL);
	SendMessage(hWndTextboxEat, WM_SETFONT, WPARAM(hFont), TRUE);

	hWndStatic = CreateWindowEx(0, L"STATIC", L"Di chuyển:", WS_CHILD | WS_VISIBLE | SS_LEFT, 940, 80, 85, 20, hWnd, NULL, hInst, NULL);
	SendMessage(hWndStatic, WM_SETFONT, WPARAM(hFont), TRUE);
	hWndTextboxMove = CreateWindowEx(0, L"EDIT", L"", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_CENTER, 1010, 80, 80, 20, hWnd, NULL, hInst, NULL);
	SendMessage(hWndTextboxMove, WM_SETFONT, WPARAM(hFont), TRUE);

	hWndStatic = CreateWindowEx(0, L"STATIC", L"Nhà cửa:", WS_CHILD | WS_VISIBLE | SS_LEFT, 740, 110, 85, 20, hWnd, NULL, hInst, NULL);
	SendMessage(hWndStatic, WM_SETFONT, WPARAM(hFont), TRUE);
	hWndTextboxHouse = CreateWindowEx(0, L"EDIT", L"", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_CENTER, 800, 110, 80, 20, hWnd, NULL, hInst, NULL);
	SendMessage(hWndTextboxHouse, WM_SETFONT, WPARAM(hFont), TRUE);

	hWndStatic = CreateWindowEx(0, L"STATIC", L"Xe cộ:", WS_CHILD | WS_VISIBLE | SS_LEFT, 940, 110, 50, 20, hWnd, NULL, hInst, NULL);
	SendMessage(hWndStatic, WM_SETFONT, WPARAM(hFont), TRUE);
	hWndTextboxCar = CreateWindowEx(0, L"EDIT", L"", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_CENTER, 1010, 110, 80, 20, hWnd, NULL, hInst, NULL);
	SendMessage(hWndTextboxCar, WM_SETFONT, WPARAM(hFont), TRUE);


	hWndStatic = CreateWindowEx(0, L"STATIC", L"Nhu yếu:", WS_CHILD | WS_VISIBLE | SS_LEFT, 740, 140, 85, 20, hWnd, NULL, hInst, NULL);
	SendMessage(hWndStatic, WM_SETFONT, WPARAM(hFont), TRUE);
	hWndTextboxNeed = CreateWindowEx(0, L"EDIT", L"", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_CENTER, 800, 140, 80, 20, hWnd, NULL, hInst, NULL);
	SendMessage(hWndTextboxNeed, WM_SETFONT, WPARAM(hFont), TRUE);

	hWndStatic = CreateWindowEx(0, L"STATIC", L"Dịch vụ:", WS_CHILD | WS_VISIBLE | SS_LEFT, 940, 140, 50, 20, hWnd, NULL, hInst, NULL);
	SendMessage(hWndStatic, WM_SETFONT, WPARAM(hFont), TRUE);
	hWndTextboxService = CreateWindowEx(0, L"EDIT", L"", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_CENTER, 1010, 140, 80, 20, hWnd, NULL, hInst, NULL);
	SendMessage(hWndTextboxService, WM_SETFONT, WPARAM(hFont), TRUE);

	//crate listview
	for (int i = 0; i < 6; i++) {
		SendMessage(hWndComboBox, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)listTargets[i]);
	}
	CalcSum();
}

//check exist char
bool Expense:: IsChar(WCHAR *s) {
	int i = 0;
	while (s[i] != '\0') {
		if (s[i] > 57 || s[i] < 48)
			return 1;
		i++;
	}
	return 0;
}

//check element in expense
bool Expense::CheckElement(WCHAR * kindExpense,WCHAR *content,WCHAR* money) {
	//if input number smaller 0
	if (money[0] == '-') {
		MessageBox(0, L"Don't input number smaller 0 - Try again", L"Error", 0);
		return 0;
	}

	//exist char in textbox
	if (IsChar(money)) {
		MessageBox(0, L"Exist char in textbox - Try again", L"Error", 0);
		return 0;
	}
	if (money[0] == '\0'||kindExpense[0]=='\0'||content[0]=='\0') {
		MessageBox(0, L"Can't be empty - Try again", L"Error", 0);
		return 0;
	}
	return 1;
}

//process when add a expense
void Expense::ProcessAdd() {
	WCHAR* kindExpense = NULL;
	WCHAR* content = NULL;
	WCHAR* money = NULL;
	WCHAR* sum = NULL;
	item tmp;

	int sizeKindExpense;
	int sizeContent;
	int sizeMoney;
	int sizeSum;

	sizeKindExpense = GetWindowTextLength(hWndComboBox);
	sizeContent = GetWindowTextLength(hWndTextboxContent);
	sizeMoney = GetWindowTextLength(hWndTextboxMoney);
	if (sizeMoney > 9) {
		MessageBox(0, L"Overflow!! Try again", L"Error", 0);
		return;
	}

	kindExpense = new WCHAR[sizeKindExpense + 1];
	content = new WCHAR[sizeContent + 1];
	money = new WCHAR[sizeMoney + 1];


	GetWindowText(hWndComboBox, kindExpense, sizeKindExpense + 1);
	GetWindowText(hWndTextboxContent, content, sizeContent + 1);
	GetWindowText(hWndTextboxMoney, money, sizeMoney + 1);

	if (!CheckElement(kindExpense, content, money))
		return;

	LV_ITEM lv;
	lv.mask = LVIF_TEXT | LVIF_IMAGE | LVIF_PARAM;
	lv.iSubItem = 0;
	lv.iItem = stt;
	lv.iSubItem = 0;
	wchar_t wStt[4];
	swprintf_s(wStt, L"%d", stt+1);
	lv.pszText = wStt;

	ListView_InsertItem(hWndListView, &lv);
	ListView_SetItemText(hWndListView, stt, 1, kindExpense);
	ListView_SetItemText(hWndListView, stt, 2, content);
	ListView_SetItemText(hWndListView, stt, 3, money);

	tmp.stt = wStt;
	tmp.kindExpense = kindExpense;
	tmp.content = content;
	tmp.money = money;
	data.push_back(tmp);

	stt++;
	CalcSum();
	InvalidateRect(hWnd, NULL, TRUE);
}

//crate 4 colum in list view
void Expense::Init4ColumListview() {
	LVCOLUMN lvCol;

	lvCol.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvCol.fmt = LVCFMT_LEFT;

	lvCol.cx = 40;
	lvCol.pszText = _T("STT");
	ListView_InsertColumn(hWndListView, 0, &lvCol);

	lvCol.cx = 100;
	lvCol.pszText = _T("Loại chi tiêu");
	ListView_InsertColumn(hWndListView, 1, &lvCol);

	lvCol.cx = 350;
	lvCol.pszText = _T("Nội dung");
	ListView_InsertColumn(hWndListView, 2, &lvCol);

	lvCol.pszText = _T("Số tiền");
	lvCol.cx = 90;
	ListView_InsertColumn(hWndListView, 3, &lvCol);

	LONG dNotView = ~( LVS_LIST );
	SetWindowLong(hWndListView, GWL_STYLE, GetWindowLong(hWndListView, GWL_STYLE) & dNotView | LVS_REPORT);
}

//read database in file text
void Expense::ReadDatabase() {
	wfstream input("DataBase.txt", ios::in);
	if (!input.is_open()) {
		MessageBox(hWnd, L"Don't read database", L"Error", 0);
		exit(0);
	}
	input.imbue(locale(input.getloc(), new codecvt_utf8<wchar_t, 0x10ffff, consume_header>()));
	//read file and get data
	while (!input.eof()) {
		item tmp;
		getline(input, tmp.stt, L'\t');
		getline(input, tmp.kindExpense, L'\t');
		getline(input, tmp.content, L'\t');
		getline(input, tmp.money, L'\n');
		data.push_back(tmp);
	}
	data.pop_back();
	input.close();
}

//write database in file text
void Expense::WriteDatabase() {
	wfstream output("DataBase.txt", ios::out);
	output.imbue(locale(output.getloc(), new codecvt_utf8<wchar_t, 0x10ffff, consume_header>()));
	if (!output.is_open()) {
		MessageBox(hWnd, L"Don't open database", L"Error", 0);
		return;
	}
	for (int i = 0; i < data.size(); i++) {
		wstring tmp= data[i].stt +L"\t"+ data[i].kindExpense+L"\t"+ data[i].content + L"\t" +data[i].money + L"\n";
		output.write(tmp.c_str(), tmp.size());
	}
	output.close();
}

//load listview to show
void Expense::LoadListView() {
	ReadDatabase();
	for (int i = 0; i < data.size(); i++) {
		LV_ITEM lv;
		lv.mask = LVIF_TEXT | LVIF_IMAGE | LVIF_PARAM;
		lv.iSubItem = 0;
		lv.iItem = stt;
		lv.iSubItem = 0;
		lv.pszText = (wchar_t*)data[i].stt.c_str();

		ListView_InsertItem(hWndListView, &lv);
		ListView_SetItemText(hWndListView, stt, 1, (wchar_t*)data[i].kindExpense.c_str());
		ListView_SetItemText(hWndListView, stt, 2, (wchar_t*)data[i].content.c_str());
		ListView_SetItemText(hWndListView, stt, 3, (wchar_t*)data[i].money.c_str());
		stt++;
	}
}

//cal sum all to show on program
void Expense::CalcSum() {
	WCHAR* bufferSum = new WCHAR[255];
	int sum = 0;
	for (int i = 0; i < data.size(); i++) {
		sum += _wtoi(data[i].money.c_str());
	}
	Expense::sumExpense = sum;
	wsprintf(bufferSum, L"%d", sum);
	SetWindowText(hWndTextboxSum, bufferSum);
}

//draw chart to show on program
void Expense::DrawChart(HDC hdc) {

	MoveToEx(hdc, 700, 70, NULL);
	LineTo(hdc,1080, 70);


	HBRUSH hbrushEat = CreateSolidBrush(RGB(255, 0, 0));
	HBRUSH hbrushMove = CreateSolidBrush(RGB(0, 255, 0));
	HBRUSH hbrushHouse = CreateSolidBrush(RGB(0, 0, 255));
	HBRUSH hbrushCar = CreateSolidBrush(RGB(255, 255, 0));
	HBRUSH hbrushNeed = CreateSolidBrush(RGB(0, 255, 255));
	HBRUSH hbrushService = CreateSolidBrush(RGB(255, 0, 255));

	RECT rcNoteEat{ 700, 80 , 730, 100 };
	FillRect(hdc, &rcNoteEat, hbrushEat);
	RECT rcNoteMove{ 900, 80 , 930, 100 };
	FillRect(hdc, &rcNoteMove, hbrushMove);

	RECT rcNoteHouse{ 700, 110 , 730, 130 };
	FillRect(hdc, &rcNoteHouse, hbrushHouse);
	RECT rcNoteCar{ 900, 110 , 930, 130 };
	FillRect(hdc, &rcNoteCar, hbrushCar);

	RECT rcNoteNeed{ 700, 140 , 730, 160 };
	FillRect(hdc, &rcNoteNeed, hbrushNeed);
	RECT rcNoteService{ 900, 140 , 930, 160 };
	FillRect(hdc, &rcNoteService, hbrushService);

	if (sumExpense == 0)
		return;

	int sumEat=0, sumMove=0, sumHouse=0, sumCar=0, sumNeed=0, sumService=0;
	for (int i = 0; i < data.size(); i++) {
		if (data[i].kindExpense == L"Ăn uống")
			sumEat += _wtoi(data[i].money.c_str());
		if (data[i].kindExpense == L"Di chuyển")
			sumMove += _wtoi(data[i].money.c_str());
		if (data[i].kindExpense == L"Nhà cửa")
			sumHouse += _wtoi(data[i].money.c_str());
		if (data[i].kindExpense == L"Xe cộ")
			sumCar += _wtoi(data[i].money.c_str());
		if (data[i].kindExpense == L"Nhu yếu")
			sumNeed += _wtoi(data[i].money.c_str());
		if (data[i].kindExpense == L"Dịch vụ")
			sumService += _wtoi(data[i].money.c_str());
	}

	WCHAR* bufferEat = new WCHAR[255];
	WCHAR* bufferMove = new WCHAR[255];
	WCHAR* bufferHouse = new WCHAR[255];
	WCHAR* bufferCar = new WCHAR[255];
	WCHAR* bufferNeed = new WCHAR[255];
	WCHAR* bufferService = new WCHAR[255];

	wsprintf(bufferEat, L"%d", sumEat);
	wsprintf(bufferMove, L"%d", sumMove);
	wsprintf(bufferHouse, L"%d", sumHouse);
	wsprintf(bufferCar, L"%d", sumCar);
	wsprintf(bufferNeed, L"%d", sumNeed);
	wsprintf(bufferService, L"%d", sumService);

	SetWindowText(hWndTextboxEat, bufferEat);
	SetWindowText(hWndTextboxMove, bufferMove);
	SetWindowText(hWndTextboxHouse, bufferHouse);
	SetWindowText(hWndTextboxCar, bufferCar);
	SetWindowText(hWndTextboxNeed, bufferNeed);
	SetWindowText(hWndTextboxService, bufferService);

	
	//Fill Chart
	RECT rcEat{ 750, 500 - ((float)sumEat / (float)sumExpense) * 300, 780, 500 };
	RECT rcMove{ 800, 500 - ((float)sumMove / (float)sumExpense) * 300, 830, 500 };
	RECT rcHouse{ 850, 500 - ((float)sumHouse / (float)sumExpense) * 300, 880, 500 };
	RECT rcCar{ 900, 500 - ((float)sumCar / (float)sumExpense) * 300, 930, 500 };
	RECT rcNeed{ 950, 500 - ((float)sumNeed / (float)sumExpense) * 300, 980, 500 };
	RECT rcService{ 1000, 500 - ((float)sumService / (float)sumExpense) * 300, 1030, 500 };

	FillRect(hdc, &rcEat, hbrushEat);
	FillRect(hdc, &rcMove, hbrushMove);
	FillRect(hdc, &rcHouse, hbrushHouse);
	FillRect(hdc, &rcCar, hbrushCar);
	FillRect(hdc, &rcNeed, hbrushNeed);
	FillRect(hdc, &rcService, hbrushService);

}