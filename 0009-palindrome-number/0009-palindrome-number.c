bool isPalindrome(int x) {
    int a,r;
    long long s=0;
    a=x;
    while (a>0)
    {
        r=a%10;
        s=s*10+r;
        a=a/10;
    }
    if (s==x)
        return true;
    else
        return false;
    // return s==x;
}