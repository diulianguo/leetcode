#include<iostream>
using namespace std;

//int main()
//{
//    char s[3];
//    char temp_s[3];
//    cin >> s;
//    int i, j,k;
//    int length = 0;
//    int sum = 0;
//    char unsafes[64][3];
//    for (i = 0; i < 3; i++){
//        if (s[i] != '\0')
//            length++;
//    }
//    for (j = 0; j < length; j++){
//        temp_s[j] = s[j];
//    }
//
//    for (i = 0; i < length; i++){
//        for (k = 97; k < 101; k++){
//            for (j = 0; j < length; j++){
//                temp_s[j] = s[j];
//            }
//            sum = 0;
//            temp_s[i] = k;
//            for (j = 0; j < length; j++)
//                sum += temp_s[j];
//            for (j = 0; j < length; j++)
//                unsafes[sum - 97 * length][j] = temp_s[j];
//        }
//    }
//    for (i = 0; i < 12; i++){
//        for (j = 0; j < length;j++)
//            cout << unsafes[i][j];
//        cout << endl;
//    }
//    system("pause");
//    return 0;
//}

void insert(int *p, int length)
{
    int *copy_p = new int(length);
    int i;
    for (i = 0; i < length; i++){
        copy_p[i] = p[i];
    }
    for (i = 0; i < p[0]-1; i++){
        copy_p[i] = copy_p[i + 1];
    }
    copy_p[i] = p[0];
    for (i = 0; i < length; i++){
        p[i] = copy_p[i];
    }
}

int main()
{
    char num[9];
    int i;
    int length = 0;
    cin >> num;
    for (i = 0; i < 9; i++)
    {
        if (num[i] != '\0')
            length++;
    }
    int *numbers = new int(length);
    for (i = 0; i < length; i++)
    {
        numbers[i] = num[i] - 48;
    }

    int t;
    cin >> t;

    for (i = 0; i < t; i++){
        insert(numbers, length);
    }
    return 0;
}