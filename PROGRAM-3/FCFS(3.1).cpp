#include<stdio.h> 

int main() { 
    int pages[50], frames[10]; 
    int n, f, i, j, k = 0, fault = 0, found; 
    
    printf("enter number of pages:"); 
    scanf("%d", &n); 
    
    printf("enter page reference string:"); 
    for(i = 0; i < n; i++) {
        scanf("%d", &pages[i]); 
    }
    
    printf("enter number of frames:"); 
    scanf("%d", &f); 
    
    for(i = 0; i < f; i++) { // Changed n to f here to prevent out-of-bounds array access
        frames[i] = -1; 
    }
    
    for(i = 0; i < n; i++) { 
        found = 0; 
        for(j = 0; j < f; j++) { 
            if(frames[j] == pages[i]) { 
                found = 1; 
                break; // FIXED: Changed breaK to break
            } 
        } 
        
        if(!found) { 
            frames[k] = pages[i]; 
            k = (k + 1) % f; 
            fault++; 
        } 
    } 
    
    printf("total page faults(FIFO)=%d\n", fault); 
    return 0; 
}

