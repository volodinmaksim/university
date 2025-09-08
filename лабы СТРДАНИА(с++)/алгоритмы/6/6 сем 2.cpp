#include <iostream>
#include <vector>
using namespace std;

void print_vec2(vector<vector<int>> dp)
{
    for (int i{}; i < dp.size(); i++)
    {
        for (int j{}; j < dp[i].size(); j++)
            cout << dp[i][j] << ' ';
        cout << endl;
    }
}


int main()
{
    setlocale(0, "");
    int n, d;
    cin >> n >> d;
    while (n < 2 * d)
    {
        cout << "невозможно\n";
        cout << "Введите заново:\n";
        cin >> n >> d;
    }

    int length = n / 2;
    vector<vector<int>> dp(length + 1, vector<int>(d + 1, 0));
    vector<vector<int>> sum(length + 1, vector<int>(d + 1, 0));


    dp[0][0] = dp[1][1] = 1;
    for (int i = 1; i <= length; ++i)
        dp[i][1] = 1;


    for (int i = 0; i <= length; ++i) {
        for (int j = 0; j <= d; ++j) {
            if (i == 0 && j == 0) sum[i][j] = 1;
            else if (i == 1 && j >= 1) sum[i][j] = 1;
            else sum[i][j] = 0;
        }
    }


    for (int i = 2; i <= length; ++i)
    {
        for (int j = 1; j <= d; ++j) 
        {

            dp[i][j] = dp[i - 1][j - 1];

            for (int k = 1; k < i; ++k) 
            {
                dp[i][j] += dp[k][j] * sum[i - k][j];
                dp[i][j] += dp[k][j] * sum[i - k][j - 1];
            }

            if (j > 1) 
                for (int k = 1; k < i; ++k) 
                    dp[i][j] -= dp[k][j] * dp[i - k][j];
        }

        sum[i][0] = dp[i][0];
        for (int j = 1; j <= d; ++j)
            sum[i][j] = sum[i][j - 1] + dp[i][j];
    }

    print_vec2(dp);
    cout << dp[length][d] << endl;
}




