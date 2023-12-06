class Solution {
public:
    int totalMoney(int n) {
        int noOfWeeks = n / 7;
        int noOfExtraDays = n % 7;
        int totalMoney = 0;
        int firstDay = 28;
        int lastDay = 28 + ((noOfWeeks-1) * 7);
        totalMoney = noOfWeeks * (firstDay + lastDay) / 2;
        int monday = noOfWeeks + 1;
        for(int i=0; i<noOfExtraDays; i++) {
            totalMoney += monday + i;
        }
        return totalMoney;
    }
};