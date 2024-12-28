#include <stdio.h>
#include <stdlib.h>


void number_system();
void input_system();

int main(void) {
	int s;
	printf("請選擇數字系統或文字系統:");
	scanf("%d", &s);
	switch (s)
	{
	case 1:
		number_system();
		break;
	case 2:
		input_system();
		break;
	};
	system("pause");
	return 0;
}

void number_system() {
	printf("1");
}

void input_system() {
	printf("2");
}