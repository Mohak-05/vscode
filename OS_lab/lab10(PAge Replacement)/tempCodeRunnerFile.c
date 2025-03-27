#include <stdio.h>
#include <stdlib.h>


int checkPresence(int cqueue[], int size, int target){
   for(int i = 0; i < size; i++){
       if(cqueue[i] == target) return 1;
   }
   return 0;
}
void FIFO(int refStrs[], int size, int numFrames){
   printf("\nFIFO Page Replacement Algorithm :");
   printf("\n-------------------------------");
   int cqueue[numFrames];
   int front = 0;
   int queuesize = 0;
   int totalFaults = 0;
   for(int i = 0; i < size; i++){
       if(!queuesize){
           printf("\nPage Request for %d -> Page Fault", refStrs[i]);
           cqueue[front] = refStrs[i];
           queuesize++;
           front = (front + 1)%numFrames;
           totalFaults++;
       }
       else{
           if(!checkPresence(cqueue, queuesize, refStrs[i])){
               printf("\nPage Request for %d -> Page Fault", refStrs[i]);
               cqueue[front] = refStrs[i];
               front = (front + 1)%numFrames;
               if(queuesize < numFrames) queuesize++;
               totalFaults++;
           }
           else{
               printf("\nPage Request for %d -> Page Hit", refStrs[i]);
           }
       }
   }
   printf("\n\nTotal Page Faults Detected: %d\n\n", totalFaults);


}
int main(){
   int numFrames, numStrings;
   printf("\nEnter the number of frames and length of reference string : ");
   scanf(" %d %d", &numFrames, &numStrings);
   int refStrs[numStrings];
   printf("\nEnter the value of the reference strings (Space Separated): ");
   for(int i = 0; i < numStrings; i++){
       scanf(" %d", &refStrs[i]);
   }
   FIFO(refStrs, numStrings, numFrames);
   return 0;
}