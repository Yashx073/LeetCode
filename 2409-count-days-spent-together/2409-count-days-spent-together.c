const int days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int days(char* date){
    int month = (date[0] - '0') * 10 + date[1] - '0';
    int day = (date[3] - '0') * 10 + date[4] - '0';

    int total = day;

    for(int i = 0; i < month-1; i++){
        total += days_in_month[i];
    }

    return total;
}

int countDaysTogether(char* arriveAlice, char* leaveAlice, char* arriveBob, char* leaveBob) {
    
int a1 = days(arriveAlice);
int a2 = days(leaveAlice);
int b1 = days(arriveBob);
int b2 = days(leaveBob);

int a = (a1 > b1) ? a1 : b1;
int b = (a2 < b2) ? a2 : b2;

return (b >= a) ?  b - a + 1 : 0;

}