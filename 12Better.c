// Page fault
#include <stdio.h>
int main()
{
    int i, hit, no_of_pages, refString[50], frame[10], no_of_frames, j, avail, pageFaults = 0;
    printf("\n Enter number of pages : ");
    scanf("%d", &no_of_pages);
    // Reading the reference string
    printf("\n Enter page number:\n");
    for (i = 1; i <= no_of_pages; i++)
        scanf("%d", &refString[i]);
    printf("\n Enter number of frames :  :");
    scanf("%d", &no_of_frames);
    // Initially all frames are empty: here empty denotes -1
    for (i = 0; i < no_of_frames; i++)
        frame[i] = -1;
    hit = 0;
    printf("\t Ref String \t Page Frames\n");
    // iterating through the reference string
    for (i = 1; i <= no_of_pages; i++)
    {
        printf("%d \t \t", refString[i]);
        avail = 0;
        // Finding whether the current page is present in memory frame, avail set to one if present in memory frame
        for (j = 0; j < no_of_frames; j++)
            if (frame[j] == refString[i])
                avail = 1;
        // avail = 0 if page not present in memory frame in that case replace the
        // first page which was allocated in a frame and increment page fault (FIFO)
        if (avail == 0)
        {
            frame[hit] = refString[i];
            hit = (hit + 1) % no_of_frames;
            pageFaults++;
            for (j = 0; j < no_of_frames; j++)
                printf("%d\t", frame[j]);
        }
        printf("\n");
    }
    printf("Page Fault Is %d", pageFaults);
    return 0;
}