// Step 1. Start to traverse the pages.
// Step 2. If the memory holds fewer pages, then the capacity else goes to step 5.
// Step 3. Push pages in the queue one at a time until the queue reaches its maximum capacity or all page requests are fulfilled.
// Step 4. If the current page is present in the memory, do nothing.
// Step 5. Else, pop the topmost(FIFO) page from the queue as it was inserted first.
// Step 6. Replace the topmost page with the current page from the string.
// Step 7. Increment the page faults. (FAULT)
// Step 8. Stop

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