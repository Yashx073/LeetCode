int tra(int start, int end, int* travel){
    int time = 0;
    for(int i = start; i < end; i++){
        time += travel[i];
    }
    return time;
}

int count(const char* garbage, char target){
    int cout = 0;
    for(int i = 0; garbage[i] != '\0'; i++){
        if(garbage[i] == target){
            cout++;
        }
    }
    return cout;
}

int garbageCollection(char** garbage, int garbageSize, int* travel, int travelSize) {
    
    int m = 0, p = 0, g = 0;
    int mi = 0, pi = 0, gi = 0;
    for(int i = 0; i < garbageSize; i++){
        if(strchr(garbage[i], 'M') != NULL){
            m += tra(mi, i, travel);
            mi = i;
            m += count(garbage[i], 'M');
        }

        if(strchr(garbage[i], 'P') != NULL){
            p += tra(pi, i, travel);
            pi = i;
            p += count(garbage[i], 'P');
        }

        if(strchr(garbage[i], 'G') != NULL){
            g += tra(gi, i, travel);
            gi = i;
            g += count(garbage[i], 'G');
        }
    }

    return m+p+g;
}