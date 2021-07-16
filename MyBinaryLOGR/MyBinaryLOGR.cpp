// MyBinaryLOGR.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <Windows.h>
#include "binary_logr.h"
#include "readData.h"

double X[100][5];
double w[4];
double lr;
double epochs;

#define CHARBUFF 124
void getGurrentDirectory(char* currentDirectory);

int main()
{
    // iniファイルから読み込むCSVファイルの名前を取得
    char currentDirectory[CHARBUFF];
    getGurrentDirectory(currentDirectory);
    char section[CHARBUFF];
    sprintf_s(section, "section1");
    char keyWord[CHARBUFF];
    sprintf_s(keyWord, "filename");
    char settingFile[CHARBUFF];
    sprintf_s(settingFile, "%s\\setting.ini", currentDirectory);
    char file_name[CHARBUFF];
    if (GetPrivateProfileString(section, keyWord, "none", file_name, CHARBUFF, settingFile) != 0) {
        //fprintf(stdout, "%s , %s\n", settingFile, file_name);
    }

    char output_dim_char[CHARBUFF];
    char keyWord2[CHARBUFF];
    sprintf_s(keyWord2, "output_dim");
    if (GetPrivateProfileString(section, keyWord2, "none", output_dim_char, CHARBUFF, settingFile) != 0) {
        //fprintf(stdout, "%s , %s\n", settingFile, output_dim_char);
    }


    char input_dim_char[CHARBUFF];
    char keyWord3[CHARBUFF];
    sprintf_s(keyWord3, "input_dim");
    if (GetPrivateProfileString(section, keyWord3, "none", input_dim_char, CHARBUFF, settingFile) != 0) {
        //fprintf(stdout, "%s , %s\n", settingFile, input_dim_char);
    }

    char lr_char[CHARBUFF];
    char keyWord4[CHARBUFF];
    sprintf_s(keyWord4, "lr");
    if (GetPrivateProfileString(section, keyWord4, "none", lr_char, CHARBUFF, settingFile) != 0) {
        //fprintf(stdout, "%s , %s\n", settingFile, lr_char);
    }

    char e_char[CHARBUFF];
    char keyWord5[CHARBUFF];
    sprintf_s(keyWord5, "epochs");
    if (GetPrivateProfileString(section, keyWord5, "none", e_char, CHARBUFF, settingFile) != 0) {
        //fprintf(stdout, "%s , %s\n", settingFile, e_char);
    }

    int output_dim = (int)atof(output_dim_char);
    int input_dim = (int)atof(input_dim_char);
    lr = atof(lr_char); // 学習率
    epochs = (int)atof(e_char);
    fprintf_s(stdout, "ロジスティック回帰を行います\n");
    fprintf_s(stdout, "読み込まれたファイル：%s\n", file_name);
    fprintf_s(stdout, "学習率：%lf\n", lr);
    fprintf_s(stdout, "epochs(繰り返し回数)：%lf\n", epochs);

    // データ読み込み
    read_data(file_name);

    // 初期化
    init();

    // fit
    fprintf_s(stdout, "fit...\n");
    int i = 0;
    for (i = 0; i < epochs; i++) {
        fit(X);
    }

    // 予測結果
    double rslt = result(X);
    fprintf_s(stdout, "予測結果: %lf%%\n", rslt);
    fprintf_s(stdout, "正常終了\n");
    
}
void getGurrentDirectory(char* currentDirectory) {
    GetCurrentDirectory(CHARBUFF, currentDirectory);
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
