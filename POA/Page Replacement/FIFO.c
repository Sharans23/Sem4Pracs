#include <stdio.h>
int nf, np, j, i, fifo_pointer = 0, hit = 0, fault = 0;
int frames[100], pages[100];
int find(int x)
{
    for (int k = 0; k < nf; k++)
    {
        if (frames[k] == x)
            return 1;
    }
    return 0;
}
void print_frame()
{
    for (int k = 0; k < nf; k++)
    {
        if (frames[k] == -1)
            printf("-\t");
        else
            printf("%d\t", frames[k]);
    }
    printf("\n");
}
void main()
{
    printf("Enter no of frames:\n");
    scanf("%d", &nf);
    printf("Enter no of page references:\n");
    scanf("%d", &np);
    printf("Enter page references:\n");
    for (i = 0; i < np; i++)
        scanf("%d", &pages[i]);
    for (i = 0; i < nf; i++)
        frames[i] = -1;
    // printing header
    for (i = 0; i < nf; i++)
        printf("F%d\t", i + 1);
    printf("\n");
    for (i = 0; i < np; i++)
    {
        if (find(pages[i]))
        {
            hit++;
            print_frame();
        }
        else
        {
            for (j = 0; j < nf; j++)
            {
                if (frames[j] == -1)
                {
                    fault++;
                    frames[j] = pages[i];
                    print_frame();
                    break;
                }
            }
            if (j == nf)
            {
                fault++;
                frames[fifo_pointer] = pages[i];
                fifo_pointer = (fifo_pointer + 1) % nf;
                print_frame();
            }
        }
    }
    printf("Number of Page Faults:%d\n", fault);
    printf("Number of Page Hits:%d\n", hit);
}