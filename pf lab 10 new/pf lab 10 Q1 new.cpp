#include <stdio.h>
typedef struct Box {
    int weight;          
    int num_subboxes;    
    struct Box* subboxes[10]; 
} Box;
int calculateTotalWeight(Box* box) {
    int totalWeight = box->weight;
    for (int i = 0; i < box->num_subboxes; i++) {
        totalWeight += calculateTotalWeight(box->subboxes[i]);
    }
    return totalWeight;
}
int main() {
    Box box1 = {10, 0, {NULL}};
    Box box2 = {20, 0, {NULL}};
    Box box3 = {0, 2, {&box1, &box2}};
    Box outerBox = {5, 1, {&box3}};
    int totalWeight = calculateTotalWeight(&outerBox);
    printf("Total weight of the outer box: %d\n", totalWeight);
    
    return 0;
}
