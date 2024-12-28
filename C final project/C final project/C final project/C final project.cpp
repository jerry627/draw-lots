#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void number_system();
void input_system();

int main(void) {
	int s;
    printf("數字系統:1 文字系統:2\n");
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
    int lowest;//最小數
    int largest;//最大數
    int target;//抽取多少目標
    int i, range;
    int* arr;

    printf("請輸入最小數: ");
    scanf("%d", &lowest);
    printf("請輸入最大數: ");
    scanf("%d", &largest);
    printf("請輸入抽取幾個目標: ");
    scanf("%d", &target);


    range = largest - lowest + 1;//計算範圍

    arr = (int*)malloc(range * sizeof(int));//動態記憶體

    // 將範圍內的數值存入陣列
    for (i = 0; i < range; i++) {
        arr[i] = lowest + i;
    }

    // 初始化隨機數種子
    srand(time(0));

    // 洗牌算法打亂陣列
    for (i = range - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    // 輸出目標數量的隨機數
    printf("隨機抽取的數字是: ");
    for (i = 0; i < target; i++) {
        printf("%d ", arr[i]);
    }
}

void input_system() {
	printf("2");
}