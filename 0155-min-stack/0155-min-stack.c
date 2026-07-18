


typedef struct {
    int arr[100000];
    int top;
    int size;
    int min[100000];
    int m;
} MinStack;


MinStack* minStackCreate() {
    MinStack* obj = malloc(sizeof(MinStack));
    obj->top = -1;
    obj->size = 10000;
    obj->m = -1;
    return obj;
}

void minStackPush(MinStack* obj, int value) {
    if(obj->top < obj->size - 1){
       obj->arr[++obj->top] = value;
    }
    if(obj->m == -1){
        obj->min[++obj->m] = value;
    }
    else if(obj->min[obj->m] >= value){
        obj->min[++obj->m] = value;
    }
}

void minStackPop(MinStack* obj) {
    if(obj->arr[obj->top] == obj->min[obj->m]){
        obj->m--;   
    }

    if(obj->top != -1){
        obj->top--;
    }    
    
}

int minStackTop(MinStack* obj) {
    return obj->arr[obj->top];   
}

int minStackGetMin(MinStack* obj) {
    return obj->min[obj->m];
}

void minStackFree(MinStack* obj) {
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, value);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/