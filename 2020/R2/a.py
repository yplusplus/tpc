def handle(s):
    return "0" * (4 - len(s)) + s

def solve():
    s = raw_input()
    lst = s.split(":")
    if "" in lst:
        p = lst.index("")
        cnt = lst.count("")
        lst = lst[:p] + ["0"] * (8 - len(lst) + cnt) + lst[p+cnt:]

    print':'.join(map(handle, lst))
    return

def main():
    T = input()
    while T > 0:
        T = T - 1
        solve()

if __name__ == "__main__":
    main()
