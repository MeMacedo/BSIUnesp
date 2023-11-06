#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, a, b;
    double dp[1000010];

    scanf("%d %d %d", &n, &a, &b);

    if (a != 0)
    {
        for (int i = 1; i < a; i++)
        {
            dp[i] = 1.0;
        }

        double pref = 0.0;

        for (int i = a; i <= n; i++)
        {
            int t = b - a + 1;

            pref += dp[i - a];

            if (i - b - 1 >= 0)
            {
                pref -= dp[i - b - 1];
            }

            double val = 1.0 + (pref / double(t));

            dp[i] = val;
        }
    }
    else
    {
        double pref = 0.0;

        for (int i = 1; i <= n; i++)
        {
            int t = b - a + 1;

            if (i)
            {
                pref += dp[i - 1];
            }

            if (i - b - 1 >= 0)
            {
                pref -= dp[i - b - 1];
            }

            dp[i] = ((double(t) + pref) / t) / (1.0 - double(1.0 / t));
        }
    }

    printf("%.7lf\n", dp[n]);

    return 0;
}
