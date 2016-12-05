#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> calexp(string t, int start, int end)
{
    vector<int> midres;
    if (start == end){
        midres.push_back(t[start]-'0');
    }else if (end - start == 2){
        switch (t[start+1])
        {
        case '+':
            midres.push_back(t[start] - '0' + t[end] - '0');
            break;
        case '-':
            midres.push_back(t[start] - t[end]);
            break;
        case '*':
            midres.push_back((t[start] - '0') * (t[end] - '0'));
            break;
        default:
            break;
        }
    } else{
        for (int k = start; k < end; k++){
            if (t[k] == '+' || t[k] == '-' || t[k] == '*'){
                vector<int> left = calexp(t, start, k - 1);
                vector<int> right = calexp(t, k + 1, end);
                for (int i = 0; i < left.size(); i++){
                    for (int j = 0; j < right.size(); j++){
                        switch (t[k])
                        {
                        case '+':
                            midres.push_back(left[i] + right[j]);
                            break;
                        case '-':
                            midres.push_back(left[i] - right[j]);
                            break;
                        case '*':
                            midres.push_back(left[i] * right[j]);
                            break;
                        default:
                            break;
                        }
                    }
                }
            }
        }
    }
    return midres;
}

//vector<int> diffWaysToCompute(string input)
//{
//    vector<int> res;
//    if (input.size() == 0)
//        return res;
//
//    int operpos = 0;
//    for (int k = 0; k < input.size(); k++){
//        if (input[k] == '+' || input[k] == '-' || input[k] == '*'){
//            vector<int> left = calexp(input, 0, k - 1);
//            vector<int> right = calexp(input, k + 1, input.size() - 1);
//            for (int i = 0; i < left.size(); i++){
//                for (int j = 0; j < right.size(); j++){
//                    switch (input[k]){
//                    case '+':
//                        res.push_back(left[i] + right[j]);
//                        break;
//                    case '-':
//                        res.push_back(left[i] - right[j]);
//                        break;
//                    case '*':
//                        res.push_back(left[i] * right[j]);
//                        break;
//                    default:
//                        break;
//                    }
//                }
//            }
//        }
//    }
//    if (res.size() == 0){
//        int i = 0, num = 0;
//        while (i < input.size()){
//            num = num * 10 + input[i] - '0';
//            i++;
//        }
//        res.push_back(num);
//    }
//    return res;
//}
vector<int> diffWaysToCompute(string input)
{
    vector<int> ret;
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == '+' || input[i] == '-' || input[i] == '*')
        {
            vector<int> left = diffWaysToCompute(input.substr(0, i));
            vector<int> right = diffWaysToCompute(input.substr(i + 1));
            for (int j = 0; j < left.size(); j++)
            {
                for (int k = 0; k < right.size(); k++)
                {
                    if (input[i] == '+')
                        ret.push_back(left[j] + right[k]);
                    else if (input[i] == '-')
                        ret.push_back(left[j] - right[k]);
                    else
                        ret.push_back(left[j] * right[k]);
                }
            }
        }
    }
    if (ret.empty())
        ret.push_back(atoi(input.c_str()));
    return ret;
}

//int main()
//{
//    string t = "10";
//    //vector<int> res = diffWaysToCompute(t);
//    cout << atoi("10") << endl;
//    cout << atoi(t.c_str()) << endl;
//    return 0;
//}
