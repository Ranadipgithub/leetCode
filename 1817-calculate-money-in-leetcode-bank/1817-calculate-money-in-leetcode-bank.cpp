class Solution {
public:
    int totalMoney(int n) {
        if(n <= 7){
            return n*(n+1)/2;
        }
        int sum = 0;
        int comp = n/7;
        int rem = n%7;
        for(int i = 1;i<=comp;i++){
            sum += 28 + (i-1)*7;
        }
        int ini = comp+1;
        cout << ini << " " << rem;
        int temp = rem*(comp) + ((rem) * (rem + 1))/2;
        cout << temp << endl;
        return sum+temp;
    }
};