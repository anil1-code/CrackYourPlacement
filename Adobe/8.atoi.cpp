int atoi(string str) {
    int i = 0, mul = 1;
    if(str[0] == '-') {
        mul = -1, i++;
    }
    int num = 0;
    for(; i < (int)str.length(); i++) {
        num *= 10;
        if(str[i] >= '0' and str[i] <= '9')
            num += str[i] - '0';
        else return -1;
    }
    return num * mul;
}