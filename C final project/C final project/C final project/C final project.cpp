#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void number_system();
void input_system();

int main(void) {
	int s;
    printf("----------------抽籤工具---------------\n");
    printf("輸入數字選擇系統，數字系統:1 文字系統:2\n");
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
    int numChits, target, i, j, enhancedIndex, enhancementFactor;
    char** chits;
    int* probabilities;
    int* selected;
    int totalProb = 0;

    printf("請輸入籤的數量: ");
    scanf("%d", &numChits);

    // 動態分配記憶體
    chits = (char**)malloc(numChits * sizeof(char*));
    probabilities = (int*)malloc(numChits * sizeof(int));
    selected = (int*)malloc(numChits * sizeof(int));

    // 初始化籤與機率
    for (i = 0; i < numChits; i++) {
        chits[i] = (char*)malloc(100 * sizeof(char)); // 每個籤分配100字元
        printf("請輸入第 %d 支籤: ", i + 1);
        scanf("%s", chits[i]);
        probabilities[i] = 1; // 預設每支籤的初始機率為1
        selected[i] = 0; // 初始化未被選中
    }

    printf("請選擇需要提升機率的籤 (輸入索引1~%d, 若無輸入0): ", numChits);
    scanf("%d", &enhancedIndex);
    if (enhancedIndex > 0 && enhancedIndex <= numChits) {
        printf("請輸入提升的倍率: ");
        scanf("%d", &enhancementFactor);
        probabilities[enhancedIndex - 1] = enhancementFactor;
    }

    printf("請輸入需要抽取的籤數量: ");
    scanf("%d", &target);

    if (target > numChits) {
        printf("抽取數量不可大於籤的總數。\n");
        return;
    }

    // 計算總機率
    for (i = 0; i < numChits; i++) {
        totalProb += probabilities[i];
    }

    srand(time(0)); // 初始化隨機數種子

    printf("抽取的籤如下:\n");
    for (i = 0; i < target; i++) {
        int randomProb = rand() % totalProb + 1; // 隨機選擇機率
        int cumulativeProb = 0;

        // 根據機率選擇籤
        for (j = 0; j < numChits; j++) {
            if (selected[j]) continue; // 跳過已選中的籤
            cumulativeProb += probabilities[j];
            if (randomProb <= cumulativeProb) {
                printf("%s\n", chits[j]);
                totalProb -= probabilities[j];
                selected[j] = 1; // 標記已選中
                break;
            }
        }
    }

    // 釋放記憶體
    for (i = 0; i < numChits; i++) {
        free(chits[i]);
    }
    free(chits);
    free(probabilities);
    free(selected);
}
