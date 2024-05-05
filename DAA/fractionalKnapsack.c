#include <stdio.h>
#include <stdlib.h>

int n = 5;
int w[10] = {12, 1, 2, 1, 4};
int p[10] = {4, 2, 2, 1, 10};
int W = 15;

void simple_fill()
{
    int current_weight = W;
    float total_profit = 0;
    int used[10];

    for (int i = 0; i < n; i++)
    {
        used[i] = 0;
    }

    while (current_weight > 0)
    {
        int maxi = -1;
        for (int i = 0; i < n; i++)
        {
            if ((used[i] == 0) && ((maxi == -1) || ((float)(p[i] / w[i]) > (float)(p[maxi] / w[maxi]))))
            {
                maxi = i;
            }
        }

        used[maxi] = 1;
        current_weight = current_weight - w[maxi];
        total_profit = total_profit + p[maxi];

        if (current_weight > 0)
        {
            printf("%d object with weight %d and profit %d added completely into the sack. Space left: %d \n", maxi + 1, w[maxi], p[maxi], current_weight);
        }
        else
        {
            printf("%d object with weight %d and profit %d added %d percent into the sack \n", maxi + 1, w[maxi], p[maxi], ((int)((1 + (float)current_weight / w[maxi]) * 100)));
            total_profit = total_profit - p[maxi];
            total_profit = total_profit + ((float)current_weight / w[maxi]) * p[maxi];
        }
    }

    printf("%f of total profit made", total_profit);
}

int main()
{
    simple_fill();
    return 0;
}