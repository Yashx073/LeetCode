bool canJump(int* nums, int numsSize) {
    int jump = 0;
    for(int i = 0; i < numsSize; i++){

        if(i > jump ){
            return false;
        }  

        if(i + nums[i] > jump){
            jump = i + nums[i];
        }

        if(jump >= numsSize - 1){
            return true;
        }
    }
    return true;
}