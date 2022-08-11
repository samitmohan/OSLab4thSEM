#include <stdio.h>
int main()
{
    int referenceString[10], pageFaults = 0, i, j, s, pages, frames;
    printf(" Enter the number of Pages: ");
    scanf("%d", &pages);
    printf("Enter reference string values: ");
    for (i = 0; i < pages; i++)
    {
        printf("Value %d:", i + 1);
        scanf("%d", &referenceString[i]);
    }

    printf("\n Total number of frames: ");
    scanf("%d", &frames);
    int temp[frames]; // temp arr of same frame number

    for (i = 0; i < frames; i++)
    {
        temp[i] = -1; // all -1 initially
    }

    for (i = 0; i < pages; i++)
    {
        s = 0; // hits
        for (j = 0; j < frames; j++)
        {
            if (referenceString[i] == temp[j]) // hit
            {
                s++;          // hit++
                pageFaults--; // fault less
            }
        }
        pageFaults++; // else increase page fault

        if ((pageFaults <= frames) && (s == 0)) // 0 hits
        {
            temp[i] = referenceString[i]; // keep doing it
        }
        else if (s == 0) // replacement time
        {
            temp[(pageFaults - 1) % frames] = referenceString[i]; // new ref string (FIFO) (remove top % size)
        }

        printf("\n");
        for (j = 0; j < frames; j++) // print all frame
        {
            printf("%d\t", temp[j]);
        }
    }
    printf("\nTotal Page Faults: %d", pageFaults);
    return 0;
}