#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

bool Include(const char* str, const char* cs)
{
	bool r = true;
	for (int i = 0; cs[i] != '\0'; i++)
		r = r && (strchr(str, cs[i]));

	return r;
}

char* Change(char* str)
{
	char* t = new char[strlen(str)];
	char* p;
	int pos1 = 0, pos2 = 0;

	*t = 0;
	while (p = strchr(str + pos1, 'n'))
	{
		if (str[p - str + 1] == 'o')
		{
			pos2 = p - str + 2;
			strncat(t, str + pos1, pos2 - pos1 - 2);
			strcat(t, "***");
			pos1 = pos2;
		}
	}
	strcat(t, str + pos1);

	strcpy(str, t);

	return t;
}

int main()
{
	char str[101];

	cout << "Enter string:" << endl;
	cin.getline(str, 100);

	char cs[] = "no";
	if (Include(str, cs))
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	
	char* dest = new char[151];

	dest = Change(str);

	cout << "Modified string (param) : " << str << endl;
	cout << "Modified string (result): " << dest << endl;

	return 0;
}