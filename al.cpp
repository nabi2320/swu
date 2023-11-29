#include <iostream>
using namespace std;

int main() {
    char R[128] = {};
    //진수 변환 2진수, 16진수, 8진수 
    int A[3] = { 2, 16, 8 };
    //16진수의 경우, A~F 표시 
    char B[3][16] = { {'0', '1'}, {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'}, {'0', '1', '2', '3', '4', '5', '6', '7'} };

    int K = 1;
    int N;

    //N 입력 받기
    cout << "N 입력: ";
    cin >> N;
    int TTEMP = N;

    //N이 음수인지 확인, 음수라면 절댓값으로 바꾸어줌 
    if (N < 0) {
        K = -1; 
        TTEMP = -TTEMP;
    }

    //첫번째 반복문. 진수 변환마다 반복 
    for (int i = 0; i < 3; i++) {
        int p = 0;
        N = TTEMP;

        //진수 변환 계산, N이 나누는 수보다 작으면 종료 
        while (N >= A[i]) {
            //나머지를 R[p]에 저장 
            R[p] = B[i][N % A[i]];
            //이후에 N값을 몫으로 교체 
            N /= A[i];
            p += 1;
        }
        //마지막 나머지도 R[p]에 저장 
        R[p] = B[i][N];

        //만약 음수라면
        if (K == -1) {
            //그중에서도 2진수라면 
            if (i == 0) {
                int TEMP = p;
                //1의 보수 처리 
                while (p >= 0) {
                    R[p] = R[p] ^ 1;
                    p -= 1;
                }
                //1을 더해서 2의 보수 처리 
                for (p = 0;R[p] == '1';p++) {
                    R[p] = '0';

                }
                R[p] = '1';
                p = TEMP;
            }
            //8진수나 16진수는 - 출력 
            else
                cout << '-';
        }

        // 최근 나머지부터 출력 
        for (p; p >= 0; p--) {
            cout << R[p];
        }

        cout << " "; // Add space between different bases
    }

    return 0;
}
