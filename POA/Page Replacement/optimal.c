#include <stdio.h>

int np, nf, frame[100], pages[100], hit = 0, fault = 0, i, j;

int find(int x)
{
    for (int k = 0; k < nf; k++)
    {
        if (frame[k] == x)
        {
            return 1;
        }
    }
    return 0;
}

void print_frame()
{
    for (int k = 0; k < nf; k++)
    {
        if (frame[k] == -1)
        {
            printf("-\t");
        }
        else
        {
            printf("%d\t", frame[k]);
        }
    }
    printf("\n");
}

int find_index(int x)
{
    int time[nf], temp;
    int future_use_index = -1; // Initialize to an invalid index

    // Initialize all time values to -1 to indicate that a page has not been accessed yet
    for (int l = 0; l < nf; l++)
    {
        time[l] = -1;
    }

    // Iterate over frames
    for (int l = 0; l < nf; l++)
    {
        // Iterate over future pages
        for (int m = x + 1; m < np; m++)
        {
            // If the current frame contains the future page, store its index in time
            if (frame[l] == pages[m])
            {
                time[l] = m;
                break; // Break to find the earliest future use of the frame
            }
        }
    }

    // Find the frame with the furthest future use
    for (int l = 0; l < nf; l++)
    {
        if (time[l] == -1)
        {
            // If a frame is not used in the future, return it immediately
            return l;
        }
        if (future_use_index == -1 || time[l] > time[future_use_index])
        {
            future_use_index = l;
        }
    }

    return future_use_index;
}

int main()
{
    printf("Enter no of frames: ");
    scanf("%d", &nf);
    printf("Enter no of pages: ");
    scanf("%d", &np);
    printf("Enter pages\n");
    for (i = 0; i < np; i++)
    {
        scanf("%d", &pages[i]);
    }
    for (i = 0; i < nf; i++)
    {
        frame[i] = -1;
    }

    for (i = 0; i < nf; i++)
    {
        printf("F%d\t", i + 1);
    }
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
                if (frame[j] == -1)
                {
                    fault++;
                    frame[j] = pages[i];
                    print_frame();
                    break;
                }
            }
            if (j == nf)
            {
                fault++;
                int index = find_index(i);
                frame[index] = pages[i];
                print_frame();
            }
        }
    }
    printf("No of faults %d:\n", fault);
    printf("No of hits %d:\n", hit);

    return 0;
}
