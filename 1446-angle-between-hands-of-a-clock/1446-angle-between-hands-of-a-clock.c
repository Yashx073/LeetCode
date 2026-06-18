double angleClock(int hour, int minutes) {
    double min = minutes * 6.0;
    double hr = (hour % 12) * 30.0 + (minutes/60.0 * 30);

    double result = min - hr;
    if(result < 0){
        result = -result;
    }
    if(result > 180){
        result = 360 - result;
    }
    return result;
}