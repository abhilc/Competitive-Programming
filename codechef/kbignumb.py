if __name__ == '__main__':
    T = raw_input();
    while int(T)!=0:
        l,n,m=map(int,raw_input().split())
        val = int(str(l) + (n-1)*str(l))
        # print val
        print(val%m)
        T = int(T)-1
