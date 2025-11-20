#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
    1. [설계]에서 정의한 변수, 배열, (필요하면) 구조체를 여기에 선언하세요.
*/

char shoulderNames[3][30] = {"어깨 돌리기", "벽 밀기 스트레칭", "팔 뻗기"};
char waistNames[3][30]    = {"고양이 자세", "옆구리 늘리기", "브리지"};
char neckNames[3][30]     = {"목 옆으로 기울이기", "고개 돌리기", "턱 당기기"};
char legNames[3][30]      = {"햄스트링 스트레칭", "종아리 늘리기", "스쿼트"};

char neckGuide[2][100] = {
    "고개를 천천히 좌우로 돌리세요. (2분)",
    "고개를 앞뒤로 천천히 숙였다 드세요. (3분)"
};
char shoulderGuide[2][100] = {
    "어깨를 앞으로 10회, 뒤로 10회 돌리세요. (3분)",
    "양팔을 뒤로 젖혀 가슴을 펴세요. (2분)"
};
char waistGuide[2][100] = {
    "허리를 좌우로 천천히 비트세요. (3분)",
    "양손을 허리에 두고 뒤로 젖혀 허리를 펴세요. (2분)"
};
char legGuide[2][100] = {
    "무릎을 굽히고 발끝을 잡으며 10초 유지하세요. (3세트)",
    "앉은 자세에서 다리를 쭉 뻗고 상체를 숙이세요. (2분)"
};

char parts[4][10] = {"어깨", "허리", "목", "다리"};


/*
    2. [알고리즘]에서 설계한 핵심 기능 함수들을 여기에 선언하세요.
*/

void initData();          // 스트레칭 데이터 초기화 (핵심 기능 3)
void recommendStretch();  // 스트레칭 추천 기능 (핵심 기능 1)
void showStretchList();   // 스트레칭 목록 보기 기능 (핵심 기능 2)


int main() {
    
    printf("--- C언어 미니 프로젝트 시작! ---\n");

    /*
        3. [알고리즘]에서 설계한 main 함수의 흐름을
           여기에 C언어로 자유롭게 구현하세요.
    */

    srand(time(NULL));

    initData();   // 핵심 기능 3

    int choice;

    while (1) {
        printf("\n===== 메뉴 =====\n");
        printf("1. 스트레칭 추천\n");
        printf("2. 스트레칭 목록 보기\n");
        printf("0. 종료\n");
        printf("번호 선택: ");
        scanf("%d", &choice);

        if (choice == 1) {
            recommendStretch();  // 핵심 기능 1
        }
        else if (choice == 2) {
            showStretchList();   // 핵심 기능 2
        }
        else if (choice == 0) {
            printf("프로그램 종료!\n");
            break;
        }
        else {
            printf("잘못된 입력입니다.\n");
        }
    }
    
    return 0;
}


/* =======================================
   아래는 실제 기능 함수 정의부
======================================= */

void initData() {
    printf("스트레칭 데이터 준비 완료!\n");
}


void recommendStretch() {

    char input[20];
    printf("\n어느 부위가 불편한가요? (어깨/허리/목/다리): ");
    scanf("%s", input);

    int r = rand() % 3;

    printf("\n=== 추천 스트레칭 ===\n");

    if (strcmp(input, "어깨") == 0)
        printf("%s\n", shoulderNames[r]);
    else if (strcmp(input, "허리") == 0)
        printf("%s\n", waistNames[r]);
    else if (strcmp(input, "목") == 0)
        printf("%s\n", neckNames[r]);
    else if (strcmp(input, "다리") == 0)
        printf("%s\n", legNames[r]);
    else
        printf("잘못된 입력입니다.\n");
}


void showStretchList() {

    int part, num;

    printf("\n== 부위 선택 ==\n");
    printf("1. 목\n2. 어깨\n3. 허리\n4. 다리\n");
    printf("번호 입력: ");
    scanf("%d", &part);

    if (part < 1 || part > 4) {
        printf("잘못된 선택입니다.\n");
        return;
    }

    printf("\n== 스트레칭 선택 ==\n");

    if (part == 1) {
        printf("1. 좌우 돌리기\n2. 앞뒤 숙이기\n");
        scanf("%d", &num);
        if (num == 1) printf("%s\n", neckGuide[0]);
        else if (num == 2) printf("%s\n", neckGuide[1]);
        else printf("잘못된 선택입니다.\n");
    }
    else if (part == 2) {
        printf("1. 어깨 돌리기\n2. 가슴 펴기\n");
        scanf("%d", &num);
        if (num == 1) printf("%s\n", shoulderGuide[0]);
        else if (num == 2) printf("%s\n", shoulderGuide[1]);
        else printf("잘못된 선택입니다.\n");
    }
    else if (part == 3) {
        printf("1. 허리 비틀기\n2. 허리 젖히기\n");
        scanf("%d", &num);
        if (num == 1) printf("%s\n", waistGuide[0]);
        else if (num == 2) printf("%s\n", waistGuide[1]);
        else printf("잘못된 선택입니다.\n");
    }
    else if (part == 4) {
        printf("1. 햄스트링\n2. 다리 숙이기\n");
        scanf("%d", &num);
        if (num == 1) printf("%s\n", legGuide[0]);
        else if (num == 2) printf("%s\n", legGuide[1]);
        else printf("잘못된 선택입니다.\n");
    }
}
