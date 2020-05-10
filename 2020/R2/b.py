def main():
    n, name = raw_input().split(" ")
    n = int(n)
    lst = raw_input().split(" ")
    candys = {}
    for c in lst:
        candys[c] = candys.get(c, 0) + 1

    cnt2 = 0
    for k, v in candys.iteritems():
        if v == 1:
            print "Alice"
            return
        elif v == 2:
            cnt2 = cnt2 + 1

    if (cnt2 == 1 and name == "Alice") or cnt2 > 1:
        print "Alice"
    else:
        print "Bob"

if __name__ == "__main__":
    main()
